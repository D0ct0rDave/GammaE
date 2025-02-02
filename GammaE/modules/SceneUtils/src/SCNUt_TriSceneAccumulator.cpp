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
// SCNUt_TriSceneAccumulator
#include "SCNUt_TriSceneAccumulator.h"
#include "GammaE_Mem.h"
#include <string.h>

// Class SCNUt_TriSceneAccumulator

SCNUt_TriSceneAccumulator::SCNUt_TriSceneAccumulator()
    : iMaxTris(0), iRealloc(100)
{
}

SCNUt_TriSceneAccumulator::~SCNUt_TriSceneAccumulator()
{
}

void SCNUt_TriSceneAccumulator::AddTriScene (SCNUt_TriScene* _poScn)
{
    if ( NumTris + _poScn->NumTris > iMaxTris )
    {
        SCNUt_Triangle* pTris;

        // Allocate space for old + new triangles
        iMaxTris = NumTris + _poScn->NumTris + iRealloc;
        pTris = (SCNUt_Triangle*)MEMAlloc( (NumTris + _poScn->NumTris + iRealloc) * sizeof(SCNUt_Triangle) );                    //
        // pTris = mNew SCNUt_Triangle[NumTris + _poScn->NumTris + iRealloc];

        // Copy old data
        if ( Tris != NULL )
            memcpy( pTris,Tris,NumTris * sizeof(SCNUt_Triangle) );

        // Copy new data
        memcpy( pTris + NumTris,_poScn->Tris,_poScn->NumTris * sizeof(SCNUt_Triangle) );

        // delete old data
        if ( Tris != NULL )
            MEMFree(Tris);
        // mDel []Tris;

        // Update object
        NumTris += _poScn->NumTris;
        Tris = pTris;
    }
    else
    {
        memcpy( Tris + NumTris,_poScn->Tris,_poScn->NumTris * sizeof(SCNUt_Triangle) );
        NumTris += _poScn->NumTris;
    }
}

void SCNUt_TriSceneAccumulator::Init (int _iNumTris)
{
    Init(_iNumTris,iRealloc);
}

void SCNUt_TriSceneAccumulator::Init (int _iNumTris, int _iRealloc)
{
    iRealloc = _iRealloc;
    SCNUt_TriScene::Init(_iNumTris);
    iMaxTris = _iNumTris;
}

// Additional Declarations
