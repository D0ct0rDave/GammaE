// ----------------------------------------------------------------------
#include "CObject3D_BSPNode.h"
// ----------------------------------------------------------------------
CObject3D_BSPNode::CObject3D_BSPNode() : poBackNode(NULL), poFrontNode(NULL)
{
    TypeID          =  e3DObj_BSPNode;
    BVol            = poCreateBoundVol();
    bFrustumTest    = true;
}
// ----------------------------------------------------------------------
CObject3D_BSPNode::~CObject3D_BSPNode()
{
}
// ----------------------------------------------------------------------
void CObject3D_BSPNode::Render ()
{
   float fCamPlaneAngle;
   float fCamPlaneDist;
   CE3D_Camera     *poCam;
   float fFOV;
   float fAngleLimit;

    poCam      = CGRenderer::I()->GetCamera();
    fFOV       = CGRenderer::I()->GetProjector()->fFOV;

     // Get the angle between the camera and the plane
    fCamPlaneAngle = oPartitionPlane.Normal().fDotProd( poCam->Dir );

     // Test the side of the plane the camera is
    if ( MATH_Utils::iTestPointPlane(poCam->Pos,oPartitionPlane) >= 0)
    {
         // The camera is in the front half space of the plane
        fAngleLimit = cos( ( 90.0f - fFOV * 0.5f ) * _PI_OVER_180_ );     // cos(90 - Fov/2);

         // The camera could see part of the back space of the plane?
         // if (fCamPlaneAngle < fAngleLimit)
        if (poBackNode)
            if ( poBackNode->bVisible() )
                poBackNode->Render();

        if (poFrontNode)
            poFrontNode->Render();
    }
    else
    {
         // The camera is in the back half space of the plane
        fAngleLimit = cos( ( 90.0f + fFOV * 0.5f ) * _PI_OVER_180_ );

         // The camera could see part of the front space of the plane?
         // if (fCamPlaneAngle > fAngleLimit)
        if (poFrontNode)
            if ( poFrontNode->bVisible() )
                poFrontNode->Render();                                                                                                                                                                                                                                                                                                                                                                                              // farthest area in rendering

         // Back to front display
        if (poBackNode)
            poBackNode->Render();
    }
} // Render
// ----------------------------------------------------------------------
CGraphBV *CObject3D_BSPNode::poCreateBoundVol()
{
    return ( CGraphBV_Manager::poCreate() );
}
// ----------------------------------------------------------------------
CGraphBV *CObject3D_BSPNode::poGetBoundVol ()
{
    return ( BVol );
}
// ----------------------------------------------------------------------
void CObject3D_BSPNode::ComputeBoundVol ()
{

    // Las bounding boxes de los objetos deben tener en cuenta
    // las transformaciones que se deben realizar en los nodos
    // hijos. Probar a transformar la BoundingBox mediante la
    // matriz asociada al nodo. Despues volver a obtener
    // los max y los mins, para volver a tener una AABB

    int cObj;
    float fXSide,fYSide,fZSide;
    CVect3 Maxs,Mins,Center;
    CGraphBV        *BV;
    CObject3D       *poSubObjs[2];

    poSubObjs[0] = poFrontNode;
    poSubObjs[1] = poBackNode;

    Mins.V3( 1e10f, 1e10f, 1e10f);
    Maxs.V3(-1e10f,-1e10f,-1e10f);

    for (cObj = 0; cObj < 2; cObj++)
    {
        if (poSubObjs[cObj])
        {
             // Compute the AABB for the object
            poSubObjs[cObj]->ComputeBoundVol();
            BV = poSubObjs[cObj]->poGetBoundVol();

             // Get object properties
            fXSide = BV->GetRange(0) * 0.5f;
            fYSide = BV->GetRange(1) * 0.5f;
            fZSide = BV->GetRange(2) * 0.5f;
            Center = BV->GetCenter();

             // Compute Maxs/Mins vectors
            if ( Center.x + fXSide > Maxs.x ) Maxs.x = Center.x + fXSide;

            if ( Center.x - fXSide < Mins.x ) Mins.x = Center.x - fXSide;

            if ( Center.y + fYSide > Maxs.y ) Maxs.y = Center.y + fYSide;

            if ( Center.y - fYSide < Mins.y ) Mins.y = Center.y - fYSide;

            if ( Center.z + fZSide > Maxs.z ) Maxs.z = Center.z + fZSide;

            if ( Center.z - fZSide < Mins.z ) Mins.z = Center.z - fZSide;
        }
    }

    BVol->Init(Maxs,Mins);
} // ComputeBoundVol
// ----------------------------------------------------------------------
void CObject3D_BSPNode::Setup (CObject3D *_poBack, CObject3D *_poFront, CPlane & _oPlane)
{
    poBackNode       = _poBack;
    poFrontNode      = _poFront;
    oPartitionPlane  = _oPlane;
}
// ----------------------------------------------------------------------
void CObject3D_BSPNode::SetBackNode (CObject3D *_poBack)
{
    poBackNode = _poBack;
}
// ----------------------------------------------------------------------
void CObject3D_BSPNode::SetFrontNode (CObject3D *_poFront)
{
    poFrontNode = _poFront;
}
// ----------------------------------------------------------------------
CObject3D *CObject3D_BSPNode::poGetBackNode ()
{
    return( poBackNode );
}
// ----------------------------------------------------------------------
CObject3D *CObject3D_BSPNode::poGetFrontNode ()
{
    return ( poFrontNode );
}
// ----------------------------------------------------------------------
void CObject3D_BSPNode::SetPartitionPlane (CPlane &_oPlane)
{
    oPartitionPlane = _oPlane;
}
// ----------------------------------------------------------------------
CPlane *CObject3D_BSPNode::poGetPartitionPlane ()
{
    return ( &oPartitionPlane );
}
// ----------------------------------------------------------------------
