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
#include "CGGCIStdCommands.h"
#include "CGGameCommandInterpreter.h"
#include "GammaE_Input.h"
#include "GameRegistry/CGVariableRegistry.h"
// -----------------------------------------------------------------------------
const CGString& CGGCICommandHelp::sCommand()
{
    static CGString oStr = "HELP";
    return(oStr);
}

const CGString& CGGCICommandHelp::sHelpString()
{
    static CGString oStr = "HELP [command]: Muestra ayuda en pantalla.";
    return(oStr);
}

ECIState CGGCICommandHelp::Exec(CGString& _sPars)
{
    if ( _sPars.szString() == NULL )
    {
        for ( uint i = 0; i < m_poCI->m_poCmds.uiNumElems(); i++ )
            m_poCI->Print( "%s\n", m_poCI->m_poCmds[i]->sHelpString().szString() );
    }
    else
    {
        _sPars.ToUpperCase();
        bool bFound = false;

        for ( uint i = 0; i < m_poCI->m_poCmds.uiNumElems(); i++ )
        {
            if ( m_poCI->m_poCmds[i]->sCommand() == _sPars )
            {
                m_poCI->Print( "%s\n", m_poCI->m_poCmds[i]->sHelpString().szString() );
                bFound = true;
            }
        }

        if ( !bFound )
            m_poCI->Print("No puedo mostrar información del comando %s\n",_sPars);
    }

    return(CIS_Running);
}
// -----------------------------------------------------------------------------
const CGString& CGGCICommandEcho::sCommand()
{
    static CGString oStr = "ECHO";
    return(oStr);
}

const CGString& CGGCICommandEcho::sHelpString()
{
    static CGString oStr = "ECHO [Text]: Escribe el argumento pasado en la consola.";
    return(oStr);
}

ECIState CGGCICommandEcho::Exec(CGString& _sPars)
{
    if ( _sPars.szString() == NULL ) return(CIS_Running);

    m_poCI->Print( (char*)_sPars.szString() );
    m_poCI->Type('\n');

    return(CIS_Running);
}
// -----------------------------------------------------------------------------
const CGString& CGGCICommandExec::sCommand()
{
    static CGString oStr = "EXEC";
    return(oStr);
}

const CGString& CGGCICommandExec::sHelpString()
{
    static CGString oStr = "EXEC [File]: Ejecuta las instrucciones encontradas en el fichero file.";
    return(oStr);
}

ECIState CGGCICommandExec::Exec(CGString& _sPars)
{
    if ( _sPars.szString() == NULL ) return(CIS_Running);

    char* szFile = Utils::Parse::ReadFile( (char*)_sPars.szString() );
    if ( !szFile )
    {
        return(CIS_Ready);
    }

    char* szLine = szFile;
    char* szNextLine = szFile;

    while ( *szLine )
    {
        NextLine(szLine,szNextLine);
        m_poCI->AddInstruction( CGString(szLine) );

        szLine = szNextLine;
    }

    MEMFree(szFile);
    return(CIS_Running);
}
// -----------------------------------------------------------------------------
const CGString& CGGCICommandDelay::sCommand()
{
    static CGString oStr = "DELAY";
    return(oStr);
}

const CGString& CGGCICommandDelay::sHelpString()
{
    static CGString oStr = "DELAY [Milliseconds]: Realiza un retardo de tiempo";
    return(oStr);
}
ECIState CGGCICommandDelay::Exec(CGString& _sPars)
{
    if ( _sPars.szString() == NULL ) return(CIS_Running);

    int iMilis = atoi( _sPars.szString() );
    m_poCI->SetDelayTime( (float)iMilis / 1000.0f );
    return(CIS_Delay);
}
// -----------------------------------------------------------------------------
const CGString& CGGCICommandCls::sCommand()
{
    static CGString oStr = "CLS";
    return(oStr);
}

const CGString& CGGCICommandCls::sHelpString()
{
    static CGString oStr = "CLS: Escribe el argumento pasado en la consola.";
    return(oStr);
}

ECIState CGGCICommandCls::Exec(CGString& _sPars)
{
    m_poCI->Cls();
    return(CIS_Running);
}
// -----------------------------------------------------------------------------
const CGString& CGGCICommandNop::sCommand()
{
    static CGString oStr = "NOP";
    return(oStr);
}

const CGString& CGGCICommandNop::sHelpString()
{
    static CGString oStr = "NOP: No hace nada.";
    return(oStr);
}

ECIState CGGCICommandNop::Exec(CGString& _sPars)
{
    return(CIS_Running);
}
// -----------------------------------------------------------------------------
const CGString& CGGCICommandBind::sCommand()
{
    static CGString oStr = "BIND";
    return(oStr);
}

const CGString& CGGCICommandBind::sHelpString()
{
    static CGString oStr = "BIND [Key] [Command] [Parameters]: Asocia una entrada a un comando y sus posibles argumentos.";
    return(oStr);
}

ECIState CGGCICommandBind::Exec(CGString& _sPars)
{
    if ( _sPars.szString() == NULL )
    {
        // Mostrar las entradas bindeadas ???
    }
    else
    {
        CGDynArray <CGString> oPars;
        _sPars.ToUpperCase();

        Utils::Parse::ParseSentence(_sPars,&oPars);
        if ( oPars.uiNumElems() < 2 ) return(CIS_Running);

        // Retrieve input key
        int iKey = CGInputRegistry::I()->iInput( oPars[0] );

        if ( iKey == -1 )
            m_poCI->Print("ERROR: Invalid input %s to bind.\n",oPars[0]);

        // Retrieve command
        int iCmd = CGCommandRegistry::I()->iRetrieveCommand( oPars[1] );

        if ( iCmd == -1 )
            m_poCI->Print("ERROR: Invalid command %s to bind to.\n",oPars[1]);

        CGString sCmdPars = "";
        for ( uint i = 2; i < oPars.uiNumElems(); i++ )
        {
            if ( i == 2 )
                sCmdPars = oPars[2];
            else
                // Add space between parameters
                sCmdPars += (CGString(" ") + oPars[i]);
        }

        // Bind key to command
        CGCommandBinder::I()->Bind(iKey,iCmd,sCmdPars);
    }

    return(CIS_Running);
}
// -----------------------------------------------------------------------------
const CGString& CGGCICommandSet::sCommand()
{
    static CGString oStr = "SET";
    return(oStr);
}

const CGString& CGGCICommandSet::sHelpString()
{
    static CGString oStr = "SET [Variable] [Value]: Establece el valor de una variable.";
    return(oStr);
}

ECIState CGGCICommandSet::Exec(CGString& _sPars)
{
    CGDynArray <CGString> oPars;
    if ( _sPars != "" )
    {
        _sPars.ToUpperCase();
        Utils::Parse::ParseSentence(_sPars,&oPars);
    }

    switch ( oPars.uiNumElems() )
    {
        // Show all the variables
        case 0:
        {
            for ( uint i = 0; i < CGVariableRegistry::I()->uiNumVariables(); i++ )
                m_poCI->Print( "    %s = %s\n",CGVariableRegistry::I()->sGetVariable(i),CGVariableRegistry::I()->sGetValue(i) );
        }
        break;

        // Show the value of this variable
        case 1:
        {
            int iIdx = CGVariableRegistry::I()->iGetIdx( oPars[0] );
            if ( iIdx == -1 )
                m_poCI->Print("The variable %s does not exist\n",oPars[0]);
            else
                m_poCI->Print( "    %s = %s\n",CGVariableRegistry::I()->sGetVariable(iIdx),CGVariableRegistry::I()->sGetValue(iIdx) );
        }
        break;

        // Set or create the variable
        case 2:
        {
            int iIdx = CGVariableRegistry::I()->iGetIdx( oPars[0] );
            if ( iIdx != -1 )
                // Create the variable
                CGVariableRegistry::I()->SetVar(oPars[0],oPars[1]);
            else
                // Set the variable
                CGVariableRegistry::I()->uiAddVar(oPars[0],oPars[1]);
        }
        break;

        default:
        break;
    }

    return(CIS_Running);
}
// -----------------------------------------------------------------------------
