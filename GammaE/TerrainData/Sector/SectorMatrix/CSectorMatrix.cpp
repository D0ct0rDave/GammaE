//## begin module%3AF9B524038E.cm preserve=no
//## end module%3AF9B524038E.cm

//## begin module%3AF9B524038E.cp preserve=no
//## end module%3AF9B524038E.cp

//## Module: CSectorMatrix%3AF9B524038E; Pseudo Package body
//## Source file: i:\Projects\GammaE\TerrainData\Sector\SectorMatrix\CSectorMatrix.cpp

//## begin module%3AF9B524038E.additionalIncludes preserve=no
//## end module%3AF9B524038E.additionalIncludes

//## begin module%3AF9B524038E.includes preserve=yes
#include <assert.h>
#include <string.h>

#include "File.h"
//## end module%3AF9B524038E.includes

// CSectorMatrix
#include "TerrainData\Sector\SectorMatrix\CSectorMatrix.h"
//## begin module%3AF9B524038E.additionalDeclarations preserve=yes
//## end module%3AF9B524038E.additionalDeclarations


// Class CSectorMatrix 






CSectorMatrix::CSectorMatrix()
  //## begin CSectorMatrix::CSectorMatrix%.hasinit preserve=no
      : SecsPerRow(0), SecsPerCol(0), SectArray(NULL), iDataType(0)
  //## end CSectorMatrix::CSectorMatrix%.hasinit
  //## begin CSectorMatrix::CSectorMatrix%.initialization preserve=yes
  //## end CSectorMatrix::CSectorMatrix%.initialization
{
  //## begin CSectorMatrix::CSectorMatrix%.body preserve=yes
  //## end CSectorMatrix::CSectorMatrix%.body
}


CSectorMatrix::~CSectorMatrix()
{
  //## begin CSectorMatrix::~CSectorMatrix%.body preserve=yes
	  Invalidate();
  //## end CSectorMatrix::~CSectorMatrix%.body
}


const CSectorMatrix & CSectorMatrix::operator=(const CSectorMatrix &right)
{
  //## begin CSectorMatrix::operator=%.body preserve=yes
	int cSect;

    Init(right.SecsPerRow,right.SecsPerCol);
    Init(right.Resolution,right.b21);

	// Copy object data
	memcpy(pData,right.pData,DataSize());

	// Copy each sector array element
	for (cSect=0;cSect<SecsPerRow*SecsPerCol;cSect++)
    {
    	SectArray[cSect] = right.SectArray[cSect]->CreateClass();
		*SectArray[cSect] = *right.SectArray[cSect];
    }

	return (*this);
  //## end CSectorMatrix::operator=%.body
}



//## Other Operations (implementation)
int CSectorMatrix::iLoadWithHandler (FILE *_FD)
{
  //## begin CSectorMatrix::iLoadWithHandler%989444559.body preserve=yes
    unsigned char	ucMajorVersion;
    unsigned char	ucMinorVersion;
	int 			cI,cJ;

	// Control file descriptor
    if (! _FD)
    {
		ERROR_SetError("CSECTMAT1011","NULL object file descriptor.");
        return(RES_OP_ERROR);
    }

    // Read object version
    if (! fread(&ucMajorVersion,1,1,_FD))
    {
		ERROR_SetError("CSECTMAT1012","Unable to read object data");
        return(RES_OP_ERROR);
    }

	// Read minor version
    fread(&ucMinorVersion,1,1,_FD);

	// Control version number
    if ((ucMajorVersion > ucMajVer) || ((ucMajorVersion == ucMajVer) && (ucMinorVersion > ucMinVer)) )
    {
        ERROR_SetError("CSECTMAT1013","Incorrect object version number");
        return(RES_OP_ERROR);
    }

    // Read object info
    fread(&SecsPerRow,4,1,_FD);

    // Read object info
    fread(&SecsPerCol,4,1,_FD);

    // Read most commmon resolution
    fread(&Resolution,4,1,_FD);

    // Write power of 2 plus 1 ?
    fread(&b21,1,1,_FD);

    // Read sector Type
	fread(&iDataType,4,1,_FD);

    // Create the circuit
    Init(SecsPerRow,SecsPerCol,Resolution,iDataType,b21);

	// Read class specific info
	fread (pData,DataSize(),1,_FD );

	// Now load sector array	
	for (cJ=0;cJ<SecsPerCol;cJ++)
		for (cI=0;cI<SecsPerRow;cI++)
		{	
			SectArray[cJ*SecsPerRow+cI] = poSectManager->poCreateClass(_FD);

			if (SectArray[cJ*SecsPerRow+cI])
			{
				if (! SectArray[cJ*SecsPerRow+cI]->iLoadWithHandler(_FD) )
				{
					ERROR_SetError("CSECTMAT1014","Unable to read sectors data");
					return(RES_OP_ERROR);
				}
			}

		}


	return(RES_OP_OK);
  //## end CSectorMatrix::iLoadWithHandler%989444559.body
}

int CSectorMatrix::iSaveWithHandler (FILE *_FD)
{
  //## begin CSectorMatrix::iSaveWithHandler%989444560.body preserve=yes
	unsigned long ulBlockLenght;
	int			  cI,cJ;

	// Control file descriptor
    if (! _FD)
    {
		ERROR_SetError("CSECTMAT2011","NULL object file descriptor.");
        return(RES_OP_ERROR);
    }

    // Write identifier
    if (! fwrite(&ulID,4,1,_FD))
    {
        ERROR_SetError("CSECTMAT2012","Unable to save object data");
        return(RES_OP_ERROR);
    }
	
    // Write block length
    ulBlockLenght = ByteSize();
	fwrite(&ulBlockLenght,4,1,_FD);

    // Write object version
    fwrite(&ucMajVer,1,1,_FD);

	// Write minor version
    fwrite(&ucMinVer,1,1,_FD);

    // Write object info
    fwrite(&SecsPerRow,4,1,_FD);

    // Write object info
    fwrite(&SecsPerCol,4,1,_FD);

    // write most commmon resolution
    fwrite(&Resolution,4,1,_FD);

    // Write power of 2 plus 1 ?
    fwrite(&b21,1,1,_FD);

    // Write Sector Type
	fwrite(&iDataType,4,1,_FD);

	// Write class specific info
	fwrite (pData, DataSize(),1,_FD );

	// Now write sector array
	for (cJ=0;cJ<SecsPerCol;cJ++)
		for (cI=0;cI<SecsPerRow;cI++)
		{	
			if (! SectArray[cJ*SecsPerRow+cI]->iSaveWithHandler(_FD) )
			{
				ERROR_SetError("CSECTMAT1014","Unable to read sectors data");
				return(RES_OP_ERROR);
			}

		}

	return(RES_OP_OK);
  //## end CSectorMatrix::iSaveWithHandler%989444560.body
}

void CSectorMatrix::Invalidate ()
{
  //## begin CSectorMatrix::Invalidate%989444562.body preserve=yes

	if (SectArray) delete[] SectArray;
	SectArray  = NULL;
	SecsPerRow = 0;
	SecsPerCol = 0;	

  //## end CSectorMatrix::Invalidate%989444562.body
}

void CSectorMatrix::Init (int _SecsPerRow, int _SecsPerCol)
{
  //## begin CSectorMatrix::Init%989530854.body preserve=yes
	Invalidate();
		
	SecsPerRow = _SecsPerRow;
	SecsPerCol = _SecsPerCol;

	SectArray = new CSector *[SecsPerRow*SecsPerCol];
  //## end CSectorMatrix::Init%989530854.body
}

void CSectorMatrix::Init (int _SecsPerRow, int _SecsPerCol, int _SectorRes, int _SectorType, bool _b21)
{
  //## begin CSectorMatrix::Init%989530855.body preserve=yes
	Init(_SectorRes,_b21);
    Init(_SecsPerRow,_SecsPerCol);
  //## end CSectorMatrix::Init%989530855.body
}

void CSectorMatrix::Init (int _iRes, bool _b21)
{
  //## begin CSectorMatrix::Init%989530858.body preserve=yes
	Resolution = _iRes;  	
	b21 = _b21;
	
	if (b21) iLast = Resolution - 1;
  //## end CSectorMatrix::Init%989530858.body
}

CSectElem & CSectorMatrix::GetValue (int _X, int _Y)
{
  //## begin CSectorMatrix::GetValue%989530859.body preserve=yes
	assert( SectArray && "No sector array");
		
	int cSectX      = (_X/iLast);
	int cSectY      = (_Y/iLast);
	int cSect       = cSectY*SecsPerRow + cSectX;

	_X -= cSectX*iLast;
	_Y -= cSectY*iLast;

	return( GetValueFromSect(cSect,_X,_Y) );
  //## end CSectorMatrix::GetValue%989530859.body
}

void CSectorMatrix::SetValue (int _X, int _Y, CSectElem &_Value)
{
  //## begin CSectorMatrix::SetValue%989530860.body preserve=yes
	assert( SectArray && "No sector array");

	int iNeighFlags = 0;
	int iFinalFlags = 0;
	int cSectX      = (_X/iLast);
	int cSectY      = (_Y/iLast);

	int cSect = cSectY*SecsPerRow + cSectX;

	_X -= cSectX*iLast;
	_Y -= cSectY*iLast;

	// Set the current value
	SetValueFromSect(cSect             ,_X   ,_Y   ,_Value);	

	if (! b21) return;

    // ----------- Fills the last row and column of the circuit
	if ((_X == iLast-1) && (cSectX == SecsPerRow-1)) iFinalFlags |= 0x01;
	if ((_Y == iLast-1) && (cSectY == SecsPerCol-1)) iFinalFlags |= 0x02;

    switch (iFinalFlags)
    {
        case 1: SetValueFromSect(cSectY*SecsPerRow+cSectX,iLast,_Y,_Value);
                if (_Y==iLast-1) SetValueFromSect(cSectY*SecsPerRow+cSectX,iLast,iLast,_Value);
                break;
        case 2: SetValueFromSect(cSectY*SecsPerRow+cSectX,_X,iLast,_Value);
                if (_X==iLast-1) SetValueFromSect(cSectY*SecsPerRow+cSectX,iLast,iLast,_Value);
                break;
        case 3: SetValueFromSect(cSectY*SecsPerRow+cSectX,iLast,iLast,_Value);
                break;
    }
  //## end CSectorMatrix::SetValue%989530860.body
}

CSectElem & CSectorMatrix::GetValueFromSect (int _iSect, int _X, int _Y)
{
  //## begin CSectorMatrix::GetValueFromSect%989530861.body preserve=yes
	assert( SectArray && "No sector array");
	return( SectArray[_iSect]->GetValue(_X,_Y) );
  //## end CSectorMatrix::GetValueFromSect%989530861.body
}

void CSectorMatrix::SetValueFromSect (int _iSect, int _X, int _Y, CSectElem &_Value)
{
  //## begin CSectorMatrix::SetValueFromSect%989530862.body preserve=yes
	assert( SectArray && "No sector array");
	SectArray[_iSect]->SetValue(_X,_Y,_Value);

    if (! b21) return;
    
	// ----------- Fills the ecXtra Row & Column for the neightbour sectors >
    int  iNeighFlags = 0;
    if ( (_X==0) && ((_iSect % SecsPerRow) >0) ) iNeighFlags |= 0x01;
    if ( (_Y==0) && ((_iSect / SecsPerCol) >0) ) iNeighFlags |= 0x02;

    switch (iNeighFlags)
    {
        case 1: SectArray[_iSect-1           ]->SetValue(iLast,_Y   ,_Value);
                break;
        case 2: SectArray[_iSect-SecsPerRow  ]->SetValue(_X   ,iLast,_Value);
                break;
        case 3: SectArray[_iSect-1           ]->SetValue(iLast,_Y   ,_Value);
                SectArray[_iSect-SecsPerRow  ]->SetValue(_X   ,iLast,_Value);
                SectArray[_iSect-SecsPerRow-1]->SetValue(iLast,iLast,_Value);
                break;
    }
  //## end CSectorMatrix::SetValueFromSect%989530862.body
}

unsigned long CSectorMatrix::ByteSize ()
{
  //## begin CSectorMatrix::ByteSize%990283800.body preserve=yes
	unsigned int uiByteSum = 0;
	int			 cSect;
	
	for (cSect=0;cSect<SecsPerCol*SecsPerRow;cSect++)
		uiByteSum += SectArray[cSect]->ByteSize();

	return ( DataSize() + uiByteSum );
  //## end CSectorMatrix::ByteSize%990283800.body
}

CSector * CSectorMatrix::GenerateLOD (int _iLOD)
{
  //## begin CSectorMatrix::GenerateLOD%991155095.body preserve=yes
	unsigned int	cSect;
    CSectorMatrix	*NewObj = (CSectorMatrix *)CreateClass();
	
	// Create the new object
	NewObj->Init(SecsPerRow,SecsPerCol);
    NewObj->Init(Resolution,b21);

	for (cSect=0;cSect<SecsPerRow*SecsPerCol;cSect++)
	{
		// Set the current element data generation method equal to the parent
		SectArray[cSect]->SetVGenMethod(VGenMethod);
		// Generate a sector LOD
		NewObj->SectArray[cSect] = SectArray[cSect]->GenerateLOD(_iLOD);
	}

    NewObj->Resolution = NewObj->SectArray[0]->GetResolution();
    
	return(NewObj);
  //## end CSectorMatrix::GenerateLOD%991155095.body
}

void CSectorMatrix::SetVGenMethod (EGenerationMethod value)
{
  //## begin CSectorMatrix::SetVGenMethod%1026770436.body preserve=yes
	VGenMethod = value;
	for (int cSect=0;cSect<SecsPerCol*SecsPerRow;cSect++)
		GetSector(cSect)->SetVGenMethod(value);
  //## end CSectorMatrix::SetVGenMethod%1026770436.body
}

// Additional Declarations
  //## begin CSectorMatrix%3AF9B524038E.declarations preserve=yes
  //## end CSectorMatrix%3AF9B524038E.declarations

//## begin module%3AF9B524038E.epilog preserve=yes
//## end module%3AF9B524038E.epilog
