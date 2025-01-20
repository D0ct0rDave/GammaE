
/*
 * Copyright (c) 2009, David Márquez de la Cruz
 * All rights reserved.
 */
//-----------------------------------------------------------------------------
#include "CGLogChannel.h"
#include "GammaE_Mem.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
//-----------------------------------------------------------------------------
CGLogChannel::CGLogChannel(CGLogger* _poLogger)
{
	if (_poLogger == NULL)
		m_poDefaultLogger = mNew CGLogger(65536);
	else
		m_poDefaultLogger = _poLogger;

	m_poLogger = m_poDefaultLogger;	
}
//-----------------------------------------------------------------------------
void CGLogChannel::Write(char *fmt,...)
{
	char szLocalBuff[8192];

	va_list argptr;
	va_start(argptr,fmt);
	vsprintf(szLocalBuff,fmt,argptr);
	va_end  (argptr);

	m_poLogger->Write(szLocalBuff);
}
//-----------------------------------------------------------------------------