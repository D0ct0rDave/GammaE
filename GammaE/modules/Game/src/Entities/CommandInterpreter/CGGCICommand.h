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
#ifndef CGGCICommands_h
#define CGGCICommands_h 1
// -----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "CGGCIState.h"
// -----------------------------------------------------------------------------
class CGGameCommandInterpreter;

class CGGCICommand
{
    public:
        CGGCICommand(CGGameCommandInterpreter* _poCI) : m_poCI(_poCI)
        {
        }

        virtual ECIState Exec(CGString& _sPars)
        {
            return(CIS_Running);
        }
        virtual const CGString& sCommand()
        {
            return( (CGString &) "" );
        }
        virtual const CGString& sHelpString()
        {
            return( (CGString &) "" );
        }

    protected:
        CGGameCommandInterpreter* m_poCI;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
