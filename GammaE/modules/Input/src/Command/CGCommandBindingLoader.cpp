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
#include "CGCommandBindingLoader.h"
// ----------------------------------------------------------------------------
#include <stdlib.h>
#include <string.h>

#include "CGCommandBinder.h"
#include "CGCommandRegistry.h"
#include "CGInputRegistry.h"
#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------
bool CGCommandBindingLoader::Init (char* _szFilename)
{
    char* StrBuff = Utils::Parse::ReadFile(_szFilename);
    char* StrPos = StrBuff;
    char* Token;
    int iKey;
    int iCmd;

    if ( !StrBuff ) return (false);

    CGCommandBinder::I()->UnBindAll();

    while ( StrPos )
    {
        Token = Utils::Parse::ParseToken(StrPos);

        if ( !strcmp(Token,"bind") )
        {
            Token = Utils::Parse::ParseToken(StrPos);

            iKey = CGInputRegistry::I()->iInput(Token);

            Token = Utils::Parse::ParseToken(StrPos);

            iCmd = CGCommandRegistry::I()->iRetrieveCommand(Token);

            if ( (iCmd != -1) && (iKey != -1) )
                CGCommandBinder::I()->Bind(iKey,iCmd);
        }
    }

    MEMFree(StrBuff);
    return (true);
}
// ----------------------------------------------------------------------------
