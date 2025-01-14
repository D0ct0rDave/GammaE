//## begin module%3CA32E37015F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CA32E37015F.cm

//## begin module%3CA32E37015F.cp preserve=no
//## end module%3CA32E37015F.cp

//## Module: CQLE_GEPreprocessor%3CA32E37015F; Pseudo Package body
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\CQLE_GEPreprocessor.cpp

//## begin module%3CA32E37015F.additionalIncludes preserve=no
//## end module%3CA32E37015F.additionalIncludes

//## begin module%3CA32E37015F.includes preserve=yes
#include "memory/gammae_mem.h"
//## end module%3CA32E37015F.includes

// CQLE_GEPreprocessor
#include "Tools\GEMapCompiler\CQLE_GEPreprocessor.h"
//## begin module%3CA32E37015F.additionalDeclarations preserve=yes
#define _CONECTOR_MAT_ "misc/connector.tga"


// ---------------------------------------------------------------------------
bool bConnectorBrush(CMapBrush *poBrush)
{
	return (! strcmp(poBrush->poBSides[0].szTex,_CONECTOR_MAT_) );
}
// ---------------------------------------------------------------------------
void Setup_QLE_CUTRIX_BrushProps(CMapBrush *_poBrush,CVect3 oPos)
{
	if (! _poBrush) return;
	int		iBrush;
	
	CVect3	oOrigin,oNormal;
	for (iBrush=0;iBrush<_poBrush->iNumBSides;iBrush++)
	{
		oNormal.Assign(_poBrush->poBSides[iBrush].oPlane.Normal());
		oOrigin.Assign(oPos);
		oOrigin.Add	  (_poBrush->poBSides[iBrush].oPlane.Origin());

		_poBrush->poBSides[iBrush].oPlane.GeneratePlaneFromFields(oOrigin,oNormal);
	}
}
// ---------------------------------------------------------------------------
void Setup_QLE_CUTRIX_EntityProps(CMapEntity *_poEnt,CVect3 oPos)
{
	if (! _poEnt) return;

	// Setup common entity props	
	switch (_poEnt->eClass)
	{
		case eMapEnt_World:
		{
		}
		break;
		case eMapEnt_Sound:	
		{
			((CMapEnt_Sound *)_poEnt)->oPos.Assign( oPos );
		}
		break;
		
		case eMapEnt_Light:
		{
			((CMapEnt_Light *)_poEnt)->oPos.Assign( oPos );
		}
		break;
		
		case eMapEnt_Monster:
		{
			((CMapEnt_Monster *)_poEnt)->oPos.Assign( oPos );
		}
		break;

		case eMapEnt_PowerUp:
		{
			((CMapEnt_PowerUp *)_poEnt)->oPos.Assign( oPos );
		}
		break;

		case eMapEnt_Item:
		{
			((CMapEnt_Item *)_poEnt)->oPos.Assign( oPos );
		}
		break;

		case eMapEnt_Trigger:
		{
			// Add position to brush
			// Setup_QLE_CUTRIX_BrushProps(((CMapEnt_Trigger*)_poEnt)->poBrush,oPos);
		}
		break;

		case eMapEnt_Platform:
		{
			// Add position to brushes
			/*
			for (int iBrush=0;iBrush<((CMapEnt_Platform*)_poEnt)->aoBrush.iNumElems();iBrush++)
			{
				Setup_QLE_CUTRIX_BrushProps(((CMapEnt_Platform*)_poEnt)->aoBrush[iBrush],oPos);
			}
			*/
			((CMapEnt_Platform*)_poEnt)->oPos.Assign( oPos );
		}
		break;

		case eMapEnt_SrcPoint:
		{
			((CMapEnt_SrcPoint*)_poEnt)->oPos.Assign( oPos );
		}
		break;

		case eMapEnt_DstPoint:
		{
			((CMapEnt_DstPoint*)_poEnt)->oPos.Assign( oPos );
		}
		break;

		case eMapEnt_PlayerStart:
		{
			((CMapEnt_PlayerStart *)_poEnt)->oPos.Assign( oPos );
		}
		break;
	}
}
//## end module%3CA32E37015F.additionalDeclarations


// Class CQLE_GEPreprocessor 

//## begin CQLE_GEPreprocessor::pbBrushInRoom%3CA430450065.attr preserve=no  protected: static bool* {UA} NULL
bool* CQLE_GEPreprocessor::pbBrushInRoom = NULL;
//## end CQLE_GEPreprocessor::pbBrushInRoom%3CA430450065.attr

//## begin CQLE_GEPreprocessor::aoQLERoom%3CA32E930126.role preserve=no  public: static CMapScene { -> RHAN}
CDynArray <CMapScene *> CQLE_GEPreprocessor::aoQLERoom;
//## end CQLE_GEPreprocessor::aoQLERoom%3CA32E930126.role

//## begin CQLE_GEPreprocessor::aoQLEConn%3CA43D2A03D4.role preserve=no  public: static CMapScene { -> UHAN}
CDynArray <CMapScene*> CQLE_GEPreprocessor::aoQLEConn;
//## end CQLE_GEPreprocessor::aoQLEConn%3CA43D2A03D4.role

CQLE_GEPreprocessor::CQLE_GEPreprocessor()
  //## begin CQLE_GEPreprocessor::CQLE_GEPreprocessor%.hasinit preserve=no
  //## end CQLE_GEPreprocessor::CQLE_GEPreprocessor%.hasinit
  //## begin CQLE_GEPreprocessor::CQLE_GEPreprocessor%.initialization preserve=yes
  //## end CQLE_GEPreprocessor::CQLE_GEPreprocessor%.initialization
{
  //## begin CQLE_GEPreprocessor::CQLE_GEPreprocessor%.body preserve=yes
  //## end CQLE_GEPreprocessor::CQLE_GEPreprocessor%.body
}


CQLE_GEPreprocessor::~CQLE_GEPreprocessor()
{
  //## begin CQLE_GEPreprocessor::~CQLE_GEPreprocessor%.body preserve=yes
  //## end CQLE_GEPreprocessor::~CQLE_GEPreprocessor%.body
}



//## Other Operations (implementation)
void CQLE_GEPreprocessor::Preprocess (CQLEMapScn *_poMap)
{
  //## begin CQLE_GEPreprocessor::Preprocess%1017327540.body preserve=yes

	// Initialize static variables
	aoQLEConn.Clear();
	aoQLERoom.Clear();	

	// Los objetos que NO aparecen como subobjetos de otros objetos, son 
	// el nodo raiz de cada habitación
	int			iObj,iSubObj,iBrush;
	CMapScene	*poNewRoom;


	// Create and initialize possible root arrays
	int *piRoot = mNew int[_poMap->iNumObjs];
	
	// NOTE: Object 0 is always the World Spawn entity. This object is
	// not a valid room	
	for (iObj=1;iObj<_poMap->iNumObjs;iObj++) piRoot[iObj] = 1;
	
	// Seek for objects that not appear in any subobject list
	for (iObj=1;iObj<_poMap->iNumObjs;iObj++)
	{
		if((_poMap->poQLEObj[iObj]->eObjType == eQLEOT_ObjList) ||
		   (_poMap->poQLEObj[iObj]->eObjType == eQLEOT_ObjListAndEntity))
		{
			for (iSubObj=0;iSubObj<_poMap->poQLEObj[iObj]->iNumChObjs;iSubObj++)
				piRoot[ _poMap->poQLEObj[iObj]->piChObjList[iSubObj] ] = 0;
		}
		else
		{
			// Is this correct???
			if (_poMap->poQLEObj[iObj]->eObjType == eQLEOT_Brush)
			{
				if (bConnectorBrush(_poMap->poBrush[ _poMap->poQLEObj[iObj]->iBrushNum ]))
					piRoot[ iObj ] = -1;
				else
					piRoot[ iObj ] = 0;
			}
			else
				piRoot[ iObj ] = 0;
		}
	}

	// Setup the objects in world space coords
	CVect3	oOrigin(0.0f,0.0f,0.0f);
		
	for (iObj=1;iObj<_poMap->iNumObjs;iObj++)
		if (piRoot[iObj])
			SetWorldSpaceSubobjects (_poMap,_poMap->poQLEObj[iObj],oOrigin);

	// Create the brush in a room array
	pbBrushInRoom = mNew bool[_poMap->iNumBrushes];
	for (iBrush=0;iBrush<_poMap->iNumBrushes;iBrush++)
		pbBrushInRoom[iBrush] = false;

	// Create the rooms
	// NOTE: Object 0 is always the World Spawn entity. This object is
	// not a valid room
	for (iObj=1;iObj<_poMap->iNumObjs;iObj++)
	{
		if (piRoot[ iObj ] == 1)
		{
			poNewRoom = mNew CMapScene;
			GenerateRoom(_poMap->poQLEObj[iObj],_poMap,poNewRoom);
			aoQLERoom.iAdd( poNewRoom );
		}
	}

	// Create the connectors
	GenerateConnectors(_poMap);

	mDel []pbBrushInRoom;
	mDel []piRoot;

	pbBrushInRoom = NULL;
  //## end CQLE_GEPreprocessor::Preprocess%1017327540.body
}

void CQLE_GEPreprocessor::GenerateRoom (CQLEObject *_poObj, CQLEMapScn *_poMap, CMapScene* _poRoom)
{
  //## begin CQLE_GEPreprocessor::GenerateRoom%1017327541.body preserve=yes
	/*
	// Seria quizás algo más elegante
	if (! strcmp(_poObj->szName,"Connector"))
	{
	}
	else
	*/
	if (! strcmp(_poObj->szName,"Trigger"))
	{
		CMapEntity *poEnt = poGenerateTrigger(_poObj,_poMap,_poRoom);
		if (poEnt)
			_poRoom->AddEntity( poEnt );
	}

else if (! strcmp(_poObj->szName,"TargetMultiple"))
	{	
		CMapEntity *poEnt = poGenerateTargetMultiple(_poObj,_poMap,_poRoom);
		if (poEnt)
			_poRoom->AddEntity( poEnt );		
	}
else if (! strcmp(_poObj->szName,"Platform"))
	{	
		CMapEntity *poEnt = poGeneratePlatform(_poObj,_poMap,_poRoom);
		if (poEnt)
			_poRoom->AddEntity( poEnt );		
	}
	// ...
else 
	{
		int iSubObj;

		// Add the brush to the room scene
		if (_poObj->iBrushNum != -1)
		{
			pbBrushInRoom[_poObj->iBrushNum] = true;	// This brush belongs to a room
			_poRoom->AddBrush( _poMap->poBrush[ _poObj->iBrushNum ] );
		}

		// Add each suboject to the room scene
		for (iSubObj=0;iSubObj<_poObj->iNumChObjs;iSubObj++)
			GenerateRoom(_poMap->poQLEObj[ _poObj->piChObjList[iSubObj] ],_poMap,_poRoom);

		// Add the entity to the room scene
		if (_poObj->iEntityNum != -1)
			_poRoom->AddEntity( _poMap->poEntity[ _poObj->iEntityNum ] );
	}

  //## end CQLE_GEPreprocessor::GenerateRoom%1017327541.body
}

CMapEntity * CQLE_GEPreprocessor::poGenerateTrigger (CQLEObject *_poObj, CQLEMapScn *_poMap, CMapScene* _poRoom)
{
  //## begin CQLE_GEPreprocessor::poGenerateTrigger%1020982174.body preserve=yes
	if (_poObj->iNumChObjs != 2) return(NULL);

	// Child objects	
	CQLEObject *poBrush  = _poMap->poQLEObj[ _poObj->piChObjList[0] ];
	CQLEObject *poEntity = _poMap->poQLEObj[ _poObj->piChObjList[1] ];
	
	if ((poBrush->iBrushNum == -1) || (poEntity->iEntityNum == -1) /*||
		(poBrush->iNumChObjs != 0) || (poEntity->iNumChObjs != 0)*/ ) return(NULL);

	// If we had mistaken the object order
	if (poBrush->iBrushNum == -1)
	{
		// Swap objects
		CQLEObject *poAux = poBrush;
		poBrush  = poEntity;
		poEntity = poAux;
	}

	CMapEntity *poEnt = _poMap->poEntity[ poEntity->iEntityNum ];
	if (! poEnt) return(NULL);
	if (poEnt->eClass != eMapEnt_Trigger) return(NULL);	

	// Set the brush as the brush trigger	
	((CMapEnt_Trigger *)poEnt)->poBrush = _poMap->poBrush[ poBrush->iBrushNum ];
	pbBrushInRoom[poBrush->iBrushNum] = true;	// This brush belongs to a room(or trigger)

	return(poEnt);
  //## end CQLE_GEPreprocessor::poGenerateTrigger%1020982174.body
}

CMapEntity * CQLE_GEPreprocessor::poGenerateTargetMultiple (CQLEObject *_poObj, CQLEMapScn *_poMap, CMapScene* _poRoom)
{
  //## begin CQLE_GEPreprocessor::poGenerateTargetMultiple%1021107564.body preserve=yes
	
	int	iSubObj;
	int iObj;
	int iEnt;
	
	// Search for the target multiple entity
	CMapEnt_TargetMultiple *poTMult = NULL;

	for (iSubObj=0;iSubObj<_poObj->iNumChObjs;iSubObj++)
	{
		iObj = _poObj->piChObjList[iSubObj];
		if (iObj != -1)
		{
			iEnt = _poMap->poQLEObj[iObj]->iEntityNum;
			if (_poMap->poEntity[iEnt]->eClass == eMapEnt_TargetMultiple)
				poTMult = (CMapEnt_TargetMultiple *)_poMap->poEntity[iEnt];
		}
	}

	
	if (! poTMult) return(NULL);

	// Add each entity to the target multiple entity
	for (iSubObj=0;iSubObj<_poObj->iNumChObjs;iSubObj++)
	{
		iObj = _poObj->piChObjList[iSubObj];
		if (iObj != -1)
		{
			iEnt = _poMap->poQLEObj[iObj]->iEntityNum;
			if (iEnt != -1)
			{
				switch (_poMap->poEntity[iEnt]->eClass)
				{
					case eMapEnt_Sound:
					case eMapEnt_Light:
					case eMapEnt_Monster:
					case eMapEnt_PowerUp:
					case eMapEnt_Item:
					case eMapEnt_Trigger:
					case eMapEnt_Platform:
					poTMult->aoTargets.iAdd( (CMapEnt_Target*)_poMap->poEntity[iEnt] );
					break;
				}
			}
		}
	}

	return(poTMult);
  //## end CQLE_GEPreprocessor::poGenerateTargetMultiple%1021107564.body
}

CMapEntity * CQLE_GEPreprocessor::poGeneratePlatform (CQLEObject *_poObj, CQLEMapScn *_poMap, CMapScene* _poRoom)
{
  //## begin CQLE_GEPreprocessor::poGeneratePlatform%1021126162.body preserve=yes
	CMapEnt_Platform *poPlatform = NULL;
	CMapEnt_DstPoint *poDstPoint = NULL;
	int				iObj;
	int				iSubObj;
	int				iEnt;
	int				iBrush;

	// Look for specific entities
	for (iSubObj=0;iSubObj<_poObj->iNumChObjs;iSubObj++)
	{
		iObj = _poObj->piChObjList[iSubObj];
		
		if ( iObj != -1)
		{
			iEnt = _poMap->poQLEObj[ iObj ]->iEntityNum;

			if (iEnt != -1)
			{
				switch (_poMap->poEntity[iEnt]->eClass)
				{
					case eMapEnt_Platform: 
					poPlatform = (CMapEnt_Platform *)_poMap->poEntity[iEnt];
					break;

					case eMapEnt_DstPoint:
					poDstPoint = (CMapEnt_DstPoint *)_poMap->poEntity[iEnt];
					break;
				}
			}
		}
	}

	if ( (! poPlatform) || (! poDstPoint)) return(NULL);

	// Assign initial and final platform positions
	poPlatform->oSrcPos.Assign(poPlatform->oPos);	// Entity positions are at this point valid
	poPlatform->oDstPos.Assign(poDstPoint->oPos);	// Entity positions are at this point valid

	// Traverse child objects and redistribute
	for (iSubObj=0;iSubObj<_poObj->iNumChObjs;iSubObj++)
	{
		iObj = _poObj->piChObjList[iSubObj];

		if ( iObj != -1)
		{
			iBrush = _poMap->poQLEObj[ iObj ]->iBrushNum;
			if ( iBrush != -1)
			{
				pbBrushInRoom[iBrush] = true;	// This brush belongs to a room (or platform)
				poPlatform->aoBrush.iAdd(_poMap->poBrush[iBrush]);
			}
		}
	}

	return(poPlatform);
  //## end CQLE_GEPreprocessor::poGeneratePlatform%1021126162.body
}

void CQLE_GEPreprocessor::GenerateConnectors (CQLEMapScn *_poMap)
{
  //## begin CQLE_GEPreprocessor::GenerateConnectors%1017392881.body preserve=yes

	// Connectors are objects of type brush, not belonging to any room and
	// with the _CONECTOR_MAT_ material
	CMapScene	*poNewConn;
	int			iBrush;

	for (iBrush=0;iBrush<_poMap->iNumBrushes;iBrush++)
	{
		if (! pbBrushInRoom[iBrush])
		{
			if (bConnectorBrush( _poMap->poBrush[iBrush] ))
			{
				poNewConn = mNew CMapScene;
				poNewConn->AddBrush( _poMap->poBrush[iBrush] );

				aoQLEConn.iAdd(poNewConn);
			}
		}
	}
  //## end CQLE_GEPreprocessor::GenerateConnectors%1017392881.body
}

void CQLE_GEPreprocessor::SetWorldSpaceSubobjects (CQLEMapScn *_poMap, CQLEObject* _poObj, CVect3 _oOfs)
{
  //## begin CQLE_GEPreprocessor::SetWorldSpaceSubobjects%1017778988.body preserve=yes

	_oOfs.Add(_poObj->oPos);

	if (_poObj->iBrushNum != -1)
		Setup_QLE_CUTRIX_BrushProps(_poMap->poBrush[_poObj->iBrushNum],_oOfs);

	int iSubObj;
	for (iSubObj=0;iSubObj<_poObj->iNumChObjs;iSubObj++)
		SetWorldSpaceSubobjects (_poMap,_poMap->poQLEObj[ _poObj->piChObjList[iSubObj] ],_oOfs);
		
	if (_poObj->iEntityNum != -1)
		Setup_QLE_CUTRIX_EntityProps(_poMap->poEntity[_poObj->iEntityNum],_oOfs);
  //## end CQLE_GEPreprocessor::SetWorldSpaceSubobjects%1017778988.body
}

// Additional Declarations
  //## begin CQLE_GEPreprocessor%3CA32E37015F.declarations preserve=yes
  //## end CQLE_GEPreprocessor%3CA32E37015F.declarations

//## begin module%3CA32E37015F.epilog preserve=yes
//## end module%3CA32E37015F.epilog
