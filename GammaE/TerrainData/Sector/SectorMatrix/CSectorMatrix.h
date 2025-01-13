//## begin module%3AF9B524038E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AF9B524038E.cm

//## begin module%3AF9B524038E.cp preserve=no
//## end module%3AF9B524038E.cp

//## Module: CSectorMatrix%3AF9B524038E; Pseudo Package specification
//## Source file: i:\Projects\GammaE\TerrainData\Sector\SectorMatrix\CSectorMatrix.h

#ifndef CSectorMatrix_h
#define CSectorMatrix_h 1

//## begin module%3AF9B524038E.additionalIncludes preserve=no
//## end module%3AF9B524038E.additionalIncludes

//## begin module%3AF9B524038E.includes preserve=yes
#include <assert.h>
//## end module%3AF9B524038E.includes

// CSector
#include "TerrainData\Sector\CSector.h"
// CSectorLoaderManager
#include "TerrainData\Sector\SectorMatrix\CSectorLoaderManager\CSectorLoaderManager.h"
//## begin module%3AF9B524038E.additionalDeclarations preserve=yes
//## end module%3AF9B524038E.additionalDeclarations


//## begin CSectorMatrix%3AF9B524038E.preface preserve=yes
//## end CSectorMatrix%3AF9B524038E.preface

//## Class: CSectorMatrix%3AF9B524038E
//## Category: TerrainData::Sector::SectorMatrix%3AF9B6CF0384
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSectorMatrix : public CSector  //## Inherits: <unnamed>%3AF9B5330276
{
  //## begin CSectorMatrix%3AF9B524038E.initialDeclarations preserve=yes
  //## end CSectorMatrix%3AF9B524038E.initialDeclarations

  public:
    //## Constructors (generated)
      CSectorMatrix();

    //## Destructor (generated)
      ~CSectorMatrix();

    //## Assignment Operation (generated)
      const CSectorMatrix & operator=(const CSectorMatrix &right);


    //## Other Operations (specified)
      //## Operation: iLoadWithHandler%989444559
      virtual int iLoadWithHandler (FILE *_FD);

      //## Operation: iSaveWithHandler%989444560
      virtual int iSaveWithHandler (FILE *_FD);

      //## Operation: Invalidate%989444562
      virtual void Invalidate ();

      //## Operation: Init%989530854
      virtual void Init (int _SecsPerRow, int _SecsPerCol);

      //## Operation: Init%989530855
      virtual void Init (int _SecsPerRow, int _SecsPerCol, int _SectorRes, int _SectorType, bool _b21);

      //## Operation: Init%989530858
      virtual void Init (int _iRes, bool _b21);

      //## Operation: GetValue%989530859
      virtual CSectElem & GetValue (int _X, int _Y);

      //## Operation: SetValue%989530860
      virtual void SetValue (int _X, int _Y, CSectElem &_Value);

      //## Operation: GetValueFromSect%989530861
      virtual CSectElem & GetValueFromSect (int _iSect, int _X, int _Y);

      //## Operation: SetValueFromSect%989530862
      virtual void SetValueFromSect (int _iSect, int _X, int _Y, CSectElem &_Value);

      //## Operation: ByteSize%990283800
      virtual unsigned long ByteSize ();

      //## Operation: GetSector%990350370
      virtual CSector * GetSector (int _iSect);

      //## Operation: GetSector%990350371
      virtual CSector * GetSector (int _iSectX, int _iSectY);

      //## Operation: iGetSecsPerRow%990479646
      virtual int iGetSecsPerRow ();

      //## Operation: iGetSecsPerCol%990479647
      virtual int iGetSecsPerCol ();

      //## Operation: iGetDataType%990479648
      virtual int iGetDataType ();

      //## Operation: GenerateLOD%991155095
      //	Generates a new object with  data corresponding to a
      //	given LOD
      virtual CSector * GenerateLOD (int _iLOD);

      //## Operation: SetVGenMethod%1026770436
      void SetVGenMethod (EGenerationMethod value);

    // Data Members for Associations

      //## Association: TerrainData::Sector::SectorMatrix::<unnamed>%3B312FAD0154
      //## Role: CSectorMatrix::poSectManager%3B312FAD0231
      //## begin CSectorMatrix::poSectManager%3B312FAD0231.role preserve=no  public: CSectorLoaderManager { -> RHAN}
      CSectorLoaderManager *poSectManager;
      //## end CSectorMatrix::poSectManager%3B312FAD0231.role

    // Additional Public Declarations
      //## begin CSectorMatrix%3AF9B524038E.public preserve=yes
      //## end CSectorMatrix%3AF9B524038E.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: SecsPerRow%3AF9B5C002DA
      //## begin CSectorMatrix::SecsPerRow%3AF9B5C002DA.attr preserve=no  protected: int {U} 0
      int SecsPerRow;
      //## end CSectorMatrix::SecsPerRow%3AF9B5C002DA.attr

      //## Attribute: SecsPerCol%3AF9B5CF02DA
      //## begin CSectorMatrix::SecsPerCol%3AF9B5CF02DA.attr preserve=no  protected: int {U} 0
      int SecsPerCol;
      //## end CSectorMatrix::SecsPerCol%3AF9B5CF02DA.attr

      //## Attribute: SectArray%3AF9BD490294
      //## begin CSectorMatrix::SectArray%3AF9BD490294.attr preserve=no  protected: CSector* * {U} NULL
      CSector* *SectArray;
      //## end CSectorMatrix::SectArray%3AF9BD490294.attr

    // Additional Protected Declarations
      //## begin CSectorMatrix%3AF9B524038E.protected preserve=yes
      //## end CSectorMatrix%3AF9B524038E.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: iDataType%3B08320F03D4
      //## begin CSectorMatrix::iDataType%3B08320F03D4.attr preserve=no  private: int {UA} 0
      int iDataType;
      //## end CSectorMatrix::iDataType%3B08320F03D4.attr

    // Additional Private Declarations
      //## begin CSectorMatrix%3AF9B524038E.private preserve=yes
      //## end CSectorMatrix%3AF9B524038E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSectorMatrix%3AF9B524038E.implementation preserve=yes
      //## end CSectorMatrix%3AF9B524038E.implementation

};

//## begin CSectorMatrix%3AF9B524038E.postscript preserve=yes
//## end CSectorMatrix%3AF9B524038E.postscript

// Class CSectorMatrix 


//## Other Operations (inline)
inline CSector * CSectorMatrix::GetSector (int _iSect)
{
  //## begin CSectorMatrix::GetSector%990350370.body preserve=yes
    assert(SectArray && "NULL Sector array in sector matrix");
	return ( SectArray[_iSect] );
  //## end CSectorMatrix::GetSector%990350370.body
}

inline CSector * CSectorMatrix::GetSector (int _iSectX, int _iSectY)
{
  //## begin CSectorMatrix::GetSector%990350371.body preserve=yes
	return ( GetSector(_iSectY*SecsPerRow + _iSectX) );
  //## end CSectorMatrix::GetSector%990350371.body
}

inline int CSectorMatrix::iGetSecsPerRow ()
{
  //## begin CSectorMatrix::iGetSecsPerRow%990479646.body preserve=yes
	return (SecsPerRow);
  //## end CSectorMatrix::iGetSecsPerRow%990479646.body
}

inline int CSectorMatrix::iGetSecsPerCol ()
{
  //## begin CSectorMatrix::iGetSecsPerCol%990479647.body preserve=yes
	return (SecsPerCol);
  //## end CSectorMatrix::iGetSecsPerCol%990479647.body
}

inline int CSectorMatrix::iGetDataType ()
{
  //## begin CSectorMatrix::iGetDataType%990479648.body preserve=yes
	return ( iDataType );
  //## end CSectorMatrix::iGetDataType%990479648.body
}

//## begin module%3AF9B524038E.epilog preserve=yes
//## end module%3AF9B524038E.epilog


#endif
