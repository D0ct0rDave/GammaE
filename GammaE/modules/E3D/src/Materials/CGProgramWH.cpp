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
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <gl/gl.h>
#include <gl/glext.h>

// ----------------------------------------------------------------------------
#include "CGProgramWH.h"
// ----------------------------------------------------------------------------
CGProgramWH::CGProgramWH() : m_sAlternatePath("")
{
}
// ----------------------------------------------------------------------------
CGProgram* CGProgramWH::poLoadResource(const CGString& _sFilename)
{
    CGString sVS = _sFilename + ".vs";
    CGString sPS = _sFilename + ".ps";

    // Read vertex shader file
    char* pucVS = ParseUtils_ReadFile( sVS.szString() );
    if ( pucVS == NULL )
    {
        CGString sFilename = m_sAlternatePath + "/" + sVS;
        pucVS = ParseUtils_ReadFile( sFilename.szString() );
    }

    // Read pixel shader file
    char* pucPS = ParseUtils_ReadFile( sPS.szString() );
    if ( pucPS == NULL )
    {
        CGString sFilename = m_sAlternatePath + "/" + sPS;
        pucPS = ParseUtils_ReadFile( sFilename.szString() );
    }

    if ( (pucVS == NULL) && (pucPS == NULL) ) return(NULL);

    // Create program
    CGProgram* poProgram = mNew CGProgram;
    poProgram->m_pucVSData = pucVS;
    poProgram->m_pucPSData = pucPS;

    return(poProgram);
}
// ----------------------------------------------------------------------------
