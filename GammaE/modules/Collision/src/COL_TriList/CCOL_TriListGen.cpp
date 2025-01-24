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

// CCOL_TriListGen
#include "COL_TriList\CCOL_TriListGen.h"

// Class CCOL_TriListGen
// %X% %Q% %Z% %W%

CGMesh* * CCOL_TriListGen::poMeshes = NULL;

int* CCOL_TriListGen::piMats = NULL;

int CCOL_TriListGen::iNumMeshes = 0;

CCOL_TriListGen::CCOL_TriListGen()
{
}

CCOL_TriListGen::~CCOL_TriListGen()
{
}

int CCOL_TriListGen::GetTriList (CCOL_TriList& _oTriList, CVect3& _oPos, float _fRadius)
{
    return(0);
}

void CCOL_TriListGen::SetMeshes (CGMesh* * _poMeshes, int* _piMats, int _iNumMeshes)
{
    poMeshes = _poMeshes;
    piMats = _piMats;
    iNumMeshes = _iNumMeshes;
}

int CCOL_TriListGen::GetTrisFromMesh (CCOL_TriList& _oTriList, CGMesh* _poMesh, int _iMat, CVect3& _oPos, float _fRadius)
{
    return(0);
}

// Additional Declarations
