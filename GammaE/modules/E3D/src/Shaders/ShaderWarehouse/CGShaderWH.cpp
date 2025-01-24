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
#include "GammaE_Mem.h"
#include <string.h>
// ----------------------------------------------------------------------------
#include "Shaders\ShaderWarehouse\CGShaderWH.h"
#include "Shaders\ShaderDefinitions\CGShaderDefWH.h"
#include "Shaders\ShaderParser\CGShaderParser.h"
// ----------------------------------------------------------------------------
CGShader* CGShaderWH::poCreateShader(const char* _szShaderName)
{
    // Look if the material already exists in the warehouse
    CGShader* poShader = poFind(_szShaderName);
    if ( poShader ) return(poShader);

    // If it doesn't exist in the shader warehouse,
    // look if it's in the shader definition warehouse
    CGTextResource* poSR = CGShaderDefWH::I()->poFind(_szShaderName);
    if ( poSR )
    {
        // Try loading shader from definition
        const char* szShaderDef = poSR->sGetData().szString();
        poShader = CGShaderParser::poParseShader(szShaderDef,_szShaderName);
    }
    else
        // Try loading shader as a texture
        poShader = CGShaderParser::poCreateShaderFromTexture(_szShaderName);

    if ( !poShader ) return(NULL);

    // Add shader to warehouse
    uiAdd(poShader,_szShaderName);

    return (poShader);
}
// ----------------------------------------------------------------------------
void CGShaderWH::Invalidate(int _iIdx)
{
    CGResourceWH <CGShader,CGShaderWH>::Invalidate(_iIdx);

    if ( _iIdx == -1 )
    {
        for ( int i = 0; i < m_oWH.uiNumElems(); i++ )
            InvalidateElem(i);                  // Should derive from resource
    }
    else
    {
        InvalidateElem(_iIdx);                  // Should derive from resource
    }
}
// ----------------------------------------------------------------------------
void CGShaderWH::InvalidateElem(int _iIdx)
{
    const char* szShaderName = m_oWH.sGetElemName(_iIdx).szString();
    CGShader* poNewShader = NULL;

    // ------------------------
    // If it doesn't exist in the shader warehouse,
    // look if it's in the shader definition warehouse
    CGTextResource* poSR = CGShaderDefWH::I()->poFind( szShaderName );
    if ( poSR )
    {
        // Try loading shader from definition
        const char* szShaderDef = poSR->sGetData().szString();
        poNewShader = CGShaderParser::poParseShader(szShaderDef,szShaderName);
    }
    else
        // Try loading shader as a texture
        poNewShader = CGShaderParser::poCreateShaderFromTexture(szShaderName);
    // ------------------------

    // Copy the contents
    if ( poNewShader == NULL )
    {
        // This shader cannot be invalidated: Probably it was created by code
        return;
    }

    if ( m_oWH.oGetElem(_iIdx) == NULL )
    {
        int a = 0;
    }
    m_oWH.oGetElem(_iIdx)->RefCopy(poNewShader);

    //
    memset( poNewShader,0,sizeof(CGShader) );
    mDel poNewShader;
}
// ----------------------------------------------------------------------------
