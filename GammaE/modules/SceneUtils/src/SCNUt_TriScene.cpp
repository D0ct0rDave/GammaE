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
// SCNUt_TriScene
#include "SCNUt_TriScene.h"
#include "GammaE_Mem.h"
#include <string.h>

// Class SCNUt_TriScene

SCNUt_TriScene::SCNUt_TriScene()
    : Tris(0), NumTris(0)
{
}

SCNUt_TriScene::~SCNUt_TriScene()
{
    if ( Tris != NULL )
        mFree(Tris);
    // mDel []Tris;
}

const SCNUt_TriScene & SCNUt_TriScene::operator=(const SCNUt_TriScene &right)
{
    Init(right.NumTris);
    memcpy( Tris,right.Tris,NumTris * sizeof(SCNUt_Triangle) );

    return(*this);
}

void SCNUt_TriScene::Init(uint _uiNumTris)
{
    if ( _uiNumTris == 0 ) return;
    if ( Tris != NULL ) mDel[] Tris;

    NumTris = _uiNumTris;
    // Tris    = mNew SCNUt_Triangle[NumTris];
    Tris = (SCNUt_Triangle*)mAlloc ( NumTris * sizeof(SCNUt_Triangle) );
}

// Additional Declarations
