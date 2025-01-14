//## begin module%3C8667C4026C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C8667C4026C.cm

//## begin module%3C8667C4026C.cp preserve=no
//## end module%3C8667C4026C.cp

//## Module: CLightMapGenerator2%3C8667C4026C; Pseudo Package body
//## Source file: i:\Projects\GammaE\Tools\LightMapGen\MapLighting\CLightMapGenerator2.cpp

//## begin module%3C8667C4026C.additionalIncludes preserve=no
//## end module%3C8667C4026C.additionalIncludes

//## begin module%3C8667C4026C.includes preserve=yes
#include "memory/gammae_mem.h"
#include "scene/gammae_scene.h"
#include <string.h>
//## end module%3C8667C4026C.includes

// CLightMapGenerator2
#include "Tools\LightMapGen\MapLighting\CLightMapGenerator2.h"
//## begin module%3C8667C4026C.additionalDeclarations preserve=yes

typedef CDynArray <CMesh *> TMeshTable;
static TMeshTable	oSMeshes;

typedef struct{
	CVect3	*poVXs[3];
	CVect4	*poVCs[3];
}TSelectedTri;

typedef CDynArray <TSelectedTri> TSelTriTable;
static TSelTriTable	oSTTable;

//## end module%3C8667C4026C.additionalDeclarations


// Class CLightMapGenerator2 

//## begin CLightMapGenerator2::oAmbColor%3C866FBC031A.attr preserve=no  private: static TFColor {UA} 
TFColor CLightMapGenerator2::oAmbColor;
//## end CLightMapGenerator2::oAmbColor%3C866FBC031A.attr

//## begin CLightMapGenerator2::poScene%3C86747B02F9.attr preserve=no  private: static CObject3D* {UA} 
CObject3D* CLightMapGenerator2::poScene;
//## end CLightMapGenerator2::poScene%3C86747B02F9.attr

CLightMapGenerator2::CLightMapGenerator2()
  //## begin CLightMapGenerator2::CLightMapGenerator2%.hasinit preserve=no
  //## end CLightMapGenerator2::CLightMapGenerator2%.hasinit
  //## begin CLightMapGenerator2::CLightMapGenerator2%.initialization preserve=yes
  //## end CLightMapGenerator2::CLightMapGenerator2%.initialization
{
  //## begin CLightMapGenerator2::CLightMapGenerator2%.body preserve=yes
  //## end CLightMapGenerator2::CLightMapGenerator2%.body
}


CLightMapGenerator2::~CLightMapGenerator2()
{
  //## begin CLightMapGenerator2::~CLightMapGenerator2%.body preserve=yes
  //## end CLightMapGenerator2::~CLightMapGenerator2%.body
}



//## Other Operations (implementation)
void CLightMapGenerator2::SetAmbientColor (TFColor _roAmbColor)
{
  //## begin CLightMapGenerator2::SetAmbientColor%1015443445.body preserve=yes
	oAmbColor = _roAmbColor;
  //## end CLightMapGenerator2::SetAmbientColor%1015443445.body
}

void CLightMapGenerator2::GenerateLighting (CObject3D* _poScene, CDynArray <CMapEntity *> _oEntities)
{
  //## begin CLightMapGenerator2::GenerateLighting%1015443440.body preserve=yes
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
	oSTTable.Clear();
  //## end CLightMapGenerator2::GenerateLighting%1015443440.body
}

void CLightMapGenerator2::Clear (CObject3D* _poObj)
{
  //## begin CLightMapGenerator2::Clear%1015456519.body preserve=yes
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
  //## end CLightMapGenerator2::Clear%1015456519.body
}

void CLightMapGenerator2::ClearMesh (CMesh *_poMesh)
{
  //## begin CLightMapGenerator2::ClearMesh%1015456520.body preserve=yes
	if (! _poMesh)		return;
	if (! _poMesh->VCs) return;
	
	int iVX;		
	for (iVX=0;iVX<_poMesh->usNumVerts;iVX++)
		_poMesh->VCs[iVX].V4(oAmbColor.r,oAmbColor.g,oAmbColor.b,oAmbColor.a);
  //## end CLightMapGenerator2::ClearMesh%1015456520.body
}

void CLightMapGenerator2::GenLitForLight (CMapEnt_Light& _roLight)
{
  //## begin CLightMapGenerator2::GenLitForLight%1015443442.body preserve=yes
	
	CGraphBV_Sphere oSphere;
	oSphere.pGetSphere()->Center.Assign(_roLight.oPos);
	if (_roLight.fRadius)
	{
		oSphere.pGetSphere()->Radius = _roLight.fRadius;
	}
	else
		oSphere.pGetSphere()->Radius = 10.0f;

	// Select the meshes the ray potentially crosses
	SelectMeshes(oSphere,poScene);

	// From these meshes select only the triangles inside the light action radius
	if(! oSMeshes.iNumElems()) 
	{
		return;
	}
	SelectTris(_roLight.fRadius,_roLight.oPos);

	
	

	// Select the vertexs the ray touches
  	int						iTri;
	int						iVX;
	TFColor					DstColor;
	TFColor					SrcColor;
	float					fDist;
	SCNUt_VisibilityTester	oVTest;
	SCNUt_TriScene			*poTScn;
	
	// Make a triangle scene for visibility testing
	poTScn = mNew SCNUt_TriScene;
	poTScn->Init(oSTTable.iNumElems());
	for (iTri=0;iTri<oSTTable.iNumElems();iTri++)
	{
		poTScn->Tris[iTri].VXs[0].Assign(*oSTTable[iTri].poVXs[0]);
		poTScn->Tris[iTri].VXs[1].Assign(*oSTTable[iTri].poVXs[1]);
		poTScn->Tris[iTri].VXs[2].Assign(*oSTTable[iTri].poVXs[2]);
	}
	
	for (iTri=0;iTri<oSTTable.iNumElems();iTri++)
	{
		for (iVX=0;iVX<3;iVX++)
		{
			fDist  = _roLight.oPos.SqDistance(*oSTTable[iTri].poVXs[iVX]);
			fDist /= _SQ_(_roLight.fRadius);

			if (fDist <= 1.0f)
			{
				if (oVTest.bIsVisible(poTScn,_roLight.oPos,*oSTTable[iTri].poVXs[iVX]))
				{
					float fFact = 1.0f - fDist;

					DstColor = Color_fn_Scale(_roLight.Color,fFact);

					SrcColor.r = oSTTable[iTri].poVCs[iVX]->X();
					SrcColor.g = oSTTable[iTri].poVCs[iVX]->Y();
					SrcColor.b = oSTTable[iTri].poVCs[iVX]->Z();
					SrcColor.a = oSTTable[iTri].poVCs[iVX]->W();
					
					DstColor = Color_fn_Add(SrcColor,DstColor);

					oSTTable[iTri].poVCs[iVX]->V4(DstColor.r,DstColor.g,DstColor.b,DstColor.a);
					// oSTTable[iTri].poVCs[iVX]->V4(1.0f,1.0f,0.0f,0.0f);
				}
			}
		}
	}

	// Delete auxiliary triangle scene
	mDel poTScn;
  //## end CLightMapGenerator2::GenLitForLight%1015443442.body
}

void CLightMapGenerator2::SelectMeshes (CGraphBV_Sphere& _roSphere, CObject3D* _poObj)
{
  //## begin CLightMapGenerator2::SelectMeshes%1015443443.body preserve=yes
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
  //## end CLightMapGenerator2::SelectMeshes%1015443443.body
}

void CLightMapGenerator2::SelectTris (float _fRadius, CVect3& _roPos)
{
  //## begin CLightMapGenerator2::SelectTris%1015443446.body preserve=yes
	int				iNumTris;
	int				iTri;
	int				iMesh;
	CTriangle		oTri;
	CVect3			*poVX;
	TSelectedTri	oSTri;	
	CVect3			oVXs[3];
	int				iA,iB,iC;

	oSTTable.Clear();
	for (iMesh=0;iMesh<oSMeshes.iNumElems();iMesh++)
	{
		switch (oSMeshes[iMesh]->eMeshType)
		{
			case E3D_MESH_NITRIS:// Lighting based on vertex reflection
			{
				iNumTris = oSMeshes[iMesh]->usNumVerts/3;
				poVX     = oSMeshes[iMesh]->VXs;

				for (iTri=0;iTri<iNumTris;iTri++)
				{
					oTri.Init(poVX);					
					oTri.ComputeAll();			
					oTri.Normal.Normalize();

					if (MATH_Utils::fTriPointSqDistance(oTri,_roPos) <= _SQ_(_fRadius) )
					{
						// Add selected triangle
						oSTri.poVXs[0] = &poVX[0];
						oSTri.poVXs[1] = &poVX[1];
						oSTri.poVXs[2] = &poVX[2];

						oSTri.poVCs[0] = &oSMeshes[iMesh]->VCs[iTri*3+0];
						oSTri.poVCs[1] = &oSMeshes[iMesh]->VCs[iTri*3+1];
						oSTri.poVCs[2] = &oSMeshes[iMesh]->VCs[iTri*3+2];

						oSTTable.iAdd(oSTri);
					}

					poVX += 3;
				}
			}
			break;

			case E3D_MESH_TRIS:// Lighting based on vertex reflection
			{
				iNumTris = oSMeshes[iMesh]->usNumPrims;
				
				for (iTri=0;iTri<iNumTris;iTri++)
				{
					iA = oSMeshes[iMesh]->Idxs[iTri*3+0];
					iB = oSMeshes[iMesh]->Idxs[iTri*3+1];
					iC = oSMeshes[iMesh]->Idxs[iTri*3+2];

					oSTri.poVXs[0] = &oSMeshes[iMesh]->VXs[iA];
					oSTri.poVXs[1] = &oSMeshes[iMesh]->VXs[iB];
					oSTri.poVXs[2] = &oSMeshes[iMesh]->VXs[iC];

					oVXs[0].Assign( *oSTri.poVXs[0] );
					oVXs[1].Assign( *oSTri.poVXs[1] );
					oVXs[2].Assign( *oSTri.poVXs[2] );
					
					oTri.Init(oVXs);
					oTri.ComputeAll();
					oTri.Normal.Normalize();

					if (MATH_Utils::fTriPointSqDistance(oTri,_roPos) <= _SQ_(_fRadius) )
					{
						// Add selected triangle
						oSTri.poVCs[0] = &oSMeshes[iMesh]->VCs[iA];
						oSTri.poVCs[1] = &oSMeshes[iMesh]->VCs[iB];
						oSTri.poVCs[2] = &oSMeshes[iMesh]->VCs[iC];

						oSTTable.iAdd(oSTri);
					}
				}
			}
			break;
		}
	}
  //## end CLightMapGenerator2::SelectTris%1015443446.body
}

// Additional Declarations
  //## begin CLightMapGenerator2%3C8667C4026C.declarations preserve=yes
  //## end CLightMapGenerator2%3C8667C4026C.declarations

//## begin module%3C8667C4026C.epilog preserve=yes
//## end module%3C8667C4026C.epilog


// Detached code regions:
// WARNING: this code will be lost if code is regenerated.
#if 0
#endif
