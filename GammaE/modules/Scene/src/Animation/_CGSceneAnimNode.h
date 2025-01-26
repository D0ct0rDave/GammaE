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
#ifndef CGSceneAnimObjectH
#define CGSceneAnimObjectH
// --------------------------------------------------------------------------------
#include "GammaE_E3D.h"
#include "GSceneEnums.h"
#include "Visitors/CGSceneVisitor.h"
// --------------------------------------------------------------------------------
class CGSceneAnimNode
{
    public:
        CGSceneAnimNode();

        ESceneNodeType eGetTypeID()
        {
            return (m_eTypeID);
        }

        // / Creates the information needed to store all the animation key frames
        virtual void Init(uint _uiNumKeyFrames);

        // / Recompute the bounding volume of all the frames
        virtual void ComputeBoundVols() = 0;

        // / Returns the number of frames in the anim object
        uint uiGetNumKeyFrames()
        {
            return (m_uiNumKeyFrames);
        }

        // / Retrieves the bounding volume of the specified frame
        CGGraphBV* poGetKeyFrameBVol(uint _uiKeyFrame)
        {
            return (m_poFrameBVol[_uiKeyFrame]);
        }

        // / Sets the bounding volume of the specified frame
        void SetKeyFrameBVol(uint _uiKeyFrame, CGGraphBV* _poBV)
        {
            m_poFrameBVol[_uiKeyFrame] = _poBV;
        }

        // / Processing functionality
        virtual void Accept(CGSceneVisitor* _poVisitor) = 0;

    protected:

        // Number of keyframes contained within this object
        uint m_uiNumKeyFrames;

        // Array to store the bounding volumes for every keyframe of the animated object
        CGStArray <CGGraphBV*> m_poFrameBVol;

        ESceneNodeType m_eTypeID;
};
// --------------------------------------------------------------------------------
#endif
// --------------------------------------------------------------------------------
