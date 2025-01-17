#include "CTRNShadow.h"
#include "Game/GameGlobals/GameGlobals.h"
#include "TRN/CTRNNeighs.h"

CMesh	*gpoMesh;
/*********************************************************************

*********************************************************************/
CTRNShadow::CTRNShadow()
{
	//goTRNMesh.Init(2048*3,2048,E3D_MESH_TRISTRIPS,
}

/*********************************************************************

*********************************************************************/
CTRNShadow::~CTRNShadow()
{
	
}

/*********************************************************************

*********************************************************************/
void CTRNShadow::Setup(CObject3D *_poObj)
{
	CVect3 oPos;
	oPos.Assign( _poObj->poGetBoundVol()->GetCenter() );
	oPos.SetZ(/*os.Z()*/ 1000.0f);
	gpoMesh = CTRNNeighs::GetNeighs(oPos,25.0f);

	goShadowCaster.Setup(oPos,_poObj,&gpoMesh,1);
}

void CTRNShadow::Render()
{
	// goRenderer.SetZPars(eE3D_ZTF_None,eE3D_ZW_Disable);
	goRenderer.SetFogPars(eE3D_FM_None,0,0,0,NULL);

	goShadowCaster.Render();
	
	goRenderer.SetFogPars(eE3D_FM_Last,0,0,0,NULL);
	// goRenderer.SetZPars(eE3D_ZTF_Last,eE3D_ZW_Last);
}
/*********************************************************************

*********************************************************************/
