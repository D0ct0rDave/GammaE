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
#include "GammaE_Mem.h"
#include "CoronaMgr\CCoronaMgr.h"
// -----------------------------------------------------------------------------
int SortCoronas( const void* a, const void* b)
{
    static unsigned int pAMat,pBMat;

    pAMat = (unsigned int) ( (CCorona*)a )->poMat;
    pBMat = (unsigned int) ( (CCorona*)b )->poMat;

    return (pAMat - pBMat);
}
// -----------------------------------------------------------------------------
CCoronaMgr::CCoronaMgr() : iMaxCoronas(0), iNumCoronas(0), fMaxCoronaDist(0.0f), bVisibles(NULL)
{
}
// -----------------------------------------------------------------------------
CCoronaMgr::~CCoronaMgr()
{
}
// -----------------------------------------------------------------------------
void CCoronaMgr::Init (int _iMaxCoronas)
{
    iMaxCoronas = _iMaxCoronas;
    iNumCoronas = 0;
    poCoronas = mNew CCorona[iMaxCoronas];
}
// -----------------------------------------------------------------------------
void CCoronaMgr::AddCorona (CGColor _oColor, CE3D_Shader* _poMat, CGVect3& _oPos, float _fXYSize)
{
    poCoronas[iNumCoronas].fXYSize = _fXYSize;
    poCoronas[iNumCoronas].oColor = _oColor;
    poCoronas[iNumCoronas].oPos = _oPos;
    poCoronas[iNumCoronas].poMat = _poMat;
    iNumCoronas++;

    // Add ordered
    qsort(poCoronas,iNumCoronas,sizeof(CCorona),SortCoronas);
}
// -----------------------------------------------------------------------------
void CCoronaMgr::SetMaxCoronaDist (float _fMaxCoronaDist)
{
    fMaxCoronaDist = _fMaxCoronaDist;
}
// -----------------------------------------------------------------------------
bool CCoronaMgr::bVisible (CCorona& _oCorona)
{
    return(true);
}
// -----------------------------------------------------------------------------
void CCoronaMgr::MarkVisibles ()
{
}
// -----------------------------------------------------------------------------
void CCoronaMgr::Render ()
{
    // Make all of them
}
// -----------------------------------------------------------------------------
