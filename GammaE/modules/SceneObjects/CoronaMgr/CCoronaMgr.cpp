//## begin module%3C72C95203E5.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C72C95203E5.cm

//## begin module%3C72C95203E5.cp preserve=no
//## end module%3C72C95203E5.cp

//## Module: CCoronaMgr%3C72C95203E5; Pseudo Package body
//## Source file: i:\Projects\GammaE\SceneObjects\CoronaMgr\CCoronaMgr.cpp

//## begin module%3C72C95203E5.additionalIncludes preserve=no
//## end module%3C72C95203E5.additionalIncludes

//## begin module%3C72C95203E5.includes preserve=yes
#include "memory/gammae_mem.h"
#include <stdlib.h>
//## end module%3C72C95203E5.includes

// CCoronaMgr
#include "SceneObjects\CoronaMgr\CCoronaMgr.h"
//## begin module%3C72C95203E5.additionalDeclarations preserve=yes

int SortCoronas( const void *a, const void *b)
{
	static unsigned int pAMat,pBMat;

	pAMat = (unsigned int) ((CCorona *)a)->poMat;
	pBMat = (unsigned int) ((CCorona *)b)->poMat;

	return ( pAMat-pBMat );
}
//## end module%3C72C95203E5.additionalDeclarations


// Class CCoronaMgr 






CCoronaMgr::CCoronaMgr()
  //## begin CCoronaMgr::CCoronaMgr%.hasinit preserve=no
      : iMaxCoronas(0), iNumCoronas(0), fMaxCoronaDist(0.0f), bVisibles(NULL)
  //## end CCoronaMgr::CCoronaMgr%.hasinit
  //## begin CCoronaMgr::CCoronaMgr%.initialization preserve=yes
  //## end CCoronaMgr::CCoronaMgr%.initialization
{
  //## begin CCoronaMgr::CCoronaMgr%.body preserve=yes
  //## end CCoronaMgr::CCoronaMgr%.body
}


CCoronaMgr::~CCoronaMgr()
{
  //## begin CCoronaMgr::~CCoronaMgr%.body preserve=yes
  //## end CCoronaMgr::~CCoronaMgr%.body
}



//## Other Operations (implementation)
void CCoronaMgr::Init (int _iMaxCoronas)
{
  //## begin CCoronaMgr::Init%1014157000.body preserve=yes
	iMaxCoronas    = _iMaxCoronas;
	iNumCoronas    = 0;	
	poCoronas	   = mNew CCorona[iMaxCoronas];
  //## end CCoronaMgr::Init%1014157000.body
}

void CCoronaMgr::AddCorona (TFColor _roColor, CE3D_Shader *_poMat, CVect3& _roPos, float _fXYSize)
{
  //## begin CCoronaMgr::AddCorona%1014157001.body preserve=yes
	poCoronas[iNumCoronas].fXYSize = _fXYSize;
	poCoronas[iNumCoronas].oColor  = _roColor;
	poCoronas[iNumCoronas].oPos    = _roPos;
	poCoronas[iNumCoronas].poMat   = _poMat;
	iNumCoronas++;

	// Add ordered
	qsort(poCoronas,iNumCoronas,sizeof(CCorona),SortCoronas);
  //## end CCoronaMgr::AddCorona%1014157001.body
}

void CCoronaMgr::SetMaxCoronaDist (float _fMaxCoronaDist)
{
  //## begin CCoronaMgr::SetMaxCoronaDist%1014157318.body preserve=yes
	fMaxCoronaDist = _fMaxCoronaDist;
  //## end CCoronaMgr::SetMaxCoronaDist%1014157318.body
}

bool CCoronaMgr::bVisible (CCorona& _roCorona)
{
  //## begin CCoronaMgr::bVisible%1014157319.body preserve=yes
	return(true);
  //## end CCoronaMgr::bVisible%1014157319.body
}

void CCoronaMgr::MarkVisibles ()
{
  //## begin CCoronaMgr::MarkVisibles%1014157320.body preserve=yes
  //## end CCoronaMgr::MarkVisibles%1014157320.body
}

void CCoronaMgr::Render ()
{
  //## begin CCoronaMgr::Render%1014157002.body preserve=yes
	// Make all of them 
  //## end CCoronaMgr::Render%1014157002.body
}

// Additional Declarations
  //## begin CCoronaMgr%3C72C95203E5.declarations preserve=yes
  //## end CCoronaMgr%3C72C95203E5.declarations

//## begin module%3C72C95203E5.epilog preserve=yes
//## end module%3C72C95203E5.epilog
