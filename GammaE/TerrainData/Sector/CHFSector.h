//## begin module%3AF50E5C0082.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AF50E5C0082.cm

//## begin module%3AF50E5C0082.cp preserve=no
//## end module%3AF50E5C0082.cp

//## Module: CHFSector%3AF50E5C0082; Pseudo Package specification
//## Source file: i:\Projects\GammaE\TerrainData\Sector\CHFSector.h

#ifndef CHFSector_h
#define CHFSector_h 1

//## begin module%3AF50E5C0082.additionalIncludes preserve=no
//## end module%3AF50E5C0082.additionalIncludes

//## begin module%3AF50E5C0082.includes preserve=yes
//## end module%3AF50E5C0082.includes

// CHeight
#include "TerrainData\SectElem\CHeight.h"
// CSector
#include "TerrainData\Sector\CSector.h"
//## begin module%3AF50E5C0082.additionalDeclarations preserve=yes
//## end module%3AF50E5C0082.additionalDeclarations


//## begin CHFSector%3AF50E5C0082.preface preserve=yes
//## end CHFSector%3AF50E5C0082.preface

//## Class: CHFSector%3AF50E5C0082
//## Category: TerrainData::Sector%3AF5122E008C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3AF878640398;CHeight { -> }

class CHFSector : public CSector  //## Inherits: <unnamed>%3AFB11B001A4
{
  //## begin CHFSector%3AF50E5C0082.initialDeclarations preserve=yes
  //## end CHFSector%3AF50E5C0082.initialDeclarations

  public:
    //## Constructors (generated)
      CHFSector();

    //## Destructor (generated)
      ~CHFSector();


    //## Other Operations (specified)
      //## Operation: GetMaxHeight%990479653
      virtual float GetMaxHeight ();

      //## Operation: GetMinHeight%990479654
      virtual float GetMinHeight ();

      //## Operation: RecomputeMaxMins%990479655
      virtual void RecomputeMaxMins ();

      //## Operation: SetValue%990479656
      //	Sets the value of a specific element inside the data
      virtual void SetValue (int _X, int _Y, CSectElem &_Value);

    // Additional Public Declarations
      //## begin CHFSector%3AF50E5C0082.public preserve=yes
      //## end CHFSector%3AF50E5C0082.public

  protected:
    // Additional Protected Declarations
      //## begin CHFSector%3AF50E5C0082.protected preserve=yes
      //## end CHFSector%3AF50E5C0082.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: MaxHeight%3AF87B2803CA
      //## begin CHFSector::MaxHeight%3AF87B2803CA.attr preserve=no  private: float {UA} 0
      float MaxHeight;
      //## end CHFSector::MaxHeight%3AF87B2803CA.attr

      //## Attribute: MinHeight%3AF87B340154
      //## begin CHFSector::MinHeight%3AF87B340154.attr preserve=no  private: float {UA} 0
      float MinHeight;
      //## end CHFSector::MinHeight%3AF87B340154.attr

      //## Attribute: bRecomputeMaxMins%3B09912D03AC
      //## begin CHFSector::bRecomputeMaxMins%3B09912D03AC.attr preserve=no  private: bool {UA} 
      bool bRecomputeMaxMins;
      //## end CHFSector::bRecomputeMaxMins%3B09912D03AC.attr

    // Additional Private Declarations
      //## begin CHFSector%3AF50E5C0082.private preserve=yes
      //## end CHFSector%3AF50E5C0082.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHFSector%3AF50E5C0082.implementation preserve=yes
      //## end CHFSector%3AF50E5C0082.implementation

};

//## begin CHFSector%3AF50E5C0082.postscript preserve=yes
//## end CHFSector%3AF50E5C0082.postscript

// Class CHFSector 

//## begin module%3AF50E5C0082.epilog preserve=yes
//## end module%3AF50E5C0082.epilog


#endif
