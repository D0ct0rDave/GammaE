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
#include "CGGEntityRenderMgr.h"
#include "GameRes/Graphic/CGGraphicInstance.h"
#include "CGGameEntityMgr.h"
// -----------------------------------------------------------------------------
void CGGEntityRenderMgr::Render()
{
    for ( uint i = 0; i < CGGameEntityMgr::I()->uiNumEntities(); i++ )
    {
        CGGameEntity* poEnt = CGGameEntityMgr::I()->poGetEntity(i);
        CGGraphicInstance* poGI = poEnt->poGraphicInstance();

        if ( (poGI != NULL) && ( poGI->bVisible() ) )
            poGI->Render();
    }
}
// -----------------------------------------------------------------------------
