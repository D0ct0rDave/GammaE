//## begin module%3CA0FCA702FF.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CA0FCA702FF.cm

//## begin module%3CA0FCA702FF.cp preserve=no
//## end module%3CA0FCA702FF.cp

//## Module: CGEMapGenerator%3CA0FCA702FF; Pseudo Package body
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\CGEMapGenerator.cpp

//## begin module%3CA0FCA702FF.additionalIncludes preserve=no
//## end module%3CA0FCA702FF.additionalIncludes

//## begin module%3CA0FCA702FF.includes preserve=yes
#include "memory/gammae_mem.h"
#include "scene/gammae_scene.h"
#include <string.h>
//## end module%3CA0FCA702FF.includes

// CQLE_GEPreprocessor
#include "Tools\GEMapCompiler\CQLE_GEPreprocessor.h"
// CGEMapGenerator
#include "Tools\GEMapCompiler\CGEMapGenerator.h"
// CMapTriSceneGen
#include "Tools\GEMapCompiler\MapData\CMapTriSceneGen.h"
//## begin module%3CA0FCA702FF.additionalDeclarations preserve=yes
//## end module%3CA0FCA702FF.additionalDeclarations


// Class CGEMapGenerator 


CGEMapGenerator::CGEMapGenerator()
  //## begin CGEMapGenerator::CGEMapGenerator%.hasinit preserve=no
  //## end CGEMapGenerator::CGEMapGenerator%.hasinit
  //## begin CGEMapGenerator::CGEMapGenerator%.initialization preserve=yes
  //## end CGEMapGenerator::CGEMapGenerator%.initialization
{
  //## begin CGEMapGenerator::CGEMapGenerator%.body preserve=yes
  //## end CGEMapGenerator::CGEMapGenerator%.body
}


CGEMapGenerator::~CGEMapGenerator()
{
  //## begin CGEMapGenerator::~CGEMapGenerator%.body preserve=yes
  //## end CGEMapGenerator::~CGEMapGenerator%.body
}



//## Other Operations (implementation)
void CGEMapGenerator::SetTexturePath (char* _szTexPath)
{
  //## begin CGEMapGenerator::SetTexturePath%1017265242.body preserve=yes
	strcpy(szTexPath,_szTexPath);
  //## end CGEMapGenerator::SetTexturePath%1017265242.body
}

CGEMap * CGEMapGenerator::poGenerate (CQLEMapScn *_poMap)
{
  //## begin CGEMapGenerator::poGenerate%1018303590.body preserve=yes
	CGEMap							*poGEMap;
	CDynArray <SCNUt_TriScene *>	oRoomTScn;
	CDynArray <CBoundingBox	   >	oRoomBBox;
	CDynArray <SCNUt_MaterialTable> oRoomMTab;
	
	// Create the main map
	poGEMap	= mNew CGEMap;

	// Setup world entity
	if (_poMap->poEntity[0]->eClass == eMapEnt_World)
	{
		strcpy(poGEMap->oWEnt.szWorldFile,((CMapEnt_World*)_poMap->poEntity[0])->szWorldFile);
		poGEMap->oWEnt.oAmbColor = ((CMapEnt_World*)_poMap->poEntity[0])->oAmbColor;
	}

	// Preprocess QLE map
	CQLE_GEPreprocessor::Preprocess(_poMap);

	// Generate the room triangle scenes
	GenerateRoomTScenes(_poMap,oRoomTScn,oRoomMTab,oRoomBBox);

	// Interconnect rooms
	GenerateConnectorArray (_poMap,poGEMap,oRoomBBox);

	// Eliminate invisible geometry
	// DestroyInvisibleTris(oRoomTScn,oRoomBBox,poGEMap);

	// Generate room scenes
	GenerateRoomArray(oRoomTScn,oRoomMTab,poGEMap);

	// Generate info of adjacent rooms	
	GenerateAdjacencyInfo(poGEMap);

	// Destroy auxiliary data
	oRoomTScn.Clear();
	oRoomBBox.Clear();
	oRoomMTab.Clear();

	return(poGEMap);
  //## end CGEMapGenerator::poGenerate%1018303590.body
}

void CGEMapGenerator::GenerateRoomTScenes (CQLEMapScn *_poMap, CDynArray <SCNUt_TriScene *>& _roRoomTScn, CDynArray<SCNUt_MaterialTable>& _roRoomMTab, CDynArray <CBoundingBox>& _roRoomBBox)
{
  //## begin CGEMapGenerator::GenerateRoomTScenes%1020591273.body preserve=yes
	
	SCNUt_TriScene				*poTScn;
	CBoundingBox				*poCompBox;	
	SCNUt_ComputeBoundingBox	oBoxComp;
	int							iRoom;

	// Intialize arrays
	_roRoomTScn.Clear();
	_roRoomBBox.Clear();
	_roRoomMTab.Clear();

	for (iRoom=0;iRoom<CQLE_GEPreprocessor::aoQLERoom.iNumElems();iRoom++)
	{
		// Create the room scene
		CMapTriSceneGen::SetTexturePath(szTexPath);
		poTScn    = CMapTriSceneGen::poGenerateScene( *CQLE_GEPreprocessor::aoQLERoom[iRoom] );
		poCompBox = oBoxComp.poComputeBoundingBox(poTScn);

		_roRoomTScn.iAdd(poTScn);
		_roRoomBBox.iAdd(*poCompBox);
		_roRoomMTab.iAdd(*CMapTriSceneGen.poMatTable);
	}
  //## end CGEMapGenerator::GenerateRoomTScenes%1020591273.body
}

void CGEMapGenerator::GenerateRoomArray (CDynArray <SCNUt_TriScene *>& _roRoomTScn, CDynArray<SCNUt_MaterialTable>& _roRoomMTab, CGEMap *_poGEMap)
{
  //## begin CGEMapGenerator::GenerateRoomArray%1017393300.body preserve=yes

	// This process has been separated in 2 phases in order to eliminate invisible
	// triangles,since is easier to work with triangle scenes than scene objects

	CGEMapRoom				*poRoom;	
	CObject3D				*poScn;
	int						iRoom;

	
	#ifdef _OCTREE_SCENE_
		SCNUt_OctreeBuilder		oBuilder;
	#else
		SCNUt_SceneBuilder		oBuilder;	
	#endif


	for (iRoom=0;iRoom<_roRoomTScn.iNumElems();iRoom++)
	{
		// Create the room node
		poRoom = mNew CGEMapRoom;

		#ifdef _OCTREE_SCENE_
			// Compute bounding volume hierarchy
			oBuilder.iMaxSubdivisions = 1;
			oBuilder.iMinTrisPerNode  = 125;
			poScn = oBuilder.poBuildOctree(*_roRoomTScn[iRoom],_roRoomMTab[iRoom]);
		#else
			poScn = oBuilder.poBuildScene(*_roRoomTScn[iRoom],_roRoomMTab[iRoom]);
		#endif

		// Compute bounding volume hierarchy
		if (poScn)
		{
			poScn->ComputeBoundVol();
			
			poRoom->poScn    = poScn;
			poRoom->poEnts   = CQLE_GEPreprocessor::aoQLERoom[iRoom]->poEntity;
			poRoom->iNumEnts = CQLE_GEPreprocessor::aoQLERoom[iRoom]->iNumEntities;

			_poGEMap->AddRoom(*poRoom);
		}

		ProcessBrushedEntities (poRoom);
	}
  //## end CGEMapGenerator::GenerateRoomArray%1017393300.body
}

void CGEMapGenerator::GenerateConnectorArray (CQLEMapScn *_poMap, CGEMap *_poGEMap, CDynArray <CBoundingBox>& _roRoomBBoxes)
{
  //## begin CGEMapGenerator::GenerateConnectorArray%1017396148.body preserve=yes

	// For each connector, compute BBox. 
		// For each room, look if Connector BBox intersects Room BBox
	
	SCNUt_TriScene				*poTScn;
	int							iConn;
	CBoundingBox				*poBBox;
	SCNUt_ComputeBoundingBox	oBBoxGen;
	CGEMapConnector				*poConn;
	
	for (iConn=0;iConn<CQLE_GEPreprocessor::aoQLEConn.iNumElems();iConn++)
	{
		poTScn = CMapTriSceneGen::poGenerateScene( *CQLE_GEPreprocessor::aoQLEConn[iConn] );
		poBBox = oBBoxGen.poComputeBoundingBox(poTScn);		

		poConn = mNew CGEMapConnector;
		poConn->oBBox = *poBBox;

		if (bGetABConnRooms(poConn,_roRoomBBoxes, poConn->iRoomA, poConn->iRoomB))
		{			
			// _poGEMap->aoRooms[poConn->iRoomA]->iNumCons ++;
			// _poGEMap->aoRooms[poConn->iRoomB]->iNumCons ++;

			_poGEMap->AddConnector(*poConn);
		}
		else
			mDel poConn;		

		mDel poTScn;		
	}
  //## end CGEMapGenerator::GenerateConnectorArray%1017396148.body
}

bool CGEMapGenerator::bGetABConnRooms (CGEMapConnector* _poConn, CDynArray <CBoundingBox>& _roRoomBBoxes, int& _riA, int& _riB)
{
  //## begin CGEMapGenerator::bGetABConnRooms%1017396150.body preserve=yes
	int iFlags;
	int iRoom;
	int iNumARooms;
	int iNumBRooms;
	
	iNumARooms = 0;
	iNumBRooms = 0;

	for (iRoom=0;iRoom<_roRoomBBoxes.iNumElems();iRoom++)
	{
		CVect3 oMaxs,oMins;

		oMaxs.Assign( _roRoomBBoxes[iRoom].Maxs );
		oMins.Assign( _roRoomBBoxes[iRoom].Mins );

		iFlags = 0;
		if (_poConn->oBBox.Maxs.Inside(oMaxs,oMins)) iFlags |= 0x01;
		if (_poConn->oBBox.Mins.Inside(oMaxs,oMins)) iFlags |= 0x02;
		
		switch (iFlags)
		{
			case 0:	// No intersection, try with the next room
					break;
			case 1: iNumARooms++;
					_riA = iRoom;
					break;
			case 2: iNumBRooms++;
					_riB = iRoom;
					break;
			case 3: // Brush completelly inside a room: invalid connector
					return(false);
					break;
		}
	}

	// A connector must only behave to 2 and only 2 rooms
	if (iNumARooms!=1) return(false);
	if (iNumBRooms!=1) return(false);
	return(true);
  //## end CGEMapGenerator::bGetABConnRooms%1017396150.body
}

void CGEMapGenerator::GenerateAdjacencyInfo (CGEMap *_poGEMap)
{
  //## begin CGEMapGenerator::GenerateAdjacencyInfo%1017414738.body preserve=yes
  	
	int iRoom;
	for (iRoom=0;iRoom<_poGEMap->aoRooms.iNumElems();iRoom++)
	{
		// For each room compute the connector array
		// For each room compute the adjacent room array
		ComputeRoomAdjacencyInfo(iRoom, _poGEMap);
	}

  //## end CGEMapGenerator::GenerateAdjacencyInfo%1017414738.body
}

void CGEMapGenerator::ComputeRoomAdjacencyInfo (int _iRoom, CGEMap* _poMap)
{
  //## begin CGEMapGenerator::ComputeRoomAdjacencyInfo%1017414736.body preserve=yes
	CGEMapRoom		*poRoom;
	CGEMapConnector	*poConn;
	CDynArray <int>	aiCArray;
	CDynArray <int>	aiARArray;
	int				iConn;

	aiCArray.Clear();
	poRoom = _poMap->aoRooms[_iRoom];

	for (iConn=0;iConn<_poMap->aoCons.iNumElems();iConn++)
	{
		poConn =&_poMap->aoCons[iConn];
		if (poConn->iRoomA == _iRoom) 
		{
			aiARArray.iAdd( poConn->iRoomB );
			aiCArray.iAdd( iConn );
		}
   else if (poConn->iRoomB == _iRoom) 
		{
		    aiARArray.iAdd( poConn->iRoomA );
			aiCArray.iAdd( iConn );
		}
	}
	
	if (aiARArray.iNumElems())
	{
		poRoom->piARoom = mNew int[aiARArray.iNumElems()];
		memcpy(poRoom->piARoom,&aiARArray[0],aiARArray.iNumElems()*sizeof(int));

		poRoom->piCons = mNew int[aiCArray.iNumElems()];
		memcpy(poRoom->piCons,&aiCArray[0],aiCArray.iNumElems()*sizeof(int));
		
		poRoom->iNumARooms = aiARArray.iNumElems();
	}
  //## end CGEMapGenerator::ComputeRoomAdjacencyInfo%1017414736.body
}

void CGEMapGenerator::DestroyInvisibleTris (CDynArray <SCNUt_TriScene *>& _roRoomTScn, CDynArray <CBoundingBox>& _roRoomBBoxes, CGEMap *_poGEMap)
{
  //## begin CGEMapGenerator::DestroyInvisibleTris%1020591280.body preserve=yes
	
	bool						*pbVisible;	
	SCNUt_TriScene				*poTScn;
	int							iRoom;
	int							iTri;
	int							iConn;
	int							iNumCons;	
	int							iCorner;
	SCNUt_VisibilityTester		oScnVTest;
	
	int							iNumVisibleTris;
	int							iCurTri;
	SCNUt_TriScene				*poNewTScn;
	
	CGEMapConnector				*poConn;

	for (iRoom=0;iRoom<_roRoomTScn.iNumElems();iRoom++)
	{
		poTScn = _roRoomTScn[iRoom];
	
		// Create and initialize visible triangle array
		pbVisible = mNew bool[poTScn->NumTris];
		memset(pbVisible,0,poTScn->NumTris*sizeof(bool));
	
		// For each connector belonging to the room		
		iNumCons		= 0;
		iConn			= 0;
		poConn			= &_poGEMap->aoCons[0];
		iNumVisibleTris	= 0;

		while (iConn<_poGEMap->aoCons.iNumElems())
		{
			// If this connector belongs to the room
			if ((poConn->iRoomA == iRoom) || (poConn->iRoomB == iRoom))
			{
				// Test every corner of the connector
				for (iCorner=0;iCorner<8;iCorner++)
				{					
					// If this connector corner is inside the Room BBox
					CVect3 oCorner = poConn->oBBox.Points[iCorner];					
					if (oCorner.Inside(_roRoomBBoxes[iRoom].Maxs,_roRoomBBoxes[iRoom].Mins))
					{
						// Test this point against all the triangle scene	
						for (iTri=0;iTri<poTScn->NumTris;iTri++)
						{
							if (! pbVisible[iTri])
							{
								if (oScnVTest.bIsVisible(poTScn,oCorner,poTScn->Tris[iTri].VXs[0]))
									pbVisible[iTri] = true;
						
						else 	if (oScnVTest.bIsVisible(poTScn,oCorner,poTScn->Tris[iTri].VXs[1]))
									pbVisible[iTri] = true;

						else	if (oScnVTest.bIsVisible(poTScn,oCorner,poTScn->Tris[iTri].VXs[2]))
									pbVisible[iTri] = true;
							}
						}
					}
				}

				iNumCons++;
			}
			
			// Next connector
			iConn ++;
			poConn++;
		}

		if (! iNumCons)
		{
			// Make all tris visibles
			memset(pbVisible,1,poTScn->NumTris*sizeof(bool));
		}

		// --------------------------------
		// Now we have the visible triangle 
		// selection for the current room
		// --------------------------------
		
		// Count visible triangles
		iNumVisibleTris	= 0;
		for (iTri=0;iTri<poTScn->NumTris;iTri++)
		{
			if (pbVisible[iTri]) 
				iNumVisibleTris++;
		}
				
		// Copy visible tris
		poNewTScn = mNew SCNUt_TriScene;
		poNewTScn->Init(iNumVisibleTris);

		iCurTri = 0;
		for (iTri=0;iTri<poTScn->NumTris;iTri++)
		{
			if (pbVisible[iTri])
			{
				poNewTScn->Tris[iCurTri] = poTScn->Tris[iTri];
				iCurTri++;
			}
		}
		
		// Substitute the old scene with the new one
		_roRoomTScn[iRoom] = poNewTScn;

		// Delete old scene
		mDel poTScn;		
		
		// Delete visible triangle array
		mDel []pbVisible;
	}

  //## end CGEMapGenerator::DestroyInvisibleTris%1020591280.body
}

void CGEMapGenerator::ProcessBrushedEntities (CGEMapRoom *_poRoom)
{
  //## begin CGEMapGenerator::ProcessBrushedEntities%1021126165.body preserve=yes	
	int							iEnt;
	
	CMapEnt_Platform			*poPlatform;
	CMapScene					*poMapScene;
	SCNUt_TriScene				*poTScn;
	CObject3D					*poScn;
	SCNUt_SceneBuilder			oBuilder;
	
	CMapEnt_Trigger				*poTrigger;
	CBoundingBox				*poBBox;
	SCNUt_ComputeBoundingBox	oBBoxGen;
	
	

	CMapTriSceneGen::SetTexturePath(szTexPath);
			
	for (iEnt=0;iEnt<_poRoom->iNumEnts;iEnt++)
	{
		if (_poRoom->poEnts[iEnt]->eClass == eMapEnt_Platform)
		{
			poPlatform = (CMapEnt_Platform*)_poRoom->poEnts[iEnt];
			
			// Setup a MapScene
			poMapScene = mNew CMapScene;				
			for (int iBrush=0;iBrush<poPlatform->aoBrush.iNumElems();iBrush++)
				poMapScene->AddBrush(poPlatform->aoBrush[iBrush]);
		
			// Generate a common triangle scene
			poTScn    = CMapTriSceneGen::poGenerateScene( *poMapScene );

			// Setup platform scene
			poScn = oBuilder.poBuildScene(*poTScn,*CMapTriSceneGen::poMatTable);
			poScn->ComputeBoundVol();
			
			poPlatform->oSrcPos.Sub( poScn->poGetBoundVol()->GetCenter() );
			poPlatform->oDstPos.Sub( poScn->poGetBoundVol()->GetCenter() );

			poPlatform->poScn = poScn;

			mDel poMapScene;
		}

   else if (_poRoom->poEnts[iEnt]->eClass == eMapEnt_Trigger)
		{
			poTrigger = (CMapEnt_Trigger*)_poRoom->poEnts[iEnt];

			poMapScene = mNew CMapScene;
			// Setup a MapScene
			poMapScene->AddBrush(poTrigger->poBrush);
			
			// Generate a common triangle scene
			poTScn = CMapTriSceneGen::poGenerateScene( *poMapScene );
			poBBox = oBBoxGen.poComputeBoundingBox(poTScn);

			// Setup trigger properties
			poTrigger->oMax.Assign(poBBox->Maxs);
			poTrigger->oMin.Assign(poBBox->Mins);

			mDel poMapScene;
			mDel poTScn;				
		}
	}	
  //## end CGEMapGenerator::ProcessBrushedEntities%1021126165.body
}

// Additional Declarations
  //## begin CGEMapGenerator%3CA0FCA702FF.declarations preserve=yes
  //## end CGEMapGenerator%3CA0FCA702FF.declarations

//## begin module%3CA0FCA702FF.epilog preserve=yes
//## end module%3CA0FCA702FF.epilog
