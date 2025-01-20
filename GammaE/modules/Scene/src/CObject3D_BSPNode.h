// ----------------------------------------------------------------------
#ifndef CObject3D_BSPNode_h
#define CObject3D_BSPNode_h 1
// ----------------------------------------------------------------------
#include "CObject3D.h"
// ----------------------------------------------------------------------
class CObject3D_BSPNode : public CObject3D
{
public: CObject3D_BSPNode();

    virtual ~CObject3D_BSPNode();

    virtual void Render ();

    virtual CGraphBV *poCreateBoundVol();

    virtual CGraphBV *poGetBoundVol ();

    virtual void ComputeBoundVol ();

    void Setup (CObject3D *_poBack, CObject3D *_poFront, CPlane & _oPlane);

    void SetBackNode (CObject3D *_poBack);

    void SetFrontNode (CObject3D *_poFront);

    CObject3D *poGetBackNode ();

    CObject3D *poGetFrontNode ();

    void SetPartitionPlane (CPlane &_oPlane);

    CPlane *poGetPartitionPlane ();
protected:
    CObject3D *poBackNode;

    CObject3D *poFrontNode;

    CPlane oPartitionPlane;
};
// ----------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------
