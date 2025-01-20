// ----------------------------------------------------------------------
#ifndef CObject3D_Leaf_h
#define CObject3D_Leaf_h 1
// ----------------------------------------------------------------------
// CObject3D
#include "CObject3D.h"
// ----------------------------------------------------------------------
class CObject3D_Leaf : public CObject3D
{
public: CObject3D_Leaf();

    virtual ~CObject3D_Leaf();

    virtual void Clear ();

    virtual CGraphBV *poCreateBoundVol ()
    {
        return ( NULL );
    };

    virtual CGraphBV *poGetBoundVol ();

    virtual void ComputeBoundVol ();

    void SetMesh (CMesh *_poMesh);

    virtual CMesh *poGetMesh ();

    virtual void SetShader (CE3D_Shader *_poShader);

    virtual CE3D_Shader *poGetShader ();

    virtual void Render ();

    CMesh *poMesh;
protected:
    CE3D_Shader *poShader;
};
// ----------------------------------------------------------------------
inline void CObject3D_Leaf::SetShader (CE3D_Shader *_poShader)
{
    poShader = _poShader;
}
// ----------------------------------------------------------------------
inline CE3D_Shader *CObject3D_Leaf::poGetShader ()
{
    return( poShader );
}
// ----------------------------------------------------------------------
#endif // ifndef CObject3D_Leaf_h
// ----------------------------------------------------------------------
