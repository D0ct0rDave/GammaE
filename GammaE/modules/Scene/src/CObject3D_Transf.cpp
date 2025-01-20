//-----------------------------------------------------------------------------
#include "GammaE_E3D.h"
//-----------------------------------------------------------------------------
#include "CObject3D_Transf.h"
//-----------------------------------------------------------------------------
CObject3D_Transf::CObject3D_Transf()
{
    m_poObj = NULL;

    TypeID       = e3DObj_Transf;

    m_oPos.V3 (0.0f,0.0f,0.0f);

    m_oSide.V3(1.0f,0.0f,0.0f);
    m_oDir.V3 (0.0f,1.0f,0.0f);
    m_oUp.V3  (0.0f,0.0f,1.0f);

    m_oTransf.LoadIdentity();

    BVol         = poCreateBoundVol();
    bFrustumTest = false;
}
//-----------------------------------------------------------------------------
CObject3D_Transf::~CObject3D_Transf()
{
    if (m_poObj) m_poObj->Deref();

    if (BVol) mDel BVol;
}
//-----------------------------------------------------------------------------
void CObject3D_Transf::SetPos (const CVect3 & _oPos)
{
   m_oPos.Assign(_oPos);
    SetupTransformation();
}
//-----------------------------------------------------------------------------
CVect3 & CObject3D_Transf::oPos()
{
    return ( m_oPos );
}
//-----------------------------------------------------------------------------
void CObject3D_Transf::SetDir (const CVect3 & _oDir)
{
   m_oDir.Assign(_oDir);
    SetupTransformation();
}
//-----------------------------------------------------------------------------
CVect3 & CObject3D_Transf::oDir ()
{
    return( m_oDir );
}
//-----------------------------------------------------------------------------
void CObject3D_Transf::SetUp (const CVect3 & _oUp)
{
   m_oUp.Assign(_oUp);
    SetupTransformation();
}
//-----------------------------------------------------------------------------
CVect3 & CObject3D_Transf::oUp ()
{
    return( m_oUp );
}
//-----------------------------------------------------------------------------
void CObject3D_Transf::SetSide (const CVect3 & _oSide)
{
   m_oSide.Assign(_oSide);
    SetupTransformation();
}
//-----------------------------------------------------------------------------
CVect3 & CObject3D_Transf::oSide ()
{
    return( m_oSide );
}
//-----------------------------------------------------------------------------
void CObject3D_Transf::Setup (const CVect3 & _oPos, const CVect3 & _oDir, const CVect3 & _oSide, const CVect3 & _oUp)
{
   m_oPos.Assign(_oPos);
   m_oDir.Assign(_oDir);
   m_oSide.Assign(_oSide);
   m_oUp.Assign(_oUp);

    SetupTransformation();
}
//-----------------------------------------------------------------------------
void CObject3D_Transf::SetTransf (const CMatrix4x4 & _oTransf)
{
   CVect4 oP = _oTransf.GetColVector(3);
   CVect4 oS = _oTransf.GetColVector(0);   // X
   CVect4 oD = _oTransf.GetColVector(1);   // Y
   CVect4 oU = _oTransf.GetColVector(2);   // Z

   m_oPos.V3(oP.x,oP.y,oP.z);
   m_oSide.V3(oS.x,oS.y,oS.z);
   m_oDir.V3(oD.x,oD.y,oD.z);
   m_oUp.V3(oU.x,oU.y,oU.z);

    m_oTransf = _oTransf;

     // Recompute Bounding Volume
    BVol->Copy( m_poObj->poGetBoundVol() );
    BVol->Transform(m_oTransf);
}
//-----------------------------------------------------------------------------
CMatrix4x4 & CObject3D_Transf::oTransf ()
{
    return( m_oTransf );
}
//-----------------------------------------------------------------------------
void CObject3D_Transf::SetObject (CObject3D *_poObj)
{
    assert (_poObj && "NULL Object");

    if (m_poObj)
        m_poObj->Deref();

    m_poObj = _poObj;

    if (m_poObj != NULL)
        m_poObj->Ref();
}
//-----------------------------------------------------------------------------
CObject3D *CObject3D_Transf::poGetObject ()
{
    return ( m_poObj );
}
//-----------------------------------------------------------------------------
void CObject3D_Transf::SetupTransformation ()
{
     // Setup transformation matrix from separate vectors
    m_oTransf.SetColVector(0,m_oSide.x,m_oSide.y,m_oSide.z,0.0f);
    m_oTransf.SetColVector(1,m_oDir.x,m_oDir.y,m_oDir.z,0.0f);
    m_oTransf.SetColVector(2,m_oUp.x,m_oUp.y,m_oUp.z,0.0f);
    m_oTransf.SetColVector(3,m_oPos.x,m_oPos.y,m_oPos.z,1.0f);

     // Recompute Bounding Volume
    BVol->Copy( m_poObj->poGetBoundVol() );
    BVol->Transform(m_oTransf);
}
//-----------------------------------------------------------------------------
CGraphBV *CObject3D_Transf::poCreateBoundVol()
{
    return ( CGraphBV_Manager::poCreate() );
}
//-----------------------------------------------------------------------------
void CObject3D_Transf::ComputeBoundVol ()
{
   m_poObj->ComputeBoundVol();
   BVol->Copy( m_poObj->poGetBoundVol() );
   BVol->Transform(m_oTransf);
}
//-----------------------------------------------------------------------------
CGraphBV *CObject3D_Transf::poGetBoundVol ()
{
    return ( BVol );
}
//-----------------------------------------------------------------------------
void CObject3D_Transf::Render ()
{
   CGRenderer::I()->PushLocalFrustum();
   CGRenderer::I()->PushWorldMatrix();

     // Setup new Ref system
    CGRenderer::I()->MultiplyMatrix(&m_oTransf);

    // Get the local frustum
    /*
       if ((poObj->eGetTypeID() != e3DObj_Leaf) &&
        (poObj->eGetTypeID() != e3DObj_CompiledLeaf))
     */
    CGRenderer::I()->ComputeLocalFrustum();

     // We only can test visibility after performing the camera transformation
    if ( bVisible() )
        m_poObj->Render();

     // Restore current state
    CGRenderer::I()->PopWorldMatrix();
    CGRenderer::I()->PopLocalFrustum();
}
//-----------------------------------------------------------------------------
