//## begin module%3AFE9A89014A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AFE9A89014A.cm

//## begin module%3AFE9A89014A.cp preserve=no
//## end module%3AFE9A89014A.cp

//## Module: CTMSector_8_16%3AFE9A89014A; Pseudo Package body
//## Source file: E:\Projects\GammaE\TerrainData\Sector\TexMap\CTMSector_8_16.cpp

//## begin module%3AFE9A89014A.additionalIncludes preserve=no
//## end module%3AFE9A89014A.additionalIncludes

//## begin module%3AFE9A89014A.includes preserve=yes
//## end module%3AFE9A89014A.includes

// CTMSector_8_16
#include "TerrainData\Sector\TexMap\CTMSector_8_16.h"
//## begin module%3AFE9A89014A.additionalDeclarations preserve=yes
#define			TM_RFLAGS_TRANSITIONTEX_MASK		0x00ff
#define         TM_RFLAGS_TRANSITIONTEX_SHIFTBITS   0

#define			TM_RFLAGS_TRANSITION_MASK			0x0300
#define			TM_RFLAGS_TRANSITION_SHIFTBITS      8

#define			TM_RFLAGS_ROTATION_MASK				0x0c00
#define         TM_RFLAGS_ROTATION_SHIFTBITS        10

#define			TM_RFLAGS_INVISTILE_MASK			0x1000
#define         TM_RFLAGS_INVISTILE_SHIFTBITS       12

#define			TMAP_IDX_OFFSET						(Resolution*Resolution*2)
#define			TMAP_FLAG_OFFSET					(0)

CTile 		T;

unsigned char   ucTile;
unsigned short  usFlag;
unsigned char  *pucTile;
unsigned short *pusFlag;

//## end module%3AFE9A89014A.additionalDeclarations


// Class CTMSector_8_16 

CTMSector_8_16::CTMSector_8_16()
  //## begin CTMSector_8_16::CTMSector_8_16%.hasinit preserve=no
  //## end CTMSector_8_16::CTMSector_8_16%.hasinit
  //## begin CTMSector_8_16::CTMSector_8_16%.initialization preserve=yes
  //## end CTMSector_8_16::CTMSector_8_16%.initialization
{
  //## begin CTMSector_8_16::CTMSector_8_16%.body preserve=yes
  	ulID = MAKE_RIFF_ID('T','M','C','S');
  //## end CTMSector_8_16::CTMSector_8_16%.body
}


CTMSector_8_16::~CTMSector_8_16()
{
  //## begin CTMSector_8_16::~CTMSector_8_16%.body preserve=yes
  //## end CTMSector_8_16::~CTMSector_8_16%.body
}



//## Other Operations (implementation)
CSector * CTMSector_8_16::CreateClass ()
{
  //## begin CTMSector_8_16::CreateClass%989763986.body preserve=yes
  	return (new CTMSector_8_16() );
  //## end CTMSector_8_16::CreateClass%989763986.body
}

unsigned long CTMSector_8_16::ElemArraySize (int _iResolution)
{
  //## begin CTMSector_8_16::ElemArraySize%989763987.body preserve=yes
	return ( (1+2) * _iResolution * _iResolution );
  //## end CTMSector_8_16::ElemArraySize%989763987.body
}

CSectElem & CTMSector_8_16::GetValue (int _X, int _Y)
{
  //## begin CTMSector_8_16::GetValue%989763988.body preserve=yes
 	ucTile = ((unsigned char  *)pData)[TMAP_IDX_OFFSET  + _Y*Resolution+_X];
	usFlag = ((unsigned short *)pData)[TMAP_FLAG_OFFSET + _Y*Resolution+_X];

    T.SetTileIdx        (  ucTile );
	T.SetRotationType   ( (usFlag & TM_RFLAGS_ROTATION_MASK     ) >> TM_RFLAGS_ROTATION_SHIFTBITS      );
	T.SetTransitionType ( (usFlag & TM_RFLAGS_TRANSITION_MASK   ) >> TM_RFLAGS_TRANSITION_SHIFTBITS    );
	T.SetTransTileIdx   ( (usFlag & TM_RFLAGS_TRANSITIONTEX_MASK) >> TM_RFLAGS_TRANSITIONTEX_SHIFTBITS );
	T.SetInvisible      ( (usFlag & TM_RFLAGS_INVISTILE_MASK    ) >> TM_RFLAGS_INVISTILE_SHIFTBITS     );

    return T;
  //## end CTMSector_8_16::GetValue%989763988.body
}

void CTMSector_8_16::SetValue (int _X, int _Y, CSectElem &_Value)
{
  //## begin CTMSector_8_16::SetValue%989763989.body preserve=yes
	pucTile = &((unsigned char  *)pData)[TMAP_IDX_OFFSET  + _Y*Resolution+_X];
	pusFlag = &((unsigned short *)pData)[TMAP_FLAG_OFFSET + _Y*Resolution+_X];

	*pusFlag = ((*(CTile *)&_Value).GetRotationType()   << TM_RFLAGS_ROTATION_SHIFTBITS)   |
		       ((*(CTile *)&_Value).GetTransitionType() << TM_RFLAGS_TRANSITION_SHIFTBITS) |
			   ((*(CTile *)&_Value).GetTransTileIdx()   << TM_RFLAGS_TRANSITIONTEX_SHIFTBITS)|
			   ((*(CTile *)&_Value).GetInvisible()	    << TM_RFLAGS_INVISTILE_SHIFTBITS);

	*pucTile = (*(CTile *)&_Value).GetTileIdx();
  //## end CTMSector_8_16::SetValue%989763989.body
}

// Additional Declarations
  //## begin CTMSector_8_16%3AFE9A89014A.declarations preserve=yes
  //## end CTMSector_8_16%3AFE9A89014A.declarations

//## begin module%3AFE9A89014A.epilog preserve=yes
//## end module%3AFE9A89014A.epilog
