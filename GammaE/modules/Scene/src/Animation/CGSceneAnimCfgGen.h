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

#ifndef CGSceneAnimCfgGenH
#define CGSceneAnimCfgGenH

// CObject3D
#include "CObject3D.h"

class CGSceneAnimCfgGen : public CGSceneNode
{
    public:
        CGSceneAnimCfgGen();

        virtual ~CGSceneAnimCfgGen();

        virtual CGBoundingVolume* poCreateBoundVol ()
        {
            return( CGraphBV_Manager::poCreate() );
        }

        virtual void SetFrameAnim(int iFrameAnim) = 0;

    protected:

    private:

    private:
};

#endif
