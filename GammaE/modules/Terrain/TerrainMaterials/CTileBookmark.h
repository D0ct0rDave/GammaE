//## begin module%3AFEFAC30136.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AFEFAC30136.cm

//## begin module%3AFEFAC30136.cp preserve=no
//## end module%3AFEFAC30136.cp

//## Module: CTileBookmark%3AFEFAC30136; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Terrain\TerrainMaterials\CTileBookmark.h

#ifndef CTileBookmark_h
#define CTileBookmark_h 1

//## begin module%3AFEFAC30136.additionalIncludes preserve=no
//## end module%3AFEFAC30136.additionalIncludes

//## begin module%3AFEFAC30136.includes preserve=yes
//## end module%3AFEFAC30136.includes

// GammaE_E3D
#include "E3D\GammaE_E3D.h"
//## begin module%3AFEFAC30136.additionalDeclarations preserve=yes
//## end module%3AFEFAC30136.additionalDeclarations


//## begin CTileBookmark%3AFEFAC30136.preface preserve=yes
//## end CTileBookmark%3AFEFAC30136.preface

//## Class: CTileBookmark%3AFEFAC30136
//## Category: Terrain::TerrainMaterials%3AFEFAB50276
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C6C4CA90377;GammaE_E3D { -> }

class CTileBookmark 
{
  //## begin CTileBookmark%3AFEFAC30136.initialDeclarations preserve=yes
  //## end CTileBookmark%3AFEFAC30136.initialDeclarations

  public:
    //## Constructors (generated)
      CTileBookmark();

    //## Destructor (generated)
      ~CTileBookmark();


    //## Other Operations (specified)
      //## Operation: Init%989790238
      void Init (int _MaxTiles, int _MaxLODs);

      //## Operation: SetTileMaterial%989790239
      void SetTileMaterial (int _iTile, int _iLOD, CE3D_Shader* _Mat);

      //## Operation: poGetTileMaterial%989958287
      CE3D_Shader* poGetTileMaterial (int _iTile, int _iLOD);

      //## Operation: GetTileLODs%990048932
      int GetTileLODs (int _iTile);

      //## Operation: Invalidate%989790241
      void Invalidate ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: MaxTiles%3AFEFB0E01C2
      int GetMaxTiles ();

      //## Attribute: MaxLODs%3B02F23501EA
      int GetMaxLODs ();

    // Data Members for Class Attributes

      //## Attribute: Tiles%3AFEFAE603B6
      //## begin CTileBookmark::Tiles%3AFEFAE603B6.attr preserve=no  public: CE3D_Shader* * {UA} NULL
      CE3D_Shader* *Tiles;
      //## end CTileBookmark::Tiles%3AFEFAE603B6.attr

      //## begin CTileBookmark::MaxTiles%3AFEFB0E01C2.attr preserve=no  public: int {UA} 0
      int MaxTiles;
      //## end CTileBookmark::MaxTiles%3AFEFB0E01C2.attr

      //## begin CTileBookmark::MaxLODs%3B02F23501EA.attr preserve=no  public: int {UA} 0
      int MaxLODs;
      //## end CTileBookmark::MaxLODs%3B02F23501EA.attr

      //## Attribute: TileLODs%3B02F32A0122
      //## begin CTileBookmark::TileLODs%3B02F32A0122.attr preserve=no  public: int * {UA} NULL
      int *TileLODs;
      //## end CTileBookmark::TileLODs%3B02F32A0122.attr

    // Additional Public Declarations
      //## begin CTileBookmark%3AFEFAC30136.public preserve=yes
      //## end CTileBookmark%3AFEFAC30136.public

  protected:
    // Additional Protected Declarations
      //## begin CTileBookmark%3AFEFAC30136.protected preserve=yes
      //## end CTileBookmark%3AFEFAC30136.protected

  private:
    // Additional Private Declarations
      //## begin CTileBookmark%3AFEFAC30136.private preserve=yes
      //## end CTileBookmark%3AFEFAC30136.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTileBookmark%3AFEFAC30136.implementation preserve=yes
      //## end CTileBookmark%3AFEFAC30136.implementation

};

//## begin CTileBookmark%3AFEFAC30136.postscript preserve=yes
//## end CTileBookmark%3AFEFAC30136.postscript

// Class CTileBookmark 

//## Get and Set Operations for Class Attributes (inline)

inline int CTileBookmark::GetMaxTiles ()
{
  //## begin CTileBookmark::GetMaxTiles%3AFEFB0E01C2.get preserve=no
  return MaxTiles;
  //## end CTileBookmark::GetMaxTiles%3AFEFB0E01C2.get
}

inline int CTileBookmark::GetMaxLODs ()
{
  //## begin CTileBookmark::GetMaxLODs%3B02F23501EA.get preserve=no
  return MaxLODs;
  //## end CTileBookmark::GetMaxLODs%3B02F23501EA.get
}

//## begin module%3AFEFAC30136.epilog preserve=yes
//## end module%3AFEFAC30136.epilog


#endif
