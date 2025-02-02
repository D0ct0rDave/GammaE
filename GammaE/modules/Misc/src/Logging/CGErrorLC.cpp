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
 * Copyright (c) 2009, David Márquez de la Cruz
 * All rights reserved.
 */
// ----------------------------------------------------------------------------
#include "CGErrorLC.h"
#include <stdarg.h>
#include <stdio.h>
// ----------------------------------------------------------------------------
void CGErrorLC::Write(char* fmt,...)
{
    char szLocalBuff[8192];

    va_list argptr;
    va_start(argptr,fmt);
    vsprintf(szLocalBuff,fmt,argptr);
    va_end  (argptr);

    m_poLogger->Write("ERROR: %s",szLocalBuff);
}
// ----------------------------------------------------------------------------
