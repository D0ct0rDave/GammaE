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
#ifndef CGSceneAnimGenH
#define CGSceneAnimGenH
// ----------------------------------------------------------------------------
#include "CObject3D.h"
// ----------------------------------------------------------------------------
class CGSceneAnimGen : public CGSceneNode
{
    public:
        CGSceneAnimGen();

        ~CGSceneAnimGen();

        virtual void SetAnimState(int _iSrc, int _iDst, float _fFactor) = 0;

        CGBoundingVolume* poCreateBoundVol ()
        {
            return( CGraphBV_Manager::poCreate() );
        }

        virtual CGBoundingVolume* poGetStateBVol(int _iState) = 0;

        int iGetNumStates();

        int iGetLastFrame();

    protected:

        int iNumStates;

    private:

    private:
};
// ----------------------------------------------------------------------------
inline int CGSceneAnimGen::iGetNumStates ()
{
    return(iNumStates);
}
// ----------------------------------------------------------------------------
inline int CGSceneAnimGen::iGetLastFrame ()
{
    return(0);
}
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
