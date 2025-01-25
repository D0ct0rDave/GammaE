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
#include "Animation\CGSceneAnimCfgMgr.h"
#include <string.h>

CGSceneAnimCfgMgr::CGSceneAnimCfgMgr()
    : iNumAnimObjs(0), iMaxAnimObjs(0), pAnimObjs(NULL), iCurrentFrame(0)
{
    TypeID = e3DObj_AnimCfgMgr;
}

CGSceneAnimCfgMgr::~CGSceneAnimCfgMgr()
{
}

void CGSceneAnimCfgMgr::Init (int _iMaxAnimObjs)
{
    iMaxAnimObjs = _iMaxAnimObjs;
    iNumAnimObjs = 0;
    pAnimObjs = mNew CGSceneAnimCfg *[iMaxAnimObjs];
    memset(pAnimObjs,0,4 * iMaxAnimObjs);
}

void CGSceneAnimCfgMgr::SetFrameAnim (int _iFrameAnim)
{
    assert (pAnimObjs && "NULL Animation object array");

    iCurrentFrame = _iFrameAnim;

    for ( int iObj = 0; iObj < iNumAnimObjs; iObj++ )
        pAnimObjs[iObj]->SetFrameAnim(_iFrameAnim);
}

CGBoundingVolume* CGSceneAnimCfgMgr::poGetBoundVol ()
{
    assert (pAnimObjs && "NULL Animation object array");

    // WARNING!: Esto no es correcto!
    return ( pAnimObjs[iCurrentFrame]->poGetBoundVol() );
}

void CGSceneAnimCfgMgr::ComputeBoundVol ()
{
    assert (pAnimObjs && "NULL Animation object array");

    for ( int iObj = 0; iObj < iNumAnimObjs; iObj++ )
        pAnimObjs[iObj]->ComputeBoundVol();
}

void CGSceneAnimCfgMgr::Render ()
{
    assert (pAnimObjs && "NULL Animation object array");

    for ( int iObj = 0; iObj < iNumAnimObjs; iObj++ )
        pAnimObjs[iObj]->Render();
}

int CGSceneAnimCfgMgr::AddAnimObj (CGSceneAnimCfg* _pAnimObj)
{
    assert (pAnimObjs && "NULL Animation object array");

    pAnimObjs[iNumAnimObjs++] = _pAnimObj;
    _pAnimObj->Ref();

    return (iNumAnimObjs - 1);
}
