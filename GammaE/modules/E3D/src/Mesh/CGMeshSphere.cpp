// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// CGMesh_Sphere
#include "Mesh\CGMeshSphere.h"
// ----------------------------------------------------------------------------
CGMeshSphere::CGMeshSphere()
{
    Init(16,1.0f);
}

CGMeshSphere::CGMeshSphere (int _iNumSlices, float _fRadius)
{
    Init(_iNumSlices,_fRadius);
}

CGMeshSphere::~CGMeshSphere()
{
}

void CGMeshSphere::Init (int _iNumSlices, float _fRadius)
{
    CGMesh::Init(_iNumSlices * _iNumSlices * 2,_iNumSlices * _iNumSlices * 2 - 2,
                 E3D_PT_NITRISTRIP,MESH_FIELD_ALL);

    int cI,cJ,iIdx;

    float theta1,theta2,theta3;
    float cs_t1,cs_t2,cs_t3;
    float sn_t1,sn_t2,sn_t3;

    float x1,y1,z1;
    float x2,y2,z2;
    float u,v;

    float fRhoStep = (_PI_) / (_iNumSlices);
    float fPhiStep = (_2PI_) / _iNumSlices;

    float fUStep = 1.0f / _iNumSlices;
    float fVStep = 1.0f / _iNumSlices;

    iIdx = 0;

    v = 0.0f;
    theta1 = -_PI2_;
    theta2 = theta1 + fRhoStep;

    for ( cJ = 0; cJ < _iNumSlices; cJ++ )
    {
        cs_t1 = Math::fCos(theta1);
        cs_t2 = Math::fCos(theta2);
        sn_t1 = Math::fSin(theta1);
        sn_t2 = Math::fSin(theta2);

        u = 0;
        theta3 = 0.0f;

        for ( cI = 0; cI < _iNumSlices; cI++ )
        {
            cs_t3 = Math::fCos(theta3);
            sn_t3 = Math::fSin(theta3);

            x1 = _fRadius * cs_t1 * cs_t3;
            y1 = _fRadius * cs_t1 * sn_t3;
            z1 = _fRadius * sn_t1;

            x2 = _fRadius * cs_t2 * cs_t3;
            y2 = _fRadius * cs_t2 * sn_t3;
            z2 = _fRadius * sn_t2;

            m_poVX[iIdx].Set(x1,y1,z1);
            m_poUV[iIdx].Set(u,v);
            m_poVC[iIdx].Set(1.0f,1.0f,1.0f,1.0f);
            m_poVN[iIdx].Assign(m_poVX[iIdx]);    // VN = Normalized(Pos - Origin) // Origin=(0,0,0)
            m_poVN[iIdx].Normalize();
            iIdx++;

            m_poVX[iIdx].Set(x2,y2,z2);
            m_poUV[iIdx].Set(u,v + fVStep);
            m_poVC[iIdx].Set(1.0f,1.0f,1.0f,1.0f);
            m_poVN[iIdx].Assign(m_poVX[iIdx]);    // VN = Normalized(Pos - Origin) // Origin=(0,0,0)
            m_poVN[iIdx].Normalize();
            iIdx++;

            u += fUStep;
            theta3 += fPhiStep;
        }

        v += fVStep;
        theta1 += fRhoStep;
        theta2 += fRhoStep;
    }
}
// ----------------------------------------------------------------------------
