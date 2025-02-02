// ----------------------------------------------------------------------------
/*! \class CGSceneCamera
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGSceneCameraH
#define CGSceneCameraH
// ----------------------------------------------------------------------------
#include "CGSceneGroup.h"
// ----------------------------------------------------------------------------
class CGSceneCamera : public CGSceneGroup
{
    public:
        CGSceneCamera();
        virtual ~CGSceneCamera();

        // / Sets the camera for this node.
        void SetCamera(CGCamera* _poCamera);

        // / Sets the viewport for this node.
        void SetViewport(CGViewport* _poViewport);

        // / Sets the projector for this node.
        void SetProjector(CGProjector* _poProjector);

        // / Retrieves the camera of this node.
        CGCamera* poGetCamera();

        // / Retrieves the viewport of this node.
        CGViewport* poGetViewport();

        // / Retrieves the projector of this node.
        CGProjector* poGetProjector();

        // General Processing Functionalities.
        virtual void Accept(CGSceneVisitor* _poVisitor)
        {
            _poVisitor->Visit(this);
        }

    protected:

        CGCamera* m_poCam;
        CGProjector* m_poProj;
        CGViewport* m_poVpt;
};
// ----------------------------------------------------------------------------
inline void CGSceneCamera::SetCamera (CGCamera* _poCamera)
{
    m_poCam = _poCamera;
}
// ----------------------------------------------------------------------------
inline void CGSceneCamera::SetViewport (CGViewport* _poViewport)
{
    m_poVpt = _poViewport;
}
// ----------------------------------------------------------------------------
inline void CGSceneCamera::SetProjector (CGProjector* _poProjector)
{
    m_poProj = _poProjector;
}
// ----------------------------------------------------------------------------
inline CGCamera* CGSceneCamera::poGetCamera ()
{
    return(m_poCam);
}
// ----------------------------------------------------------------------------
inline CGViewport* CGSceneCamera::poGetViewport ()
{
    return(m_poVpt);
}
// ----------------------------------------------------------------------------
inline CGProjector* CGSceneCamera::poGetProjector ()
{
    return(m_poProj);
}
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
