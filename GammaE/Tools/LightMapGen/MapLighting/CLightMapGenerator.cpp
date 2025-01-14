//## begin module%3C83D30502E1.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C83D30502E1.cm

//## begin module%3C83D30502E1.cp preserve=no
//## end module%3C83D30502E1.cp

//## Module: CLightMapGenerator%3C83D30502E1; Pseudo Package body
//## Source file: i:\Projects\GammaE\Tools\LightMapGen\MapLighting\CLightMapGenerator.cpp

//## begin module%3C83D30502E1.additionalIncludes preserve=no
//## end module%3C83D30502E1.additionalIncludes

//## begin module%3C83D30502E1.includes preserve=yes
#include "memory/gammae_mem.h"
#include <string.h>
//## end module%3C83D30502E1.includes

// CLightMapGenerator
#include "Tools\LightMapGen\MapLighting\CLightMapGenerator.h"
//## begin module%3C83D30502E1.additionalDeclarations preserve=yes
//## end module%3C83D30502E1.additionalDeclarations


// Class CLightMapGenerator 

//## begin CLightMapGenerator::poEntity%3C83D38E0324.attr preserve=no  private: static CMapEntity * * {UA} NULL
CMapEntity * *CLightMapGenerator::poEntity = NULL;
//## end CLightMapGenerator::poEntity%3C83D38E0324.attr

//## begin CLightMapGenerator::iNumEntities%3C83D3A3034D.attr preserve=no  private: static int {UA} 0
int CLightMapGenerator::iNumEntities = 0;
//## end CLightMapGenerator::iNumEntities%3C83D3A3034D.attr

//## begin CLightMapGenerator::poMesh%3C83D4000120.attr preserve=no  private: static CMesh * * {UA} NULL
CMesh * *CLightMapGenerator::poMesh = NULL;
//## end CLightMapGenerator::poMesh%3C83D4000120.attr

//## begin CLightMapGenerator::iNumMeshes%3C83D4090321.attr preserve=no  private: static int {UA} 0
int CLightMapGenerator::iNumMeshes = 0;
//## end CLightMapGenerator::iNumMeshes%3C83D4090321.attr

//## begin CLightMapGenerator::poMarkedMeshes%3C83EDB202AF.attr preserve=no  private: static CMesh ** {UA} NULL
CMesh **CLightMapGenerator::poMarkedMeshes = NULL;
//## end CLightMapGenerator::poMarkedMeshes%3C83EDB202AF.attr

//## begin CLightMapGenerator::iNumMarkedMeshes%3C83EDC000A7.attr preserve=no  private: static int {UA} 0
int CLightMapGenerator::iNumMarkedMeshes = 0;
//## end CLightMapGenerator::iNumMarkedMeshes%3C83EDC000A7.attr

//## begin CLightMapGenerator::oAmbColor%3C83F1A4022F.attr preserve=no  private: static TFColor {UA} 
TFColor CLightMapGenerator::oAmbColor;
//## end CLightMapGenerator::oAmbColor%3C83F1A4022F.attr

//## begin CLightMapGenerator::oRayMat%3C853DC9028E.attr preserve=no  private: static CMatrix4x4 {UA} 
CMatrix4x4 CLightMapGenerator::oRayMat;
//## end CLightMapGenerator::oRayMat%3C853DC9028E.attr

CLightMapGenerator::CLightMapGenerator()
  //## begin CLightMapGenerator::CLightMapGenerator%.hasinit preserve=no
  //## end CLightMapGenerator::CLightMapGenerator%.hasinit
  //## begin CLightMapGenerator::CLightMapGenerator%.initialization preserve=yes
  //## end CLightMapGenerator::CLightMapGenerator%.initialization
{
  //## begin CLightMapGenerator::CLightMapGenerator%.body preserve=yes
  //## end CLightMapGenerator::CLightMapGenerator%.body
}


CLightMapGenerator::~CLightMapGenerator()
{
  //## begin CLightMapGenerator::~CLightMapGenerator%.body preserve=yes
  //## end CLightMapGenerator::~CLightMapGenerator%.body
}



//## Other Operations (implementation)
void CLightMapGenerator::GenerateLighting (CObject3D* _poScene, CMapEntity * *_poEntities, int _iNumEntities)
{
  //## begin CLightMapGenerator::GenerateLighting%1015273104.body preserve=yes
	poMesh     = NULL;
	iNumMeshes = 0;
	EnumerateMeshes(_poScene);

	poMarkedMeshes   = mNew CMesh *[iNumMeshes];	

	int iEnt;
	for (iEnt=0;iEnt<iNumEntities;iEnt++)
	{
		if (poEntity[iEnt]->eClass == eMapEnt_Light)
			GenLitForLight( *(CMapEnt_Light *)poEntity[iEnt],_poScene );
	} 
  //## end CLightMapGenerator::GenerateLighting%1015273104.body
}

void CLightMapGenerator::ComputeRayMatrix (CRay& _roRay)
{
  //## begin CLightMapGenerator::ComputeRayMatrix%1015354975.body preserve=yes
	
	// Compute light coordinate system matrix
	CVect3 oRayX;
	CVect3 oRayY;
	CVect3 oRayZ;
	
	oRayZ.Assign    (_roRay.Dir);	oRayZ.Normalize();
	oRayY.Orthogonal(_roRay.Dir);	oRayY.Normalize();
	oRayX.CrossProd (oRayY,oRayZ);	oRayX.Normalize();	// <- Last not necessary

	oRayMat.LoadIdentity();
	oRayMat.SetColVector(0,oRayX.X(),oRayX.Y(),oRayX.Z(),0.0f);
	oRayMat.SetColVector(1,oRayY.X(),oRayY.Y(),oRayY.Z(),0.0f);
	oRayMat.SetColVector(2,oRayZ.X(),oRayZ.Y(),oRayZ.Z(),0.0f);
	oRayMat.SetColVector(3,-_roRay.Origin.X(),-_roRay.Origin.Y(),-_roRay.Origin.Z(),1.0f);
  //## end CLightMapGenerator::ComputeRayMatrix%1015354975.body
}

void CLightMapGenerator::EnumerateMeshes (CObject3D* _poObj)
{
  //## begin CLightMapGenerator::EnumerateMeshes%1015273109.body preserve=yes
	if (! _poObj) return;
	
	int iObj;
	switch ( _poObj->eGetTypeID() )
	{
		case e3DObj_Leaf:			CMesh* *poNewMeshes;
									poNewMeshes = mNew CMesh *[iNumMeshes+1];									

									if (poMesh)
									{
										memcpy(poNewMeshes,poMesh,iNumMeshes*sizeof(CMesh*));
										mDel []poMesh;
									}

									poMesh = poNewMeshes;
									poMesh[iNumMeshes] = ((CObject3D_Leaf*)_poObj)->poGetMesh();
									iNumMeshes++;
									break;

		case e3DObj_Node:			for (iObj=0;iObj<((CObject3D_Node*)_poObj)->iNumSubObjs();iObj++)
										EnumerateMeshes( ((CObject3D_Node*)_poObj)->poGetObject(iObj) );
									break;
		case e3DObj_BSPNode:		EnumerateMeshes( ((CObject3D_BSPNode*)_poObj)->poGetBackNode() );
									EnumerateMeshes( ((CObject3D_BSPNode*)_poObj)->poGetFrontNode() );
									break;
	}
  //## end CLightMapGenerator::EnumerateMeshes%1015273109.body
}

void CLightMapGenerator::GenLitForLight (CMapEnt_Light& _roLight, CObject3D* _poScene)
{
  //## begin CLightMapGenerator::GenLitForLight%1015273108.body preserve=yes
	int		iMesh;
	int		iVX;
	CRay	oRay;
	TFColor	Color;

	for (iMesh=0;iMesh<iNumMeshes;iMesh++)
	{	
		printf("Mesh %d\n",iMesh);
		if (poMesh[iMesh]->VCs)
		{
			if (poMesh[iMesh]->VNs)
			{
				// Lighting based on vertex reflection
				for (iVX=0;iVX<poMesh[iMesh]->usNumVerts;iVX++)
				{					
					oRay.InitFromPoints(_roLight.oPos,poMesh[iMesh]->VXs[iVX]);
					oRay.Dir.Normalize();										
					ComputeRayMatrix (oRay);

					if (bRayToPos(oRay,poMesh[iMesh]->VXs[iVX],_poScene))
						Color = _roLight.Color;
					else
						Color = oAmbColor;
					
					poMesh[iMesh]->VCs[iVX].V4(Color.r,Color.g,Color.b,Color.a);
				}
			}
			else
			{
				// Lighting based on vertex visibility
				for (iVX=0;iVX<poMesh[iMesh]->usNumIdxs;iVX++)
				{
					oRay.InitFromPoints(_roLight.oPos,poMesh[iMesh]->VXs[iVX]);
					oRay.Dir.Normalize();										
					ComputeRayMatrix (oRay);

					if (bRayToPos(oRay,poMesh[iMesh]->VXs[iVX],_poScene))
						Color = _roLight.Color;
					else
						Color = oAmbColor;
					
					poMesh[iMesh]->VCs[iVX].V4(Color.r,Color.g,Color.b,Color.a);
				}
			}
		}
	}
  //## end CLightMapGenerator::GenLitForLight%1015273108.body
}

bool CLightMapGenerator::bRayToPos (CRay& _roRay, CVect3& _roPos, CObject3D* _poScene)
{
  //## begin CLightMapGenerator::bRayToPos%1015273105.body preserve=yes
	SCNUt_TriScene *poTScn;

	iNumMarkedMeshes = 0;	
	MarkCrossedMeshes(_roRay,_poScene);
	poTScn = poGetRayScene(_roRay);

	if (! poTScn)			return(false);
	if (! poTScn->NumTris)	return(false);
	if (! poTScn->Tris)		return(false);
		
	// For all those triangles, compute intersection point,
	int				iTri;		
	CRay			oRay;		
	CTriangle		oTri;		
	CVect3			oPoint;		
	CVect3			oMax,oMin;
	CVect3			*poVX;

	oRay.Dir.V3   (0.0f,0.0f,1.0f);
	oRay.Origin.V3(0.0f,0.0f,0.0f);
	
	for (iTri=0;iTri<poTScn->NumTris;iTri++)
	{
		// Get vertex Bounding Box
		poVX = poTScn->Tris[iTri].VXs;
		
		if ((poVX[0].Z()>0.0f) || (poVX[1].Z()>0.0f) || (poVX[2].Z()>0.0f)) 
		{
			MATH_Utils::GetMaxMins(poVX[0].v[0],poVX[1].v[0],poVX[2].v[0],oMax.v[0],oMin.v[0]);
			MATH_Utils::GetMaxMins(poVX[0].v[1],poVX[1].v[1],poVX[2].v[1],oMax.v[1],oMin.v[1]);

			if ((oMin.X() < 0.0f) && (oMin.Y() < 0.0f) &&
				(oMax.X() > 0.0f) && (oMax.Y() > 0.0f))
			{
				// Ray crosses triangle BBox
				oTri.Init(poVX);
				oTri.ComputeAll();

				if (MATH_Utils::iTestRayTriIntersection(oRay,oTri,oPoint))
				{	
					if (oPoint.Z() < _roPos.Z())
					{
						// We've found a triangle that intersects the ray before
						// it arrives to destination position
						mDel poTScn;
						return(false);
					}
				}
			}
		}
	}

	mDel poTScn;
	return(true);
  //## end CLightMapGenerator::bRayToPos%1015273105.body
}

void CLightMapGenerator::MarkCrossedMeshes (CRay& _roRay, CObject3D* _poObj)
{
  //## begin CLightMapGenerator::MarkCrossedMeshes%1015273106.body preserve=yes
	if (! _poObj) return;
	
	int				iObj;	
	CVect3			oPoint;
	CGraphBV_Box	oBox;
	
	// Get object BVol
	oBox.Copy( _poObj->poGetBoundVol() );
	// Test if the ray crosses the BBox.
	if (! MATH_Utils::iTestRayAABBIntersection(_roRay,oBox.Vol.Maxs,oBox.Vol.Mins)) return;

	switch ( _poObj->eGetTypeID() )
	{
		case e3DObj_Leaf:			poMarkedMeshes[iNumMarkedMeshes++] = ((CObject3D_Leaf*)_poObj)->poGetMesh();
									break;

		case e3DObj_Node:			for (iObj=0;iObj<((CObject3D_Node*)_poObj)->iNumSubObjs();iObj++)
										MarkCrossedMeshes(_roRay,((CObject3D_Node*)_poObj)->poGetObject(iObj));
									break;

		case e3DObj_BSPNode:		MarkCrossedMeshes(_roRay, ((CObject3D_BSPNode*)_poObj)->poGetBackNode()  );
									MarkCrossedMeshes(_roRay, ((CObject3D_BSPNode*)_poObj)->poGetFrontNode() );
									break;
	}
  //## end CLightMapGenerator::MarkCrossedMeshes%1015273106.body
}

SCNUt_TriScene* CLightMapGenerator::poGetRayScene (CRay& _roRay)
{
  //## begin CLightMapGenerator::poGetRayScene%1015273107.body preserve=yes
	SCNUt_TriSceneAccumulator	*poTScnAcc = mNew SCNUt_TriSceneAccumulator;
	SCNUt_Mesh2TriScene			oM2TScn;
	SCNUt_TriScene				*poTScn;
	SCNUt_TransformTriScene		oTScnTransf;	
	int							iMesh;

	poTScnAcc->Init(0,1024);
	for (iMesh=0;iMesh<iNumMarkedMeshes;iMesh++)
	{
		poTScn = oM2TScn.Generate(*poMarkedMeshes[iMesh],0);
		if (poTScn)
		{
			if (poTScn->NumTris)
				poTScnAcc->AddTriScene(poTScn);
		}
		
		mDel poTScn;
	}
	
	// Transform tri scene in ray light coords
	oTScnTransf.Transform(*poTScnAcc,oRayMat);
	
	return(poTScnAcc);
  //## end CLightMapGenerator::poGetRayScene%1015273107.body
}

void CLightMapGenerator::SetAmbientColor (TFColor _roAmbColor)
{
  //## begin CLightMapGenerator::SetAmbientColor%1015279068.body preserve=yes
	oAmbColor = _roAmbColor;
  //## end CLightMapGenerator::SetAmbientColor%1015279068.body
}

// Additional Declarations
  //## begin CLightMapGenerator%3C83D30502E1.declarations preserve=yes
  //## end CLightMapGenerator%3C83D30502E1.declarations

//## begin module%3C83D30502E1.epilog preserve=yes
//## end module%3C83D30502E1.epilog
