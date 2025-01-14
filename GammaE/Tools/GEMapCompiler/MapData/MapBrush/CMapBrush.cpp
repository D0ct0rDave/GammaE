//## begin module%3C7423B10131.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7423B10131.cm

//## begin module%3C7423B10131.cp preserve=no
//## end module%3C7423B10131.cp

//## Module: CMapBrush%3C7423B10131; Pseudo Package body
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\MapData\MapBrush\CMapBrush.cpp

//## begin module%3C7423B10131.additionalIncludes preserve=no
//## end module%3C7423B10131.additionalIncludes

//## begin module%3C7423B10131.includes preserve=yes
#include "memory/gammae_mem.h"
#include <string.h>
//## end module%3C7423B10131.includes

// CMapBrush
#include "Tools\GEMapCompiler\MapData\MapBrush\CMapBrush.h"
//## begin module%3C7423B10131.additionalDeclarations preserve=yes
//## end module%3C7423B10131.additionalDeclarations


// Class CMapBrush 





CMapBrush::CMapBrush()
  //## begin CMapBrush::CMapBrush%.hasinit preserve=no
      : iNumBSides(0), poBSides(NULL)
  //## end CMapBrush::CMapBrush%.hasinit
  //## begin CMapBrush::CMapBrush%.initialization preserve=yes
  //## end CMapBrush::CMapBrush%.initialization
{
  //## begin CMapBrush::CMapBrush%.body preserve=yes
  //## end CMapBrush::CMapBrush%.body
}


CMapBrush::~CMapBrush()
{
  //## begin CMapBrush::~CMapBrush%.body preserve=yes
	if (poBSides) mDel []poBSides;
  //## end CMapBrush::~CMapBrush%.body
}



//## Other Operations (implementation)
void CMapBrush::AddBrushSide (CMapBrushSide &_roBrushSide)
{
  //## begin CMapBrush::AddBrushSide%1014246303.body preserve=yes
	CMapBrushSide* poNewBSide;

	// Allocate space for old + new instructions
	poNewBSide = mNew CMapBrushSide[iNumBSides+1];

	// Copy old data
	if (poBSides) 
		memcpy(poNewBSide,poBSides,iNumBSides*sizeof(CMapBrushSide));

	// Add new instruction
	poNewBSide[iNumBSides] = _roBrushSide;
	
	// delete old data
	if (poBSides) mDel []poBSides;

	// Update object		
	poBSides = poNewBSide;

	iNumBSides++;
  //## end CMapBrush::AddBrushSide%1014246303.body
}

// Additional Declarations
  //## begin CMapBrush%3C7423B10131.declarations preserve=yes
  //## end CMapBrush%3C7423B10131.declarations

//## begin module%3C7423B10131.epilog preserve=yes
//## end module%3C7423B10131.epilog
