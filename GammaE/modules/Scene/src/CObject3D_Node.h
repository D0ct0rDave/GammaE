// ----------------------------------------------------------------------------
#ifndef CObject3D_Node_h
#define CObject3D_Node_h 1
// ----------------------------------------------------------------------------
#include "CObject3D.h"
#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------
class CObject3D_Node : public CObject3D
{

public: CObject3D_Node();

    CObject3D_Node(uint _uiMaxSubObjs);

    virtual ~CObject3D_Node();

    virtual void Init(uint _uiMaxSubObjs);

    virtual void Clear();

    virtual CGraphBV *poCreateBoundVol();

    virtual CGraphBV *poGetBoundVol();

    virtual void ComputeBoundVol();

    void DelObject(uint _uiPos);

    int iAddObject(CObject3D *_poObj);

    virtual void SetObject(CObject3D *_poObj, uint _uiPos);

    CObject3D *poGetObject(uint _uiPos);

    virtual void Render();

    uint uiNumSubObjs();
protected:
     // Data Members for Class Attributes
    CGStArray <CObject3D *> poSubObj;
};
// ----------------------------------------------------------------------------
#endif // ifndef CObject3D_Node_h
// ----------------------------------------------------------------------------
