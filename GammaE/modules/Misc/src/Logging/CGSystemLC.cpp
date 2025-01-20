
/*
 * Copyright (c) 2009, David Márquez de la Cruz
 * All rights reserved.
 */

//-----------------------------------------------------------------------------
#include "CGSystemLC.h"
#include "CGStandardLC.h"
#include "CGErrorLC.h"
#include "CGWarningLC.h"

#include <stdarg.h>
#include <stdio.h>
//-----------------------------------------------------------------------------
void CGSystemLC::Write(char *fmt,...)
{
	char szLocalBuff[8192];

	va_list argptr;
	va_start(argptr,fmt);
	vsprintf(szLocalBuff,fmt,argptr);
	va_end  (argptr);

	m_poLogger->Write(szLocalBuff);
	CGStandardLC::I()->Write(szLocalBuff);
}
//-----------------------------------------------------------------------------
void CGSystemLC::Error(char *fmt,...)
{
	char szLocalBuff[8192];

	va_list argptr;
	va_start(argptr,fmt);
	vsprintf(szLocalBuff,fmt,argptr);
	va_end  (argptr);

	m_poLogger->Write("ERROR: %s",szLocalBuff);
	CGErrorLC::I()->Write(szLocalBuff);
}
//-----------------------------------------------------------------------------
void CGSystemLC::Warning(char *fmt,...)
{
	char szLocalBuff[8192];

	va_list argptr;
	va_start(argptr,fmt);
	vsprintf(szLocalBuff,fmt,argptr);
	va_end  (argptr);

	m_poLogger->Write("WARNING: %s",szLocalBuff);
	CGWarningLC::I()->Write(szLocalBuff);
}
//-----------------------------------------------------------------------------

