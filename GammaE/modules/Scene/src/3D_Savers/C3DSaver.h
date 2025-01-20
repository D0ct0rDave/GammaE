//	  %X% %Q% %Z% %W%

#ifndef C3DSaver_h
#define C3DSaver_h 1

// GammaE_E3D
#include "GammaE_E3D.h"
// CObject3D
#include "CObject3D.h"

class C3DSaver
{

public: C3DSaver();

    ~C3DSaver();

    virtual int iSave (char *_Filename, CObject3D *_pObj) = 0;

     // Additional Public Declarations
protected:
     // Additional Protected Declarations
private:
     // Additional Private Declarations
private:
    // Additional Implementation Declarations
};

// Class C3DSaver

#endif
