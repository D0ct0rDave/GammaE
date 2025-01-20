//	  %X% %Q% %Z% %W%

#ifndef CObject3D_AnimTransf_h
#define CObject3D_AnimTransf_h 1

// CObject3D_AnimGen
#include "Animation\CObject3D_AnimGen.h"

class CObject3D_AnimTransf : public CObject3D_AnimGen
{

public: CObject3D_AnimTransf();

    virtual ~CObject3D_AnimTransf();

    void CreateStates (int _iNumStates);

    virtual CGraphBV *poGetBoundVol ();

    virtual void ComputeBoundVol ();

    virtual void Render ();

    virtual void SetAnimState (int _iSrc, int _iDst, float _fFactor);

    virtual CGraphBV *poGetStateBVol (int _iState);

    // Data Members for Class Attributes

    CMatrix4x4 *pTransStates;

     // Additional Public Declarations
protected:
     // Additional Protected Declarations
private:
    // Data Members for Class Attributes

    CMatrix4x4 Trans;

     // Additional Private Declarations
private:
    // Additional Implementation Declarations
};

// Class CObject3D_AnimTransf

#endif // ifndef CObject3D_AnimTransf_h
