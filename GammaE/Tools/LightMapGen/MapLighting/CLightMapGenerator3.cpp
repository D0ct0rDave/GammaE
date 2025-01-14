//## begin module%3CD4FA30005C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CD4FA30005C.cm

//## begin module%3CD4FA30005C.cp preserve=no
//## end module%3CD4FA30005C.cp

//## Module: CLightMapGenerator3%3CD4FA30005C; Pseudo Package body
//## Source file: i:\Projects\GammaE\Tools\LightMapGen\MapLighting\CLightMapGenerator3.cpp

//## begin module%3CD4FA30005C.additionalIncludes preserve=no
//## end module%3CD4FA30005C.additionalIncludes

//## begin module%3CD4FA30005C.includes preserve=yes
//## end module%3CD4FA30005C.includes

// CLightMapGenerator3
#include "Tools\LightMapGen\MapLighting\CLightMapGenerator3.h"
//## begin module%3CD4FA30005C.additionalDeclarations preserve=yes

typedef CDynArray <CMesh *> TMeshTable;
static TMeshTable	oSMeshes;
//## end module%3CD4FA30005C.additionalDeclarations


// Class CLightMapGenerator3 

//## begin CLightMapGenerator3::oAmbColor%3CD4FA470100.attr preserve=no  private: static TFColor {UA} 
TFColor CLightMapGenerator3::oAmbColor;
//## end CLightMapGenerator3::oAmbColor%3CD4FA470100.attr

//## begin CLightMapGenerator3::poScene%3CD4FA530247.attr preserve=no  private: static CObject3D* {UA} 
CObject3D* CLightMapGenerator3::poScene;
//## end CLightMapGenerator3::poScene%3CD4FA530247.attr

CLightMapGenerator3::CLightMapGenerator3()
  //## begin CLightMapGenerator3::CLightMapGenerator3%.hasinit preserve=no
  //## end CLightMapGenerator3::CLightMapGenerator3%.hasinit
  //## begin CLightMapGenerator3::CLightMapGenerator3%.initialization preserve=yes
  //## end CLightMapGenerator3::CLightMapGenerator3%.initialization
{
  //## begin CLightMapGenerator3::CLightMapGenerator3%.body preserve=yes
  //## end CLightMapGenerator3::CLightMapGenerator3%.body
}


CLightMapGenerator3::~CLightMapGenerator3()
{
  //## begin CLightMapGenerator3::~CLightMapGenerator3%.body preserve=yes
  //## end CLightMapGenerator3::~CLightMapGenerator3%.body
}



//## Other Operations (implementation)
void CLightMapGenerator3::SetAmbientColor (TFColor _roAmbColor)
{
  //## begin CLightMapGenerator3::SetAmbientColor%1020591274.body preserve=yes
	oAmbColor = _roAmbColor;
  //## end CLightMapGenerator3::SetAmbientColor%1020591274.body
}

void CLightMapGenerator3::GenerateLighting (CObject3D* _poScene, CDynArray <CMapEntity *> _oEntities)
{
  //## begin CLightMapGenerator3::GenerateLighting%1020591275.body preserve=yes
	poScene		 = _poScene;

	// First of all clear the etnire scene
	Clear(_poScene);

	// Generate lighting for the scene
	int iEnt;
	for (iEnt=0;iEnt<_oEntities.iNumElems();iEnt++)
	{
		// Clear selected meshes table
		oSMeshes.Clear();
		
		printf ("Entity %d of %d\n",iEnt+1,_oEntities.iNumElems());

		if (_oEntities[iEnt]->eClass == eMapEnt_Light)
		{
			// Setup light physical props			
			GenLitForLight( *(CMapEnt_Light *)_oEntities[iEnt] );
		}
	}

	oSMeshes.Clear();	
  //## end CLightMapGenerator3::GenerateLighting%1020591275.body
}

void CLightMapGenerator3::Clear (CObject3D* _poObj)
{
  //## begin CLightMapGenerator3::Clear%1020591276.body preserve=yes
  	if (! _poObj) return;	

	switch ( _poObj->eGetTypeID() )
	{
		case e3DObj_Leaf:			ClearMesh( ((CObject3D_Leaf*)_poObj)->poGetMesh() );
									break;

		case e3DObj_Node:			int iObj;
									for (iObj=0;iObj<((CObject3D_Node*)_poObj)->iNumSubObjs();iObj++)
										Clear( ((CObject3D_Node*)_poObj)->poGetObject(iObj) );
									break;
		case e3DObj_BSPNode:		Clear( ((CObject3D_BSPNode*)_poObj)->poGetBackNode() );
									Clear( ((CObject3D_BSPNode*)_poObj)->poGetFrontNode() );
									break;
	}

  //## end CLightMapGenerator3::Clear%1020591276.body
}

void CLightMapGenerator3::ClearMesh (CMesh *_poMesh)
{
  //## begin CLightMapGenerator3::ClearMesh%1020591277.body preserve=yes
  	if (! _poMesh)		return;
	if (! _poMesh->VCs) return;
	
	int iVX;		
	for (iVX=0;iVX<_poMesh->usNumVerts;iVX++)
		_poMesh->VCs[iVX].V4(oAmbColor.r,oAmbColor.g,oAmbColor.b,oAmbColor.a);
  //## end CLightMapGenerator3::ClearMesh%1020591277.body
}

void CLightMapGenerator3::GenLitForLight (CMapEnt_Light& _roLight)
{
  //## begin CLightMapGenerator3::GenLitForLight%1020591278.body preserve=yes
	
	
	// Select the meshes inside the light sphere of influence
	CGraphBV_Sphere			oSphere;	
	oSphere.pGetSphere()->Center.Assign(_roLight.oPos);

	if (_roLight.fRadius)
	{
		oSphere.pGetSphere()->Radius = _roLight.fRadius;
	}
	else
		oSphere.pGetSphere()->Radius = 10.0f;
	
	SelectMeshes(oSphere,poScene);


	// From these meshes select only the triangles inside the light action radius
	if(! oSMeshes.iNumElems()) 
		return;


	// Compute lighting for the light vertex based on distance to the light source
  	int		iMesh;
	int		iVX;
	TFColor	DstColor;
	TFColor	SrcColor;
	float	fDist;
	CVect3  oLDir;

	for (iMesh=0;iMesh<oSMeshes.iNumElems();iMesh++)
	{
		for (iVX=0;iVX<oSMeshes[iMesh]->usNumVerts;iVX++)
		{
			oLDir.Assign(_roLight.oPos);
			oLDir.Sub(oSMeshes[iMesh]->VXs[iVX]);
			
			fDist  = oLDir.Module();			
			fDist /= _roLight.fRadius;

			if (fDist <= 1.0f)
			{
				// Angle of incidence of the light to the vertex
				// Light must be attenuated by this
				float fAngFact = 1.0f;
				if (oSMeshes[iMesh]->VNs)
				{
					oLDir.Normalize();
					fAngFact = oLDir.DotProd( oSMeshes[iMesh]->VNs[iVX] );
					if (fAngFact< 0.0f) fAngFact = 0.0f;
					fAngFact *= 3.0f;					
				}
				float fFact = 1.0f - fDist;
				fFact *= (fFact*fFact);	// Increase contrast
				fFact *= 3.0f;			// Increase bright

				DstColor = Color_fn_Scale(_roLight.Color,fFact*fAngFact);

				SrcColor.r = oSMeshes[iMesh]->VCs[iVX].X();
				SrcColor.g = oSMeshes[iMesh]->VCs[iVX].Y();
				SrcColor.b = oSMeshes[iMesh]->VCs[iVX].Z();
				SrcColor.a = oSMeshes[iMesh]->VCs[iVX].W();
					
				DstColor = Color_fn_Add(SrcColor,DstColor);

				oSMeshes[iMesh]->VCs[iVX].V4(DstColor.r,DstColor.g,DstColor.b,DstColor.a);
			}
		}
	}

  //## end CLightMapGenerator3::GenLitForLight%1020591278.body
}

void CLightMapGenerator3::SelectMeshes (CGraphBV_Sphere& _roSphere, CObject3D* _poObj)
{
  //## begin CLightMapGenerator3::SelectMeshes%1020591279.body preserve=yes
  	if (! _poObj) return;	
	
	if (! CCOL_ST_ColTester::iTestCollision(&_roSphere,_poObj->poGetBoundVol())) return;
	
	int iObj;	
	switch ( _poObj->eGetTypeID() )
	{
		case e3DObj_Leaf:			oSMeshes.iAdd( ((CObject3D_Leaf*)_poObj)->poGetMesh() );
									break;

		case e3DObj_Node:			for (iObj=0;iObj<((CObject3D_Node*)_poObj)->iNumSubObjs();iObj++)
										SelectMeshes(_roSphere,((CObject3D_Node*)_poObj)->poGetObject(iObj) );
									break;
		case e3DObj_BSPNode:		SelectMeshes(_roSphere,((CObject3D_BSPNode*)_poObj)->poGetBackNode() );
									SelectMeshes(_roSphere,((CObject3D_BSPNode*)_poObj)->poGetFrontNode() );
									break;
	}
  //## end CLightMapGenerator3::SelectMeshes%1020591279.body
}

// Additional Declarations
  //## begin CLightMapGenerator3%3CD4FA30005C.declarations preserve=yes
  //## end CLightMapGenerator3%3CD4FA30005C.declarations

//## begin module%3CD4FA30005C.epilog preserve=yes
//## end module%3CD4FA30005C.epilog
