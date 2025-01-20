//	  %X% %Q% %Z% %W%

#ifndef C3DLoader_h
#define C3DLoader_h 1

// GammaE_E3D
#include "GammaE_E3D.h"
// CObject3D
#include "CObject3D.h"

class C3DLoader
{

public: C3DLoader();

    ~C3DLoader();

    virtual CObject3D *pLoad (char *Filename) = 0;

     // Additional Public Declarations
protected:
     // Additional Protected Declarations
private:
     // Additional Private Declarations
private:
    // Additional Implementation Declarations
};

// Class C3DLoader

#endif
