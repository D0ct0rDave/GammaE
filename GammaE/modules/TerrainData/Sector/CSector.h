//## begin module%3AF50E46017C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AF50E46017C.cm

//## begin module%3AF50E46017C.cp preserve=no
//## end module%3AF50E46017C.cp

//## Module: CSector%3AF50E46017C; Pseudo Package specification
//## Source file: E76.:\Projects\GammaE\TerrainData\Sector\CSector.h

#ifndef CSector_h
#define CSector_h 1

//## begin module%3AF50E46017C.additionalIncludes preserve=no
//## end module%3AF50E46017C.additionalIncludes

//## begin module%3AF50E46017C.includes preserve=yes
#include <stdlib.h>
#include <stdio.h>
#include "FileSys/GammaE_FileSys.h"
//## end module%3AF50E46017C.includes

// CSectElem
#include "TerrainData\SectElem\CSectElem.h"
//## begin module%3AF50E46017C.additionalDeclarations preserve=yes
typedef enum {
	eGM_Nearest,
	eGM_Linear,
	eGM_CosLinear,
	
	eGM_NumGenMethods

}EGenerationMethod;
//## end module%3AF50E46017C.additionalDeclarations


//## begin CSector%3AF50E46017C.preface preserve=yes
//## end CSector%3AF50E46017C.preface

//## Class: CSector%3AF50E46017C
//## Category: TerrainData::Sector%3AF5122E008C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3AF8704401C2;CSectElem { -> }

class CSector 
{
  //## begin CSector%3AF50E46017C.initialDeclarations preserve=yes
  //## end CSector%3AF50E46017C.initialDeclarations

  public:
    //## Constructors (generated)
      CSector();

    //## Destructor (generated)
      ~CSector();

    //## Assignment Operation (generated)
      const CSector & operator=(const CSector &right);


    //## Other Operations (specified)
      //## Operation: Init%989359113
      //	Initializes data according the given characteristics.
      virtual void Init (int _iRes, bool _b21);

      //## Operation: Invalidate%989359112
      //	Erases and invalidates the data stored into the current
      //	class
      virtual void Invalidate ();

      //## Operation: GetID%989139156
      //	Gets the file identifier of the current class
      virtual unsigned long GetID ();

      //## Operation: ByteSize%989139157
      //	The size of the entire object in disk.
      virtual unsigned long ByteSize ();

      //## Operation: GetValue%989359109
      //	Gets the value of a specific element inside the data
      virtual CSectElem & GetValue (int _X, int _Y) = 0;

      //## Operation: SetValue%989359110
      //	Sets the value of a specific element inside the data
      virtual void SetValue (int _X, int _Y, CSectElem &_Value) = 0;

      //## Operation: GetValueF%990742414
      virtual CSectElem & GetValueF (float _fX, float _fY);

      //## Operation: GenerateLOD%989359111
      //	Generates a new object with  data corresponding to a
      //	given LOD
      virtual CSector * GenerateLOD (int _iLOD);

      //## Operation: GetLODData%989359114
      //	Gets the raw data of a given LOD
      virtual void GetLODData (int _iLOD, void *_pData);

      //## Operation: iLoad%989359124
      //	Loads an object from the given file
      virtual int iLoad (char *_Filename);

      //## Operation: iLoadWithHandler%989359125
      //	Loads and initializes object data, from disk.
      virtual int iLoadWithHandler (FILE *_FD);

      //## Operation: iSave%989359126
      //	Save the entire object inside the given file
      virtual int iSave (char *_Filename);

      //## Operation: iSaveWithHandler%989359127
      //	Save the object contents into a file, associated to the
      //	current file descriptor
      virtual int iSaveWithHandler (FILE *_FD);

      //## Operation: DataSize%989359128
      //	The size of the data from this object
      virtual unsigned long DataSize ();

      //## Operation: CreateClass%989359129
      //	Creates a new object of the same class as the current
      //	object
      virtual CSector * CreateClass () = 0;

      //## Operation: ElemArraySize%989667594
      //	The equivalent size for an object of the given
      //	characteristics.
      virtual unsigned long ElemArraySize (int _iResolution);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: VGenMethod%3AF86A470064
      EGenerationMethod GetVGenMethod ();
      void SetVGenMethod (EGenerationMethod value);

      //## Attribute: Resolution%3AF86BA5019A
      int GetResolution ();

    // Data Members for Class Attributes

      //## begin CSector::VGenMethod%3AF86A470064.attr preserve=no  public: EGenerationMethod {UA} eGM_Nearest
      EGenerationMethod VGenMethod;
      //## end CSector::VGenMethod%3AF86A470064.attr

      //## begin CSector::Resolution%3AF86BA5019A.attr preserve=no  public: int {UA} 0
      int Resolution;
      //## end CSector::Resolution%3AF86BA5019A.attr

    // Additional Public Declarations
      //## begin CSector%3AF50E46017C.public preserve=yes
      //## end CSector%3AF50E46017C.public

  protected:
    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: b21%3AFB119E012C
      bool Getb21 ();

    // Data Members for Class Attributes

      //## Attribute: ulID%3AF50F5D01FE
      //## begin CSector::ulID%3AF50F5D01FE.attr preserve=no  protected: unsigned long {U} 0
      unsigned long ulID;
      //## end CSector::ulID%3AF50F5D01FE.attr

      //## Attribute: pData%3AF86B7A01CC
      //## begin CSector::pData%3AF86B7A01CC.attr preserve=no  protected: void * {U} NULL
      void *pData;
      //## end CSector::pData%3AF86B7A01CC.attr

      //## Attribute: ucMajVer%3AF874E702D0
      //## begin CSector::ucMajVer%3AF874E702D0.attr preserve=no  protected: unsigned char {U} 1
      unsigned char ucMajVer;
      //## end CSector::ucMajVer%3AF874E702D0.attr

      //## Attribute: ucMinVer%3AF874F4008C
      //## begin CSector::ucMinVer%3AF874F4008C.attr preserve=no  protected: unsigned char {U} 0
      unsigned char ucMinVer;
      //## end CSector::ucMinVer%3AF874F4008C.attr

      //## begin CSector::b21%3AFB119E012C.attr preserve=no  protected: bool {UA} false
      bool b21;
      //## end CSector::b21%3AFB119E012C.attr

      //## Attribute: iLast%3B0D89C602E4
      //## begin CSector::iLast%3B0D89C602E4.attr preserve=no  protected: int {UA} 0
      int iLast;
      //## end CSector::iLast%3B0D89C602E4.attr

    // Additional Protected Declarations
      //## begin CSector%3AF50E46017C.protected preserve=yes
      //## end CSector%3AF50E46017C.protected

  private:

    //## Other Operations (specified)
      //## Operation: GetValueLOD%991155097
      CSectElem & GetValueLOD (int _X, int _Y, int _iLOD);

    // Additional Private Declarations
      //## begin CSector%3AF50E46017C.private preserve=yes
      //## end CSector%3AF50E46017C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSector%3AF50E46017C.implementation preserve=yes
      //## end CSector%3AF50E46017C.implementation

};

//## begin CSector%3AF50E46017C.postscript preserve=yes
//## end CSector%3AF50E46017C.postscript

// Class CSector 


//## Other Operations (inline)
inline unsigned long CSector::GetID ()
{
  //## begin CSector::GetID%989139156.body preserve=yes
	return(ulID);
  //## end CSector::GetID%989139156.body
}

//## Get and Set Operations for Class Attributes (inline)

inline EGenerationMethod CSector::GetVGenMethod ()
{
  //## begin CSector::GetVGenMethod%3AF86A470064.get preserve=no
  return VGenMethod;
  //## end CSector::GetVGenMethod%3AF86A470064.get
}

inline void CSector::SetVGenMethod (EGenerationMethod value)
{
  //## begin CSector::SetVGenMethod%3AF86A470064.set preserve=no
  VGenMethod = value;
  //## end CSector::SetVGenMethod%3AF86A470064.set
}

inline int CSector::GetResolution ()
{
  //## begin CSector::GetResolution%3AF86BA5019A.get preserve=no
  return Resolution;
  //## end CSector::GetResolution%3AF86BA5019A.get
}

inline bool CSector::Getb21 ()
{
  //## begin CSector::Getb21%3AFB119E012C.get preserve=no
  return b21;
  //## end CSector::Getb21%3AFB119E012C.get
}

//## begin module%3AF50E46017C.epilog preserve=yes
//## end module%3AF50E46017C.epilog


#endif
