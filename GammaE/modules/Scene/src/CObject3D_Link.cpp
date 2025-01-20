//	  %X% %Q% %Z% %W%

#include "PrecompiledHeaders.h"

// CObject3D_Link
#include "Scene\CObject3D_Link.h"

// Class CObject3D_Link

CObject3D_Link::CObject3D_Link()
    : iObjWHIdx(-1), pObjWH(NULL)
{
    TypeID = e3DObj_Link;
}

CObject3D_Link::~CObject3D_Link()
{
    Unlink();
}

void CObject3D_Link::Link (int _iObjWHIdx, CObject3D_Warehouse *_pObjWH)
{
   static CObject3D_Gen *pObj;

    iObjWHIdx = _iObjWHIdx;
    pObjWH    = _pObjWH;

    pObj = pObjWH->GetObject(iObjWHIdx);
    pObj->Reference();
}

void CObject3D_Link::Unlink ()
{
   static CObject3D_Gen *pObj = pObjWH->GetObject(iObjWHIdx);

   pObj->UnReference();
}

CGraphBV *CObject3D_Link::poGetBoundVol ()
{
   static CObject3D_Gen *pObj = pObjWH->GetObject(iObjWHIdx);

    return ( pObj->poGetBoundVol() );
}

void CObject3D_Link::ComputeBoundVol ()
{
   static CObject3D_Gen *pObj = pObjWH->GetObject(iObjWHIdx);

   pObj->ComputeBoundVol();
}

void CObject3D_Link::Render ()
{
   static CObject3D_Gen *pObj = pObjWH->GetObject(iObjWHIdx);

   pObj->Render();
}

// Additional Declarations
