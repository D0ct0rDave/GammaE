//-----------------------------------------------------------------------------
#ifdef _MBCS
	#ifdef __BORLANDC__
	#undef _ASSERTE
	#include <vcl.h>
        #else
       	#include <windows.h>
	#endif
#else
#endif
//-----------------------------------------------------------------------------
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glext.h>

#include "CGRenderer.h"


// CE3D_ShaderRenderer_OGL
#include "Drivers\OGL\ShaderRenderOGL\CE3D_ShaderRenderer_OGL.h"
//-----------------------------------------------------------------------------
//Our two function pointers.

// DEBUG_CODE
void __stdcall glActiveTextureARB_FACKED(uint){};
void __stdcall glClientActiveTextureARB_FACKED(uint){};
void __stdcall glBlendColor_FACKED(float,float,float,float){};
// ! DEBUG_CODE

PFNGLLOCKARRAYSEXTPROC			glLockArraysEXT			 = NULL;
PFNGLUNLOCKARRAYSEXTPROC		glUnlockArraysEXT		 = NULL;
PFNGLACTIVETEXTUREARBPROC		glActiveTextureARB		 = NULL;
PFNGLCLIENTACTIVETEXTUREARBPROC	glClientActiveTextureARB = NULL;
PFNGLBLENDCOLOREXTPROC			glBlendColor			 = NULL;
//-----------------------------------------------------------------------------
#ifndef CHECKERRORS
	#ifdef _DEBUG
	static void CHECKERRORS()
	{
		int iError;
		do{

			iError = glGetError();
			if (iError != GL_NO_ERROR)
			{
				int a=0;
			}
		}while (iError != GL_NO_ERROR);
	}
	#else
	#define CHECKERRORS()
	#endif
#endif
//-----------------------------------------------------------------------------
CE3D_ShaderRenderer_OGL::CE3D_ShaderRenderer_OGL(): poCurrentBV(NULL), poCurrentCMesh(NULL), poCurrentMesh(NULL), iMaxTMUs(1), iCurrentTMU(0), bFlushGeometry(false), bGeometryFlushed(false)
{
}
//-----------------------------------------------------------------------------
CE3D_ShaderRenderer_OGL::~CE3D_ShaderRenderer_OGL()
{
}
//-----------------------------------------------------------------------------
void CE3D_ShaderRenderer_OGL::Init ()
{
  	#ifdef WIN32
	glLockArraysEXT			= (PFNGLLOCKARRAYSEXTPROC)			wglGetProcAddress("glLockArraysEXT");
	glUnlockArraysEXT		= (PFNGLUNLOCKARRAYSEXTPROC)		wglGetProcAddress("glUnlockArraysEXT");
	glActiveTextureARB		= (PFNGLACTIVETEXTUREARBPROC)		wglGetProcAddress("glActiveTextureARB");
	glClientActiveTextureARB= (PFNGLCLIENTACTIVETEXTUREARBPROC)	wglGetProcAddress("glClientActiveTextureARB");
	glBlendColor			= (PFNGLBLENDCOLOREXTPROC)			wglGetProcAddress("glBlendColor");

	// DEBUG_CODE
	if (glActiveTextureARB == NULL)  glActiveTextureARB = glActiveTextureARB_FACKED;
	if (glClientActiveTextureARB == NULL) glClientActiveTextureARB = glClientActiveTextureARB_FACKED;
	if (glBlendColor == NULL) glBlendColor = glBlendColor_FACKED;
	// ! DEBUG_CODE

	#endif
}
//-----------------------------------------------------------------------------
void CE3D_ShaderRenderer_OGL::Render_ShInsProgram(CE3D_ShIns_Program* _poTI)
{
	CGRenderer::I()->SetCurrentProgram( _poTI->poGetProgram() );
}
//-----------------------------------------------------------------------------
void CE3D_ShaderRenderer_OGL::Render_ShInsTexture (CE3D_ShIns_Texture* _poTI)
{
	// Enable texturing for current TMU
	glEnable(GL_TEXTURE_2D);

	iCurrentTMU++;
	if (iCurrentTMU==iMaxTMUs) bFlushGeometry = true;

	CGRenderer::I()->SetCurrentTextureContext(_poTI->m_poTex);
	Render_Geometry();
}
//-----------------------------------------------------------------------------
void CE3D_ShaderRenderer_OGL::Render_ShInsColor (CE3D_ShIns_Color* _poTI)
{
	// Disable texturing for current TMU
	glDisable(GL_TEXTURE_2D);	

	iCurrentTMU++;
	if (iCurrentTMU==iMaxTMUs) bFlushGeometry = true;
	
	CGRenderer::I()->SetConstantColor( _poTI->oGetColor() );
	
	glBlendColor( _poTI->oGetColor().r, _poTI->oGetColor().g,_poTI->oGetColor().b,_poTI->oGetColor().a);
	glBlendFunc(GL_CONSTANT_ALPHA,GL_ONE_MINUS_CONSTANT_ALPHA);
	
	Render_Geometry();	
}
//-----------------------------------------------------------------------------
void CE3D_ShaderRenderer_OGL::Render_ShInsWireframe (CE3D_ShIns_Wireframe* _poTI)
{
	// Set polygon mode	
	glPolygonMode(GL_BACK ,GL_LINE);
	glPolygonMode(GL_FRONT,GL_LINE);

	// Disable texturing for current TMU
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_CULL_FACE);

	iCurrentTMU++;
	if (iCurrentTMU==iMaxTMUs) bFlushGeometry = true;

	CGRenderer::I()->SetConstantColor( _poTI->oGetColor() );

	glBlendColor( _poTI->oGetColor().r,_poTI->oGetColor().g,_poTI->oGetColor().b,_poTI->oGetColor().a);
	glBlendFunc(GL_CONSTANT_ALPHA,GL_ONE_MINUS_CONSTANT_ALPHA);// ??? Siempre deberia ir aqui???

	Render_Geometry();

	// Restore polygon mode	
	glPolygonMode(GL_BACK ,GL_FILL);
	glPolygonMode(GL_FRONT,GL_FILL);
}
//-----------------------------------------------------------------------------
void CE3D_ShaderRenderer_OGL::Render_ShInsExtension (CE3D_ShIns_Extension* _poTI)
{
	iCurrentTMU++;
	if (iCurrentTMU==iMaxTMUs) bFlushGeometry = true;

  	_poTI->pFunction()((void *)&poCurrentMesh);
	Render_Geometry();
}
//-----------------------------------------------------------------------------
void CE3D_ShaderRenderer_OGL::Render_ShInsGeoOp (CE3D_ShIns_GeoOp* _poTI)
{
  	float fValue;
	
	if (_poTI->poGetEvaluator())
		fValue = _poTI->poGetEvaluator()->GetValue();	
	else
		fValue = 0.0f;
	
	glMatrixMode(GL_MODELVIEW);
	switch (_poTI->eGetGOpType())
	{
		case eSIGeoOp_RotateX:	glRotatef(fValue,1.0f,0.0f,0.0f);	break;
		case eSIGeoOp_RotateY:	glRotatef(fValue,0.0f,1.0f,0.0f);	break;
		case eSIGeoOp_RotateZ:	glRotatef(fValue,0.0f,0.0f,1.0f);	break;
		case eSIGeoOp_Scale:	glScalef (fValue,fValue,fValue);	break;
		case eSIGeoOp_ScaleX:	glScalef (fValue,1.0f,1.0f);		break;
		case eSIGeoOp_ScaleY:	glScalef (1.0f,fValue,1.0f);		break;
		case eSIGeoOp_ScaleZ:	glScalef (1.0f,1.0f,fValue);		break;
		case eSIGeoOp_TransX:	glTranslatef(fValue,0.0f,0.0f);		break;
		case eSIGeoOp_TransY:	glTranslatef(0.0f,fValue,0.0f);		break;
		case eSIGeoOp_TransZ:	glTranslatef(0.0f,0.0f,fValue);		break;
	}
	CHECKERRORS();
}
//-----------------------------------------------------------------------------
void CE3D_ShaderRenderer_OGL::Render_ShInsTexOp (CE3D_ShIns_TexOp* _poTI)
{
  	float fValue;
	
	if (_poTI->poGetEvaluator())
		fValue = _poTI->poGetEvaluator()->GetValue();	
	else
		fValue = 0.0f;
	
	glMatrixMode(GL_TEXTURE);
	switch (_poTI->eGetTOpType())
	{
		case eSITexOp_Rotate:	glRotatef(fValue,0.0f,0.0f,1.0f);	break;
		case eSITexOp_Scale:	glScalef (fValue,fValue,1.0f);		break;
		case eSITexOp_ScaleU:	glScalef (fValue,1.0f,1.0f);		break;
		case eSITexOp_ScaleV:	glScalef (1.0f,fValue,1.0f);		break;		
		case eSITexOp_TransU:	glTranslatef(fValue,0.0f,0.0f);		break;
		case eSITexOp_TransV:	glTranslatef(0.0f,fValue,0.0f);		break;

		case eSITexOp_ReflectMap:glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
								glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);

								glEnable(GL_TEXTURE_GEN_S);
								glEnable(GL_TEXTURE_GEN_T);		
								break;

		case eSITexOp_EnvMap:	float fX;		
								float fY;
								fX = poCurrentBV->GetRange(0);
								fY = poCurrentBV->GetRange(1);
								if (fX) fX = 0.5f/fX;
								if (fY) fY = 0.5f/fY;									
								glScalef(fX,fY,1.0f);

								glEnable(GL_TEXTURE_GEN_S);
								glEnable(GL_TEXTURE_GEN_T);

								glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_EYE_LINEAR);
								glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_EYE_LINEAR);
								break;

		case eSITexOp_Matrix:	glMultMatrixf(_poTI->m_poMat->m );
								break;
		
		case eSITexOp_FrameSet:	int		iFrame;
								int		iXFrame;
								int		iYFrame;
								int		iTotalFrames;
								float	fSPF;
								float	fXStep;
								float	fYStep;

								fXStep = 1.0f / _poTI->m_uiImgCols;
								fYStep = 1.0f / _poTI->m_uiImgRows;

								iTotalFrames = _poTI->m_uiImgCols *_poTI->m_uiImgRows;
								fSPF		 = 1.0f / (iTotalFrames*_poTI->m_fFreq);

								iFrame  = (int)(CGRenderer::I()->REStats.fTotalTime / fSPF) % iTotalFrames;
								iYFrame = iFrame / _poTI->m_uiImgCols;
								iXFrame = iFrame - (iYFrame*_poTI->m_uiImgCols);

								glTranslatef(iXFrame*fXStep,iYFrame*fYStep,0.0f);
								glScalef(fXStep,fYStep,1.0f);								
								break;								
	}
	CHECKERRORS();
}
//-----------------------------------------------------------------------------
void CE3D_ShaderRenderer_OGL::Render_ShInsBlendOp (CE3D_ShIns_BlendOp* _poTI)
{
  	bGeometryFlushed = false;

	//<WARNING: DEBUG CODE>
	glDisable  (GL_CULL_FACE);
	bEnableCF = true;

	switch (_poTI->eGetBlendMode())
	{	
        // ------------------
        // Blending ops
        // ------------------
        case E3D_BM_Copy:	        glBlendFunc(GL_ONE,GL_ZERO);
									glEnable   (GL_CULL_FACE);
									bEnableCF  = false;
                                    break;
        case E3D_BM_Mult:			glBlendFunc(GL_DST_COLOR,GL_ZERO);
								    break;
        case E3D_BM_Mult2x:			glBlendFunc(GL_DST_COLOR,GL_SRC_COLOR);
                                    break;
        case E3D_BM_Add:			glBlendFunc(GL_ONE,GL_ONE);
                                    break;
        case E3D_BM_AddAndMult:		glBlendFunc(GL_DST_COLOR,GL_ONE);
                                    break;
        case E3D_BM_MultAndAdd:		glBlendFunc(GL_ONE,GL_SRC_COLOR);
                                    break;
		case E3D_BM_Alpha:			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
									glEnable   (GL_ALPHA_TEST);
									bDisableAT = true;
									break;
		case E3D_BM_AlphaAdd:		glBlendFunc(GL_SRC_ALPHA, GL_ONE);
									glEnable   (GL_ALPHA_TEST);
									bDisableAT = true;
									break;
		case E3D_BM_AlphaInv:		glBlendFunc(GL_ONE_MINUS_SRC_ALPHA,GL_SRC_ALPHA);
									glEnable   (GL_ALPHA_TEST);
									bDisableAT = true;
									break;
		case E3D_BM_AlphaThrough:	// Useful for dummy management
									glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
									glEnable   (GL_ALPHA_TEST);
									bDisableAT = true;
									break;
	}
}
//-----------------------------------------------------------------------------
void CE3D_ShaderRenderer_OGL::Render_ShInsZOp (CE3D_ShIns_ZOp* _poTI)
{
	CGRenderer::I()->SetZPars(_poTI->eGetZTestFunc(), _poTI->eGetZWrite());
}
//-----------------------------------------------------------------------------
void CE3D_ShaderRenderer_OGL::Render_Geometry ()
{
	// WARNING DEBUG CODE
	glDisable(GL_CULL_FACE);
	
  	if (bFlushGeometry)
	{
		switch(eMeshType)
		{
			case eE3DMT_Mesh:			RenderMesh(poCurrentMesh);			break;
			case eE3DMT_CompiledMesh:	RenderCompiledMesh(poCurrentCMesh);	break;
		}

		iCurrentTMU		 = 0;
		bGeometryFlushed = true;
	}

	// Current texture unit
	InitTMU(iCurrentTMU);

	// Reset the program to fixed function
	CGRenderer::I()->SetCurrentProgram(NULL);
}
//-----------------------------------------------------------------------------
void CE3D_ShaderRenderer_OGL::InitTMU (int _iTMU)
{
  
	// First set current TMU
	switch (iCurrentTMU)
	{
		case 0:	glActiveTextureARB(GL_TEXTURE0_ARB);
				glClientActiveTextureARB(GL_TEXTURE0_ARB);				
				break;

		case 1:	glActiveTextureARB(GL_TEXTURE1_ARB);
				glClientActiveTextureARB(GL_TEXTURE1_ARB);				
				break;

		case 2:	glActiveTextureARB(GL_TEXTURE2_ARB);				
				glClientActiveTextureARB(GL_TEXTURE2_ARB);				
				break;

		case 3:	glActiveTextureARB(GL_TEXTURE3_ARB);
				glClientActiveTextureARB(GL_TEXTURE3_ARB);				
				break;
			// ...
	}
	 
	if (bDisableAT)
	{
		glDisable(GL_ALPHA_TEST);
		bDisableAT = false;
	}

	if (bEnableCF)
	{
        // <WARNING: DEBUG CODE>
		// glDisable (GL_CULL_FACE);	// DEBUG
		glEnable	(GL_CULL_FACE);
		glDepthFunc (GL_LEQUAL);
		glDepthMask	(GL_TRUE);
		bEnableCF  = false;
	}

	// Enable texturing for this texture unit
	glEnable(GL_TEXTURE_2D);

	// Reset texture matrix
	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();
	CHECKERRORS();

	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);

	// Setup default blending mode
	glBlendFunc(GL_ONE,GL_ZERO);

	// Set previous z pars
	CGRenderer::I()->SetZPars(E3D_ZTF_Last, E3D_ZW_Last);
}
//-----------------------------------------------------------------------------
void CE3D_ShaderRenderer_OGL::BeginShaderRender ()
{
	InitTMU(0);

	// glDisable (GL_CULL_FACE);	// DEBUG
	glEnable (GL_CULL_FACE);
	
	/*
	glActiveTextureARB(GL_TEXTURE0_ARB);				
	glDisable(GL_TEXTURE_2D);
	
	glActiveTextureARB(GL_TEXTURE1_ARB);
	glDisable(GL_TEXTURE_2D);
		
	glActiveTextureARB(GL_TEXTURE2_ARB);
	glDisable(GL_TEXTURE_2D);

	glActiveTextureARB(GL_TEXTURE3_ARB);				
	glDisable(GL_TEXTURE_2D);
	*/

 	// OPTIMIZATION: glLockArrays Util cuando varias pasadas sobre el mismo objeto!
	// We are telling OGL that from this point, we will not perform any modification
	// in the vertex buffers
	// glLockArraysEXT(0,CurrentMesh->usNumVerts);
}
//-----------------------------------------------------------------------------
void CE3D_ShaderRenderer_OGL::EndShaderRender ()
{
  	
	// Unlock the arrays
	// glUnlockArraysEXT();

}
//-----------------------------------------------------------------------------
void CE3D_ShaderRenderer_OGL::RenderShader (CE3D_Shader *_poShader)
{
  	if (! _poShader) return;

	CE3D_ShaderInstruction *poShIns;
	for (int iIns=0;iIns<_poShader->iGetNumInstructions();iIns++)
	{
		poShIns =_poShader->pGetInstruction(iIns);
		
		if (poShIns)
		{
			switch (poShIns->eGetInstructionType())
			{
				case E3D_SHI_Program:	if (!CGRenderer::I()->REState.FlatRender)
											Render_ShInsProgram((CE3D_ShIns_Program*)poShIns);
										else
										{
											bFlushGeometry = true;
											Render_Geometry();
										}
										break;
				case E3D_SHI_Texture:	if (!CGRenderer::I()->REState.FlatRender)
											Render_ShInsTexture((CE3D_ShIns_Texture*)poShIns);
										else
										{
											bFlushGeometry = true;
											Render_Geometry();
										}
										break;
				case E3D_SHI_Color :		if (!CGRenderer::I()->REState.FlatRender)
											Render_ShInsColor((CE3D_ShIns_Color*)poShIns);
										else
										{
											bFlushGeometry = true;
											Render_Geometry();
										}
										break;
				case E3D_SHI_Wireframe:	if (!CGRenderer::I()->REState.FlatRender)
											Render_ShInsWireframe((CE3D_ShIns_Wireframe*)poShIns);
										else
										{
											bFlushGeometry = true;
											Render_Geometry();
										}
										break;
				case E3D_SHI_Extension:	if (!CGRenderer::I()->REState.FlatRender)
											Render_ShInsExtension((CE3D_ShIns_Extension*)poShIns);
										else
										{
											bFlushGeometry = true;
											Render_Geometry();
										}
										break;
				case E3D_SHI_GeoOp:		Render_ShInsGeoOp((CE3D_ShIns_GeoOp*)poShIns);
										break;
				case E3D_SHI_TexOp:		if (!CGRenderer::I()->REState.FlatRender)
											Render_ShInsTexOp((CE3D_ShIns_TexOp*)poShIns);
										break;
				case E3D_SHI_BlendOp:	if (!CGRenderer::I()->REState.FlatRender)
											Render_ShInsBlendOp((CE3D_ShIns_BlendOp*)poShIns);
										break;
				case E3D_SHI_ZOp:		Render_ShInsZOp((CE3D_ShIns_ZOp*)poShIns);
										break;
				case E3D_SHI_SetTMU:		
										break;															
			}
		}
	}
}
//-----------------------------------------------------------------------------
void CE3D_ShaderRenderer_OGL::Render (CMesh *_poMesh, CE3D_Shader *_poShader)
{
  	assert (_poMesh   && "NULL Mesh operand");
	
	eMeshType	  = eE3DMT_Mesh;
	poCurrentMesh = _poMesh;
	poCurrentBV	  = _poMesh->GetBoundVol();

	if (_poShader)
	{
		BeginShaderRender();
			RenderShader(_poShader);
		EndShaderRender();
	}
	else
	{
		// Only process geometric data
		RenderMesh(_poMesh);
	}
}
//-----------------------------------------------------------------------------
void CE3D_ShaderRenderer_OGL::Render (CCompiledMesh *_poCMesh, CE3D_Shader *_poShader)
{
  	assert (_poCMesh  && "NULL Mesh operand");
	
	eMeshType	    = eE3DMT_CompiledMesh;
	poCurrentCMesh	= _poCMesh;
	poCurrentBV		= _poCMesh->poGetBV();

	if (_poShader)
	{
		BeginShaderRender();
			RenderShader(_poShader);
		EndShaderRender();
	}
	else
		RenderCompiledMesh(_poCMesh);
}
//-----------------------------------------------------------------------------
void CE3D_ShaderRenderer_OGL::RenderMesh (CMesh *_poMesh)
{
  	// Setup color array. If any
	CHECKERRORS();
	
	unsigned int uiTris = 0;

	if (CGRenderer::I()->REState.FlatRender)
	{
		/*
		if ((_poMesh->VCs) && !(CGRenderer::I()->REState.FlatRender))
		{
			glEnableClientState(GL_COLOR_ARRAY);
			glColorPointer(4,GL_FLOAT,0,_poMesh->VCs);
		}
		else
		*/
		glDisableClientState(GL_COLOR_ARRAY);

		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
	}
	else
	{
		if (_poMesh->VCs)
		{
			glEnableClientState(GL_COLOR_ARRAY);
			glColorPointer(4,GL_FLOAT,0,_poMesh->VCs);
		}
		else
		{
			glDisableClientState(GL_COLOR_ARRAY);
		}

		// Setup texcoord array. If any
		if (_poMesh->UVs)
		{
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);

			// <WARNING!!!>
			// Special case (if _poMesh->UVs == _poMesh->VXs)

			if ((void*)_poMesh->UVs == (void*)_poMesh->VXs)	
				glTexCoordPointer(3,GL_FLOAT,0,_poMesh->UVs);
			else
				glTexCoordPointer(2,GL_FLOAT,0,_poMesh->UVs);
		}
		else
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);

		// Setup second texcoord array. if multitexture
		if (_poMesh->UVs2)
		{
			glActiveTextureARB	(GL_TEXTURE1_ARB);
			glEnableClientState	(GL_TEXTURE_COORD_ARRAY);

			// <WARNING!!!>
			// Special case (if _poMesh->UVs == _poMesh->VXs)
			if ((void*)_poMesh->UVs2 == (void*)_poMesh->VXs)	
				glTexCoordPointer(3,GL_FLOAT,0,_poMesh->UVs2);
			else
				glTexCoordPointer(2,GL_FLOAT,0,_poMesh->UVs2);

			glActiveTextureARB	(GL_TEXTURE0_ARB);
		}

		// Setup normal array. If any
		if (_poMesh->VNs)
		{
			glEnableClientState(GL_NORMAL_ARRAY);
			glNormalPointer    (GL_FLOAT,0,_poMesh->VNs);
		}
		else
			glDisableClientState(GL_NORMAL_ARRAY);
	}

	
	// Setup vertex array. Always != null.
	glVertexPointer(3,GL_FLOAT,0,_poMesh->VXs);


	switch (poCurrentMesh->eMeshType)
	{
		case E3D_MESH_NONE:			return;
									break;
		case E3D_MESH_TRIS:			// Draw the elements
									uiTris = _poMesh->usNumPrims;
									glDrawElements (GL_TRIANGLES     ,_poMesh->usNumIdxs,GL_UNSIGNED_SHORT,(void *)_poMesh->Idxs);
									break;
		case E3D_MESH_QUADS:		uiTris = _poMesh->usNumPrims*2;
									glDrawElements (GL_QUADS         ,_poMesh->usNumIdxs,GL_UNSIGNED_SHORT,(void *)_poMesh->Idxs);
									break;
		case E3D_MESH_TRIFANS:		uiTris = _poMesh->usNumPrims;
									glDrawElements (GL_TRIANGLE_FAN  ,_poMesh->usNumIdxs,GL_UNSIGNED_SHORT,(void *)_poMesh->Idxs);
									break;
		case E3D_MESH_TRISTRIPS:	uiTris = _poMesh->usNumPrims;
									glDrawElements (GL_TRIANGLE_STRIP,_poMesh->usNumIdxs,GL_UNSIGNED_SHORT,(void *)_poMesh->Idxs);
									break;
		case E3D_MESH_QUADSTRIPS:	uiTris = _poMesh->usNumPrims*2;
									glDrawElements (GL_QUAD_STRIP    ,_poMesh->usNumIdxs,GL_UNSIGNED_SHORT,(void *)_poMesh->Idxs);
									break;
		case E3D_MESH_NITRIS:		uiTris = _poMesh->usNumPrims;
									glDrawArrays   (GL_TRIANGLES	 ,0,_poMesh->usNumPrims*3);
									break;
		case E3D_MESH_NIQUADS:		uiTris = _poMesh->usNumPrims*2;
									glDrawArrays   (GL_QUADS		 ,0,_poMesh->usNumPrims*4);
									break;
		case E3D_MESH_NITRISTRIP:	uiTris = _poMesh->usNumPrims;
									glDrawArrays   (GL_TRIANGLE_STRIP,0,_poMesh->usNumPrims+2);
									break;
	}

	CGRenderer::I()->REStats.NumRenderedTris  += uiTris;
	CGRenderer::I()->REStats.NumRenderedVerts += _poMesh->usNumVerts;

	CHECKERRORS();
}
//-----------------------------------------------------------------------------
void CE3D_ShaderRenderer_OGL::RenderCompiledMesh (CCompiledMesh *_poCMesh)
{
  	glCallList(poCurrentCMesh->iID);

	CGRenderer::I()->REStats.NumRenderedTris  += poCurrentCMesh->usNumPrims;
	CGRenderer::I()->REStats.NumRenderedVerts += poCurrentCMesh->usNumVerts;
}
//-----------------------------------------------------------------------------
