//	  %X% %Q% %Z% %W%

#ifndef CObject3D_AnimNode_h
#define CObject3D_AnimNode_h 1

// CObject3D_AnimGen
#include "Animation\CObject3D_AnimGen.h"

class CObject3D_AnimNode : public CObject3D_AnimGen
{

public: CObject3D_AnimNode();

    virtual ~CObject3D_AnimNode();

    virtual CGraphBV *poGetBoundVol ();

    virtual void ComputeBoundVol ();

    virtual void Render ();

    virtual void SetAnimState (int _iSrc, int _iDst, float _fFactor);

    virtual CGraphBV *poGetStateBVol (int _iState);

    void Init (int _iMaxObjs);

    int AddObject (CObject3D_AnimGen *_poObj);

    void CreateStates (int _iNumStates);

    void Clear ();

    CObject3D *poGetObject (int _iObj);

    // Data Members for Class Attributes

    CObject3D * *poObjs;

    int iNumObjs;

    int iMaxObjs;

    CGraphBV * *poBVolStates;

     // Additional Public Declarations
protected:
     // Additional Protected Declarations
private:
     // Additional Private Declarations
private:
    // Additional Implementation Declarations
};

// Class CObject3D_AnimNode

#endif // ifndef CObject3D_AnimNode_h
