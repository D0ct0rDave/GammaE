//	  %X% %Q% %Z% %W%

#ifndef CObject3D_h
#define CObject3D_h 1

// GammaE_E3D
#include "GammaE_E3D.h"
#include "GammaE_Misc.h"
// e3DObjectTypeID
#include "e3DObjectTypeID.h"

class CObject3D : public CGReferenceCounter
{

public: CObject3D();

    virtual ~CObject3D();

    virtual CGraphBV *poCreateBoundVol () = 0;

    virtual CGraphBV *poGetBoundVol () = 0;

    virtual void ComputeBoundVol () = 0;

    virtual void Render () = 0;

    void SetBoundVol (CGraphBV *_pGBV);

    virtual bool bVisible ();

    e3DObjectTypeID eGetTypeID ();

     // Additional Public Declarations
    virtual void Deref ();
protected:
    // Data Members for Class Attributes

    CGraphBV *BVol;

    bool bFrustumTest;

    e3DObjectTypeID TypeID;

     // Additional Protected Declarations
private:
     // Additional Private Declarations
private:
    // Additional Implementation Declarations
};

// Class CObject3D

inline void CObject3D::SetBoundVol (CGraphBV *_pGBV)
{
    BVol = _pGBV;
}

inline e3DObjectTypeID CObject3D::eGetTypeID ()
{
    return( TypeID );
}

#endif // ifndef CObject3D_h
