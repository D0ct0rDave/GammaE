//## begin module%3BA91166024F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BA91166024F.cm

//## begin module%3BA91166024F.cp preserve=no
//## end module%3BA91166024F.cp

//## Module: CGraphBV_FileIO%3BA91166024F; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\BoundingVolume\GraphBoundVol\GraphBVUtils\CGraphBV_FileIO.h

#ifndef CGraphBV_FileIO_h
#define CGraphBV_FileIO_h 1

//## begin module%3BA91166024F.additionalIncludes preserve=no
//## end module%3BA91166024F.additionalIncludes

//## begin module%3BA91166024F.includes preserve=yes
#include <stdio.h>
//## end module%3BA91166024F.includes

// GammaE_FileSys
#include "FileSys\GammaE_FileSys.h"
// CGraphBV_Sphere
#include "E3D\BoundingVolume\GraphBoundVol\CGraphBV_Sphere.h"
// CGraphBV_Point
#include "E3D\BoundingVolume\GraphBoundVol\CGraphBV_Point.h"
// CGraphBV_Cylinder
#include "E3D\BoundingVolume\GraphBoundVol\CGraphBV_Cylinder.h"
// CGraphBV_Box
#include "E3D\BoundingVolume\GraphBoundVol\CGraphBV_Box.h"
//## begin module%3BA91166024F.additionalDeclarations preserve=yes
//## end module%3BA91166024F.additionalDeclarations


//## begin CGraphBV_FileIO%3BA91166024F.preface preserve=yes
//## end CGraphBV_FileIO%3BA91166024F.preface

//## Class: CGraphBV_FileIO%3BA91166024F
//## Category: E3D::BoundingVolume::GraphBoundVol::GraphBVUtils%3BA90F6402BE
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BA911CC02CD;CGraphBV_Sphere { -> }
//## Uses: <unnamed>%3BA911CE0045;CGraphBV_Box { -> }
//## Uses: <unnamed>%3BA911D0019D;CGraphBV_Cylinder { -> }
//## Uses: <unnamed>%3C4DB45A0375;CGraphBV_Point { -> }
//## Uses: <unnamed>%3C7E664C01FC;GammaE_FileSys { -> }

class CGraphBV_FileIO 
{
  //## begin CGraphBV_FileIO%3BA91166024F.initialDeclarations preserve=yes
  //## end CGraphBV_FileIO%3BA91166024F.initialDeclarations

  public:
    //## Constructors (generated)
      CGraphBV_FileIO();

    //## Destructor (generated)
      ~CGraphBV_FileIO();


    //## Other Operations (specified)
      //## Operation: pLoadGraphBV%1000933012
      static CGraphBV * pLoadGraphBV (CFile& _roFile);

      //## Operation: iSaveGraphBV%1000933013
      static int iSaveGraphBV (CFile& _roFile, CGraphBV *_pGBV);

    // Additional Public Declarations
      //## begin CGraphBV_FileIO%3BA91166024F.public preserve=yes
      //## end CGraphBV_FileIO%3BA91166024F.public

  protected:
    // Additional Protected Declarations
      //## begin CGraphBV_FileIO%3BA91166024F.protected preserve=yes
      //## end CGraphBV_FileIO%3BA91166024F.protected

  private:
    // Additional Private Declarations
      //## begin CGraphBV_FileIO%3BA91166024F.private preserve=yes
      //## end CGraphBV_FileIO%3BA91166024F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGraphBV_FileIO%3BA91166024F.implementation preserve=yes
      //## end CGraphBV_FileIO%3BA91166024F.implementation

};

//## begin CGraphBV_FileIO%3BA91166024F.postscript preserve=yes
//## end CGraphBV_FileIO%3BA91166024F.postscript

// Class CGraphBV_FileIO 

//## begin module%3BA91166024F.epilog preserve=yes
//## end module%3BA91166024F.epilog


#endif
