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
// CSkyDome
#include "SkyDome\CSkyDome.h"

// Class CSkyDome

CSkyDome::CSkyDome()
    : fRadius(0.0f), fRot(0.0f), FogAffected(false)
{
}

CSkyDome::~CSkyDome()
{
}

void CSkyDome::SetRotation (float _fRot)
{
    fRot = _fRot;
}

void CSkyDome::SetRadius (float _fRadius)
{
    fRadius = _fRadius;
}

void CSkyDome::SetAxis (CGVect3 _Axis)
{
    Axis.Assign(_Axis);
}

void CSkyDome::SetPosition (CGVect3 _Pos)
{
    Pos.Assign(_Pos);
}

void CSkyDome::CreateDome (bool _bFogAffected, int _iNumVSlices, int _iNumHSlices, int _iStartVSlice, int _iEndVSlice, float _fUTiling, float _fVTiling)
{
    m_poSkyDomeMesh = mNew CGMesh();
    m_poSkyDomeMesh->Init( (_iEndVSlice - _iStartVSlice) * (_iNumHSlices + 1) * 2,
                 (_iEndVSlice - _iStartVSlice) * (_iNumHSlices + 1) * 2 - 2,
                 E3D_PrimitiveType::E3D_PT_NITRISTRIP,
                 MESH_FIELD_VERTEXS | MESH_FIELD_UVCOORDS );

    int cI,cJ,iIdx;

    float theta1,theta2,theta3;
    float cs_t1,cs_t2,cs_t3;
    float sn_t1,sn_t2,sn_t3;

    float x1,y1,z1;
    float x2,y2,z2;
    float u,v;

    float fRhoStep = (_PI_) / _iNumVSlices;
    float fPhiStep = (_2PI_) / _iNumHSlices;

    float fUStep = 1.0f / (float)_iNumHSlices;
    float fVStep = -1.0f / (float)(_iNumVSlices >> 1);

    iIdx = 0;

    v = 1.0f;
    theta1 = (float)_iStartVSlice * fRhoStep - _PI2_;
    theta2 = theta1 + fRhoStep;

    for ( cJ = _iStartVSlice; cJ < _iEndVSlice; cJ++ )
    {
        cs_t1 = Math::fCos(theta1);
        cs_t2 = Math::fCos(theta2);
        sn_t1 = Math::fSin(theta1);
        sn_t2 = Math::fSin(theta2);

        u = 0;
        theta3 = 0.0f;

        for ( cI = 0; cI <= _iNumHSlices; cI++ )
        {
            cs_t3 = Math::fCos(theta3);
            sn_t3 = Math::fSin(theta3);

            x1 = cs_t1 * cs_t3;
            y1 = cs_t1 * sn_t3;
            z1 = sn_t1;

            x2 = cs_t2 * cs_t3;
            y2 = cs_t2 * sn_t3;
            z2 = sn_t2;

            m_poSkyDomeMesh->m_poVX[iIdx].Set(x1,y1,z1);
            m_poSkyDomeMesh->m_poUV[iIdx].Set(u * _fUTiling,v * _fVTiling);
            iIdx++;

            m_poSkyDomeMesh->m_poVX[iIdx].Set(x2,y2,z2);
            m_poSkyDomeMesh->m_poUV[iIdx].Set(u * _fUTiling,(v + fVStep) * _fVTiling);

            iIdx++;

            u += fUStep;
            theta3 += fPhiStep;
        }

        v += fVStep;
        if ( v == 0.0f )
            fVStep *= -1.0f;

        theta1 += fRhoStep;
        theta2 += fRhoStep;
    }

    // Fog affects skydome?
    FogAffected = _bFogAffected;
    SetMesh(m_poSkyDomeMesh);
}

void CSkyDome::Render ()
{
    if ( !FogAffected )
        CGRenderer::I()->SetFogPars(E3D_FM_None,0,0,0,NULL);

    CGRenderer::I()->PushWorldMatrix();

    CGMatrix4x4 oM;
    oM.LoadIdentity();
    oM.Translate(Pos.x,Pos.y,Pos.z);
    oM.RotateFromArbitraryAxis(fRot,Axis.x,Axis.y,Axis.z);
    oM.Scale(fRadius,fRadius,fRadius);

    CGRenderer::I()->MultiplyMatrix(oM);

    CGSCNVRenderer::I()->Render(this);

    CGRenderer::I()->PopWorldMatrix();

    if ( !FogAffected )
        CGRenderer::I()->SetFogPars(E3D_FM_Last,0,0,0,NULL);
}

// Additional Declarations
