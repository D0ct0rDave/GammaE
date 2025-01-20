//	  %X% %Q% %Z% %W%

#ifndef CObject3D_AnimGen_h
#define CObject3D_AnimGen_h 1

// CObject3D
#include "CObject3D.h"

class CObject3D_AnimGen : public CObject3D
{

public: CObject3D_AnimGen();

    ~CObject3D_AnimGen();

    virtual void SetAnimState (int _iSrc, int _iDst, float _fFactor) = 0;

    CGraphBV *poCreateBoundVol ()
    {
        return( CGraphBV_Manager::poCreate() );
    };

    virtual CGraphBV *poGetStateBVol (int _iState) = 0;

    int iGetNumStates ();

    int iGetLastFrame ();

     // Additional Public Declarations
protected:
    // Data Members for Class Attributes

    int iNumStates;

     // Additional Protected Declarations
private:
     // Additional Private Declarations
private:
    // Additional Implementation Declarations
};

// Class CObject3D_AnimGen

inline int CObject3D_AnimGen::iGetNumStates ()
{
    return( iNumStates );
}

inline int CObject3D_AnimGen::iGetLastFrame ()
{
    return( 0 );
}

#endif // ifndef CObject3D_AnimGen_h
