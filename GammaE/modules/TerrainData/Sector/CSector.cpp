//## begin module%3AF50E46017C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AF50E46017C.cm

//## begin module%3AF50E46017C.cp preserve=no
//## end module%3AF50E46017C.cp

//## Module: CSector%3AF50E46017C; Pseudo Package body
//## Source file: E:\Projects\GammaE\TerrainData\Sector\CSector.cpp

//## begin module%3AF50E46017C.additionalIncludes preserve=no
//## end module%3AF50E46017C.additionalIncludes

//## begin module%3AF50E46017C.includes preserve=yes
#include <assert.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "File.h"
//## end module%3AF50E46017C.includes

// CSector
#include "TerrainData\Sector\CSector.h"
//## begin module%3AF50E46017C.additionalDeclarations preserve=yes

// GetValueLOD local variable
	CSectElem *GVL_a  = NULL;
	CSectElem *GVL_b  = NULL;
	CSectElem *GVL_c  = NULL;
	CSectElem *GVL_d  = NULL;
	CSectElem *GVL_r1 = NULL;
	CSectElem *GVL_r2 = NULL;

	CSectElem *GVL_Sum = NULL;
//## end module%3AF50E46017C.additionalDeclarations


// Class CSector 









CSector::CSector()
  //## begin CSector::CSector%.hasinit preserve=no
      : ulID(0), VGenMethod(eGM_Nearest), pData(NULL), Resolution(0), ucMajVer(1), ucMinVer(0), b21(false), iLast(0)
  //## end CSector::CSector%.hasinit
  //## begin CSector::CSector%.initialization preserve=yes
  //## end CSector::CSector%.initialization
{
  //## begin CSector::CSector%.body preserve=yes
  //## end CSector::CSector%.body
}


CSector::~CSector()
{
  //## begin CSector::~CSector%.body preserve=yes
	Invalidate();
  //## end CSector::~CSector%.body
}


const CSector & CSector::operator=(const CSector &right)
{
  //## begin CSector::operator=%.body preserve=yes
	// Assume assignement between elements of identical class
	Init(right.Resolution,right.b21);
	memcpy( pData,right.pData,DataSize() );
	
	return (*this);
  //## end CSector::operator=%.body
}



//## Other Operations (implementation)
void CSector::Init (int _iRes, bool _b21)
{
  //## begin CSector::Init%989359113.body preserve=yes
  	Invalidate();

	Resolution = _iRes;
	b21 = _b21;
	
	iLast	   = _iRes-1;
	pData      = malloc( DataSize() );
	memset(pData,0,DataSize() );

  //## end CSector::Init%989359113.body
}

void CSector::Invalidate ()
{
  //## begin CSector::Invalidate%989359112.body preserve=yes
	if (pData) free(pData);
	
	pData      = NULL;
	Resolution = 0;
  //## end CSector::Invalidate%989359112.body
}

unsigned long CSector::ByteSize ()
{
  //## begin CSector::ByteSize%989139157.body preserve=yes
	
	// Version + Res + Data
	return ( 1+1 + 4 + DataSize() );

  //## end CSector::ByteSize%989139157.body
}

CSectElem & CSector::GetValueF (float _fX, float _fY)
{
  //## begin CSector::GetValueF%990742414.body preserve=yes
	if (VGenMethod == eGM_Nearest) return ( GetValue((int)_fX,(int)_fY) );

	if ( GVL_a )
	{
		delete GVL_a;
		delete GVL_b;
		delete GVL_c;
		delete GVL_d;
		delete GVL_r1;
		delete GVL_r2;
	}
	
	GVL_a  = GetValue(0,0).CreateClass();
	GVL_b  = GetValue(0,0).CreateClass();
	GVL_c  = GetValue(0,0).CreateClass();
	GVL_d  = GetValue(0,0).CreateClass();
	GVL_r1 = GetValue(0,0).CreateClass();
	GVL_r2 = GetValue(0,0).CreateClass();
    
	int 	iX1,iY1,iX2,iY2;	
    float	fX,fY;				// fractional parts

    iX1 = (int)_fX;
    iY1 = (int)_fY;

    if (iX1 < iLast) iX2 = iX1+1; else iX2 = iX1;
    if (iY1 < iLast) iY2 = iY1+1; else iY2 = iY1;

    fX = _fX - iX1;
    fY = _fY - iY1;

	GVL_a->Set( GetValue(iX1,iY1).Get() );
	GVL_b->Set( GetValue(iX2,iY1).Get() );
	GVL_c->Set( GetValue(iX1,iY2).Get() );
	GVL_d->Set( GetValue(iX2,iY2).Get() );

	switch (VGenMethod)
    {
		case eGM_Linear:	GVL_r1->LinInterpolate(*GVL_a,*GVL_b,fX);
				        	GVL_r2->LinInterpolate(*GVL_c,*GVL_d,fX);

							return ( GVL_a->LinInterpolate(*GVL_r1,*GVL_r2,fY) );

							break;
		case eGM_CosLinear: GVL_r1->CosInterpolate(*GVL_a,*GVL_b,fX);
				        	GVL_r2->CosInterpolate(*GVL_c,*GVL_d,fX);

							return ( GVL_a->CosInterpolate(*GVL_r1,*GVL_r2,fY) );
							break;
    }

	return ( *GVL_a );
  //## end CSector::GetValueF%990742414.body
}

CSectElem & CSector::GetValueLOD (int _X, int _Y, int _iLOD)
{
  //## begin CSector::GetValueLOD%991155097.body preserve=yes
	switch (VGenMethod)
	{
		case eGM_Nearest:	return( GetValue(_X,_Y) );
							break;
		case eGM_Linear:
		case eGM_CosLinear: int cK,cL,cX,cY,cElems,iSize;
							if (GVL_Sum) delete (GVL_Sum);

							GVL_Sum = GetValue(0,0).CreateClass();
							iSize = (1 << (_iLOD-1));

							cElems = 0;
							GVL_Sum->Clear();
							for (cL=-iSize;cL<iSize;cL++)
							{
								cY = _Y + cL;

								if ( (cY>=0) && (cY < Resolution) )
								{
									for (cK=-iSize;cK<iSize;cK++)
									{
										cX = _X + cK;

										if ((cX>=0) && (cX < Resolution))
										{
											GVL_Sum->Add( GetValue(cX,cY) );
											cElems++;
										}
									}
								}
							}

							if (cElems) GVL_Sum->Scale( 1.0f/(float)cElems );

							return ( *GVL_Sum );
							break;
	}

	return ( *GVL_Sum );
  //## end CSector::GetValueLOD%991155097.body
}

CSector * CSector::GenerateLOD (int _iLOD)
{
  //## begin CSector::GenerateLOD%989359111.body preserve=yes
	unsigned int	 uiNewSectorRes;
	unsigned int	 cI,cJ;
	CSector			*LODSect = CreateClass();

	if (_iLOD > 0)
	{
		// LOD reducido respector al original
		if (b21)
			uiNewSectorRes = ((Resolution & 0xfffffffe) >> _iLOD) + 1;
		else
			uiNewSectorRes = Resolution >> _iLOD;
		
		LODSect->Init(uiNewSectorRes,b21);
		
		for (cJ=0;cJ<uiNewSectorRes;cJ++)
			for (cI=0;cI<uiNewSectorRes;cI++)
				LODSect->SetValue(cI,cJ,GetValueLOD(cI << _iLOD,cJ << _iLOD,_iLOD) );
	}
else if (_iLOD < 0)
	{
		// LOD expandido respecto al original
		if (b21)
			uiNewSectorRes = ((Resolution & 0xfffffffe) << _iLOD) + 1;
		else
			uiNewSectorRes = Resolution >> _iLOD;
		
		LODSect->Init(uiNewSectorRes,b21);


		float cX,cY;
		float fStep = (float)Resolution / (float)uiNewSectorRes;		
		
		cY = 0;
		for (cJ=0;cJ<uiNewSectorRes;cJ++)
		{
			cX = 0;
			for (cI=0;cI<uiNewSectorRes;cI++)
			{
				LODSect->SetValue(cI,cJ,GetValueF(cX,cY) );
				cX += fStep;
			}

			cY += fStep;
		}
	}
else{
		// Direct copy: do not put -> *LODSect = *this
        // HeightField sectors need to recompute max mins
        LODSect->Init(Resolution,b21);
		for (cJ=0;cJ<Resolution;cJ++)
			for (cI=0;cI<Resolution;cI++)
				LODSect->SetValue(cI,cJ,GetValue(cI,cJ));
	}
	
	return(LODSect);
  //## end CSector::GenerateLOD%989359111.body
}

void CSector::GetLODData (int _iLOD, void *_pData)
{
  //## begin CSector::GetLODData%989359114.body preserve=yes	
  //## end CSector::GetLODData%989359114.body
}

int CSector::iLoad (char *_Filename)
{
  //## begin CSector::iLoad%989359124.body preserve=yes
    unsigned int   ulBlockLenght;
    unsigned int   ulLoadedID;
    FILE          *fd;
    int			   iRes;

	// Control Filename string
    if (! _Filename)
    {
        ERROR_SetError("CSECT1001","NULL object filename.");
        return(RES_OP_ERROR);
    }

	// Try opening file
	fd  = fopen (_Filename,"rb");
	if (! fd)
    {
        ERROR_SetError("CSECT1002","Unable to open file",_Filename);
        return(RES_OP_ERROR);
    }

    // Read identifier
    if (! fread(&ulLoadedID,4,1,fd))
    {
        ERROR_SetError("CSECT1003","Unable to read object from file");
        fclose(fd);
        return(RES_OP_ERROR);
    }

	// Compare IDs
    if (ulLoadedID != ulID)
    {
        ERROR_SetError("CSECT1004","Bad object identifier.");
        fclose(fd);
        return(RES_OP_ERROR);
    }

	// Read block lenght
    if (! fread(&ulBlockLenght,4,1,fd))
    {
        ERROR_SetError("CSECT1005","Unable to read data lenght from file");
        fclose(fd);
        return(RES_OP_ERROR);
    }

	// Load the rest of the data
    iRes = iLoadWithHandler(fd);

	// Close file
    fclose(fd);
	
    return ( iRes );
  //## end CSector::iLoad%989359124.body
}

int CSector::iLoadWithHandler (FILE *_FD)
{
  //## begin CSector::iLoadWithHandler%989359125.body preserve=yes
    unsigned char  ucMajorVersion;
    unsigned char  ucMinorVersion;

	// Control file descriptor
    if (! _FD)
    {
		ERROR_SetError("CSECT1011","NULL object file descriptor.");
        return(RES_OP_ERROR);
    }

    // Read object version
    if (! fread(&ucMajorVersion,1,1,_FD))
    {
		ERROR_SetError("CSECT1012","Unable to read object data");
        return(RES_OP_ERROR);
    }

	// Read minor version
    fread(&ucMinorVersion,1,1,_FD);

	// Control version number
    if ((ucMajorVersion > ucMajVer) || ((ucMajorVersion == ucMajVer) && (ucMinorVersion > ucMinVer)) )
    {
        ERROR_SetError("CSECT1013","Incorrect object version number");
        return(RES_OP_ERROR);
    }

    // Read object info
    fread(&b21,1,1,_FD);

    // Read object info
    fread(&Resolution,4,1,_FD);

    // Create the circuit
    Init(Resolution,b21);

    // Read object info
    fread( pData,DataSize(),1,_FD);

	return(RES_OP_OK);
  //## end CSector::iLoadWithHandler%989359125.body
}

int CSector::iSave (char *_Filename)
{
  //## begin CSector::iSave%989359126.body preserve=yes
    FILE			*fd;
    int				iRes;

    if (! _Filename)
    {
        ERROR_SetError("CSECT2001","NULL filename.");
        return(RES_OP_ERROR);
    }

	fd  = fopen (_Filename,"wb");
	if (! fd)
    {
        ERROR_SetError("CSECT2002","Unable to open file for saving",_Filename);
        return(RES_OP_ERROR);
    }

    iRes = iSaveWithHandler(fd);
    fclose(fd);
    
    return ( iRes );
  //## end CSector::iSave%989359126.body
}

int CSector::iSaveWithHandler (FILE *_FD)
{
  //## begin CSector::iSaveWithHandler%989359127.body preserve=yes
    unsigned int	ulBlockLenght;

    // Write identifier
    if (! fwrite(&ulID,4,1,_FD))
    {
        ERROR_SetError("CSECT2011","Unable to save object data");
        return(RES_OP_ERROR);
    }
	
    // Write block length
    ulBlockLenght = ByteSize();
	fwrite(&ulBlockLenght,4,1,_FD);

    // Write object version
    fwrite(&ucMajVer,1,1,_FD);
    fwrite(&ucMinVer,1,1,_FD);

    // Read object info
    fwrite(&b21,1,1,_FD);

    // Write object info
    fwrite(&Resolution,4,1,_FD);

    fwrite(pData,DataSize(),1,_FD);

    return(RES_OP_OK);
  //## end CSector::iSaveWithHandler%989359127.body
}

unsigned long CSector::DataSize ()
{
  //## begin CSector::DataSize%989359128.body preserve=yes
	return( ElemArraySize(Resolution) );
  //## end CSector::DataSize%989359128.body
}

unsigned long CSector::ElemArraySize (int _iResolution)
{
  //## begin CSector::ElemArraySize%989667594.body preserve=yes
	return(0);
  //## end CSector::ElemArraySize%989667594.body
}

// Additional Declarations
  //## begin CSector%3AF50E46017C.declarations preserve=yes
  //## end CSector%3AF50E46017C.declarations

//## begin module%3AF50E46017C.epilog preserve=yes
//## end module%3AF50E46017C.epilog
