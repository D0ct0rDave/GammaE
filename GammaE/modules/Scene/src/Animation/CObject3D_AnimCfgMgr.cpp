// CObject3D_AnimCfgMgr
#include "Animation\CObject3D_AnimCfgMgr.h"
#include <string.h>

// Class CObject3D_AnimCfgMgr

CObject3D_AnimCfgMgr::CObject3D_AnimCfgMgr()
    : iNumAnimObjs(0), iMaxAnimObjs(0), pAnimObjs(NULL), iCurrentFrame(0)
{
    TypeID = e3DObj_AnimCfgMgr;
}

CObject3D_AnimCfgMgr::~CObject3D_AnimCfgMgr()
{
}

void CObject3D_AnimCfgMgr::Init (int _iMaxAnimObjs)
{
    iMaxAnimObjs = _iMaxAnimObjs;
    iNumAnimObjs = 0;
    pAnimObjs = mNew CObject3D_AnimCfg *[iMaxAnimObjs];
    memset(pAnimObjs,0,4 * iMaxAnimObjs);
}

void CObject3D_AnimCfgMgr::SetFrameAnim (int _iFrameAnim)
{
    assert (pAnimObjs && "NULL Animation object array");

    iCurrentFrame = _iFrameAnim;

    for(int iObj = 0; iObj < iNumAnimObjs; iObj++)
        pAnimObjs[iObj]->SetFrameAnim(_iFrameAnim);
}

CGraphBV *CObject3D_AnimCfgMgr::poGetBoundVol ()
{
    assert (pAnimObjs && "NULL Animation object array");

     // WARNING!: Esto no es correcto!
    return ( pAnimObjs[iCurrentFrame]->poGetBoundVol() );

}

void CObject3D_AnimCfgMgr::ComputeBoundVol ()
{
    assert (pAnimObjs && "NULL Animation object array");

    for(int iObj = 0; iObj < iNumAnimObjs; iObj++)
        pAnimObjs[iObj]->ComputeBoundVol();
}

void CObject3D_AnimCfgMgr::Render ()
{
    assert (pAnimObjs && "NULL Animation object array");

    for(int iObj = 0; iObj < iNumAnimObjs; iObj++)
        pAnimObjs[iObj]->Render();
}

int CObject3D_AnimCfgMgr::AddAnimObj (CObject3D_AnimCfg *_pAnimObj)
{
    assert (pAnimObjs && "NULL Animation object array");

    pAnimObjs[iNumAnimObjs++] = _pAnimObj;
    _pAnimObj->Ref();

    return ( iNumAnimObjs - 1 );
}

// Additional Declarations
