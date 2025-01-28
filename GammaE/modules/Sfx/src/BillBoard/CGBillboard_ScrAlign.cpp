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
// CGBillboard_ScrAlign
#include "Billboard\CGBillboard_ScrAlign.h"

// Class CGBillboard_ScrAlign

CGBillboard_ScrAlign::CGBillboard_ScrAlign()
{
}

CGBillboard_ScrAlign::~CGBillboard_ScrAlign()
{
}

void CGBillboard_ScrAlign::Render ()
{
    CGMatrix4x4 M,M1;
    CGCamera* Cam = CGRenderer::I()->poGetCamera();

    CGVect3 e1,e2,e3;
    // e1.Assign(Cam->Side);	e1.Scale(-1);
    e2.Assign(Cam->oGetUp());
    e2.Scale( 1);
    e3.Assign(Cam->oGetDir());
    e3.Scale(-1);
    e1.CrossProd(e2,e3);
    M.LoadFromAxes(e1,e2,e3);

    CGRenderer::I()->GetWorldMatrix(&M1);

    M1.Set(0,3,0);
    M1.Set(1,3,0);
    M1.Set(2,3,0);
    M1.Transpose();

    CGRenderer::I()->PushWorldMatrix();

    CGRenderer::I()->MultiplyMatrix(M);
    
    CGSCNVRenderer::I()->Render(this);

    CGRenderer::I()->PopWorldMatrix();
}

// Additional Declarations
