//## begin module%3C604EBE02A5.cm preserve=no
//## end module%3C604EBE02A5.cm

//## begin module%3C604EBE02A5.cp preserve=no
//## end module%3C604EBE02A5.cp

//## Module: CE3D_ShaderParser%3C604EBE02A5; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\Shaders\ShaderParser\CE3D_ShaderParser.cpp

//## begin module%3C604EBE02A5.additionalIncludes preserve=no
//## end module%3C604EBE02A5.additionalIncludes

//## begin module%3C604EBE02A5.includes preserve=yes
#include <string.h>
#include "Memory/GammaE_Mem.h"
//## end module%3C604EBE02A5.includes

// CE3D_ShaderInsts
#include "E3D\Shaders\ShaderInstructions\CE3D_ShaderInsts.h"
// CE3D_ShaderParser
#include "E3D\Shaders\ShaderParser\CE3D_ShaderParser.h"
//## begin module%3C604EBE02A5.additionalDeclarations preserve=yes
#define stricmp _stricmp

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

    E3D_PSH_TEX_BEGINDEF,
    E3D_PSH_TEX_ENDDEF,
    E3D_PSH_TEX_PARS,

    E3D_PSH_COL_BEGINDEF,
    E3D_PSH_COL_ENDDEF,
    E3D_PSH_COL_PARS,

    E3D_PSH_EVALUATOR_ENDDEF,
    E3D_PSH_EVALUATOR_BEGINDEF,
	E3D_PSH_EV_CTE,
	
	E3D_PSH_EXT_NAME,
    E3D_PSH_EXT_BEGINDEF,
    E3D_PSH_EXT_ENDDEF,
    E3D_PSH_EXT_READY

}TE3D_ParseShader_State;
//## end module%3C604EBE02A5.additionalDeclarations


// Class CE3D_ShaderParser 

CE3D_ShaderParser::CE3D_ShaderParser()
  //## begin CE3D_ShaderParser::CE3D_ShaderParser%.hasinit preserve=no
  //## end CE3D_ShaderParser::CE3D_ShaderParser%.hasinit
  //## begin CE3D_ShaderParser::CE3D_ShaderParser%.initialization preserve=yes
  //## end CE3D_ShaderParser::CE3D_ShaderParser%.initialization
{
  //## begin CE3D_ShaderParser::CE3D_ShaderParser%.body preserve=yes
  //## end CE3D_ShaderParser::CE3D_ShaderParser%.body
}


CE3D_ShaderParser::~CE3D_ShaderParser()
{
  //## begin CE3D_ShaderParser::~CE3D_ShaderParser%.body preserve=yes
  //## end CE3D_ShaderParser::~CE3D_ShaderParser%.body
}



//## Other Operations (implementation)
CE3D_Shader * CE3D_ShaderParser::poCreateShaderFromTexture (char *_szTexName)
{
  //## begin CE3D_ShaderParser::poCreateShaderFromTexture%1012941677.body preserve=yes
    
	// ------------------------------------
	// First of all try loading the texture
	// ------------------------------------
	// Create the mipmap object
    TMipMapObj	*MipMapObj	= TMipMapWarehouse::LoadMipMap(_szTexName,0);
	if (! MipMapObj) return(NULL);
    
	// Create the texture object node
    TTextureObj   *TexObj	= TTexObjWarehouse::AllocateTexObj();
	// TTextureObj   *TexObj = mNew TTextureObj;	
    if (! TexObj)
    {
        // WARNING
        // Maximum number of texture objects reached
        return(NULL);	// Return a null material ???
    }
    TexObj->UWrap     = E3D_TEX_WRAP_REPEAT;
    TexObj->VWrap     = E3D_TEX_WRAP_REPEAT;
    TexObj->MinFilter = E3D_TEX_MIN_FILTER_NEAREST;
    TexObj->MaxFilter = E3D_TEX_MIN_FILTER_LINEAR;
   	TexObj->MipMapObj = MipMapObj;

    
	// Create texture shader instruction
	CE3D_ShIns_Texture *poShTex = mNew CE3D_ShIns_Texture();
    if (! poShTex)
		return(NULL); // Return a null material ???
	poShTex->pTex = TexObj;
    

	// Setup shader
	CE3D_Shader	*poSh = mNew CE3D_Shader();	
	poSh->AddInstruction(poShTex);
	
    return(poSh);
  //## end CE3D_ShaderParser::poCreateShaderFromTexture%1012941677.body
}

CE3D_Shader * CE3D_ShaderParser::poParseShader (char *_szShaderDefinition, char* _szShaderName)
{
  //## begin CE3D_ShaderParser::poParseShader%1012941678.body preserve=yes
    if ((! _szShaderDefinition)	&& (!_szShaderName)) return(NULL);
    
	CE3D_Shader	*poShader	= NULL;
    char *szShStr			= ParseUtils_CreateString(_szShaderDefinition);
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

				else if (! stricmp(szToken,"TexOp"))
						poShader->AddInstruction( poParse_ShIns_TextureOperation(szShStr) );

				else if (! stricmp(szToken,"GeoOp"))
						poShader->AddInstruction( poParse_ShIns_GeometricOperation(szShStr) );

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
		poShader = poCreateShaderFromTexture(_szShaderName);
	}	

	mFree(szShaderStream);

	return(poShader);
  //## end CE3D_ShaderParser::poParseShader%1012941678.body
}

CE3D_ShaderInstruction * CE3D_ShaderParser::poParse_ShIns_Texture (char *&_szDesc)
{
  //## begin CE3D_ShaderParser::poParse_ShIns_Texture%1012941679.body preserve=yes
	CE3D_ShIns_Texture	*MatNode   = NULL;
    TTextureObj			*TexObj    = NULL;
    TMipMapObj			*MipMapObj = NULL;

    // Variable parameters with default values
	char		 *szToken;
	char 		 MipMapName[MAX_CARS];
    unsigned int MipMapLODS = 1;
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
        	case E3D_PSH_TEX_BEGINDEF:	if (! stricmp(szToken,"{"))
                                 		ParseState = E3D_PSH_TEX_PARS;
            						else
									{
                                    	// Copy the texture name
										strcpy(MipMapName,szToken);
										// WARNING if name redefinition
									}
									break;

			case E3D_PSH_TEX_PARS:	// Image filename
            				 		if (! stricmp(szToken,"Image"))
                             		{
                                    	NextToken(szToken,_szDesc);
										strcpy(MipMapName,szToken);
									}
									// Mignification filter
							 else   if (! stricmp(szToken,"MinFilter"))
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
							 else 	if (! stricmp(szToken,"MagFilter"))
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
							 else	if (! stricmp(szToken,"NumLODs"))
                             		{
                                    	NextToken(szToken,_szDesc);
                                     	if (! sscanf(szToken,"%d",&MipMapLODS))
                                        	// WARNING
                                        	MipMapLODS = 1;
									}
									
									/*
									// MipMap generation method
							 else 	if (! stricmp(szToken,"MMGenMethod"))
                             		{
                                    	NextToken(szToken,_szDesc);
                                        	if (! stricmp(szToken,"NORMAL"))
                                            	MMCMethod = MMCM_Normal;
									   else if (! stricmp(szToken,"HLINEAR_FILTERING"))
                                            	MMCMethod = MMCM_HLinearFiltering;
									   else if (! stricmp(szToken,"VLINEAR_FILTERING"))
                                            	MMCMethod = MMCM_VLinearFiltering;
									   else if (! stricmp(szToken,"BILINEAR_FILTERING"))
                                            	MMCMethod = MMCM_BilinearFiltering;
									   else
									   {
                                       			// WARNING
									   }
									}
									*/
							 else 	if (! stricmp(szToken,"UWrap"))
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
							 else 	if (! stricmp(szToken,"VWrap"))
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
							 else   {
                             			// WARNING
										// Unknown token name
									}
								break;
		}
    }
	// --------------------------------------------------------------------------
	// END: Parse texture paramters
	// --------------------------------------------------------------------------

    // Create the material node
    MatNode = mNew CE3D_ShIns_Texture();
    if (! MatNode) return(NULL); // Return a null material ???

    // Create the texture object node
    TexObj = TTexObjWarehouse::AllocateTexObj();

    if (! TexObj)
    {
        // WARNING
        // Maximum number of texture objects reached
        mDel MatNode;
        return(NULL);	// Return a null material ???
    }

	// Setup material node
	MatNode->pTex   = TexObj;    

	// Setup texture object
    TexObj->UWrap     = UWrap;
    TexObj->VWrap     = VWrap;
    TexObj->MinFilter = MinFilter;
    TexObj->MaxFilter = MagFilter;

	// Create the texture object
    MipMapObj = TMipMapWarehouse::LoadMipMap(MipMapName,MipMapLODS);

    if (MipMapObj)
    	TexObj->MipMapObj = MipMapObj;
    else
    {
		// WARNING
        // No mipmap filename defined, return the null texture ???
		TexObj->MipMapObj = NULL;
    }

    return(MatNode);
  //## end CE3D_ShaderParser::poParse_ShIns_Texture%1012941679.body
}

void CE3D_ShaderParser::Parse_Color_General (char* _szDesc, float* _fR, float* _fG, float* _fB, float* _fA)
{
  //## begin CE3D_ShaderParser::Parse_Color_General%1013026081.body preserve=yes
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
						if (r>1.0f) r = 1.0f;	else if (r<0.0f) r=0.0f;

					// scan green component
					NextToken(szToken,_szDesc);
					if (! sscanf(szToken,"%f",&g))
						g = 1.0f;
					else
						if (g>1.0f) g = 1.0f;	else if (g<0.0f) g=0.0f;
					
					// scan blue component
					NextToken(szToken,_szDesc);
					if (! sscanf(szToken,"%f",&b))
						b = 1.0f;
					else
						if (b>1.0f) b = 1.0f;	else if (b<0.0f) b=0.0f;

					// scan alpha component
					NextToken(szToken,_szDesc);
					if (! sscanf(szToken,"%f",&a))
						a = 1.0f;
					else
						if (a>1.0f) a = 1.0f;	else if (a<0.0f) a=0.0f;

					ParseState = E3D_PSH_COL_ENDDEF;
				}
			}
			break;

            case E3D_PSH_COL_PARS:  // Red color
                             		if (! stricmp(szToken,"r"))
                             		{
										// scan red component
                                    	NextToken(szToken,_szDesc);
										if (! sscanf(szToken,"%f",&r))
											r = 1.0f;
										else
											if (r>1.0f) r = 1.0f;	else if (r<0.0f) r=0.0f;
                                    }
                                    // Green color
                             else   if (! stricmp(szToken,"g"))
                             		{
										// scan green component
										NextToken(szToken,_szDesc);
										if (! sscanf(szToken,"%f",&g))
											g = 1.0f;
										else
											if (g>1.0f) g = 1.0f;	else if (g<0.0f) g=0.0f;
                                    }
                                    // Blue color
                             else   if (! stricmp(szToken,"b"))
                             		{
										// scan blue component
										NextToken(szToken,_szDesc);
										if (! sscanf(szToken,"%f",&b))
											b = 1.0f;
										else
											if (b>1.0f) b = 1.0f;	else if (b<0.0f) b=0.0f;

                                    }
                                    // Alpha color
                             else   if (! stricmp(szToken,"a"))
                             		{
										// scan alpha component
										NextToken(szToken,_szDesc);
										if (! sscanf(szToken,"%f",&a))
											a = 1.0f;
										else
											if (a>1.0f) a = 1.0f;	else if (a<0.0f) a=0.0f;
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
	}

	*_fR = r;
	*_fG = g;
	*_fB = b;
	*_fA = a;
  //## end CE3D_ShaderParser::Parse_Color_General%1013026081.body
}

CE3D_ShaderInstruction * CE3D_ShaderParser::poParse_ShIns_Color (char *&_szDesc)
{
  //## begin CE3D_ShaderParser::poParse_ShIns_Color%1012941680.body preserve=yes
    CE3D_ShIns_Color	*poSh   = NULL;   
	float				fR,fG,fB,fA;
    
	// Create the material node
	Parse_Color_General (_szDesc,&fR,&fG,&fB,&fA);

    poSh = mNew CE3D_ShIns_Color();
    if (! poSh)	return(NULL);	// Return a null material ???

    // Create the texture object node
	poSh->oColor.SetColor(fR,fG,fB,fA);

    return(poSh);
  //## end CE3D_ShaderParser::poParse_ShIns_Color%1012941680.body
}

CE3D_ShaderInstruction * CE3D_ShaderParser::poParse_ShIns_Wireframe (char *&_szDesc)
{
  //## begin CE3D_ShaderParser::poParse_ShIns_Wireframe%1012941681.body preserve=yes
    CE3D_ShIns_Wireframe	*poSh   = NULL;   
	float					fR,fG,fB,fA;
    
	// Create the material node
	Parse_Color_General (_szDesc,&fR,&fG,&fB,&fA);

    poSh = mNew CE3D_ShIns_Wireframe();
    if (! poSh)	return(NULL);	// Return a null material ???

    // Create the texture object node
	poSh->oColor.SetColor(fR,fG,fB,fA);

    return(poSh);
  //## end CE3D_ShaderParser::poParse_ShIns_Wireframe%1012941681.body
}

CE3D_ShaderInstruction * CE3D_ShaderParser::poParse_ShIns_Extension (char *&_szDesc)
{
  //## begin CE3D_ShaderParser::poParse_ShIns_Extension%1012941682.body preserve=yes
	char *szToken;	
	NextToken(szToken,_szDesc);		

	// Get the extension from the Extension DB
	TExtensionFunction pFunc = (TExtensionFunction)CE3D_ShaderExtDB::pGetExtension(szToken);
		
	if (! pFunc) return(NULL);
	
	CE3D_ShIns_Extension *poSh;	
	poSh  = mNew CE3D_ShIns_Extension();			
	poSh->pFunction = pFunc;
		
	return(poSh);
  //## end CE3D_ShaderParser::poParse_ShIns_Extension%1012941682.body
}

CE3D_ShaderInstruction * CE3D_ShaderParser::poParse_ShIns_BlendingOperation (char *&_szDesc)
{
  //## begin CE3D_ShaderParser::poParse_ShIns_BlendingOperation%1012941683.body preserve=yes
	char *szToken;	
	NextToken(szToken,_szDesc);	

	CE3D_ShIns_BlendOp *poSh = mNew CE3D_ShIns_BlendOp();
	poSh->SeteBOpType(eSIBOp_NULL);

	if (! stricmp(szToken,"Copy"))
		poSh->SeteBOpType(eSIBOp_Copy);
	if (! stricmp(szToken,"Mult"))
		poSh->SeteBOpType(eSIBOp_Mult);
	if (! stricmp(szToken,"Mult2x"))
		poSh->SeteBOpType(eSIBOp_Mult2x);
	if (! stricmp(szToken,"Add"))
		poSh->SeteBOpType(eSIBOp_Add);
	if (! stricmp(szToken,"Add&Mult"))
		poSh->SeteBOpType(eSIBOp_MultAndAdd);
	if (! stricmp(szToken,"Mult&Add"))
		poSh->SeteBOpType(eSIBOp_AddAndMult);
	if (! stricmp(szToken,"Alpha"))
		poSh->SeteBOpType(eSIBOp_Alpha);
	if (! stricmp(szToken,"AlphaAdd"))
		poSh->SeteBOpType(eSIBOp_AlphaAdd);
	if (! stricmp(szToken,"AlphaInv"))
		poSh->SeteBOpType(eSIBOp_AlphaInv);
	if (! stricmp(szToken,"AlphaThrough"))
		poSh->SeteBOpType(eSIBOp_AlphaThrough);

	return(poSh);
  //## end CE3D_ShaderParser::poParse_ShIns_BlendingOperation%1012941683.body
}

CE3D_ShaderInstruction * CE3D_ShaderParser::poParse_ShIns_TextureOperation (char *&_szDesc)
{
  //## begin CE3D_ShaderParser::poParse_ShIns_TextureOperation%1012941684.body preserve=yes
	char *szToken;
	NextToken(szToken,_szDesc);	

	CE3D_ShIns_TexOp *poSh = mNew CE3D_ShIns_TexOp();
	poSh->SeteTOpType(eSITexOp_NULL);

	if (! stricmp(szToken,"Rotate"))
		poSh->SeteTOpType(eSITexOp_Rotate);
	if (! stricmp(szToken,"ScaleUV"))
		poSh->SeteTOpType(eSITexOp_Scale);
	if (! stricmp(szToken,"ScaleU"))
		poSh->SeteTOpType(eSITexOp_ScaleU);
	if (! stricmp(szToken,"ScaleV"))
		poSh->SeteTOpType(eSITexOp_ScaleV);
	if (! stricmp(szToken,"TransU"))
		poSh->SeteTOpType(eSITexOp_TransU);
	if (! stricmp(szToken,"TransV"))
		poSh->SeteTOpType(eSITexOp_TransV);
	if (! stricmp(szToken,"ReflectMap"))
		poSh->SeteTOpType(eSITexOp_ReflectMap);
	if (! stricmp(szToken,"EnvMap"))
		poSh->SeteTOpType(eSITexOp_EnvMap);
	if (! stricmp(szToken,"Matrix"))
		poSh->SeteTOpType(eSITexOp_Matrix);

	poSh->poEval = poParseEvaluator(_szDesc);

	return(poSh);
  //## end CE3D_ShaderParser::poParse_ShIns_TextureOperation%1012941684.body
}

CE3D_ShaderInstruction * CE3D_ShaderParser::poParse_ShIns_GeometricOperation (char *&_szDesc)
{
  //## begin CE3D_ShaderParser::poParse_ShIns_GeometricOperation%1012941685.body preserve=yes
	char *szToken;
	NextToken(szToken,_szDesc);	

	CE3D_ShIns_GeoOp *poSh = mNew CE3D_ShIns_GeoOp();
	poSh->SeteGOpType(eSIGeoOp_NULL);

	if (! stricmp(szToken,"RotateX"))
		poSh->SeteGOpType(eSIGeoOp_RotateX);
	if (! stricmp(szToken,"RotateY"))
		poSh->SeteGOpType(eSIGeoOp_RotateY);
	if (! stricmp(szToken,"RotateZ"))
		poSh->SeteGOpType(eSIGeoOp_RotateZ);
	if (! stricmp(szToken,"Scale"))
		poSh->SeteGOpType(eSIGeoOp_Scale);
	if (! stricmp(szToken,"ScaleX"))
		poSh->SeteGOpType(eSIGeoOp_ScaleX);
	if (! stricmp(szToken,"ScaleY"))
		poSh->SeteGOpType(eSIGeoOp_ScaleY);
	if (! stricmp(szToken,"ScaleZ"))
		poSh->SeteGOpType(eSIGeoOp_ScaleZ);
	if (! stricmp(szToken,"TransX"))
		poSh->SeteGOpType(eSIGeoOp_TransX);
	if (! stricmp(szToken,"TransY"))
		poSh->SeteGOpType(eSIGeoOp_TransY);
	if (! stricmp(szToken,"TransZ"))
		poSh->SeteGOpType(eSIGeoOp_TransZ);

	poSh->poEval = poParseEvaluator(_szDesc);

	return(poSh);
  //## end CE3D_ShaderParser::poParse_ShIns_GeometricOperation%1012941685.body
}

CE3D_ShaderInstruction * CE3D_ShaderParser::poParse_ShIns_SetTMU (char *&_szDesc)
{
  //## begin CE3D_ShaderParser::poParse_ShIns_SetTMU%1012941686.body preserve=yes
	if (! _szDesc) return(NULL);

	CE3D_ShIns_SetTMU *poSh = mNew CE3D_ShIns_SetTMU();
	sscanf(_szDesc,"%i",&poSh->iTMU);

	return(poSh);
  //## end CE3D_ShaderParser::poParse_ShIns_SetTMU%1012941686.body
}

CEvaluator * CE3D_ShaderParser::poParseEvaluator (char *_szDesc)
{
  //## begin CE3D_ShaderParser::poParseEvaluator%1013026082.body preserve=yes
	return(NULL);
  //## end CE3D_ShaderParser::poParseEvaluator%1013026082.body
}

// Additional Declarations
  //## begin CE3D_ShaderParser%3C604EBE02A5.declarations preserve=yes
  //## end CE3D_ShaderParser%3C604EBE02A5.declarations

//## begin module%3C604EBE02A5.epilog preserve=yes
//## end module%3C604EBE02A5.epilog
