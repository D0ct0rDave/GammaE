//-----------------------------------------------------------------------------
#include "CGGEntityRenderMgr.h"
#include "GameRes/Graphic/CGGraphicInstance.h"
#include "CGGameEntityMgr.h"
//-----------------------------------------------------------------------------
void CGGEntityRenderMgr::Render()
{
	for (uint i=0;i<CGGameEntityMgr::I()->uiNumEntities();i++)
	{
		CGGameEntity*     poEnt = CGGameEntityMgr::I()->poGetEntity(i);
		CGGraphicInstance* poGI = poEnt->poGraphicInstance();

		if ((poGI != NULL) && (poGI->bVisible()))
			poGI->Render();
	}
}
//-----------------------------------------------------------------------------