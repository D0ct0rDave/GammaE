// ----------------------------------------------------------------------------
#ifndef CObject3D_Mux_h
#define CObject3D_Mux_h 1
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "CObject3D_Node.h"
// ----------------------------------------------------------------------------
class CObject3D_Mux : public CObject3D_Node
{
public: CObject3D_Mux();

    virtual ~CObject3D_Mux();

    virtual void Init(uint _uiMaxSubObjects);

    virtual void Render();

    void SelectAll();

    void SelectNone();

    void Select(uint _uiIdx);

    void Deselect(uint _uiIdx);

    bool bIsSelected(uint _uiIdx);
protected:
    bool *m_bSelected;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
