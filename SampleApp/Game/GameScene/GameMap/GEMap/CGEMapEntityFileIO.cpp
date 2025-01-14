//## begin module%3CA6E1CA02EB.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CA6E1CA02EB.cm

//## begin module%3CA6E1CA02EB.cp preserve=no
//## end module%3CA6E1CA02EB.cp

//## Module: CGEMapEntityFileIO%3CA6E1CA02EB; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\GameScene\GameMap\GEMap\CGEMapEntityFileIO.cpp

//## begin module%3CA6E1CA02EB.additionalIncludes preserve=no
//## end module%3CA6E1CA02EB.additionalIncludes

//## begin module%3CA6E1CA02EB.includes preserve=yes
//## end module%3CA6E1CA02EB.includes

// CGEMapEntityFileIO
#include "Game\GameScene\GameMap\GEMap\CGEMapEntityFileIO.h"
//## begin module%3CA6E1CA02EB.additionalDeclarations preserve=yes
#include "memory/gammae_mem.h"
//## end module%3CA6E1CA02EB.additionalDeclarations


// Class CGEMapEntityFileIO 

CGEMapEntityFileIO::CGEMapEntityFileIO()
  //## begin CGEMapEntityFileIO::CGEMapEntityFileIO%.hasinit preserve=no
  //## end CGEMapEntityFileIO::CGEMapEntityFileIO%.hasinit
  //## begin CGEMapEntityFileIO::CGEMapEntityFileIO%.initialization preserve=yes
  //## end CGEMapEntityFileIO::CGEMapEntityFileIO%.initialization
{
  //## begin CGEMapEntityFileIO::CGEMapEntityFileIO%.body preserve=yes
  //## end CGEMapEntityFileIO::CGEMapEntityFileIO%.body
}


CGEMapEntityFileIO::~CGEMapEntityFileIO()
{
  //## begin CGEMapEntityFileIO::~CGEMapEntityFileIO%.body preserve=yes
  //## end CGEMapEntityFileIO::~CGEMapEntityFileIO%.body
}



//## Other Operations (implementation)
void CGEMapEntityFileIO::SaveEntity (CMapEntity* _poEnt, CFile& _roFile)
{
  //## begin CGEMapEntityFileIO::SaveEntity%1017566940.body preserve=yes
	assert(_poEnt && "NULL Entity");
	
	_roFile.Write((int)_poEnt->eClass);

	switch(_poEnt->eClass)
	{
		case eMapEnt_World:
		{
			_roFile.WriteCharArray( ((CMapEnt_World*)_poEnt)->szWorldFile,32 );
			_roFile.WriteFloatArray( (float*)&((CMapEnt_World*)_poEnt)->oAmbColor,4  );
		}
		break;

		case eMapEnt_NULL:
		{
		}
		break;

		case eMapEnt_PlayerStart:
		{
			_roFile.WriteFloatArray( ((CMapEnt_PlayerStart*)_poEnt)->oPos.v,3 );
			_roFile.Write(((CMapEnt_PlayerStart*)_poEnt)->iType );
		}
		break;
		
		case eMapEnt_SrcPoint:
		{
			_roFile.WriteFloatArray( ((CMapEnt_SrcPoint*)_poEnt)->oPos.v,3 );
		}
		break;

		case eMapEnt_DstPoint:
		{
			_roFile.WriteFloatArray( ((CMapEnt_DstPoint*)_poEnt)->oPos.v,3 );
		}
		break;

		case eMapEnt_Sound:
		{
			_roFile.WriteCharArray ( ((CMapEnt_Target*)_poEnt)->szName,32 );
			_roFile.WriteCharArray ( ((CMapEnt_Sound*)_poEnt)->szFileName,64 );
			_roFile.WriteFloatArray( ((CMapEnt_Sound*)_poEnt)->oPos.v,3 );
			_roFile.Write(((CMapEnt_Sound*)_poEnt)->iType );
		}
		break;
		
		case eMapEnt_Light:
		{
			_roFile.WriteCharArray ( ((CMapEnt_Target*)_poEnt)->szName,32 );
			_roFile.WriteFloatArray(((CMapEnt_Light*)_poEnt)->oPos.v,3 );
			_roFile.WriteFloatArray(((CMapEnt_Light*)_poEnt)->oDir.v,3 );						
			_roFile.WriteFloatArray( (float*)&((CMapEnt_Light*)_poEnt)->Color,4  );
			_roFile.Write          (((CMapEnt_Light*)_poEnt)->fRadius);
			_roFile.Write		   (((CMapEnt_Light*)_poEnt)->iType );
		}
		break;

		case eMapEnt_Monster:
		{
			_roFile.WriteCharArray ( ((CMapEnt_Target*)_poEnt)->szName,32 );
			_roFile.WriteFloatArray( ((CMapEnt_Monster*)_poEnt)->oPos.v,3 );
			_roFile.Write(((CMapEnt_Monster*)_poEnt)->iType );
		}
		break;

		case eMapEnt_PowerUp:
		{
			_roFile.WriteCharArray ( ((CMapEnt_Target*)_poEnt)->szName,32 );
			_roFile.WriteFloatArray( ((CMapEnt_PowerUp*)_poEnt)->oPos.v,3 );
			_roFile.Write(((CMapEnt_PowerUp*)_poEnt)->iType );
		}
		break;
		
		case eMapEnt_Item:
		{
			_roFile.WriteCharArray ( ((CMapEnt_Target*)_poEnt)->szName,32 );
			_roFile.WriteFloatArray( ((CMapEnt_Item*)_poEnt)->oPos.v,3 );
			_roFile.Write(((CMapEnt_Item*)_poEnt)->iType );
		}
		break;

		case eMapEnt_Trigger:
		{
			_roFile.WriteCharArray ( ((CMapEnt_Target *)_poEnt)->szName,32 );
			_roFile.WriteCharArray ( ((CMapEnt_Trigger*)_poEnt)->szTargetName,32 );
			_roFile.WriteCharArray ( ((CMapEnt_Trigger*)_poEnt)->szSecTarget ,32 );
			_roFile.WriteFloatArray( ((CMapEnt_Trigger*)_poEnt)->oMax.v ,3 );
			_roFile.WriteFloatArray( ((CMapEnt_Trigger*)_poEnt)->oMin.v ,3 );
		}
		break;

		case eMapEnt_TargetMultiple:
		{
			_roFile.WriteCharArray ( ((CMapEnt_Target *)_poEnt)->szName,32 );			
			
			for (int iEnt=0;iEnt<((CMapEnt_TargetMultiple*)_poEnt)->aoTargets.iNumElems();iEnt++)
				SaveEntity(((CMapEnt_TargetMultiple*)_poEnt)->aoTargets[iEnt],_roFile);
		}
		break;

		case eMapEnt_Platform:
		{
			_roFile.WriteCharArray ( ((CMapEnt_Target *)_poEnt)->szName,32 );
			_roFile.Write( ((CMapEnt_Platform*)_poEnt)->fSpeed    );
			_roFile.Write( ((CMapEnt_Platform*)_poEnt)->fEndAc    );
			_roFile.Write( ((CMapEnt_Platform*)_poEnt)->fStartDec );
			_roFile.WriteFloatArray( ((CMapEnt_Platform*)_poEnt)->oSrcPos.v ,3 );
			_roFile.WriteFloatArray( ((CMapEnt_Platform*)_poEnt)->oDstPos.v ,3 );

			CSaverGEM oSaver;
			oSaver.iSave(_roFile,((CMapEnt_Platform*)_poEnt)->poScn);
		}
		break;
	}
  //## end CGEMapEntityFileIO::SaveEntity%1017566940.body
}

CMapEntity* CGEMapEntityFileIO::poLoadEntity (CFile& _roFile)
{
  //## begin CGEMapEntityFileIO::poLoadEntity%1017566941.body preserve=yes
	CMapEntity			*poEnt = NULL;
	CMapEntityClass		eEntClass;

	eEntClass = (CMapEntityClass)_roFile.iRead();
	switch(eEntClass)
	{
		case eMapEnt_World:
		{
			poEnt = mNew CMapEnt_World;
			_roFile.ReadCharArray( ((CMapEnt_World*)poEnt)->szWorldFile,32 );
			_roFile.ReadFloatArray( (float*)&((CMapEnt_World*)poEnt)->oAmbColor,4  );
		}
		break;

		case eMapEnt_NULL:
		{
		}
		break;
		
		case eMapEnt_PlayerStart:
		{
			poEnt = mNew CMapEnt_PlayerStart;
			_roFile.ReadFloatArray( ((CMapEnt_PlayerStart*)poEnt)->oPos.v,3 );			
			((CMapEnt_PlayerStart*)poEnt)->iType = _roFile.iRead();
		}
		break;

		case eMapEnt_SrcPoint:
		{
			poEnt = mNew CMapEnt_SrcPoint;
			_roFile.ReadFloatArray( ((CMapEnt_SrcPoint*)poEnt)->oPos.v,3 );
		}
		break;

		case eMapEnt_DstPoint:
		{
			poEnt = mNew CMapEnt_DstPoint;
			_roFile.ReadFloatArray( ((CMapEnt_DstPoint*)poEnt)->oPos.v,3 );
		}
		break;


		case eMapEnt_Sound:
		{
			poEnt = mNew CMapEnt_Sound;
			
			_roFile.ReadCharArray ( ((CMapEnt_Target*)poEnt)->szName,32 );
			_roFile.ReadCharArray ( ((CMapEnt_Sound*)poEnt)->szName,64);
			_roFile.ReadFloatArray( ((CMapEnt_Sound*)poEnt)->oPos.v,3 );
			((CMapEnt_Sound*)poEnt)->iType = _roFile.iRead();
		}
		break;
		
		case eMapEnt_Light:
		{
			poEnt = mNew CMapEnt_Light;
			
			_roFile.ReadCharArray ( ((CMapEnt_Target*)poEnt)->szName,32 );
			_roFile.ReadFloatArray(((CMapEnt_Light*)poEnt)->oPos.v,3 );
			_roFile.ReadFloatArray(((CMapEnt_Light*)poEnt)->oDir.v,3 );						
			_roFile.ReadFloatArray( (float*)&((CMapEnt_Light*)poEnt)->Color,4  );			
			((CMapEnt_Light*)poEnt)->fRadius = _roFile.fRead();
			((CMapEnt_Light*)poEnt)->iType = _roFile.iRead();
		}
		break;

		case eMapEnt_Monster:
		{
			poEnt = mNew CMapEnt_Monster;
			
			_roFile.ReadCharArray ( ((CMapEnt_Target*)poEnt)->szName,32 );
			_roFile.ReadFloatArray( ((CMapEnt_Monster*)poEnt)->oPos.v,3 );
			((CMapEnt_Monster*)poEnt)->iType = _roFile.iRead();
		}
		break;

		case eMapEnt_PowerUp:
		{
			poEnt = mNew CMapEnt_PowerUp;
			
			_roFile.ReadCharArray ( ((CMapEnt_Target*)poEnt)->szName,32 );
			_roFile.ReadFloatArray( ((CMapEnt_PowerUp*)poEnt)->oPos.v,3 );			
			((CMapEnt_PowerUp*)poEnt)->iType = _roFile.iRead();

		}
		break;
		
		case eMapEnt_Item:
		{
			poEnt = mNew CMapEnt_Item;
			
			_roFile.ReadCharArray ( ((CMapEnt_Target*)poEnt)->szName,32 );
			_roFile.ReadFloatArray( ((CMapEnt_Item*)poEnt)->oPos.v,3 );			
			((CMapEnt_Item*)poEnt)->iType = _roFile.iRead();
		}
		break;

		case eMapEnt_Trigger:
		{
			poEnt = mNew CMapEnt_Trigger;

			_roFile.ReadCharArray ( ((CMapEnt_Target*)poEnt)->szName,32 );
			_roFile.ReadCharArray ( ((CMapEnt_Trigger*)poEnt)->szTargetName,32 );
			_roFile.ReadCharArray ( ((CMapEnt_Trigger*)poEnt)->szSecTarget ,32 );
			_roFile.ReadFloatArray( ((CMapEnt_Trigger*)poEnt)->oMax.v ,3 );
			_roFile.ReadFloatArray( ((CMapEnt_Trigger*)poEnt)->oMin.v ,3 );
		}
		break;

		case eMapEnt_TargetMultiple:
		{
			poEnt = mNew CMapEnt_TargetMultiple;

			_roFile.ReadCharArray ( ((CMapEnt_Target *)poEnt)->szName,32 );			
			
			for (int iEnt=0;iEnt<((CMapEnt_TargetMultiple*)poEnt)->aoTargets.iNumElems();iEnt++)
				((CMapEnt_TargetMultiple*)poEnt)->aoTargets.iAdd( (CMapEnt_Target*)poLoadEntity(_roFile) );
		}
		break;

		case eMapEnt_Platform:
		{
			poEnt = mNew CMapEnt_Platform;

			_roFile.ReadCharArray ( ((CMapEnt_Target *)poEnt)->szName,32 );
			((CMapEnt_Platform*)poEnt)->fSpeed    = _roFile.fRead();
			((CMapEnt_Platform*)poEnt)->fEndAc    = _roFile.fRead();
			((CMapEnt_Platform*)poEnt)->fStartDec = _roFile.fRead();
			_roFile.ReadFloatArray( ((CMapEnt_Platform*)poEnt)->oSrcPos.v ,3 );
			_roFile.ReadFloatArray( ((CMapEnt_Platform*)poEnt)->oDstPos.v ,3 );
			
			unsigned int uiID;
			unsigned int uiBlockSize;

			_roFile.iRead(&uiID,4);
			uiBlockSize = _roFile.iRead();

			if ( uiID != GEM_FILE_IDENTIFIER)
			{
				mDel poEnt;
				return(NULL);
			}

			CLoaderGEM oLoader;
			((CMapEnt_Platform*)poEnt)->poScn = oLoader.pLoad(_roFile);
		}
		break;
	}

	return(poEnt);
  //## end CGEMapEntityFileIO::poLoadEntity%1017566941.body
}

// Additional Declarations
  //## begin CGEMapEntityFileIO%3CA6E1CA02EB.declarations preserve=yes
  //## end CGEMapEntityFileIO%3CA6E1CA02EB.declarations

//## begin module%3CA6E1CA02EB.epilog preserve=yes
//## end module%3CA6E1CA02EB.epilog
