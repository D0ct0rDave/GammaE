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
// %X% %Q% %Z% %W%

#include "PrecompiledHeaders.h"

// CGSceneLink
#include "Scene\CGSceneLink.h"

// Class CGSceneLink

CGSceneLink::CGSceneLink()
    : iObjWHIdx(-1), pObjWH(NULL)
{
    TypeID = e3DObj_Link;
}

CGSceneLink::~CGSceneLink()
{
    Unlink();
}

void CGSceneLink::Link (int _iObjWHIdx, CGSceneWarehouse* _pObjWH)
{
    static CGSceneGen* pObj;

    iObjWHIdx = _iObjWHIdx;
    pObjWH = _pObjWH;

    pObj = pObjWH->GetObject(iObjWHIdx);
    pObj->Reference();
}

void CGSceneLink::Unlink ()
{
    static CGSceneGen* pObj = pObjWH->GetObject(iObjWHIdx);
    pObj->UnReference();
}

CGBoundingVolume* CGSceneLink::poGetBoundVol ()
{
    static CGSceneGen* pObj = pObjWH->GetObject(iObjWHIdx);
    return ( pObj->poGetBoundVol() );
}

void CGSceneLink::ComputeBoundVol ()
{
    static CGSceneGen* pObj = pObjWH->GetObject(iObjWHIdx);
    pObj->ComputeBoundVol();
}

void CGSceneLink::Render ()
{
    static CGSceneGen* pObj = pObjWH->GetObject(iObjWHIdx);
    pObj->Render();
}

// Additional Declarations
