// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#include "CGGraphicInstance.h"
#include "CGGraphicResourceWH.h"
#include "GammaE_E3D.h"
// #include "SFX/Special/CSFXObjectFactory.h"
// -----------------------------------------------------------------------------
CGGraphicInstance::CGGraphicInstance() : m_bVisible(false), m_fScale(1.0f),
    m_oPos(0,0,0), m_fPitch(0.0f), m_fYaw(0.0f), m_fRoll(0.0f), m_poResource(NULL), m_bDirty(false), m_oColor(0xffffffff)
{
    m_oMat.LoadIdentity();
}
// -----------------------------------------------------------------------------
CGGraphicInstance::CGGraphicInstance(const CGString& _sResource) : m_bVisible(false), m_fScale(1.0f),
    m_oPos(0,0,0), m_fPitch(0.0f), m_fYaw(0.0f), m_fRoll(0.0f), m_poResource(NULL), m_bDirty(false), m_oColor(0xffffffff)
{
    m_oMat.LoadIdentity();
    Init(_sResource);
}
// -----------------------------------------------------------------------------
CGGraphicInstance::CGGraphicInstance(CGGraphicResource* _poResource) : m_bVisible(false), m_fScale(1.0f),
    m_oPos(0,0,0), m_fPitch(0.0f), m_fYaw(0.0f), m_fRoll(0.0f), m_bDirty(false), m_oColor(0xffffffff)
{
    m_poResource = _poResource;
    m_oMat.LoadIdentity();
}
// -----------------------------------------------------------------------------
CGGraphicInstance::~CGGraphicInstance()
{
}
// -----------------------------------------------------------------------------
/*
   static char sszClassName[MAX_CHARS];

   char* szClassName(char* _szObjName)
   {
    char* szName = _szObjName;

    // Go to the end of the string
    while (*szName) szName++;

    //
    int iLen = strlen(_szObjName) - 1;

    // Go backwards to skip object numbers
    while ((iLen >= 0) && (_szObjName[iLen] >='0') && (_szObjName[iLen]<='9'))
        iLen--;

    // Terminate string
    strncpy(sszClassName,_szObjName,iLen+1);
    sszClassName[iLen+1] = 0;

    return(sszClassName);
   }
 */
// -----------------------------------------------------------------------------
void CGGraphicInstance::Init(const CGString& _sResource)
{
    m_poResource = CGGraphicResourceWH::I()->poLoad(_sResource);
}
// -----------------------------------------------------------------------------
void CGGraphicInstance::UpdateTransform()
{
    if ( m_bDirty == false ) return;

    CGMatrix4x4 oScale;
    oScale.LoadIdentity();
    oScale.Scale(m_fScale,m_fScale,m_fScale);

    CGMatrix4x4 oTrans;
    oTrans.LoadIdentity();
    oTrans.Translate(m_oPos);

    CGMatrix4x4 oRX;
    oRX.LoadIdentity();
    oRX.Rotate('x',m_fPitch);

    CGMatrix4x4 oRY;
    oRY.LoadIdentity();
    oRY.Rotate('y',m_fYaw);

    CGMatrix4x4 oRZ;
    oRZ.LoadIdentity();
    oRZ.Rotate('z',m_fRoll);

    //
    m_oMat = oTrans * oScale * oRX * oRY * oRZ;

    // v' = T*R*S*v
    // Clear flag
    m_bDirty = false;
}
// -----------------------------------------------------------------------------
void CGGraphicInstance::Update(float _fDeltaT)
{
    //
    UpdateTransform();
}
// -----------------------------------------------------------------------------
void CGGraphicInstance::Render()
{
    if ( !m_bVisible ) return;

    if ( m_bDirty )
        UpdateTransform();

    if ( m_poResource )
    {
        CGRenderer::I()->PushWorldMatrix();

        CGRenderer::I()->MultiplyMatrix(m_oMat);

        CGRenderer::I()->SetConstantColor(m_oColor);

        // Render Object
        CGSCNVRenderer::I()->Render(m_poResource->poGetModel());

        CGRenderer::I()->PopWorldMatrix();
    }
}
// -----------------------------------------------------------------------------
void CGGraphicInstance::Visible(bool _bEnable)
{
    m_bVisible = _bEnable;
}
// -----------------------------------------------------------------------------
