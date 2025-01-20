// ----------------------------------------------------------------------
#ifndef CObject3D_Camera_h
#define CObject3D_Camera_h 1
// ----------------------------------------------------------------------
#include "CObject3D_Node.h"
// ----------------------------------------------------------------------
class CObject3D_Camera : public CObject3D_Node
{
public: CObject3D_Camera();

    virtual ~CObject3D_Camera();

    virtual void PreRender ();

    virtual void Render ();

    virtual void PostRender ();

    void SetCamera (CE3D_Camera *_poCamera);

    void SetViewport (CE3D_Viewport *_poViewport);

    void SetProjector (CE3D_Projector *_poProjector);

    CE3D_Camera *poGetCamera ();

    CE3D_Viewport *poGetViewport ();

    CE3D_Projector *poGetProjector ();

    // Data Members for Class Attributes

    CE3D_Camera *poCam;

    CE3D_Projector *poProj;

    CE3D_Viewport *poVpt;

     // Additional Public Declarations
protected:
    CE3D_Camera *poOldCam;

    CE3D_Projector *poOldProj;

    CE3D_Viewport *poOldVpt;
};
// ----------------------------------------------------------------------
inline void CObject3D_Camera::SetCamera (CE3D_Camera *_poCamera)
{
    poCam = _poCamera;
}
// ----------------------------------------------------------------------
inline void CObject3D_Camera::SetViewport (CE3D_Viewport *_poViewport)
{
    poVpt = _poViewport;
}
// ----------------------------------------------------------------------
inline void CObject3D_Camera::SetProjector (CE3D_Projector *_poProjector)
{
    poProj = _poProjector;
}
// ----------------------------------------------------------------------
inline CE3D_Camera *CObject3D_Camera::poGetCamera ()
{
    return( poCam );
}
// ----------------------------------------------------------------------
inline CE3D_Viewport *CObject3D_Camera::poGetViewport ()
{
    return( poVpt );
}
// ----------------------------------------------------------------------
inline CE3D_Projector *CObject3D_Camera::poGetProjector ()
{
    return( poProj );
}
// ----------------------------------------------------------------------
#endif // ifndef CObject3D_Camera_h
// ----------------------------------------------------------------------
