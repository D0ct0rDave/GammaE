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
#ifndef CGSceneAnimNodeH
#define CGSceneAnimNodeH
// ----------------------------------------------------------------------------
#include "CGSceneNode.h"
// ----------------------------------------------------------------------------
class CGSceneAnimNode : public CGSceneNode
{
    public:
        CGSceneAnimNode();

        virtual void SetAnimState(int _iSrc, int _iDst, float _fFactor) = 0;

        CGGraphBV* poCreateBoundVol ()
        {
            return( CGGraphBVFactory::poCreate() );
        }

        virtual CGGraphBV* poGetStateBVol(int _iState) = 0;

        int iGetNumStates();

        int iGetLastFrame();

    protected:

        int iNumStates;

};
// ----------------------------------------------------------------------------
inline int CGSceneAnimNode::iGetNumStates ()
{
    return(iNumStates);
}
// ----------------------------------------------------------------------------
inline int CGSceneAnimNode::iGetLastFrame ()
{
    return(0);
}
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
