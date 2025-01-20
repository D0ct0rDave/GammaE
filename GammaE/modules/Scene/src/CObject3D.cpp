// CObject3D
#include "CObject3D.h"

// Class CObject3D

CObject3D::CObject3D()
    : BVol(NULL), bFrustumTest(false)
{
    TypeID   = e3DObj_Gen;
}

CObject3D::~CObject3D()
{
}

void CObject3D::Deref ()
{
   CGReferenceCounter::Deref();

    if (m_uiNumRefs == 0)
        mDel this;
}

bool CObject3D::bVisible ()
{
    if ( CGRenderer::I()->UsingFrustumCulling() )
    {
        if (!bFrustumTest) return( true );

        return ( poGetBoundVol()->TestFrustum( CGRenderer::I()->GetLocalFrustum() ) );
    }
    else
        return( true );
}

// Additional Declarations
