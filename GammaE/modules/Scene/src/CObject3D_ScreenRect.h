// ----------------------------------------------------------------------
#ifndef CObject3D_ScreenRect_h
#define CObject3D_ScreenRect_h 1
// ----------------------------------------------------------------------
// CObject3D
#include "CObject3D.h"
// ----------------------------------------------------------------------
class CObject3D_ScreenRect : public CObject3D
{
public: CObject3D_ScreenRect();

    virtual ~CObject3D_ScreenRect();

    virtual void Clear ();

    virtual CGraphBV *poCreateBoundVol();

    virtual CGraphBV *poGetBoundVol ();

    virtual void ComputeBoundVol ();

    virtual void SetRect(float _fX,float _fY,float _fTX,float _fTY);
    virtual void SetShader (CE3D_Shader *_poShader);

    virtual CE3D_Shader *poGetShader ();

    virtual void Render ();
protected:
    CMesh *poMesh;
    CE3D_Shader *poShader;
    CMatrix4x4 oMat;
};
// ----------------------------------------------------------------------
inline void CObject3D_ScreenRect::SetShader (CE3D_Shader *_poShader)
{
    poShader = _poShader;
}
// ----------------------------------------------------------------------
inline CE3D_Shader *CObject3D_ScreenRect::poGetShader ()
{
    return( poShader );
}
// ----------------------------------------------------------------------
#endif // ifndef CObject3D_ScreenRect_h
// ----------------------------------------------------------------------
