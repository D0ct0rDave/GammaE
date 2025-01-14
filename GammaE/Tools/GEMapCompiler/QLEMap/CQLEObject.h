//## begin module%3CA0F4770124.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CA0F4770124.cm

//## begin module%3CA0F4770124.cp preserve=no
//## end module%3CA0F4770124.cp

//## Module: CQLEObject%3CA0F4770124; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\QLEMap\CQLEObject.h

#ifndef CQLEObject_h
#define CQLEObject_h 1

//## begin module%3CA0F4770124.additionalIncludes preserve=no
//## end module%3CA0F4770124.additionalIncludes

//## begin module%3CA0F4770124.includes preserve=yes
//## end module%3CA0F4770124.includes

// eQLE_ObjType
#include "Tools\GEMapCompiler\QLEMap\eQLE_ObjType.h"
// GammaE_Math
#include "Math\GammaE_Math.h"
//## begin module%3CA0F4770124.additionalDeclarations preserve=yes
//## end module%3CA0F4770124.additionalDeclarations


//## begin CQLEObject%3CA0F4770124.preface preserve=yes
//## end CQLEObject%3CA0F4770124.preface

//## Class: CQLEObject%3CA0F4770124
//## Category: Tools::GEMapCompiler::QLEMap%3CA0F45D0394
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3CA0F513004C;eQLE_ObjType { -> }
//## Uses: <unnamed>%3CA82983013D;GammaE_Math { -> }

class CQLEObject 
{
  //## begin CQLEObject%3CA0F4770124.initialDeclarations preserve=yes
  //## end CQLEObject%3CA0F4770124.initialDeclarations

  public:
    //## Constructors (generated)
      CQLEObject();

    //## Destructor (generated)
      ~CQLEObject();


    //## Other Operations (specified)
      //## Operation: AddChildObject%1017265241
      void AddChildObject (int _iObj);

    // Data Members for Class Attributes

      //## Attribute: eObjType%3CA0F514030B
      //## begin CQLEObject::eObjType%3CA0F514030B.attr preserve=no  public: eQLE_ObjType {UA} eQLEOT_None
      eQLE_ObjType eObjType;
      //## end CQLEObject::eObjType%3CA0F514030B.attr

      //## Attribute: iBrushNum%3CA0F5260343
      //## begin CQLEObject::iBrushNum%3CA0F5260343.attr preserve=no  public: int {UA} -1
      int iBrushNum;
      //## end CQLEObject::iBrushNum%3CA0F5260343.attr

      //## Attribute: iEntityNum%3CA342380130
      //## begin CQLEObject::iEntityNum%3CA342380130.attr preserve=no  public: int {UA} -1
      int iEntityNum;
      //## end CQLEObject::iEntityNum%3CA342380130.attr

      //## Attribute: iNumChObjs%3CA0F543018C
      //## begin CQLEObject::iNumChObjs%3CA0F543018C.attr preserve=no  public: int {UA} 0
      int iNumChObjs;
      //## end CQLEObject::iNumChObjs%3CA0F543018C.attr

      //## Attribute: piChObjList%3CA0F546021C
      //## begin CQLEObject::piChObjList%3CA0F546021C.attr preserve=no  public: int * {UA} NULL
      int *piChObjList;
      //## end CQLEObject::piChObjList%3CA0F546021C.attr

      //## Attribute: oPos%3CA8295B0013
      //## begin CQLEObject::oPos%3CA8295B0013.attr preserve=no  public: CVect3 {UA} 
      CVect3 oPos;
      //## end CQLEObject::oPos%3CA8295B0013.attr

      //## Attribute: oScl%3CA8296701DC
      //## begin CQLEObject::oScl%3CA8296701DC.attr preserve=no  public: CVect3 {UA} 
      CVect3 oScl;
      //## end CQLEObject::oScl%3CA8296701DC.attr

      //## Attribute: oDir%3CA8296D01C7
      //## begin CQLEObject::oDir%3CA8296D01C7.attr preserve=no  public: CVect3 {UA} 
      CVect3 oDir;
      //## end CQLEObject::oDir%3CA8296D01C7.attr

      //## Attribute: szName%3CDAF38C0313
      //## begin CQLEObject::szName%3CDAF38C0313.attr preserve=no  public: char[64] {UA} 
      char szName[64];
      //## end CQLEObject::szName%3CDAF38C0313.attr

    // Additional Public Declarations
      //## begin CQLEObject%3CA0F4770124.public preserve=yes
      //## end CQLEObject%3CA0F4770124.public

  protected:
    // Additional Protected Declarations
      //## begin CQLEObject%3CA0F4770124.protected preserve=yes
      //## end CQLEObject%3CA0F4770124.protected

  private:
    // Additional Private Declarations
      //## begin CQLEObject%3CA0F4770124.private preserve=yes
      //## end CQLEObject%3CA0F4770124.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CQLEObject%3CA0F4770124.implementation preserve=yes
      //## end CQLEObject%3CA0F4770124.implementation

};

//## begin CQLEObject%3CA0F4770124.postscript preserve=yes
//## end CQLEObject%3CA0F4770124.postscript

// Class CQLEObject 

//## begin module%3CA0F4770124.epilog preserve=yes
//## end module%3CA0F4770124.epilog


#endif
