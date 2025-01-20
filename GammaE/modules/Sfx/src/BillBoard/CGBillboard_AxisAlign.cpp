




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
	if (x) Flags |= 0x01;
	if (y) Flags |= 0x02;
	if (z) Flags |= 0x04;
}

void CGBillboard_AxisAlign::Render ()
{
  	CVect3		 InvPos;
	CMatrix4x4	 M;
	CE3D_Camera	*Cam = CGRenderer::I()->GetCamera();
	
	if (Flags & 0x01) InvPos.x = -Cam->Pos.x; else  InvPos.x = 0;
	if (Flags & 0x02) InvPos.y = -Cam->Pos.y; else  InvPos.y = 0;
	if (Flags & 0x04) InvPos.z = -Cam->Pos.z; else  InvPos.z = 0;

	CGRenderer::I()->PushWorldMatrix();

		CMatrix4x4 oM;
		oM.LoadIdentity();
		oM.Translate(InvPos.x,InvPos.y,InvPos.z);

		CGRenderer::I()->MultiplyMatrix(&oM);

		CObject3D_Node::Render();

	CGRenderer::I()->PopWorldMatrix();
}

// Additional Declarations
    
