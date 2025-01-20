

#include "CGraphicResourceMgr.h"
// -----------------------------------------------------------------------------

MEM_HashTable <CGraphicResource*> CGraphicResourceMgr::m_aoGraphicResources;
// -----------------------------------------------------------------------------
void CGraphicResourceMgr::Register(char* _szResourceName,CGraphicResource* _poGRes)
{
	m_aoGraphicResources.hAdd(_szResourceName,_poGRes);
}
// -----------------------------------------------------------------------------
CGraphicResource *CGraphicResourceMgr::poGetResource(char* _szResourceName)
{
	return ( *m_aoGraphicResources.poGet(_szResourceName) );
}
// -----------------------------------------------------------------------------
void CGraphicResourceMgr::Invalidate()
{
	m_aoGraphicResources.Invalidate();
}
// -----------------------------------------------------------------------------