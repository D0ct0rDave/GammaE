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
#ifndef CGSceneAnimTransfH
#define CGSceneAnimTransfH
// --------------------------------------------------------------------------------
#include "Animation\CGSceneAnimObject.h"
// --------------------------------------------------------------------------------
class CGSceneAnimTransf : public CGSceneAnimObject
{
    public:
        CGSceneAnimTransf();
        virtual ~CGSceneAnimTransf();

        // / Sets up the data inside the animated object
        void Setup(CGMatrix4x4* _poTransforms)
        {
            m_poTransforms = _poTransforms;
        }

        // / Retrieves the array of transform for this animated object
        CGMatrix4x4* poGetTransforms()
        {
            return(m_poTransforms);
        }

        // / Recompute the bounding volume of all the frames
        virtual void ComputeBoundVols()
        {
            assert(false && "Not implemented!!");
        }

        // General Processing Functionalities
        virtual void Accept(CGSceneVisitor* _poVisitor)
        {
            _poVisitor->Visit(this);
        }

    protected:

        // Array to store the transform keyframes
        CGMatrix4x4* m_poTransforms;
};
// --------------------------------------------------------------------------------
#endif
// --------------------------------------------------------------------------------
