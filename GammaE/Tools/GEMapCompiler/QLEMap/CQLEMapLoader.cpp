//## begin module%3CA0F58F02C1.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CA0F58F02C1.cm

//## begin module%3CA0F58F02C1.cp preserve=no
//## end module%3CA0F58F02C1.cp

//## Module: CQLEMapLoader%3CA0F58F02C1; Pseudo Package body
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\QLEMap\CQLEMapLoader.cpp

//## begin module%3CA0F58F02C1.additionalIncludes preserve=no
//## end module%3CA0F58F02C1.additionalIncludes

//## begin module%3CA0F58F02C1.includes preserve=yes
#include <string.h>
#include "memory/gammae_mem.h"
#include "misc/gammae_misc.h"
#include <stdlib.h>
#include <stdio.h>
//## end module%3CA0F58F02C1.includes

// CQLEMapLoader
#include "Tools\GEMapCompiler\QLEMap\CQLEMapLoader.h"
//## begin module%3CA0F58F02C1.additionalDeclarations preserve=yes

// ---------------------------------------------------------------------------
#define TK_QLEPARS_READY				0
#define TK_QLEPARS_START_BRACKET		1
#define TK_QLEPARS_END_BRACKET			2
#define TK_QLEPARS_CLASSNAME			3
#define TK_QLEPARS_ENTITYDEF			4
#define TK_QLEPARS_BRUSHDEF				5
#define TK_QLEPARS_OBJECTDEF			6
// ---------------------------------------------------------------------------
CMapEntityClass eGetEntityTypeByName(char *_szEntName)
{
	if (! strcmp (_szEntName,"worldspawn"))		return(eMapEnt_World);	
	if (! strcmp (_szEntName,"PlayerStart"))	return(eMapEnt_PlayerStart);
	if (! strcmp (_szEntName,"Sound"))			return(eMapEnt_Sound);
	if (! strcmp (_szEntName,"Light"))			return(eMapEnt_Light);
	if (! strncmp(_szEntName,"monster_",8))		return(eMapEnt_Monster);
	if (! strcmp (_szEntName,"Trigger"))		return(eMapEnt_Trigger);	
	if (! strcmp (_szEntName,"Platform"))		return(eMapEnt_Platform);	
	if (! strcmp (_szEntName,"SrcPoint"))		return(eMapEnt_SrcPoint);
	if (! strcmp (_szEntName,"DstPoint"))		return(eMapEnt_DstPoint);
	if (! strcmp (_szEntName,"TargetMultiple"))	return(eMapEnt_TargetMultiple);

	return(eMapEnt_NULL);
}

// ---------------------------------------------------------------------------
CMapEntity *poCreateEntityByClass(CMapEntityClass _eEntClass)
{
	switch (_eEntClass)
	{
		case eMapEnt_World:			return(mNew CMapEnt_World);
		case eMapEnt_PlayerStart:	return(mNew CMapEnt_PlayerStart);
		case eMapEnt_Sound:			return(mNew CMapEnt_Sound);
		case eMapEnt_Light:			return(mNew CMapEnt_Light);
		case eMapEnt_Monster:		return(mNew CMapEnt_Monster);
		case eMapEnt_Trigger:		return(mNew CMapEnt_Trigger);
		case eMapEnt_Platform:		return(mNew CMapEnt_Platform);
		case eMapEnt_SrcPoint:		return(mNew CMapEnt_SrcPoint);
		case eMapEnt_DstPoint:		return(mNew CMapEnt_DstPoint);
		case eMapEnt_TargetMultiple:return(mNew CMapEnt_TargetMultiple);
	}
	return(NULL);
}
// ---------------------------------------------------------------------------
//## end module%3CA0F58F02C1.additionalDeclarations


// Class CQLEMapLoader 

CQLEMapLoader::CQLEMapLoader()
  //## begin CQLEMapLoader::CQLEMapLoader%.hasinit preserve=no
  //## end CQLEMapLoader::CQLEMapLoader%.hasinit
  //## begin CQLEMapLoader::CQLEMapLoader%.initialization preserve=yes
  //## end CQLEMapLoader::CQLEMapLoader%.initialization
{
  //## begin CQLEMapLoader::CQLEMapLoader%.body preserve=yes
  //## end CQLEMapLoader::CQLEMapLoader%.body
}


CQLEMapLoader::~CQLEMapLoader()
{
  //## begin CQLEMapLoader::~CQLEMapLoader%.body preserve=yes
  //## end CQLEMapLoader::~CQLEMapLoader%.body
}



//## Other Operations (implementation)
CQLEMapScn * CQLEMapLoader::iLoad (char* _szFilename)
{
  //## begin CQLEMapLoader::iLoad%1017265239.body preserve=yes
	
	char	*szMapStream = ParseUtils_ReadFile(_szFilename);
	if (! szMapStream) return(NULL);
	
	char	*szToken;
	char	*szMapStr;
	char	szObjName[256];

		
	CQLEMapScn		*poQLEScn = mNew CQLEMapScn;	

	szMapStr		= szMapStream;

	while (szMapStr)
	{		
		NextToken(szToken,szMapStr);

		if (! strcmp(szToken,"{"))
		{	
			if (! strncmp(szMapStr,"// Brush",8))
			{	
				// Skip the rest of the line				
				NextLine(szToken,szMapStr);
				ParseBrush (poQLEScn,szMapStr);
			}
	   else if (! strncmp(szMapStr,"// Entity",9))
			{
				// Skip the rest of the line				
				NextLine(szToken,szMapStr);
				ParseEntity(poQLEScn,szMapStr);
			}
	   else if (! strncmp(szMapStr,"// Object",9))
			{				
				int dummy;
				if (sscanf(szMapStr,"// Object %d : %s",&dummy,szObjName) < 2)
					szObjName[0] = 0;

				// Skip the rest of the line
				NextLine(szToken,szMapStr);
				ParseObject(poQLEScn,szMapStr,szObjName);
			}
		}
	}

	mDel []szMapStream;
	return(poQLEScn);
  //## end CQLEMapLoader::iLoad%1017265239.body
}

void CQLEMapLoader::ParseBrush (CQLEMapScn* _poQLEScn, char *&_szMapStr)
{
  //## begin CQLEMapLoader::ParseBrush%1017265240.body preserve=yes
	char			szTexture[80];
	float			fA[3];
	float			fB[3];
	float			fC[3];
	float			fRAngle;
	int				iUOfs,iVOfs;	
	float			fUScale,fVScale;
	CVect3			oVX[3];
					
	char			*szLine;
	char			*szToken = _szMapStr;

	CMapBrush		*poBrush = mNew CMapBrush;
	CMapBrushSide	oBSide;
	
	do{
		
		NextLine(szLine,_szMapStr);
		sscanf(szLine,"( %f %f %f ) ( %f %f %f ) ( %f %f %f ) %s %d %d %f %f %f",
						&fA[0],&fA[1],&fA[2],&fB[0],&fB[1],&fB[2],&fC[0],&fC[1],&fC[2],
						szTexture,
						&iUOfs,&iVOfs,
						&fRAngle,&fUScale,&fVScale);
			
		NextToken(szToken,szLine);

		// Setup brush side
		if (strcmp(szToken,"}"))
		{
			// Reverse winding
			oBSide.oVecs[0].V3(fA[0],fA[1],fA[2]);
			oBSide.oVecs[1].V3(fB[0],fB[1],fB[2]);
			oBSide.oVecs[2].V3(fC[0],fC[1],fC[2]);
				
			oBSide.oPlane.GenerateFromPoints(oBSide.oVecs[2],oBSide.oVecs[1],oBSide.oVecs[0]);

			strcpy(oBSide.szTex,szTexture);				

			oBSide.fUOfs   = iUOfs;
			oBSide.fVOfs   = iVOfs;
			oBSide.fAngle  = fRAngle;

			oBSide.fUScale = fUScale;
			oBSide.fVScale = fVScale;
			if (oBSide.fUScale == 0.0f) oBSide.fUScale = 1.0f;
			if (oBSide.fVScale == 0.0f) oBSide.fVScale = 1.0f;
			
			poBrush->AddBrushSide(oBSide);
		}
	}while(strcmp(szToken,"}"));
	
	// Add the brush to the map
	_poQLEScn->AddBrush(poBrush);
  //## end CQLEMapLoader::ParseBrush%1017265240.body
}

void CQLEMapLoader::ParseEntity (CQLEMapScn* _poQLEScn, char *&_szMapStr)
{
  //## begin CQLEMapLoader::ParseEntity%1017265243.body preserve=yes
	char				*szToken;
	CMapEntity			*poEntity;
	CMapEntityClass		 eEntClass;
	NextQuotedToken(szToken,_szMapStr);	

	poEntity = NULL;

	if (! strcmp(szToken,"classname"))
	{		
		NextQuotedToken(szToken,_szMapStr);		
		eEntClass = eGetEntityTypeByName(szToken);
		poEntity  = poCreateEntityByClass(eEntClass);
		if (! poEntity) return;

		do{
			NextQuotedToken(szToken,_szMapStr);

			switch (eEntClass)
			{
				// -----------------------------
				// Non target entities
				// -----------------------------
				case eMapEnt_World:
				{
					// Terrain File
					if (! strcmp(szToken,"terrainfile"))
					{
						NextQuotedToken(szToken,_szMapStr);
						strcpy(((CMapEnt_World*)poEntity)->szWorldFile,szToken);
					}
					// Ambient light
			   else if (! strcmp(szToken,"ambientlight"))
					{
						TFColor *poColor= &((CMapEnt_World*)poEntity)->oAmbColor;
						sscanf(szToken,"%f %f %f",&poColor->r,&poColor->g,&poColor->b);
						poColor->a = 0.0f;
					}
				}
				break;

				case eMapEnt_SrcPoint:
				{
				}
				break;

				case eMapEnt_DstPoint:
				{
				}
				break;

				case eMapEnt_PlayerStart:
				{
				}
				break;

				// -----------------------------
				// Target entities (common part)
				// -----------------------------
				case eMapEnt_Sound:
				case eMapEnt_Light:
				case eMapEnt_Monster:
				case eMapEnt_PowerUp:
				case eMapEnt_Item:
				case eMapEnt_Trigger:				
				case eMapEnt_Platform:
				case eMapEnt_TargetMultiple:
				{
					// Target Name
					if (! strcmp(szToken,"name"))
					{
						NextQuotedToken(szToken,_szMapStr);
						strncpy(((CMapEnt_Target*)poEntity)->szName,szToken,32);
						break;
					}

					// Target Type
			   else if (! strcmp(szToken,"Type"))
					{
						NextQuotedToken(szToken,_szMapStr);

						if (! strcmp(szToken,"Translate"))
							((CMapEnt_Target*)poEntity)->eType = eMapEnt_TT_Translate;
				   else if (! strcmp(szToken,"Rotate"))
							((CMapEnt_Target*)poEntity)->eType = eMapEnt_TT_Rotate;
				   else if (! strcmp(szToken,"Disapear"))
							((CMapEnt_Target*)poEntity)->eType = eMapEnt_TT_Disappear;
				   else if (! strcmp(szToken,"Appear"))
							((CMapEnt_Target*)poEntity)->eType = eMapEnt_TT_Appear;
					else
						// Default
						((CMapEnt_Target*)poEntity)->eType = eMapEnt_TT_None;
						break;
					}

					// Trigger mode
			   else if (! strcmp(szToken,"TriggerMode"))
					{
						NextQuotedToken(szToken,_szMapStr);
						
						if (! strcmp(szToken,"Always"))
							((CMapEnt_Target*)poEntity)->eTriggerMode = eMapEnt_TM_Always;
				   else if (! strcmp(szToken,"Multiple"))
							((CMapEnt_Target*)poEntity)->eTriggerMode = eMapEnt_TM_Multiple;
				   else if (! strcmp(szToken,"Once"))
							((CMapEnt_Target*)poEntity)->eTriggerMode = eMapEnt_TM_Once;
				   else
						// Default
						((CMapEnt_Target*)poEntity)->eTriggerMode = eMapEnt_TM_Always;
						break;
					}

					// -----------------------------
					// Target entities (specific part)
					// -----------------------------
					switch (eEntClass)
					{
						// ------------------------
						case eMapEnt_Sound:
						{
							if (! strcmp(szToken,"origin"))
							{
								NextQuotedToken(szToken,_szMapStr);
							}
					else if (! strcmp(szToken,"angle"))
							{					

							}
  					else if (! strcmp(szToken,"sound"))
							{	
								// Sound filename
								NextQuotedToken(szToken,_szMapStr);
								strncpy(((CMapEnt_Sound*)poEntity)->szFileName,szToken,64);
							}
					   else if (! strcmp(szToken,"style"))
							{					

							}
						}
						break;
						
						// ------------------------
						case eMapEnt_Light:
						{
							/*
							if (! strcmp(szToken,"origin"))
							{
								NextQuotedToken(szToken,_szMapStr);
							}
					   else if (! strcmp(szToken,"angle"))
							{
							}
					   else if (! strcmp(szToken,"style"))
							{

							}
							*/
						}
						break;					
						// ------------------------
						case eMapEnt_Monster:
						{
						}
						break;
						// ------------------------
						case eMapEnt_PowerUp:
						{
						}
						break;
						// ------------------------
						case eMapEnt_Item:
						{
						}
						break;
						// ------------------------
						case eMapEnt_TargetMultiple:
						{
						}
						break;
						// ------------------------
						// Trigger entity
						// ------------------------
						case eMapEnt_Trigger:
						{
					        if (! strcmp(szToken,"targetname"))
							{
								NextQuotedToken(szToken,_szMapStr);
								strncpy(((CMapEnt_Trigger*)poEntity)->szTargetName,szToken,32);
							}
					   else if (! strcmp(szToken,"sectarget"))
							{
								NextQuotedToken(szToken,_szMapStr);
								strncpy(((CMapEnt_Trigger*)poEntity)->szSecTarget,szToken,32);
							}
						}
						break;

						// ------------------------
						// Platform entity
						// ------------------------
						case eMapEnt_Platform:
						{
							// Speed
							if (! strcmp(szToken,"Speed"))
							{
								NextQuotedToken(szToken,_szMapStr);
								int iValue;
								sscanf(szToken,"%d",&iValue);
								((CMapEnt_Platform*)poEntity)->fSpeed = iValue;
							}
							
							// End accelerating
					   else if (! strcmp(szToken,"EndAccel"))
							{
								NextQuotedToken(szToken,_szMapStr);
								int iValue;
								sscanf(szToken,"%d",&iValue);
								((CMapEnt_Platform*)poEntity)->fEndAc = iValue;

							}

							// Start deceleration
					   else if (! strcmp(szToken,"StartDecel"))
							{
								NextQuotedToken(szToken,_szMapStr);
								int iValue;
								sscanf(szToken,"%d",&iValue);
								((CMapEnt_Platform*)poEntity)->fStartDec = iValue;
							}
						}
						break;

					}	// ! switch (eEntClass) (Target Specific part)
				}	// ! case TargetClass (Target Common part)
			}	// ! switch (eEntClass)
		}while (*szToken != '}');

		_poQLEScn->AddEntity(poEntity);
		NextLine(szToken,_szMapStr);
	} // ! (szToken == classname)
  //## end CQLEMapLoader::ParseEntity%1017265243.body
}

void CQLEMapLoader::ParseObject (CQLEMapScn* _poQLEScn, char*& _szMapStr, char* _szObjName)
{
  //## begin CQLEMapLoader::ParseObject%1017265244.body preserve=yes
	char			*szLine;
	char			*szToken = _szMapStr;
	int				iObj;
	CQLEObject		*poObj = mNew CQLEObject;	
	
	// Copy the name of the object
	strcpy(poObj->szName,_szObjName);

	// Parse first 3 lines
	NextLine(szLine,_szMapStr);
	sscanf	(szLine,"Position: (%f, %f, %f)",
				&poObj->oPos.v[0],
				&poObj->oPos.v[1],
				&poObj->oPos.v[2]);
	
	NextLine(szLine,_szMapStr);
	sscanf	(szLine,"Orientation (rad): (%f, %f, %f)",
				&poObj->oDir.v[0],
				&poObj->oDir.v[1],
				&poObj->oDir.v[2]);
	
	NextLine(szLine,_szMapStr);
	sscanf	(szLine,"Scale: (%f, %f, %f)",
				&poObj->oScl.v[0],
				&poObj->oScl.v[1],
				&poObj->oScl.v[2]);
		
	// look for leaf or node object	
	NextLine(szLine,_szMapStr);	
	NextToken(szToken,szLine);

	// -------------------------------
	// Brushes
	// -------------------------------
	if (! strcmp(szToken,"Brush:"))
	{
		poObj->eObjType = eQLEOT_Brush;

		NextToken(szToken,szLine);		
		sscanf(szToken,"%d",&poObj->iBrushNum);
	}
	// -------------------------------
	// Objects
	// -------------------------------
else if (! strcmp(szToken,"Objects:"))
	{
		poObj->eObjType = eQLEOT_ObjList;

		do
		{
			do
			{
				NextToken(szToken,szLine);
				sscanf(szToken,"%d,",&iObj);
				poObj->AddChildObject(iObj);
			}while (szToken<szLine);

			// Look for entity keyword
			NextLine(szLine,_szMapStr);
			NextToken(szToken,szLine);

			// CUTRIX thanks to the way QLE handles entity info half in the
			// object node and the other half in the entity itself
			if (! strcmp(szToken,"Entity:"))
			{
				poObj->eObjType = eQLEOT_ObjListAndEntity;
				NextToken(szToken,szLine);
				
				sscanf(szToken,"%d",&poObj->iEntityNum);				
			}

		}while (! strcmp(szToken,"Objects:"));
	}

	// -------------------------------
	// Entities
	// -------------------------------
else if (! strcmp(szToken,"Entity:"))
	{
		poObj->eObjType = eQLEOT_Entity;

		NextToken(szToken,szLine);			
		sscanf(szToken,"%d",&poObj->iEntityNum);
	}

	// -------------------------------
	while (strcmp(szToken,"}"))
	{
		NextLine(szLine,_szMapStr);	
		NextToken(szToken,szLine);
	}

	// Add the object to the map
	_poQLEScn->AddObject(poObj);
  //## end CQLEMapLoader::ParseObject%1017265244.body
}

// Additional Declarations
  //## begin CQLEMapLoader%3CA0F58F02C1.declarations preserve=yes
  //## end CQLEMapLoader%3CA0F58F02C1.declarations

//## begin module%3CA0F58F02C1.epilog preserve=yes
//## end module%3CA0F58F02C1.epilog
