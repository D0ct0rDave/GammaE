//-----------------------------------------------------------------------------
#include "CHUDIcon.h"
//-----------------------------------------------------------------------------
CHUDIcon::CHUDIcon()
{
  	eGraphBV_TypeID eOldType = CGraphBV_Manager::eGetBVMode();
	CGraphBV_Manager::SetBVMode(eGraphBV_Box);
	
		CMesh_Rect	*poMesh;
		poMesh = mNew CMesh_Rect;
		
		poLeaf = mNew CObject3D_Leaf;
		poLeaf->SetMesh(poMesh);

		SetObject(poLeaf);

	CGraphBV_Manager::SetBVMode(eOldType);	
	ComputeBoundVol();
}
//-----------------------------------------------------------------------------
CGraphBV* CHUDIcon::poCreateBoundVol ()
{
  	eGraphBV_TypeID eOldType = CGraphBV_Manager::eGetBVMode();
	CGraphBV_Manager::SetBVMode(eGraphBV_Box);

  		CGraphBV* poBVol = CGraphBV_Manager::poCreate();
	
	CGraphBV_Manager::SetBVMode(eOldType);	

	return(poBVol);
}
//-----------------------------------------------------------------------------
CHUDIcon::~CHUDIcon()
{
	// CObject3D_Mux::~CObject3D_Mux();
}
//-----------------------------------------------------------------------------
void CHUDIcon::SetIcon(CE3D_Shader *_poShader)
{
	poLeaf->SetShader(_poShader);
}
//-----------------------------------------------------------------------------