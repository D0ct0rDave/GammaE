//-----------------------------------------------------------------------------
#ifndef CObject3D_Transf_h
#define CObject3D_Transf_h 1
//-----------------------------------------------------------------------------

#include "CObject3D.h"

//-----------------------------------------------------------------------------
class CObject3D_Transf : public CObject3D
{
public: CObject3D_Transf();

    virtual ~CObject3D_Transf();

    void SetPos (const CVect3 & _oPos);

    CVect3 & oPos();

    void SetDir (const CVect3 & _oDir);

    CVect3 & oDir();

    void SetUp (const CVect3 & _oUp);

    CVect3 & oUp();

    void SetSide (const CVect3 & _oSide);

    CVect3 & oSide();

    void Setup (const CVect3 & _oPos, const CVect3 & _oDir, const CVect3 & _oSide, const CVect3 & _oUp);

    void SetTransf (const CMatrix4x4 & _oTransf);

    CMatrix4x4 & oTransf ();

    void SetObject (CObject3D *_poObj);

    CObject3D *poGetObject ();

    virtual CGraphBV *poCreateBoundVol ();

    virtual void ComputeBoundVol ();

    virtual CGraphBV *poGetBoundVol ();

    virtual void Render ();

     // Additional Public Declarations
protected:
    void SetupTransformation ();

    // Data Members for Class Attributes

    CMatrix4x4 m_oTransf;

    CVect3 m_oPos;

    CVect3 m_oDir;

    CVect3 m_oUp;

    CVect3 m_oSide;

    CObject3D *m_poObj;
};

//-----------------------------------------------------------------------------
#endif // ifndef CObject3D_Transf_h
//-----------------------------------------------------------------------------
