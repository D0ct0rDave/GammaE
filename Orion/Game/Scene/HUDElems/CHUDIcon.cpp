#include "CHUDIcon.h"

CHUDIcon::CHUDIcon()
{
	Init(1);

	CMesh_Rect	*poMesh;
	poMesh = mNew CMesh_Rect;	
	
	poLeaf = mNew CObject3D_Leaf;
	poLeaf->SetMesh(poMesh);
	poLeaf->ComputeBoundVol();
	
	iAddObject(poLeaf);
	ComputeBoundVol();
}

CHUDIcon::~CHUDIcon()
{
}

void CHUDIcon::SetIcon(CE3D_Shader *_poShader)
{
	poLeaf->SetShader(_poShader);
}

void CHUDIcon::Enable()
{
	SelectAll();
}

void CHUDIcon::Disable()
{
	SelectNone();
}

void CHUDIcon::SetVisible(bool _bShow)
{
	if (_bShow) Enable(); else Disable();
}

