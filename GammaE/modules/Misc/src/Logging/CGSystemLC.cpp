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
#include "CGSystemLC.h"
#include "CGStandardLC.h"
#include "CGErrorLC.h"
#include "CGWarningLC.h"

#include <stdarg.h>
#include <stdio.h>
// ----------------------------------------------------------------------------
void CGSystemLC::Write(char* fmt,...)
{
    char szLocalBuff[8192];

    va_list argptr;
    va_start(argptr,fmt);
    vsprintf(szLocalBuff,fmt,argptr);
    va_end  (argptr);

    m_poLogger->Write(szLocalBuff);
    CGStandardLC::I()->Write(szLocalBuff);
}
// ----------------------------------------------------------------------------
void CGSystemLC::Error(char* fmt,...)
{
    char szLocalBuff[8192];

    va_list argptr;
    va_start(argptr,fmt);
    vsprintf(szLocalBuff,fmt,argptr);
    va_end  (argptr);

    m_poLogger->Write("ERROR: %s",szLocalBuff);
    CGErrorLC::I()->Write(szLocalBuff);
}
// ----------------------------------------------------------------------------
void CGSystemLC::Warning(char* fmt,...)
{
    char szLocalBuff[8192];

    va_list argptr;
    va_start(argptr,fmt);
    vsprintf(szLocalBuff,fmt,argptr);
    va_end  (argptr);

    m_poLogger->Write("WARNING: %s",szLocalBuff);
    CGWarningLC::I()->Write(szLocalBuff);
}
// ----------------------------------------------------------------------------
