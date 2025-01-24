// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#include "CGGameExtendedCI.h"
#include "CGGCIExtendedCommands.h"
// -----------------------------------------------------------------------------
CGGameExtendedCI::CGGameExtendedCI()
{
    RegisterCommand( mNew CGGCICommandSystemLog ( (CGGameCommandInterpreter*)this ) );
    RegisterCommand( mNew CGGCICommandErrorLog ( (CGGameCommandInterpreter*)this ) );
    RegisterCommand( mNew CGGCICommandClearSysLog ( (CGGameCommandInterpreter*)this ) );
    RegisterCommand( mNew CGGCICommandClearErrorLog ( (CGGameCommandInterpreter*)this ) );
    RegisterCommand( mNew CGGCICommandListEntities ( (CGGameCommandInterpreter*)this ) );
    RegisterCommand( mNew CGGCICommandSwitchEntityState ( (CGGameCommandInterpreter*)this ) );
}
// -----------------------------------------------------------------------------
