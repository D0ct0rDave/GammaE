//## begin module%3A9AB97B0096.cm preserve=no
//## end module%3A9AB97B0096.cm

//## begin module%3A9AB97B0096.cp preserve=no
//## end module%3A9AB97B0096.cp

//## Module: CE3D_ShaderRenderer_OGL%3A9AB97B0096; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\Drivers\OGL\ShaderRenderOGL\CE3D_ShaderRenderer_OGL.cpp

//## begin module%3A9AB97B0096.additionalIncludes preserve=no
//## end module%3A9AB97B0096.additionalIncludes

//## begin module%3A9AB97B0096.includes preserve=yes

#ifdef _MBCS
	#include <windows.h>
#else
	#ifdef __BORLANDC__
	#include <vcl.h>
	#endif
#endif

#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glext.h>
//## end module%3A9AB97B0096.includes

// CE3D_ShaderRenderer_OGL
#include "E3D\Drivers\OGL\ShaderRenderOGL\CE3D_ShaderRenderer_OGL.h"
//## begin module%3A9AB97B0096.additionalDeclarations preserve=yes


//Our two function pointers.

// DEBUG_CODE
void __stdcall glActiveTextureARB_FACKED(unsigned int i)
{
}

void __stdcall glClientActiveTextureARB_FACKED(unsigned int i)
{
}
// ! DEBUG_CODE

PFNGLLOCKARRAYSEXTPROC			glLockArraysEXT			 = NULL;
PFNGLUNLOCKARRAYSEXTPROC		glUnlockArraysEXT		 = NULL;
PFNGLACTIVETEXTUREARBPROC		glActiveTextureARB		 = NULL;
PFNGLCLIENTACTIVETEXTUREARBPROC	glClientActiveTextureARB = NULL;

extern	CE3D_Renderer *gpoE3DRenderer;

#ifndef CONTROL_ERRORS
	#ifdef _DEBUG
	static void CONTROL_ERRORS()
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
	#define CONTROL_ERRORS()
	#endif
#endif
//## end module%3A9AB97B0096.additionalDeclarations


// Class CE3D_ShaderRenderer_OGL 















CE3D_ShaderRenderer_OGL::CE3D_ShaderRenderer_OGL()
  //## begin CE3D_ShaderRenderer_OGL::CE3D_ShaderRenderer_OGL%.hasinit preserve=no
      : poCurrentBV(NULL), poCurrentCMesh(NULL), poCurrentMesh(NULL), iMaxTMUs(1), iCurrentTMU(0), bFlushGeometry(false), bGeometryFlushed(false)
  //## end CE3D_ShaderRenderer_OGL::CE3D_ShaderRenderer_OGL%.hasinit
  //## begin CE3D_ShaderRenderer_OGL::CE3D_ShaderRenderer_OGL%.initialization preserve=yes
  //## end CE3D_ShaderRenderer_OGL::CE3D_ShaderRenderer_OGL%.initialization
{
  //## begin CE3D_ShaderRenderer_OGL::CE3D_ShaderRenderer_OGL%.body preserve=yes
  //## end CE3D_ShaderRenderer_OGL::CE3D_ShaderRenderer_OGL%.body
}


CE3D_ShaderRenderer_OGL::~CE3D_ShaderRenderer_OGL()
{
  //## begin CE3D_ShaderRenderer_OGL::~CE3D_ShaderRenderer_OGL%.body preserve=yes
  //## end CE3D_ShaderRenderer_OGL::~CE3D_ShaderRenderer_OGL%.body
}



//## Other Operations (implementation)
void CE3D_ShaderRenderer_OGL::Init ()
{
  //## begin CE3D_ShaderRenderer_OGL::Init%1011714680.body preserve=yes
	#ifdef WIN32
	glLockArraysEXT			= (PFNGLLOCKARRAYSEXTPROC)			wglGetProcAddress("glLockArraysEXT");
	glUnlockArraysEXT		= (PFNGLUNLOCKARRAYSEXTPROC)		wglGetProcAddress("glUnlockArraysEXT");
	glActiveTextureARB		= (PFNGLACTIVETEXTUREARBPROC)		wglGetProcAddress("glActiveTextureARB");
	glClientActiveTextureARB= (PFNGLCLIENTACTIVETEXTUREARBPROC)	wglGetProcAddress("glClientActiveTextureARB");

	// DEBUG_CODE
	if (! glActiveTextureARB)  glActiveTextureARB = glActiveTextureARB_FACKED;
	if (! glClientActiveTextureARB) glClientActiveTextureARB = glClientActiveTextureARB_FACKED;
	// ! DEBUG_CODE

	#endif
  //## end CE3D_ShaderRenderer_OGL::Init%1011714680.body
}

void CE3D_ShaderRenderer_OGL::Render_ShInsTexture (CE3D_ShIns_Texture* _poTI)
{
  //## begin CE3D_ShaderRenderer_OGL::Render_ShInsTexture%1013981858.body preserve=yes
	
	// Enable texturing for current TMU
	glEnable(GL_TEXTURE_2D);

	iCurrentTMU++;
	if (iCurrentTMU==iMaxTMUs) bFlushGeometry = true;

	gpoE3DRenderer->SetCurrentTextureContext(_poTI->pTex);
	
	glColor4f(1.0f,1.0f,1.0f,0.0f);
	Render_Geometry();
  //## end CE3D_ShaderRenderer_OGL::Render_ShInsTexture%1013981858.body
}

void CE3D_ShaderRenderer_OGL::Render_ShInsColor (CE3D_ShIns_Color* _poTI)
{
  //## begin CE3D_ShaderRenderer_OGL::Render_ShInsColor%1013981859.body preserve=yes
	bUsingConstantColor = true;

	// Disable texturing for current TMU
	glDisable(GL_TEXTURE_2D);	

	iCurrentTMU++;
	if (iCurrentTMU==iMaxTMUs) bFlushGeometry = true;

	TFColor Color = _poTI->oColor.Color();
	glColor4f(Color.r,Color.g,Color.b,Color.a);

	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA); // ??? Siempre deberia ir aqui???	
	Render_Geometry();	
	
	glColor4f(1.0f,1.0f,1.0f,1.0f);
  //## end CE3D_ShaderRenderer_OGL::Render_ShInsColor%1013981859.body
}

void CE3D_ShaderRenderer_OGL::Render_ShInsWireframe (CE3D_ShIns_Wireframe* _poTI)
{
  //## begin CE3D_ShaderRenderer_OGL::Render_ShInsWireframe%1013981860.body preserve=yes
  	bUsingConstantColor = true;	

	// Set polygon mode	
	glPolygonMode(GL_BACK ,GL_LINE);
	glPolygonMode(GL_FRONT,GL_LINE);

	// Disable texturing for current TMU
	glDisable(GL_TEXTURE_2D);	

	TFColor Color = _poTI->oColor.Color();
	glColor4f(Color.r,Color.g,Color.b,Color.a);

	// glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA); // ??? Siempre deberia ir aqui???	
	Render_Geometry();		

	// Restore polygon mode	
	glPolygonMode(GL_BACK ,GL_FILL);
	glPolygonMode(GL_FRONT,GL_FILL);

	glColor4f(1.0f,1.0f,1.0f,1.0f);
  //## end CE3D_ShaderRenderer_OGL::Render_ShInsWireframe%1013981860.body
}

void CE3D_ShaderRenderer_OGL::Render_ShInsExtension (CE3D_ShIns_Extension* _poTI)
{
  //## begin CE3D_ShaderRenderer_OGL::Render_ShInsExtension%1013981861.body preserve=yes
	_poTI->pFunction((void *)&poCurrentMesh);
	Render_Geometry();
  //## end CE3D_ShaderRenderer_OGL::Render_ShInsExtension%1013981861.body
}

void CE3D_ShaderRenderer_OGL::Render_ShInsGeoOp (CE3D_ShIns_GeoOp* _poTI)
{
  //## begin CE3D_ShaderRenderer_OGL::Render_ShInsGeoOp%1013981862.body preserve=yes
	float fValue = _poTI->poEval->GetValue();	
	
	glMatrixMode(GL_MODELVIEW);
	switch (_poTI->GeteGOpType())
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
	CONTROL_ERRORS();
  //## end CE3D_ShaderRenderer_OGL::Render_ShInsGeoOp%1013981862.body
}

void CE3D_ShaderRenderer_OGL::Render_ShInsTexOp (CE3D_ShIns_TexOp* _poTI)
{
  //## begin CE3D_ShaderRenderer_OGL::Render_ShInsTexOp%1013981863.body preserve=yes
	float fValue;
	
	if (_poTI->poEval)
		fValue = _poTI->poEval->GetValue();	
	else
		fValue = 0.0f;
	
	glMatrixMode(GL_TEXTURE);
	switch (_poTI->GeteTOpType())
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

		case eSITexOp_Matrix:	glMultMatrixf(_poTI->poMat->m);							
								break;
	}
	CONTROL_ERRORS();
  //## end CE3D_ShaderRenderer_OGL::Render_ShInsTexOp%1013981863.body
}

void CE3D_ShaderRenderer_OGL::Render_ShInsBlendOp (CE3D_ShIns_BlendOp* _poTI)
{
  //## begin CE3D_ShaderRenderer_OGL::Render_ShInsBlendOp%1013981864.body preserve=yes
	bGeometryFlushed = false;

	glDisable  (GL_CULL_FACE);
	bEnableCF  = true;

	switch (_poTI->GeteBOpType())
	{	
        // ------------------
        // Blending ops
        // ------------------
        case eSIBOp_Copy:	        glBlendFunc(GL_ONE,GL_ZERO);
									glEnable   (GL_CULL_FACE);
									bEnableCF  = false;
                                    break;
        case eSIBOp_Mult:			glBlendFunc(GL_DST_COLOR,GL_ZERO);									
								    break;
        case eSIBOp_Mult2x:			glBlendFunc(GL_DST_COLOR,GL_SRC_COLOR);
                                    break;
        case eSIBOp_Add:			glBlendFunc(GL_ONE,GL_ONE);
                                    break;
        case eSIBOp_AddAndMult:		glBlendFunc(GL_DST_COLOR,GL_ONE);
                                    break;
        case eSIBOp_MultAndAdd:		glBlendFunc(GL_ONE,GL_SRC_COLOR);
                                    break;        
		case eSIBOp_Alpha:			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
									break;
		case eSIBOp_AlphaAdd:		glBlendFunc(GL_SRC_ALPHA, GL_ONE);									
									break;
		case eSIBOp_AlphaInv:		glBlendFunc(GL_ONE_MINUS_SRC_ALPHA,GL_SRC_ALPHA);
									break;
		case eSIBOp_AlphaThrough:	// Useful for dummy management
									glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
									glEnable   (GL_ALPHA_TEST);									
									bDisableAT = true;
									
									break;
	}
  //## end CE3D_ShaderRenderer_OGL::Render_ShInsBlendOp%1013981864.body
}

void CE3D_ShaderRenderer_OGL::Render_Geometry ()
{
  //## begin CE3D_ShaderRenderer_OGL::Render_Geometry%1013981865.body preserve=yes
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
  //## end CE3D_ShaderRenderer_OGL::Render_Geometry%1013981865.body
}

void CE3D_ShaderRenderer_OGL::InitTMU (int _iTMU)
{
  //## begin CE3D_ShaderRenderer_OGL::InitTMU%1013981866.body preserve=yes

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
		// glDisable (GL_CULL_FACE);	// DEBUG
		glEnable (GL_CULL_FACE);

		bEnableCF  = false;
	}

	// Enable texturing for this texture unit
	glEnable(GL_TEXTURE_2D);

	// Reset texture matrix
	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();
	CONTROL_ERRORS();

	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);

	// Setup default blending mode
	glBlendFunc(GL_ONE,GL_ZERO);

  //## end CE3D_ShaderRenderer_OGL::InitTMU%1013981866.body
}

void CE3D_ShaderRenderer_OGL::BeginShaderRender ()
{
  //## begin CE3D_ShaderRenderer_OGL::BeginShaderRender%983551121.body preserve=yes
	bUsingConstantColor = false;	

	// glDisable (GL_CULL_FACE);	// DEBUG
	// glEnable (GL_CULL_FACE);
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
  //## end CE3D_ShaderRenderer_OGL::BeginShaderRender%983551121.body
}

void CE3D_ShaderRenderer_OGL::EndShaderRender ()
{
  //## begin CE3D_ShaderRenderer_OGL::EndShaderRender%983551122.body preserve=yes
	
	// Unlock the arrays
	// glUnlockArraysEXT();

  //## end CE3D_ShaderRenderer_OGL::EndShaderRender%983551122.body
}

void CE3D_ShaderRenderer_OGL::RenderShader (CE3D_Shader *_poShader)
{
  //## begin CE3D_ShaderRenderer_OGL::RenderShader%983551123.body preserve=yes
	if (! _poShader) return;

	CE3D_ShaderInstruction *poShIns;
	for (int iIns=0;iIns<_poShader->iGetNumInstructions();iIns++)
	{
		poShIns =_poShader->pGetInstruction(iIns);
		
		if (poShIns)
		{
			switch (poShIns->eInsType)
			{
				case eShIns_Texture:	if (!gpoE3DRenderer->REState.FlatRender)
											Render_ShInsTexture((CE3D_ShIns_Texture*)poShIns);
										else
										{
											bFlushGeometry = true;
											Render_Geometry();
										}
										break;
				case eShIns_Color :		if (!gpoE3DRenderer->REState.FlatRender)
											Render_ShInsColor((CE3D_ShIns_Color*)poShIns);
										else
										{
											bFlushGeometry = true;
											Render_Geometry();
										}
										break;
				case eShIns_Wireframe:	if (!gpoE3DRenderer->REState.FlatRender)
											Render_ShInsWireframe((CE3D_ShIns_Wireframe*)poShIns);
										else
										{
											bFlushGeometry = true;
											Render_Geometry();
										}
										break;
				case eShIns_Extension:	if (!gpoE3DRenderer->REState.FlatRender)
											Render_ShInsExtension((CE3D_ShIns_Extension*)poShIns);
										else
										{
											bFlushGeometry = true;
											Render_Geometry();
										}
										break;
				case eShIns_GeoOp:		Render_ShInsGeoOp((CE3D_ShIns_GeoOp*)poShIns);
										break;
				case eShIns_TexOp:		if (!gpoE3DRenderer->REState.FlatRender)
											Render_ShInsTexOp((CE3D_ShIns_TexOp*)poShIns);
										break;
				case eShIns_BlendOp:	if (!gpoE3DRenderer->REState.FlatRender)
											Render_ShInsBlendOp((CE3D_ShIns_BlendOp*)poShIns);
										break;
				case eShIns_SetTMU:		
										break;															
			}
		}
	}
  //## end CE3D_ShaderRenderer_OGL::RenderShader%983551123.body
}

void CE3D_ShaderRenderer_OGL::Render (CMesh *_poMesh, CE3D_Shader *_poShader)
{
  //## begin CE3D_ShaderRenderer_OGL::Render%983551120.body preserve=yes
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
  //## end CE3D_ShaderRenderer_OGL::Render%983551120.body
}

void CE3D_ShaderRenderer_OGL::Render (CCompiledMesh *_poCMesh, CE3D_Shader *_poShader)
{
  //## begin CE3D_ShaderRenderer_OGL::Render%1011911191.body preserve=yes
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
  //## end CE3D_ShaderRenderer_OGL::Render%1011911191.body
}

void CE3D_ShaderRenderer_OGL::RenderMesh (CMesh *_poMesh)
{
  //## begin CE3D_ShaderRenderer_OGL::RenderMesh%983551127.body preserve=yes
	// Setup color array. If any
	CONTROL_ERRORS();

	if ((bUsingConstantColor) || (gpoE3DRenderer->REState.FlatRender))
	{
		if ((_poMesh->VCs) && !(gpoE3DRenderer->REState.FlatRender))
		{
			glEnableClientState(GL_COLOR_ARRAY);
			glColorPointer(4,GL_FLOAT,0,_poMesh->VCs);
		}
		else
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
			glDisableClientState(GL_COLOR_ARRAY);

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
									glDrawElements (GL_TRIANGLES     ,_poMesh->usNumIdxs,GL_UNSIGNED_SHORT,(void *)_poMesh->Idxs);
									break;
		case E3D_MESH_QUADS:		glDrawElements (GL_QUADS         ,_poMesh->usNumIdxs,GL_UNSIGNED_SHORT,(void *)_poMesh->Idxs);
									break;
		case E3D_MESH_TRIFANS:		glDrawElements (GL_TRIANGLE_FAN  ,_poMesh->usNumIdxs,GL_UNSIGNED_SHORT,(void *)_poMesh->Idxs);
									break;
		case E3D_MESH_TRISTRIPS:	glDrawElements (GL_TRIANGLE_STRIP,_poMesh->usNumIdxs,GL_UNSIGNED_SHORT,(void *)_poMesh->Idxs);
									break;
		case E3D_MESH_QUADSTRIPS:	glDrawElements (GL_QUAD_STRIP    ,_poMesh->usNumIdxs,GL_UNSIGNED_SHORT,(void *)_poMesh->Idxs);
									break;

		case E3D_MESH_NITRIS:		glDrawArrays   (GL_TRIANGLES	 ,0,_poMesh->usNumPrims*3);
									break;
		case E3D_MESH_NIQUADS:		glDrawArrays   (GL_QUADS		 ,0,_poMesh->usNumPrims*4);
									break;
		case E3D_MESH_NITRISTRIP:	glDrawArrays   (GL_TRIANGLE_STRIP,0,_poMesh->usNumPrims+2);
									break;
	}

	gpoE3DRenderer->REStats.NumRenderedTris  += _poMesh->usNumPrims;
	gpoE3DRenderer->REStats.NumRenderedVerts += _poMesh->usNumVerts;

	CONTROL_ERRORS();
  //## end CE3D_ShaderRenderer_OGL::RenderMesh%983551127.body
}

void CE3D_ShaderRenderer_OGL::RenderCompiledMesh (CCompiledMesh *_poCMesh)
{
  //## begin CE3D_ShaderRenderer_OGL::RenderCompiledMesh%1011911190.body preserve=yes
	glCallList(poCurrentCMesh->iID);

	gpoE3DRenderer->REStats.NumRenderedTris	 += poCurrentCMesh->usNumPrims;
	gpoE3DRenderer->REStats.NumRenderedVerts += poCurrentCMesh->usNumVerts;
  //## end CE3D_ShaderRenderer_OGL::RenderCompiledMesh%1011911190.body
}

// Additional Declarations
  //## begin CE3D_ShaderRenderer_OGL%3A9AB97B0096.declarations preserve=yes
  //## end CE3D_ShaderRenderer_OGL%3A9AB97B0096.declarations

//## begin module%3A9AB97B0096.epilog preserve=yes
//## end module%3A9AB97B0096.epilog
