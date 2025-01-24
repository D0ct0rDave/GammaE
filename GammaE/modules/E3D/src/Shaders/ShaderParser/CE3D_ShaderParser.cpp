// ----------------------------------------------------------------------------
#include <string.h>
#include <stdio.h>

#include "GammaE_Mem.h"
// ----------------------------------------------------------------------------
#include "Materials/CGTexObj.h"
#include "Materials/MipmapWH.h"
#include "Materials/TexObjWH.h"
#include "Materials/CGProgramWH.h"
#include "Shaders\CE3D_ShaderExtDB.h"

#include "Shaders\ShaderInstructions\CE3D_ShaderInsts.h"
#include "Shaders\ShaderParser\CE3D_ShaderParser.h"

#include "E3D_Enums.h"
// ----------------------------------------------------------------------------
typedef enum {

	E3D_PSH_NODE_NAME,
	E3D_PSH_NODE_READY,
    E3D_PSH_NODE_BEGINDEF,
    E3D_PSH_NODE_ENDDEF,
	E3D_PSH_NODE_INSTDEF,

	E3D_PSH_MAT_READY,
    E3D_PSH_MAT_NAME,
    E3D_PSH_MAT_BEGINDEF,
    E3D_PSH_MAT_BEGINNODEDEF,
    E3D_PSH_MAT_ENDNODEDEF,
	E3D_PSH_MAT_ENDDEF,
	E3D_PSH_MAT_INSTDEF,

	E3D_PSH_BOP_NAME,
    E3D_PSH_BOP_BEGINDEF,
    E3D_PSH_BOP_ENDDEF,
    E3D_PSH_BOP_READY,

	E3D_PSH_TOP_NAME,
    E3D_PSH_TOP_BEGINDEF,
    E3D_PSH_TOP_ENDDEF,
    E3D_PSH_TOP_READY,

	E3D_PSH_GOP_NAME,
    E3D_PSH_GOP_BEGINDEF,
    E3D_PSH_GOP_ENDDEF,
    E3D_PSH_GOP_READY,

    E3D_PSH_ZOP_BEGINDEF,
    E3D_PSH_ZOP_ENDDEF,
    E3D_PSH_ZOP_PARS,

    E3D_PSH_TEX_BEGINDEF,
    E3D_PSH_TEX_ENDDEF,
    E3D_PSH_TEX_PARS,

    E3D_PSH_PROG_BEGINDEF,
    E3D_PSH_PROG_ENDDEF,
    E3D_PSH_PROG_PARS,

    E3D_PSH_COL_BEGINDEF,
    E3D_PSH_COL_ENDDEF,
    E3D_PSH_COL_PARS,

    E3D_PSH_EVALUATOR_BEGINDEF,
    E3D_PSH_EVALUATOR_ENDDEF,
	E3D_PSH_EV_CTE,
	
	E3D_PSH_EXT_NAME,
    E3D_PSH_EXT_BEGINDEF,
    E3D_PSH_EXT_ENDDEF,
    E3D_PSH_EXT_READY

}TE3D_ParseShader_State;
// ----------------------------------------------------------------------------
CE3D_ShaderParser::CE3D_ShaderParser()
{
}
// ----------------------------------------------------------------------------
CE3D_Shader * CE3D_ShaderParser::poCreateShaderFromTexture (const CGString& _sTexName)
{     
	// ------------------------------------
	// First of all try loading the texture
	// ------------------------------------
	// Create the mipmap object
    CGMipMap* poMipMapObj	= CMipMapWH::I()->poLoad(_sTexName.szString());
	if (! poMipMapObj) return(NULL);
    
	// Create the texture object node
    CGTextureObj  *TexObj	= mNew CGTextureObj;
    if (! TexObj)
    {
        // WARNING
        // Maximum number of texture objects reached
        return(NULL);	// Return a null material ???
	}

    TexObj->m_uiUWrap     = E3D_TEX_WRAP_REPEAT;
    TexObj->m_uiVWrap     = E3D_TEX_WRAP_REPEAT;
    TexObj->m_uiMinFilter = E3D_TEX_MIN_FILTER_NEAREST;
    TexObj->m_uiMaxFilter = E3D_TEX_MIN_FILTER_LINEAR;
   	TexObj->m_poMipMap	  = poMipMapObj;
    
	// Create texture shader instruction
	CE3D_ShIns_Texture *poShTex = mNew CE3D_ShIns_Texture();
	poShTex->m_poTex = TexObj;

	// Setup shader
	CE3D_Shader	*poSh = mNew CE3D_Shader();	
	poSh->AddInstruction(poShTex);

	CTexObjWH::I()->uiAdd(TexObj,_sTexName);
    return(poSh);
}
// ----------------------------------------------------------------------------
CE3D_Shader * CE3D_ShaderParser::poParseShader(const CGString& _sShaderDefinition,const CGString& _sShaderName)
{
	CE3D_Shader	*poShader	= NULL;
    char *szShStr			= ParseUtils_CreateString( (char*)_sShaderDefinition.szString() );
    char *szShaderStream	= szShStr;
    char *szToken;

    TE3D_ParseShader_State ParseState = E3D_PSH_MAT_BEGINDEF;

    while ((ParseState != E3D_PSH_MAT_ENDDEF) && (szShStr))
    {
        NextToken(szToken,szShStr);		

		switch (ParseState)
		{
        	case E3D_PSH_MAT_BEGINDEF:
			{
				if (! stricmp(szToken,"{"))
				{
					ParseState = E3D_PSH_MAT_INSTDEF;
					poShader   = mNew CE3D_Shader;
				}
				else
				{
					// Error
					return(NULL);
				}
			}
			break;

			case E3D_PSH_MAT_INSTDEF:
			{
					 if (! stricmp(szToken,"BlendOp"))
						poShader->AddInstruction( poParse_ShIns_BlendingOperation(szShStr) );

				else if (! stricmp(szToken,"ZOp"))
						poShader->AddInstruction( poParse_ShIns_ZOperation(szShStr) );

				else if (! stricmp(szToken,"TexOp"))
						poShader->AddInstruction( poParse_ShIns_TextureOperation(szShStr) );

				else if (! stricmp(szToken,"GeoOp"))
						poShader->AddInstruction( poParse_ShIns_GeometricOperation(szShStr) );

				else if (! stricmp(szToken,"Program"))
						poShader->AddInstruction( poParse_ShIns_Program(szShStr) );

				else if (! stricmp(szToken,"Texture"))
						poShader->AddInstruction( poParse_ShIns_Texture(szShStr) );

				else if (! stricmp(szToken,"Color"))
						poShader->AddInstruction( poParse_ShIns_Color(szShStr) );

				else if (! stricmp(szToken,"Wireframe"))
						poShader->AddInstruction( poParse_ShIns_Wireframe(szShStr) );

				else if (! stricmp(szToken,"Extension"))
						poShader->AddInstruction( poParse_ShIns_Extension(szShStr) );

				else if (! stricmp(szToken,"SetTMU"))
						poShader->AddInstruction( poParse_ShIns_SetTMU(szShStr) );

				else if (! stricmp(szToken,"}")) 
						ParseState = E3D_PSH_MAT_ENDDEF;
			}
		}
	}
	
	// --------------------------------------------------------------------------
	// END: Parse shader instructions
	// --------------------------------------------------------------------------
	if (! poShader)
	{
		// The shader couldn't be created. Try loading as a texture with its material name
		poShader = poCreateShaderFromTexture(_sShaderName);
	}	

	mFree(szShaderStream);

	return(poShader);
}
// ----------------------------------------------------------------------------
CE3D_ShaderInstruction * CE3D_ShaderParser::poParse_ShIns_Program (char *&_szDesc)
{
    CE3D_ShIns_Program	*poSh   = NULL;
	float				fR,fG,fB,fA;

	//    
  	char *szToken;	
	NextToken(szToken,_szDesc);		

    poSh = mNew CE3D_ShIns_Program();
    if (! poSh)	return(NULL);

    // Create the texture object node
	poSh->SetProgram( CGProgramWH::I()->poLoad(szToken) );

    return(poSh);
}
// ----------------------------------------------------------------------------
CE3D_ShaderInstruction * CE3D_ShaderParser::poParse_ShIns_Texture (char *&_szDesc)
{
  	CE3D_ShIns_Texture*	MatNode   = NULL;
    CGTextureObj*		TexObj    = NULL;
    CGMipMap*			MipMapObj = NULL;

    // Variable parameters with default values
	char*		szToken;
	char 		 MipMapName[MAX_CHARS];
    unsigned int MipMapLODS = 1;
    // tdeMipMapCreationMethod MMCMethod = MMCM_BilinearFiltering;
    unsigned int VWrap     = E3D_TEX_WRAP_REPEAT;
    unsigned int UWrap     = E3D_TEX_WRAP_REPEAT;
    unsigned int MinFilter = E3D_TEX_MIN_FILTER_NEAREST;
    unsigned int MagFilter = E3D_TEX_MAX_FILTER_NEAREST;
    MipMapName[0] = 0;
	
	// --------------------------------------------------------------------------
	// BEGIN: Parse texture parameters
	// --------------------------------------------------------------------------
    TE3D_ParseShader_State ParseState  = E3D_PSH_TEX_BEGINDEF;

    while ((ParseState != E3D_PSH_TEX_ENDDEF) && (_szDesc))
    {
        NextToken(szToken,_szDesc);

		if (! stricmp(szToken,"}")) 
			ParseState = E3D_PSH_TEX_ENDDEF;

		switch (ParseState)
		{
        	case E3D_PSH_TEX_BEGINDEF:	
        	{
				if (! stricmp(szToken,"{"))
             		ParseState = E3D_PSH_TEX_PARS;
				else
				{
                	// Copy the texture name
					strcpy(MipMapName,szToken);
					// WARNING if name redefinition
				}
			}
			break;

			case E3D_PSH_TEX_PARS:
			{
				// Image filename
 				if (! stricmp(szToken,"Image"))
 				{
        			NextToken(szToken,_szDesc);
					strcpy(MipMapName,szToken);
				}

				// Mignification filter
			else if (! stricmp(szToken,"MinFilter"))
 				{
            			NextToken(szToken,_szDesc);

            			if (! stricmp(szToken,"NEAREST"))
                			MinFilter = E3D_TEX_MIN_FILTER_NEAREST;
				   else if (! stricmp(szToken,"LINEAR"))
                			MinFilter = E3D_TEX_MIN_FILTER_LINEAR;
				   else if (! stricmp(szToken,"NEAREST_MIPMAP_NEAREST"))
                			MinFilter = E3D_TEX_MIN_FILTER_NEAREST_MIPMAP_NEAREST;
				   else if (! stricmp(szToken,"NEAREST_MIPMAP_LINEAR"))
                			MinFilter = E3D_TEX_MIN_FILTER_NEAREST_MIPMAP_LINEAR;
				   else if (! stricmp(szToken,"LINEAR_MIPMAP_NEAREST"))
                			MinFilter = E3D_TEX_MIN_FILTER_LINEAR_MIPMAP_NEAREST;
				   else if (! stricmp(szToken,"LINEAR_MIPMAP_LINEAR"))
                			MinFilter = E3D_TEX_MIN_FILTER_LINEAR_MIPMAP_LINEAR;
				   else
				   {
           				// WARNING
				   }
				}

				// Magnification filter
			else if (! stricmp(szToken,"MagFilter"))
 				{
        			NextToken(szToken,_szDesc);

            		if (! stricmp(szToken,"NEAREST"))
                		MagFilter = E3D_TEX_MAX_FILTER_NEAREST;
			   else if (! stricmp(szToken,"LINEAR"))
               			MagFilter = E3D_TEX_MAX_FILTER_LINEAR;
					else
					{
           					// WARNING
					}
				}

				// Number of LODs
			else if (! stricmp(szToken,"NumLODs"))
 				{
        			NextToken(szToken,_szDesc);
         			if (! sscanf(szToken,"%d",&MipMapLODS))
            			// WARNING
            			MipMapLODS = 1;
				}

				// MipMap generation method
			else if (! stricmp(szToken,"MMGenMethod"))
 				{
        			NextToken(szToken,_szDesc);
					/*
            			if (! stricmp(szToken,"NORMAL"))
                			MMCMethod = MMCM_Normal;
				   else if (! stricmp(szToken,"HLINEAR_FILTERING"))
                			MMCMethod = MMCM_HLinearFiltering;
				   else if (! stricmp(szToken,"VLINEAR_FILTERING"))
                			MMCMethod = MMCM_VLinearFiltering;
				   else if (! stricmp(szToken,"BILINEAR_FILTERING"))
                			MMCMethod = MMCM_BilinearFiltering;
				   else if (! stricmp(szToken,"BILINEAR_MRQZ_FILTERING"))
           					MMCMethod = MMCM_BilinearMRQZFiltering;
				   else
				   {
           					// WARNING
				   }
				   */				   
				}

			else if (! stricmp(szToken,"UWrap"))
				{
        			NextToken(szToken,_szDesc);
            			if (! stricmp(szToken,"REPEAT"))
                			UWrap = E3D_TEX_WRAP_REPEAT;
				   else if (! stricmp(szToken,"CLAMP"))
                			UWrap = E3D_TEX_WRAP_CLAMP;
				   else
				   {
           					// WARNING
				   }
				}

			else if (! stricmp(szToken,"VWrap"))
				{
        			NextToken(szToken,_szDesc);
            			if (! stricmp(szToken,"REPEAT"))
                			VWrap = E3D_TEX_WRAP_REPEAT;
				   else if (! stricmp(szToken,"CLAMP"))
                			VWrap = E3D_TEX_WRAP_CLAMP;
				   else
				   {
           					// WARNING
				   }
				}

			else {
 					// WARNING
					// Unknown token name
				}
			}
			break;
		}
	}

	// --------------------------------------------------------------------------
	// END: Parse texture parameters
	// --------------------------------------------------------------------------

    // Create the material node
    MatNode = mNew CE3D_ShIns_Texture();
    if (! MatNode) return(NULL); // Return a null material ???

    // Create the texture object node
    TexObj = mNew CGTextureObj;

    if (! TexObj)
    {
        // WARNING
        // Maximum number of texture objects reached
        mDel MatNode;
        return(NULL);	// Return a null material ???
	}

	// Setup material node
	MatNode->m_poTex      = TexObj;

	// Setup texture object
    TexObj->m_uiUWrap     = UWrap;
    TexObj->m_uiVWrap     = VWrap;
    TexObj->m_uiMinFilter = MinFilter;
    TexObj->m_uiMaxFilter = MagFilter;

	// Create the texture object
    MipMapObj = CMipMapWH::I()->poLoad(MipMapName);

    if (MipMapObj)
    	TexObj->m_poMipMap = MipMapObj;
    else
    {
		// WARNING
        // No mipmap filename defined, return the null texture ???
		TexObj->m_poMipMap = NULL;    	
	}

    return(MatNode);
}
// ----------------------------------------------------------------------------
void CE3D_ShaderParser::Parse_Color_General (char* _szDesc, float* _fR, float* _fG, float* _fB, float* _fA)
{
  	char *szToken;

    // Variable parameters with default values
	float r = 1.0f;
    float g = 1.0f;
	float b = 1.0f;
    float a = 1.0f;

    TE3D_ParseShader_State ParseState  = E3D_PSH_COL_BEGINDEF;

    while ((ParseState != E3D_PSH_COL_ENDDEF) && (_szDesc))
    {
        NextToken(szToken,_szDesc);        

        switch (ParseState)
        {
        	case E3D_PSH_COL_BEGINDEF:
			{
				if (! stricmp(szToken,"{"))
					ParseState = E3D_PSH_COL_PARS;
            	else
				{
					// scan red component
                    if (! sscanf(szToken,"%f",&r))
						r = 1.0f;
					else
						r = MATH_Common::fClamp(0.0f,1.0f,r);

					// scan green component
					NextToken(szToken,_szDesc);
					if (! sscanf(szToken,"%f",&g))
						g = 1.0f;
					else
						g = MATH_Common::fClamp(0.0f,1.0f,g);

					// scan blue component
					NextToken(szToken,_szDesc);
					if (! sscanf(szToken,"%f",&b))
						b = 1.0f;
					else
						b = MATH_Common::fClamp(0.0f,1.0f,b);

					// scan alpha component
					NextToken(szToken,_szDesc);
					if (! sscanf(szToken,"%f",&a))
						a = 1.0f;
					else
						a = MATH_Common::fClamp(0.0f,1.0f,a);

					ParseState = E3D_PSH_COL_ENDDEF;
				}
			}
			break;

            case E3D_PSH_COL_PARS:  // Red color
            {
         		if (! stricmp(szToken,"r"))
         		{
					// scan red component
                	NextToken(szToken,_szDesc);
					if (! sscanf(szToken,"%f",&r))
						r = 1.0f;
					else
						r = MATH_Common::fClamp(0.0f,1.0f,r);
				}

                // Green color
         else   if (! stricmp(szToken,"g"))
         		{
					// scan green component
					NextToken(szToken,_szDesc);
					if (! sscanf(szToken,"%f",&g))
						g = 1.0f;
					else
						g = MATH_Common::fClamp(0.0f,1.0f,g);
				}

                // Blue color
         else   if (! stricmp(szToken,"b"))
         		{
					// scan blue component
					NextToken(szToken,_szDesc);
					if (! sscanf(szToken,"%f",&b))
						b = 1.0f;
					else
						b = MATH_Common::fClamp(0.0f,1.0f,b);

				}

                // Alpha color
         else   if (! stricmp(szToken,"a"))
         		{
					// scan alpha component
					NextToken(szToken,_szDesc);
					if (! sscanf(szToken,"%f",&a))
						a = 1.0f;
					else
						a = MATH_Common::fClamp(0.0f,1.0f,a);
				}
		 
		 else   if (! stricmp(szToken,"}")) 
				{
					ParseState = E3D_PSH_COL_ENDDEF;
				}
         
         else   {
         			// WARNING
                    // Unknown szToken name
				}
			}
			break;
		}
	}

	*_fR = r;
	*_fG = g;
	*_fB = b;
	*_fA = a;
}
// ----------------------------------------------------------------------------
CE3D_ShaderInstruction * CE3D_ShaderParser::poParse_ShIns_Color (char *&_szDesc)
{
    CE3D_ShIns_Color*	poSh   = NULL;   
	float				fR,fG,fB,fA;
    
	// Create the material node
	Parse_Color_General (_szDesc,&fR,&fG,&fB,&fA);

    poSh = mNew CE3D_ShIns_Color();
    if (! poSh)	return(NULL);	// Return a null material ???

    // Create the texture object node
	poSh->SetColor( CGColor(fR,fG,fB,fA) );

    return(poSh);
}
// ----------------------------------------------------------------------------
CE3D_ShaderInstruction * CE3D_ShaderParser::poParse_ShIns_Wireframe (char *&_szDesc)
{
    CE3D_ShIns_Wireframe*	poSh   = NULL;   
	float					fR,fG,fB,fA;
    
	// Create the material node
	Parse_Color_General (_szDesc,&fR,&fG,&fB,&fA);

    poSh = mNew CE3D_ShIns_Wireframe();
    if (! poSh)	return(NULL);	// Return a null material ???

    // Create the texture object node
	poSh->SetColor( CGColor(fR,fG,fB,fA) );

    return(poSh);
}
// ----------------------------------------------------------------------------
CE3D_ShaderInstruction * CE3D_ShaderParser::poParse_ShIns_Extension (char *&_szDesc)
{
  	char *szToken;	
	NextToken(szToken,_szDesc);		

	// Get the extension from the Extension DB
	TExtensionFunction pFunc = (TExtensionFunction)CE3D_ShaderExtDB::pGetExtension(szToken);
		
	if (! pFunc) return(NULL);
	
	CE3D_ShIns_Extension *poSh;	
	poSh  = mNew CE3D_ShIns_Extension();			
	poSh->SetFunction(pFunc);
		
	return(poSh);
}
// ----------------------------------------------------------------------------
CE3D_ShaderInstruction * CE3D_ShaderParser::poParse_ShIns_BlendingOperation (char *&_szDesc)
{
  	char *szToken;
	NextToken(szToken,_szDesc);	

	CE3D_ShIns_BlendOp *poSh = mNew CE3D_ShIns_BlendOp();
	poSh->SetBlendMode(E3D_BM_NULL);

	if (! stricmp(szToken,"Copy"))
		poSh->SetBlendMode(E3D_BM_Copy);
	if (! stricmp(szToken,"Mult"))
		poSh->SetBlendMode(E3D_BM_Mult);
	if (! stricmp(szToken,"Mult2x"))
		poSh->SetBlendMode(E3D_BM_Mult2x);
	if (! stricmp(szToken,"Add"))
		poSh->SetBlendMode(E3D_BM_Add);
	if (! stricmp(szToken,"Add&Mult"))
		poSh->SetBlendMode(E3D_BM_AddAndMult);
	if (! stricmp(szToken,"Mult&Add"))
		poSh->SetBlendMode(E3D_BM_MultAndAdd);
	if (! stricmp(szToken,"Alpha"))
		poSh->SetBlendMode(E3D_BM_Alpha);
	if (! stricmp(szToken,"AlphaAdd"))
		poSh->SetBlendMode(E3D_BM_AlphaAdd);
	if (! stricmp(szToken,"AlphaInv"))
		poSh->SetBlendMode(E3D_BM_AlphaInv);
	if (! stricmp(szToken,"AlphaThrough"))
		poSh->SetBlendMode(E3D_BM_AlphaThrough);

	return(poSh);
}
// ----------------------------------------------------------------------------
CE3D_ShaderInstruction * CE3D_ShaderParser::poParse_ShIns_ZOperation (char *&_szDesc)
{
  	char *szToken;
	NextToken(szToken,_szDesc);	

	float			fRefValue	= 0.0f;
	E3D_ZTestFunc	eZTestFunc	= E3D_ZTF_LEqual;
	E3D_ZWrite		eZWrite		= E3D_ZW_Enable;

    TE3D_ParseShader_State ParseState  = E3D_PSH_ZOP_BEGINDEF;

    while ((ParseState != E3D_PSH_ZOP_ENDDEF) && (_szDesc))
    {
        NextToken(szToken,_szDesc);

        switch (ParseState)
        {
        	case E3D_PSH_ZOP_BEGINDEF:
			{
				if (! stricmp(szToken,"{"))
					ParseState = E3D_PSH_ZOP_PARS;
            	else
				{
					// ZFunc
					if (! stricmp(szToken,"ZFunc"))
 					{
        				NextToken(szToken,_szDesc);

        				if (! stricmp(szToken,"ALWAYS"))
            				eZTestFunc = E3D_ZTF_Always;
				   else if (! stricmp(szToken,"NEVER"))
            				eZTestFunc = E3D_ZTF_Never;
				   else if (! stricmp(szToken,"LESS"))
            				eZTestFunc = E3D_ZTF_Less;
				   else if (! stricmp(szToken,"LEQUAL"))
            				eZTestFunc = E3D_ZTF_LEqual;
				   else if (! stricmp(szToken,"GREATER"))
            				eZTestFunc = E3D_ZTF_Greater;
				   else if (! stricmp(szToken,"GEQUAL"))
            				eZTestFunc = E3D_ZTF_GEqual;
				   else if (! stricmp(szToken,"EQUAL"))
            				eZTestFunc = E3D_ZTF_Equal;
				   else if (! stricmp(szToken,"NOTEQUAL"))
            				eZTestFunc = E3D_ZTF_NotEqual;
						else
						{
       						// WARNING
						}
					}

/*
					// ZFunc Ref Value
			   else if (! stricmp(szToken,"RefVal"))
 					{
        				NextToken(szToken,_szDesc);

        				if (! sscanf(szToken,"%f",&fRefValue))
							fRefValue = 1.0f;
						else
							fRefValue = MATH_Common::fClamp(0.0f,1.0f,fRefValue);
					}
*/

					// ZWrite
			   else if (! stricmp(szToken,"ZWrite"))
 					{
        				NextToken(szToken,_szDesc);

            			if (! stricmp(szToken,"ENABLE"))
                			eZWrite = E3D_ZW_Enable;
				   else if (! stricmp(szToken,"DISABLE"))
							eZWrite = E3D_ZW_Disable;
					else{
           						// WARNING
						}
					}
					
					// 
			   else if (! stricmp(szToken,"}")) 
					{
						ParseState = E3D_PSH_ZOP_ENDDEF;
					}         
					else
					{
         				// WARNING
						// Unknown szToken name
					}
				}
			}
			break;
		}
	}

	// Create Z Operation
	CE3D_ShIns_ZOp *poSh = mNew CE3D_ShIns_ZOp();
	
	poSh->SetZTestFunc(eZTestFunc);
	poSh->SetZWrite(eZWrite);

	return(poSh);
}
// ----------------------------------------------------------------------------
CE3D_ShaderInstruction * CE3D_ShaderParser::poParse_ShIns_TextureOperation (char *&_szDesc)
{
  	char *szToken;
	NextToken(szToken,_szDesc);	

	CE3D_ShIns_TexOp *poSh = mNew CE3D_ShIns_TexOp();
	poSh->SetTOpType(eSITexOp_NULL);

	if (! stricmp(szToken,"Rotate"))
	{
		poSh->SetTOpType(eSITexOp_Rotate);
		poSh->SetEvaluator( poParseEvaluator(_szDesc) );
	}
	if (! stricmp(szToken,"ScaleUV"))
	{
		poSh->SetTOpType(eSITexOp_Scale);
		poSh->SetEvaluator( poParseEvaluator(_szDesc) );
	}
	if (! stricmp(szToken,"ScaleU"))
	{
		poSh->SetTOpType(eSITexOp_ScaleU);
		poSh->SetEvaluator( poParseEvaluator(_szDesc) );
	}
	if (! stricmp(szToken,"ScaleV"))
	{
		poSh->SetTOpType(eSITexOp_ScaleV);
		poSh->SetEvaluator( poParseEvaluator(_szDesc) );
	}
	if (! stricmp(szToken,"TransU"))
	{
		poSh->SetTOpType(eSITexOp_TransU);
		poSh->SetEvaluator( poParseEvaluator(_szDesc) );
	}
	if (! stricmp(szToken,"TransV"))
	{
		poSh->SetTOpType(eSITexOp_TransV);
		poSh->SetEvaluator( poParseEvaluator(_szDesc) );
	}
	if (! stricmp(szToken,"ReflectMap"))
		poSh->SetTOpType(eSITexOp_ReflectMap);
	if (! stricmp(szToken,"EnvMap"))
		poSh->SetTOpType(eSITexOp_EnvMap);
	if (! stricmp(szToken,"Matrix"))
		poSh->SetTOpType(eSITexOp_Matrix);
	if (! stricmp(szToken,"FrameSet"))
	{
		poSh->SetTOpType(eSITexOp_FrameSet);
		NextToken(szToken,_szDesc);		sscanf(szToken,"%d",&poSh->m_uiImgCols);
		NextToken(szToken,_szDesc);		sscanf(szToken,"%d",&poSh->m_uiImgRows);
		NextToken(szToken,_szDesc);		sscanf(szToken,"%f",&poSh->m_fFreq);
	}

	return(poSh);
}
// ----------------------------------------------------------------------------
CE3D_ShaderInstruction * CE3D_ShaderParser::poParse_ShIns_GeometricOperation (char *&_szDesc)
{
  	char *szToken;
	NextToken(szToken,_szDesc);	

	CE3D_ShIns_GeoOp *poSh = mNew CE3D_ShIns_GeoOp();
	poSh->SetGOpType(eSIGeoOp_NULL);

	if (! stricmp(szToken,"RotateX"))
		poSh->SetGOpType(eSIGeoOp_RotateX);
	if (! stricmp(szToken,"RotateY"))
		poSh->SetGOpType(eSIGeoOp_RotateY);
	if (! stricmp(szToken,"RotateZ"))
		poSh->SetGOpType(eSIGeoOp_RotateZ);
	if (! stricmp(szToken,"Scale"))
		poSh->SetGOpType(eSIGeoOp_Scale);
	if (! stricmp(szToken,"ScaleX"))
		poSh->SetGOpType(eSIGeoOp_ScaleX);
	if (! stricmp(szToken,"ScaleY"))
		poSh->SetGOpType(eSIGeoOp_ScaleY);
	if (! stricmp(szToken,"ScaleZ"))
		poSh->SetGOpType(eSIGeoOp_ScaleZ);
	if (! stricmp(szToken,"TransX"))
		poSh->SetGOpType(eSIGeoOp_TransX);
	if (! stricmp(szToken,"TransY"))
		poSh->SetGOpType(eSIGeoOp_TransY);
	if (! stricmp(szToken,"TransZ"))
		poSh->SetGOpType(eSIGeoOp_TransZ);

	poSh->SetEvaluator( poParseEvaluator(_szDesc) );

	return(poSh);
}
// ----------------------------------------------------------------------------
CE3D_ShaderInstruction * CE3D_ShaderParser::poParse_ShIns_SetTMU (char *&_szDesc)
{
  	if (! _szDesc) return(NULL);

	uint uiTMU;
	sscanf(_szDesc,"%i",&uiTMU);

	CE3D_ShIns_SetTMU *poSh = mNew CE3D_ShIns_SetTMU();
	poSh->SetTMU(uiTMU);

	return(poSh);
}
// ----------------------------------------------------------------------------
CEvaluator * CE3D_ShaderParser::poParseEvaluator (char *&_szDesc)
{
  	char	*szToken;
	float	fValue;

	NextToken(szToken,_szDesc);
		
		if (! strcmp(szToken,"EVMult"))
		{
			CEval_Mult	*poMult = mNew CEval_Mult;
			CEvaluator	*poOpA  = poParseEvaluator(_szDesc);
			if (! poOpA)
			{
				mDel poMult;
				return(NULL);
			}
			
			CEvaluator	*poOpB  = poParseEvaluator(_szDesc);
			if (! poOpB)
			{
				mDel poMult;
				mDel poOpA;
				return(NULL);
			}
			
			poMult->SetOperandA(poOpA);
			poMult->SetOperandB(poOpB);
			return(poMult);
		}
   
   else if (! strcmp(szToken,"EVSum"))
		{
			CEval_Sum	*poSum = mNew CEval_Sum;
			CEvaluator	*poOpA = poParseEvaluator(_szDesc);
			if (! poOpA)
			{
				mDel poSum;
				return(NULL);
			}
			
			CEvaluator	*poOpB  = poParseEvaluator(_szDesc);
			if (! poOpB)
			{
				mDel poSum;
				mDel poOpA;
				return(NULL);
			}
			
			poSum->SetOperandA(poOpA);
			poSum->SetOperandB(poOpB);
			return(poSum);
		}

   else if (! strcmp(szToken,"EVSin"))
		{
			CEval_Sin	*poSin = mNew CEval_Sin;
			CEvaluator	*poAmp = poParseEvaluator(_szDesc);
			if (! poAmp)
			{
				mDel poSin;
				return(NULL);
			}
			CEvaluator	*poFMult = poParseEvaluator(_szDesc);
			if (! poFMult)
			{
				mDel poSin;
				mDel poAmp;
				return(NULL);
			}
			
			CEvaluator	*poPhase  = poParseEvaluator(_szDesc);
			if (! poPhase)
			{
				mDel poSin;
				mDel poAmp;
				mDel poFMult;
				return(NULL);
			}
			
			poSin->SetAmplitude(poAmp);
			poSin->SetFreqMult (poFMult);
			poSin->SetPhase    (poPhase);

			return(poSin);
		}

   else if (! strcmp(szToken,"EVCos"))
		{
			CEval_Cos	*poCos = mNew CEval_Cos;
			CEvaluator	*poAmp = poParseEvaluator(_szDesc);
			if (! poAmp)
			{
				mDel poCos;
				return(NULL);
			}
			CEvaluator	*poFMult = poParseEvaluator(_szDesc);
			if (! poFMult)
			{
				mDel poCos;
				mDel poAmp;
				return(NULL);
			}
			
			CEvaluator	*poPhase  = poParseEvaluator(_szDesc);
			if (! poPhase)
			{
				mDel poCos;
				mDel poAmp;
				mDel poFMult;
				return(NULL);
			}
			
			poCos->SetAmplitude(poAmp);
			poCos->SetFreqMult (poFMult);
			poCos->SetPhase    (poPhase);

			return(poCos);
		}

   else if (! strcmp(szToken,"EVSaw"))
		{
			CEval_SawTooth	*poSaw = mNew CEval_SawTooth;
			CEvaluator	*poAmp = poParseEvaluator(_szDesc);
			if (! poAmp)
			{
				mDel poSaw;
				return(NULL);
			}
			CEvaluator	*poFMult = poParseEvaluator(_szDesc);
			if (! poFMult)
			{
				mDel poSaw;
				mDel poAmp;
				return(NULL);
			}
			
			CEvaluator	*poPhase  = poParseEvaluator(_szDesc);
			if (! poPhase)
			{
				mDel poSaw;
				mDel poAmp;
				mDel poFMult;
				return(NULL);
			}
			
			poSaw->SetAmplitude(poAmp);
			poSaw->SetFreqMult (poFMult);
			poSaw->SetPhase    (poPhase);

			return(poSaw);
		}

   else if (! strcmp(szToken,"EVSquare"))
		{
			CEval_Square	*poSquare = mNew CEval_Square;
			CEvaluator	*poAmp = poParseEvaluator(_szDesc);
			if (! poAmp)
			{
				mDel poSquare;
				return(NULL);
			}
			CEvaluator	*poFMult = poParseEvaluator(_szDesc);
			if (! poFMult)
			{
				mDel poSquare;
				mDel poAmp;
				return(NULL);
			}
			
			CEvaluator	*poPhase  = poParseEvaluator(_szDesc);
			if (! poPhase)
			{
				mDel poSquare;
				mDel poAmp;
				mDel poFMult;
				return(NULL);
			}
			
			poSquare->SetAmplitude(poAmp);
			poSquare->SetFreqMult (poFMult);
			poSquare->SetPhase    (poPhase);

			return(poSquare);
		}

   else if (! strcmp(szToken,"EVTriangle"))
		{
			CEval_Triangle	*poTriangle = mNew CEval_Triangle;
			CEvaluator	*poAmp = poParseEvaluator(_szDesc);
			if (! poAmp)
			{
				mDel poTriangle;
				return(NULL);
			}
			CEvaluator	*poFMult = poParseEvaluator(_szDesc);
			if (! poFMult)
			{
				mDel poTriangle;
				mDel poAmp;
				return(NULL);
			}
			
			CEvaluator	*poPhase  = poParseEvaluator(_szDesc);
			if (! poPhase)
			{
				mDel poTriangle;
				mDel poAmp;
				mDel poFMult;
				return(NULL);
			}
			
			poTriangle->SetAmplitude(poAmp);
			poTriangle->SetFreqMult (poFMult);
			poTriangle->SetPhase    (poPhase);

			return(poTriangle);
		}

   else if (! strcmp(szToken,"EVTime"))
		{
			CEval_Time *poTime = mNew CEval_Time;			
			return(poTime);			
		}

  else  if (sscanf(szToken,"%f",&fValue))
		{
			CEval_Const *poConst = mNew CEval_Const;
			poConst->SetConstant(fValue);
			return(poConst);
		}
	
	return(NULL);
}
// Additional Declarations
// ----------------------------------------------------------------------------
