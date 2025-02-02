// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#include "CGShaderDefFileWH.h"
#include "CGShaderDefWH.h"
// ----------------------------------------------------------------------------
bool bControlBracketPairs(char* ShaderString)
{
    int NumBrackets = 0;

    while ( *ShaderString )
    {
        if ( *ShaderString == '{' ) NumBrackets++;
        else
        if ( *ShaderString == '}' ) NumBrackets--;

        if ( NumBrackets < 0 ) return(false);

        ShaderString++;
    }

    return(NumBrackets == 0);
}
// ----------------------------------------------------------------------------
char* pcFindNextShader(char* ShaderString)
{
    if ( ShaderString == NULL ) return(NULL);
    if ( *ShaderString == 0 ) return(NULL);

    while ( strnicmp(ShaderString,"Material ",9) )
    {
        ShaderString++;
        if ( *ShaderString == 0 ) return(NULL);
    }

    return(ShaderString);
}
// ----------------------------------------------------------------------------
bool bGetShaderDefinition(char* _szShaderString,char* * _szShaderName,char* * _szShaderDef)
{
    char* szShaderName;
    char* szShaderDefinition;

    // skip "material" token
    szShaderName = Utils::Parse::ParseToken(_szShaderString);
    // Get material name
    szShaderName = Utils::Parse::ParseToken(_szShaderString);
    // Get material definition
    szShaderDefinition = _szShaderString;

    if ( !bControlBracketPairs(szShaderDefinition) ) return(false);

    *_szShaderName = Utils::Parse::CreateString(szShaderName      );
    *_szShaderDef = Utils::Parse::CreateString(szShaderDefinition);

    return(true);
}
// ----------------------------------------------------------------------------
void CGShaderDefFileWH::ProcessShaderDefFile(const CGString& _sShaderDefs)
{
    char* szShaderFile = (char*)_sShaderDefs.szString();
    char* szShaderStream = szShaderFile;
    char* szShaderDef;
    uint uiNumReadShaders = 0;

    while ( szShaderFile )
    {
        // Set the cursor pointing to the next shader definition starting point
        szShaderDef = pcFindNextShader(szShaderFile);
        szShaderFile = szShaderDef;

        if ( szShaderDef )
        {
            // Set the cursor pointing to the next shader definition starting point
            szShaderFile = pcFindNextShader(szShaderDef + 1);

            if ( szShaderFile )
            {
                uint uiLen = szShaderFile - szShaderDef;
                char* szShaderDefCopy = (char*)MEMAlloc(uiLen + 1);
                memcpy(szShaderDefCopy,szShaderDef,uiLen);
                szShaderDefCopy[uiLen] = 0;

                AddShader(szShaderDefCopy);

                MEMFree(szShaderDefCopy);
            }
            else
            {
                AddShader(szShaderDef);
            }
        }
    }
}
// ----------------------------------------------------------------------------
void CGShaderDefFileWH::AddShader(char* _szShaderString)
{
    char* szShaderName = NULL;
    char* szShaderDef = NULL;

    // Get the shader definition
    if ( !bGetShaderDefinition(_szShaderString,&szShaderName,&szShaderDef) )
        return;

    CGTextResource* poSR = mNew CGTextResource(szShaderDef);
    CGShaderDefWH::I()->uiAdd(poSR,szShaderName);
}
// ----------------------------------------------------------------------------
CGTextResource* CGShaderDefFileWH::poLoadResource(const CGString& _sFilename)
{
    CGTextResource* poRes = mNew CGTextResource;
    poRes->SetData( Utils::Parse::ReadFile( (char*)_sFilename.szString() ) );

    ProcessShaderDefFile( poRes->sGetData().szString() );

    return (poRes);
}
// ----------------------------------------------------------------------------
void CGShaderDefFileWH::Reload()
{
    CGDiskResourceWH <CGTextResource, CGShaderDefFileWH>::Reload();
}
// ----------------------------------------------------------------------------
