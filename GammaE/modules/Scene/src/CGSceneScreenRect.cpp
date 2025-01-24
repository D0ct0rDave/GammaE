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
#include "GammaE_Mem.h"
#include "CGSceneScreenRect.h"
// ----------------------------------------------------------------------------
CGSceneScreenRect::CGSceneScreenRect() :
    m_poShader(NULL)
{
    m_eNodeType = SNT_ScreenRect;
    m_poMesh = mNew CGMeshRect;

    m_oMat.LoadIdentity();
    m_oMat.Set(1,1,-1.0f);
}
// ----------------------------------------------------------------------------
CGSceneScreenRect::~CGSceneScreenRect()
{
    mDel m_poMesh;
    m_poMesh = NULL;
}
// ----------------------------------------------------------------------------
void CGSceneScreenRect::SetRect(float _fX,float _fY,float _fTX,float _fTY)
{
    /*
       m_oMat.LoadIdentity();
       m_oMat.Translate(-1.0f,1.0f,0.0f);
       m_oMat.Translate(_fX/0.5f,-_fY/0.5f,0.0f);
       m_oMat.Scale(_fTX,_fTY,1);
       m_oMat.Translate(1.0f,-1.0f,0.0f);
       m_oMat.Scale(2.0f,2.0f,1);
       m_oMat.Scale(1.0f/_fTX,-1.0f/_fTY,1.0f);
       m_oMat.Translate(_fX,_fY,0.0f);
     */
    // m_oMat.LoadIdentity();
    // m_oMat.Scale(_fTX,-_fTY,1.0f);
    // m_oMat.Translate(_fX - 2.0f*_fTX,_fY - 2.0f*_fTY,0.0f);

    // ComputeBoundVol();
}
// ----------------------------------------------------------------------------
