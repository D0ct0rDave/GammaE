//	  %X% %Q% %Z% %W%

#ifndef CObject3D_Link_h
#define CObject3D_Link_h 1

// CObject3D_Warehouse
#include "Scene\CObject3D_Warehouse.h"
// CObject3D_Gen
#include "Scene\CObject3D_Gen.h"

//	Util para tener referencias a objetos en el mundo, o en
//	un fichero. Las referencias son a objetos almacenados en
//	la Warehouse de los objetos.

class CObject3D_Link : public CObject3D_Gen
{

public: CObject3D_Link();

    virtual ~CObject3D_Link();

    void Link (int _iObjWHIdx, CObject3D_Warehouse *_pObjWH);

    void Unlink ();

    virtual CGraphBV *poGetBoundVol ();

    virtual void ComputeBoundVol ();

    virtual void Render ();

     // Additional Public Declarations
protected:
    // Data Members for Class Attributes

    int iObjWHIdx;

    CObject3D_Warehouse *pObjWH;

     // Additional Protected Declarations
private:
     // Additional Private Declarations
private:
    // Additional Implementation Declarations
};

// Class CObject3D_Link

#endif // ifndef CObject3D_Link_h
