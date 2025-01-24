// ----------------------------------------------------------------------------
#include <string.h>
#include "GammaE_Mem.h"
// ----------------------------------------------------------------------------
#include "CObject3D_Switch.h"
// ----------------------------------------------------------------------------
CObject3D_Switch::~CObject3D_Switch()
{
    if (m_poObj)
        m_poObj->Deref();
}
// ----------------------------------------------------------------------------
CGraphBV *CObject3D_Switch::poCreateBoundVol()
{
    return( NULL );
}
// ----------------------------------------------------------------------------
void CObject3D_Switch::ComputeBoundVol()
{
    if (!m_poObj) return;

    m_poObj->ComputeBoundVol();
}
// ----------------------------------------------------------------------------
CGraphBV *CObject3D_Switch::poGetBoundVol()
{
    if (!m_poObj) return( NULL );

    return( m_poObj->poGetBoundVol() );
}
// ----------------------------------------------------------------------------
void CObject3D_Switch::Render()
{
    if (m_poObj)
        m_poObj->Render();
}
// ----------------------------------------------------------------------------
