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
#include "CGGCIExtendedCommands.h"
#include "../CGGameCommandInterpreter.h";
#include "../../CGGameEntityMgr.h"
// -----------------------------------------------------------------------------
const CGString& CGGCICommandListEntities::sCommand()
{
    static CGString oStr = "LSENTS";
    return(oStr);
}

const CGString& CGGCICommandListEntities::sHelpString()
{
    static CGString oStr = "LSENTS: Muestra las entidades registradas en el sistema.";
    return(oStr);
}

ECIState CGGCICommandListEntities::Exec(CGString& _sPars)
{
    for ( uint i = 0; i < CGGameEntityMgr::I()->uiNumEntities(); i++ )
    {
        CGString& sStr = CGGameEntityMgr::I()->poGetEntity(i)->sUID();
        m_poCI->Print( "%s\n", sStr.szString() );
    }

    return(CIS_Running);
}
// -----------------------------------------------------------------------------
const CGString& CGGCICommandSwitchEntityState::sCommand()
{
    static CGString oStr = "SETENTSTATE";
    return(oStr);
}

const CGString& CGGCICommandSwitchEntityState::sHelpString()
{
    static CGString oStr = "SETENTSTATE [Entity, State]: Cambia el estado de una entidad determinada";
    return(oStr);
}

ECIState CGGCICommandSwitchEntityState::Exec(CGString& _sPars)
{
    return(CIS_Running);
}
// -----------------------------------------------------------------------------
const CGString& CGGCICommandSystemLog::sCommand()
{
    static CGString oStr = "LOG";
    return(oStr);
}

const CGString& CGGCICommandSystemLog::sHelpString()
{
    static CGString oStr = "LOG [Entity]: Muestra el log de una entidad. Sin argumentos muestra el log del sistema. ";
    return(oStr);
}

ECIState CGGCICommandSystemLog::Exec(CGString& _sPars)
{
    if ( _sPars.szString() == NULL )
    {
        m_poCI->Print( CGSystemLC::I()->poGetLogger()->szGetBuffer() );
    }
    else
    {
        for ( uint i = 0; i < CGGameEntityMgr::I()->uiNumEntities(); i++ )
        {
            CGGameEntity* poGE = CGGameEntityMgr::I()->poGetEntity(i);
            if ( (poGE) && (poGE->sUID() |= _sPars) && poGE->poLogger() )
                m_poCI->Print( poGE->poLogger()->szGetBuffer() );
        }
    }

    return(CIS_Running);
}
// -----------------------------------------------------------------------------
const CGString& CGGCICommandErrorLog::sCommand()
{
    static CGString oStr = "ERRORLOG";
    return(oStr);
}

const CGString& CGGCICommandErrorLog::sHelpString()
{
    static CGString oStr = "ERRORLOG: Muestra el log de errores.";
    return(oStr);
}

ECIState CGGCICommandErrorLog::Exec(CGString& _sPars)
{
    m_poCI->Print( CGErrorLC::I()->poGetLogger()->szGetBuffer() );
    return(CIS_Running);
}
// -----------------------------------------------------------------------------
const CGString& CGGCICommandClearErrorLog::sCommand()
{
    static CGString oStr = "CLEARERRORLOG";
    return(oStr);
}

const CGString& CGGCICommandClearErrorLog::sHelpString()
{
    static CGString oStr = "CLEARERRORLOG: Limpia el log de errores.";
    return(oStr);
}

ECIState CGGCICommandClearErrorLog::Exec(CGString& _sPars)
{
    CGErrorLC::I()->Clear();
    return(CIS_Running);
}
// -----------------------------------------------------------------------------
const CGString& CGGCICommandClearSysLog::sCommand()
{
    static CGString oStr = "CLEARLOG";
    return(oStr);
}

const CGString& CGGCICommandClearSysLog::sHelpString()
{
    static CGString oStr = "CLEARLOG [Ent]: Limpia el log de una entidad. Sin argumentos, limpia el log del sistema.";
    return(oStr);
}

ECIState CGGCICommandClearSysLog::Exec(CGString& _sPars)
{
    if ( _sPars.szString() == NULL )
    {
        CGSystemLC::I()->Clear();
    }
    else
    {
        for ( uint i = 0; i < CGGameEntityMgr::I()->uiNumEntities(); i++ )
        {
            CGGameEntity* poGE = CGGameEntityMgr::I()->poGetEntity(i);
            if ( (poGE) && (poGE->sUID() |= _sPars) && poGE->poLogger() )
                poGE->poLogger()->Clear();
        }
    }

    return(CIS_Running);
}
// -----------------------------------------------------------------------------
