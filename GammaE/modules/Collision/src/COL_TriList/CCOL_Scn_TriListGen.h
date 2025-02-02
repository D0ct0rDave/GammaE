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
#ifndef CCOL_Scn_TriListGen_h
#define CCOL_Scn_TriListGen_h 1
// -----------------------------------------------------------------------------
#include "GammaE_Scene.h"
// -----------------------------------------------------------------------------
// CCOL_TriListGen
#include "COL_TriList\CCOL_TriListGen.h"
// -----------------------------------------------------------------------------
class CCOL_Scn_TriListGen : public CCOL_TriListGen
{
    public:

        virtual int GetTriList(CCOL_TriList& _oTriList, const CGVect3& _oPos, float _fRadius);

        virtual int GetTrisFromMesh(CCOL_TriList& _oTriList, CGMesh* _poMesh, int _iMat, const CGVect3& _oPos, float _fRadius);

};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------