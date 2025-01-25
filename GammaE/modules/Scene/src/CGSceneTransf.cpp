// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#include "GammaE_E3D.h"
// ----------------------------------------------------------------------------
#include "CGSceneTransf.h"
// ----------------------------------------------------------------------------
CGSceneTransf::CGSceneTransf() :
    m_poObj(NULL)
{
    m_eNodeType = SNT_Transf;

    m_oPos.V3 (0.0f,0.0f,0.0f);
    m_oSide.Set(1.0f,0.0f,0.0f);
    m_oDir.V3 (0.0f,1.0f,0.0f);
    m_oUp.V3  (0.0f,0.0f,1.0f);

    m_oTransf.LoadIdentity();
}
// ----------------------------------------------------------------------------
CGSceneTransf::~CGSceneTransf()
{
    if ( m_poObj ) m_poObj->Deref();
    if ( m_poBV ) mDel m_poBV;
}
// ----------------------------------------------------------------------------
void CGSceneTransf::SetPos (const CGVect3& _oPos)
{
    m_oPos.Assign(_oPos);
    SetupTransformation();
}
// ----------------------------------------------------------------------------
const CGVect3& CGSceneTransf::oPos()
{
    return (m_oPos);
}
// ----------------------------------------------------------------------------
void CGSceneTransf::SetDir (const CGVect3& _oDir)
{
    m_oDir.Assign(_oDir);
    SetupTransformation();
}
// ----------------------------------------------------------------------------
const CGVect3& CGSceneTransf::oDir ()
{
    return(m_oDir);
}
// ----------------------------------------------------------------------------
void CGSceneTransf::SetUp (const CGVect3& _oUp)
{
    m_oUp.Assign(_oUp);
    SetupTransformation();
}
// ----------------------------------------------------------------------------
const CGVect3& CGSceneTransf::oUp ()
{
    return(m_oUp);
}
// ----------------------------------------------------------------------------
void CGSceneTransf::SetSide (const CGVect3& _oSide)
{
    m_oSide.Assign(_oSide);
    SetupTransformation();
}
// ----------------------------------------------------------------------------
const CGVect3& CGSceneTransf::oSide ()
{
    return(m_oSide);
}
// ----------------------------------------------------------------------------
void CGSceneTransf::Setup (const CGVect3& _oPos, const CGVect3& _oDir, const CGVect3& _oSide, const CGVect3& _oUp)
{
    m_oPos.Assign(_oPos);
    m_oDir.Assign(_oDir);
    m_oSide.Assign(_oSide);
    m_oUp.Assign(_oUp);

    SetupTransformation();
}
// ----------------------------------------------------------------------------
void CGSceneTransf::SetTransf (const CGMatrix4x4& _oTransf)
{
    CVect4 oP = _oTransf.GetColVector(3);
    CVect4 oS = _oTransf.GetColVector(0);                    // X
    CVect4 oD = _oTransf.GetColVector(1);                    // Y
    CVect4 oU = _oTransf.GetColVector(2);                    // Z

    m_oPos.Set(oP.x,oP.y,oP.z);
    m_oSide.Set(oS.x,oS.y,oS.z);
    m_oDir.Set(oD.x,oD.y,oD.z);
    m_oUp.Set(oU.x,oU.y,oU.z);

    m_oTransf = _oTransf;

    // Recompute Bounding Volume
    m_poBV->Copy( m_poObj->poGetBV() );
    m_poBV->Transform(m_oTransf);
}
// ----------------------------------------------------------------------------
void CGSceneTransf::SetObject (CGSceneNode* _poObj)
{
    assert (_poObj && "NULL Object");

    if ( m_poObj )
        m_poObj->Deref();

    m_poObj = _poObj;

    if ( m_poObj != NULL )
        m_poObj->Ref();
}
// ----------------------------------------------------------------------------
CGSceneNode* CGSceneTransf::poGetObject ()
{
    return (m_poObj);
}
// ----------------------------------------------------------------------------
void CGSceneTransf::SetupTransformation ()
{
    // Setup transformation matrix from separate vectors
    m_oTransf.SetCol(0,m_oSide.x,m_oSide.y,m_oSide.z,0.0f);
    m_oTransf.SetCol(1,m_oDir.x,m_oDir.y,m_oDir.z,0.0f);
    m_oTransf.SetCol(2,m_oUp.x,m_oUp.y,m_oUp.z,0.0f);
    m_oTransf.SetCol(3,m_oPos.x,m_oPos.y,m_oPos.z,1.0f);

    // Recompute Bounding Volume
    m_poBV->Copy( m_poObj->poGetBV() );
    m_poBV->Transform(m_oTransf);
}
// ----------------------------------------------------------------------------
