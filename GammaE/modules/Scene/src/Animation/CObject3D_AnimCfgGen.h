//	  %X% %Q% %Z% %W%

#ifndef CObject3D_AnimCfgGen_h
#define CObject3D_AnimCfgGen_h 1

// CObject3D
#include "CObject3D.h"

class CObject3D_AnimCfgGen : public CObject3D
{

public: CObject3D_AnimCfgGen();

    virtual ~CObject3D_AnimCfgGen();

    virtual CGraphBV *poCreateBoundVol ()
    {
        return( CGraphBV_Manager::poCreate() );
    };

    virtual void SetFrameAnim (int iFrameAnim) = 0;

     // Additional Public Declarations
protected:
     // Additional Protected Declarations
private:
     // Additional Private Declarations
private:
    // Additional Implementation Declarations
};

// Class CObject3D_AnimCfgGen

#endif
