// ----------------------------------------------------------------------------
#include "CE3D_ShaderDefFileWH.h"
#include "CE3D_ShaderDefWH.h"

// CE3D_ShaderDefWH
//-----------------------------------------------------------------------------
bool bControlBracketPairs(char *ShaderString)
{
	int NumBrackets = 0;

    while (*ShaderString)
    {
    	 if (*ShaderString == '{') NumBrackets++;
    else if (*ShaderString == '}') NumBrackets--;

		if (NumBrackets<0) return(false);

        ShaderString ++;
}

    return(NumBrackets==0);
}
//-----------------------------------------------------------------------------
char* pcFindNextShader(char *ShaderString)
{
	if (ShaderString == NULL)  return(NULL);
	if (*ShaderString == 0) return(NULL);

	while ( strnicmp(ShaderString,"Material ",9) )
    {
        ShaderString++;
        if (*ShaderString == 0) return(NULL);
}

	return(ShaderString);
}
//-----------------------------------------------------------------------------
bool bGetShaderDefinition(char* _szShaderString,char** _szShaderName,char** _szShaderDef)
{
	char *szShaderName;
	char *szShaderDefinition;

	// skip "material" token
    szShaderName       = ParseUtils_ParseToken(_szShaderString);
	// Get material name
	szShaderName       = ParseUtils_ParseToken(_szShaderString);
	// Get material definition
    szShaderDefinition = _szShaderString;

    if (! bControlBracketPairs(szShaderDefinition)) return(false);

    *_szShaderName = ParseUtils_CreateString(szShaderName      );
    *_szShaderDef  = ParseUtils_CreateString(szShaderDefinition);

	return(true);
}
// ----------------------------------------------------------------------------
void CE3D_ShaderDefFileWH::ProcessShaderDefFile(const CGString& _sShaderDefs)
{
	char*			szShaderFile   = (char*)_sShaderDefs.szString();
    char*			szShaderStream = szShaderFile;
    char*			szShaderDef;
    unsigned int	uiNumReadShaders = 0;

    while (szShaderFile)
    {
		// Set the cursor pointing to the next shader definition starting point
    	szShaderDef  = pcFindNextShader(szShaderFile);
        szShaderFile = szShaderDef;

        if (szShaderDef)
       	{
       		// Set the cursor pointing to the next shader definition starting point
			szShaderFile = pcFindNextShader(szShaderDef+1);

    	    if (szShaderFile)
    	    {
    			uint uiLen = szShaderFile-szShaderDef;
    			char* szShaderDefCopy = (char*)mAlloc(uiLen+1);
    			memcpy(szShaderDefCopy,szShaderDef,uiLen);
    			szShaderDefCopy[uiLen] = 0;

    			AddShader(szShaderDefCopy);

    			mFree(szShaderDefCopy);
			}
			else
			{
				AddShader(szShaderDef);
			}
		}
}
}
// ----------------------------------------------------------------------------
void CE3D_ShaderDefFileWH::AddShader(char* _szShaderString)
{
	char* szShaderName = NULL;
	char* szShaderDef  = NULL;

    // Get the shader definition
    if (! bGetShaderDefinition(_szShaderString,&szShaderName,&szShaderDef))
		return;

	CGTextResource* poSR = mNew CGTextResource(szShaderDef);
	CE3D_ShaderDefWH::I()->uiAdd(poSR,szShaderName);
}
// ----------------------------------------------------------------------------
CGTextResource* CE3D_ShaderDefFileWH::poLoadResource(const CGString& _sFilename)
{
	CGTextResource* poRes = mNew CGTextResource;
	poRes->SetData( ParseUtils_ReadFile((char*)_sFilename.szString()) );

	ProcessShaderDefFile( poRes->sGetData().szString() );

	return ( poRes );
}
// ----------------------------------------------------------------------------
void CE3D_ShaderDefFileWH::Reload()
{
	CE3D_ShaderDefWH::I()->Reset();
	CGDiskResourceWH<CGTextResource, CE3D_ShaderDefFileWH>::Reload();
}
// ----------------------------------------------------------------------------
