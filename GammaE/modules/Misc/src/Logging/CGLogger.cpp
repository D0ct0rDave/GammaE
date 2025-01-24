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
/*
 * Copyright (c) 2009, David M�rquez de la Cruz
 * All rights reserved.
 */
// ----------------------------------------------------------------------------
#include "CGLogger.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "GammaE_Mem.h"
// ----------------------------------------------------------------------------
CGLogger::CGLogger(uint _uiBufferSize)
{
    m_uiBufferSize = _uiBufferSize;
    m_pucBuffer = (char*)MEMAlloc(m_uiBufferSize);
    memset(m_pucBuffer,0,m_uiBufferSize);
}
// ----------------------------------------------------------------------------
void CGLogger::Write(char* fmt,...)
{
    char szLocalBuff[8192];

    va_list argptr;
    va_start(argptr,fmt);
    vsprintf(szLocalBuff,fmt,argptr);
    va_end  (argptr);

    if ( strlen(szLocalBuff) + strlen(m_pucBuffer) < m_uiBufferSize )
        // Concat
        strcat(m_pucBuffer,szLocalBuff);
    else
        // copy
        strncpy(m_pucBuffer,szLocalBuff,m_uiBufferSize);
}
// ----------------------------------------------------------------------------
void CGLogger::Clear()
{
    m_pucBuffer[0] = 0;
}
// ----------------------------------------------------------------------------
