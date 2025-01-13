//## begin module%3BE87546036A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BE87546036A.cm

//## begin module%3BE87546036A.cp preserve=no
//## end module%3BE87546036A.cp

//## Module: SCNUt_OctreeBuilder%3BE87546036A; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\OctreeBuilder\SCNUt_OctreeBuilder.cpp

//## begin module%3BE87546036A.additionalIncludes preserve=no
//## end module%3BE87546036A.additionalIncludes

//## begin module%3BE87546036A.includes preserve=yes
#include "memory/gammae_mem.h"
//## end module%3BE87546036A.includes

// SCNUt_OctreeBuilder
#include "Scene\SceneUtils\OctreeBuilder\SCNUt_OctreeBuilder.h"
//## begin module%3BE87546036A.additionalDeclarations preserve=yes
//## end module%3BE87546036A.additionalDeclarations


// Class SCNUt_OctreeBuilder 



SCNUt_OctreeBuilder::SCNUt_OctreeBuilder()
  //## begin SCNUt_OctreeBuilder::SCNUt_OctreeBuilder%.hasinit preserve=no
      : iMaxSubdivisions(0), iMinTrisPerNode(0)
  //## end SCNUt_OctreeBuilder::SCNUt_OctreeBuilder%.hasinit
  //## begin SCNUt_OctreeBuilder::SCNUt_OctreeBuilder%.initialization preserve=yes
  //## end SCNUt_OctreeBuilder::SCNUt_OctreeBuilder%.initialization
{
  //## begin SCNUt_OctreeBuilder::SCNUt_OctreeBuilder%.body preserve=yes
  //## end SCNUt_OctreeBuilder::SCNUt_OctreeBuilder%.body
}


SCNUt_OctreeBuilder::~SCNUt_OctreeBuilder()
{
  //## begin SCNUt_OctreeBuilder::~SCNUt_OctreeBuilder%.body preserve=yes
  //## end SCNUt_OctreeBuilder::~SCNUt_OctreeBuilder%.body
}



//## Other Operations (implementation)
CObject3D * SCNUt_OctreeBuilder::poBuildOctree (SCNUt_TriScene& _roScene, SCNUt_MaterialTable &_roMatTable)
{
  //## begin SCNUt_OctreeBuilder::poBuildOctree%1005085994.body preserve=yes
    if (! iMaxSubdivisions)
    {
        SCNUt_SceneBuilder	oSBld;
        return(oSBld.poBuildScene(_roScene,_roMatTable));
    }
    else
    	return (poBuildOctreeRec(_roScene,1,_roMatTable));
  //## end SCNUt_OctreeBuilder::poBuildOctree%1005085994.body
}

CObject3D * SCNUt_OctreeBuilder::poBuildOctreeRec (SCNUt_TriScene& _roScene, int _iCurrentSubs, SCNUt_MaterialTable &_roMatTable)
{
  //## begin SCNUt_OctreeBuilder::poBuildOctreeRec%1015354974.body preserve=yes
	// -----------------------------------------------------------
	// Split the node in height subspaces
	// -----------------------------------------------------------
	CBoundingBox				*poBox;
	SCNUt_ComputeBoundingBox	oCBBox;
	SCNUt_TriSceneSplitter		oTScnSplitter;

	poBox = oCBBox.poComputeBoundingBox(&_roScene);

	CVect3 oCenter;
	CVect3 oHMP,oVMP,oDMP;		// Horizontal middle point, Vertical Middle Point,Depth Middle Point

	// Get the center point of the BBox
	oCenter.Assign(poBox->Maxs);
	oCenter.Add   (poBox->Mins);
	oCenter.Scale (0.5f);

	oHMP.Assign(oCenter);
	oHMP.SetX(poBox->Maxs.X());

	oDMP.Assign(oCenter);
	oDMP.SetY(poBox->Maxs.Y());
	
	oVMP.Assign(oCenter);
	oVMP.SetZ(poBox->Maxs.Z());
	
	// Compute separating planes
	CPlane oHPlane,oVPlane,oDPlane;		// Horizontal,Vertical,Depth plane
	oHPlane.GenerateFromPoints(oCenter,oHMP,oDMP);
	oVPlane.GenerateFromPoints(oCenter,oHMP,oVMP);
	oDPlane.GenerateFromPoints(oCenter,oVMP,oDMP);

	SCNUt_TriScene	*poHChild[2];
	SCNUt_TriScene	*poVChild[4];
	SCNUt_TriScene	*poChildScenes[2+4+8];
	
	// Split in horizontal plane
	oTScnSplitter.ClassifyAndSplitScene(_roScene,oHPlane);
	poHChild[0] = oTScnSplitter.poBackScene;
	poHChild[1] = oTScnSplitter.poFrontScene;

	// Split in vertical plane
	oTScnSplitter.ClassifyAndSplitScene(*poHChild[0],oVPlane);
	poVChild[0] = oTScnSplitter.poBackScene;
	poVChild[1] = oTScnSplitter.poFrontScene;

	oTScnSplitter.ClassifyAndSplitScene(*poHChild[1],oVPlane);
	poVChild[2] = oTScnSplitter.poBackScene;
	poVChild[3] = oTScnSplitter.poFrontScene;
	mDel poHChild[0];
	mDel poHChild[1];

	// Split in depth plane
	oTScnSplitter.ClassifyAndSplitScene(*poVChild[0],oDPlane);
	poChildScenes[0] = oTScnSplitter.poBackScene;			// Child 0
	poChildScenes[1] = oTScnSplitter.poFrontScene;			// Child 1
	
	oTScnSplitter.ClassifyAndSplitScene(*poVChild[1],oDPlane);
	poChildScenes[2] = oTScnSplitter.poBackScene;			// Child 2
	poChildScenes[3] = oTScnSplitter.poFrontScene;			// Child 3
	
	oTScnSplitter.ClassifyAndSplitScene(*poVChild[2],oDPlane);
	poChildScenes[4] = oTScnSplitter.poBackScene;			// Child 4
	poChildScenes[5] = oTScnSplitter.poFrontScene;			// Child 5
	
	oTScnSplitter.ClassifyAndSplitScene(*poVChild[3],oDPlane);
	poChildScenes[6] = oTScnSplitter.poBackScene;			// Child 6
	poChildScenes[7] = oTScnSplitter.poFrontScene;			// Child 7
	mDel poVChild[0];
	mDel poVChild[1];
	mDel poVChild[2];
	mDel poVChild[3];

	// -----------------------------------------------------------
	// Generate a separate scene for every new subspace
	// -----------------------------------------------------------
	CObject3D_Node		*poObj;
	int					iChild;
	SCNUt_SceneBuilder	oSBld;

	poObj = mNew CObject3D_Node;
	poObj->Init(8);

	for (iChild=0;iChild<8;iChild++)
	{
		if ((poChildScenes[iChild]->NumTris < iMinTrisPerNode) ||
			(_iCurrentSubs == iMaxSubdivisions))
        {
			/*
            poObj->SetObject(oSBld.poBuildScene(*poChildScenes[iChild],_roMatTable),
							iChild);
            */
            poObj->iAddObject(oSBld.poBuildScene(*poChildScenes[iChild],_roMatTable));
        }
		else
        {
			/*
            poObj->SetObject(poBuildOctreeRec(*poChildScenes[iChild],_iCurrentSubs+1,_roMatTable),
							iChild);
            */
            poObj->iAddObject(oSBld.poBuildScene(*poChildScenes[iChild],_roMatTable));
        }

		mDel(poChildScenes[iChild]);
	}

	return(poObj);
  //## end SCNUt_OctreeBuilder::poBuildOctreeRec%1015354974.body
}

// Additional Declarations
  //## begin SCNUt_OctreeBuilder%3BE87546036A.declarations preserve=yes
  //## end SCNUt_OctreeBuilder%3BE87546036A.declarations

//## begin module%3BE87546036A.epilog preserve=yes
//## end module%3BE87546036A.epilog
