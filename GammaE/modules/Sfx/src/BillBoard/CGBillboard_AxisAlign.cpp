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
// CGBillboard_AxisAlign
#include "Billboard\CGBillboard_AxisAlign.h"

// Class CGBillboard_AxisAlign

CGBillboard_AxisAlign::CGBillboard_AxisAlign()
{
}

CGBillboard_AxisAlign::~CGBillboard_AxisAlign()
{
}

void CGBillboard_AxisAlign::SetAxis (bool x, bool y, bool z)
{
    Flags = 0;
    if ( x ) Flags |= 0x01;
    if ( y ) Flags |= 0x02;
    if ( z ) Flags |= 0x04;
}

void CGBillboard_AxisAlign::Render ()
{
    CGVect3 InvPos;
    CGMatrix4x4 M;
    CGCamera* Cam = CGRenderer::I()->poGetCamera();

    if ( Flags & 0x01 ) InvPos.x = -Cam->oGetPos().x;
    else InvPos.x = 0;
    if ( Flags & 0x02 ) InvPos.y = -Cam->oGetPos().y;
    else InvPos.y = 0;
    if ( Flags & 0x04 ) InvPos.z = -Cam->oGetPos().z;
    else InvPos.z = 0;

    CGRenderer::I()->PushWorldMatrix();

    CGMatrix4x4 oM;
    oM.LoadIdentity();
    oM.Translate(InvPos.x,InvPos.y,InvPos.z);

    CGRenderer::I()->MultiplyMatrix(oM);

    CGSCNVRenderer::I()->Render(this);

    CGRenderer::I()->PopWorldMatrix();
}

// Additional Declarations
