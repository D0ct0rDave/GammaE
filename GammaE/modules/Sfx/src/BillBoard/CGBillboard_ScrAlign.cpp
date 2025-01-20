




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
    CMatrix4x4	 M,M1;
	CE3D_Camera	*Cam = CGRenderer::I()->GetCamera();
	
	CVect3 e1,e2,e3;
	// e1.Assign(Cam->Side);	e1.Scale(-1);
	e2.Assign(Cam->Up  );	e2.Scale( 1);
	e3.Assign(Cam->Dir );	e3.Scale(-1);
	e1.CrossProd(e2,e3);
	M.LoadFromAxis(e1,e2,e3);

	CGRenderer::I()->GetWorldMatrix(&M1);	

	M1.Set(0,3,0);	M1.Set(1,3,0);	M1.Set(2,3,0);
	M1.Transpose();

	CGRenderer::I()->PushWorldMatrix();

		CGRenderer::I()->MultiplyMatrix(&M);
		CObject3D_Node::Render();

	CGRenderer::I()->PopWorldMatrix();
}

// Additional Declarations
    
