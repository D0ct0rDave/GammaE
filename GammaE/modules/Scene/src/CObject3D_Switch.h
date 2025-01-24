// ----------------------------------------------------------------------------
#ifndef CObject3D_Switch_h
#define CObject3D_Switch_h 1
// ----------------------------------------------------------------------------
#include "CObject3D.h"
// ----------------------------------------------------------------------------
class CObject3D_Switch : public CObject3D
{
public: CObject3D_Switch() : m_bEnabled(true),m_poObj(NULL)
    {
    };

    virtual ~CObject3D_Switch();

     /// Sets the object linked to this node
    void SetObject(CObject3D *_poObj)
    {
        if (m_poObj)
            m_poObj->Deref();

        m_poObj = _poObj;

        if (m_poObj != NULL)
            m_poObj->Ref();
    };

     /// Retrieves the object linked to this node
    CObject3D *poGetObject()
    {
        return( m_poObj );
    };

     /// Renders the geometry associated to this node
    virtual void Render();

     /// Enables or disables the rendering of this node. By default enables it
    void Enable(bool _bEnable = true)
    {
        m_bEnabled = _bEnable;
    };

     /// Disables the rendering of this node
    void Disable()
    {
        m_bEnabled = false;
    };

     /// Retrieves whether this node is enabled for rendering or not
    bool bEnabled()
    {
        return( m_bEnabled );
    };

     /// Recomputes the bounding volume associated to this node
    virtual void ComputeBoundVol();

     /// Retrieves the bounding volume of this node
    virtual CGraphBV *poGetBoundVol();
protected:
     /// Creates the bounding volume for this node
    virtual CGraphBV *poCreateBoundVol();

    CObject3D *m_poObj;
    bool m_bEnabled;
};
// ----------------------------------------------------------------------------
#endif // ifndef CObject3D_Switch_h
// ----------------------------------------------------------------------------
