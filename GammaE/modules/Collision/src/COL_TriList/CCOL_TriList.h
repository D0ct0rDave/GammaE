//## begin module%3C1D01EF00DE.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C1D01EF00DE.cm

//## begin module%3C1D01EF00DE.cp preserve=no
//## end module%3C1D01EF00DE.cp

//## Module: CCOL_TriList%3C1D01EF00DE; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\COL_TriList\CCOL_TriList.h

#ifndef CCOL_TriList_h
#define CCOL_TriList_h 1

//## begin module%3C1D01EF00DE.additionalIncludes preserve=no
//## end module%3C1D01EF00DE.additionalIncludes

//## begin module%3C1D01EF00DE.includes preserve=yes
//## end module%3C1D01EF00DE.includes

// GammaE_Math
#include "Math\GammaE_Math.h"
//## begin module%3C1D01EF00DE.additionalDeclarations preserve=yes
//## end module%3C1D01EF00DE.additionalDeclarations


//## begin CCOL_TriList%3C1D01EF00DE.preface preserve=yes
//## end CCOL_TriList%3C1D01EF00DE.preface

//## Class: CCOL_TriList%3C1D01EF00DE
//## Category: Collision::COL_TriList%3C1BEBCD00BD
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C1D05B0000E;GammaE_Math { -> }

class CCOL_TriList 
{
  //## begin CCOL_TriList%3C1D01EF00DE.initialDeclarations preserve=yes
  //## end CCOL_TriList%3C1D01EF00DE.initialDeclarations

  public:
    //## Constructors (generated)
      CCOL_TriList();

    //## Destructor (generated)
      ~CCOL_TriList();


    //## Other Operations (specified)
      //## Operation: Init%1008534184
      void Init (int _iMaxTris);

      //## Operation: Reset%1008534187
      void Reset ();

      //## Operation: iFreeTris%1008534188
      int iFreeTris ();

      //## Operation: iAddTri%1009406734
      int iAddTri (CVect3* _poVX, CVect3& _roVN, int _iMat, float _fFrameFact);

      //## Operation: iAddTri%1008534186
      int iAddTri (CVect3& _roVX0, CVect3& _roVX1, CVect3& _roVX2, CVect3& _roVN, int _iMat, float _fFrameFact);

    // Data Members for Class Attributes

      //## Attribute: iMaxTris%3C1D02090302
      //## begin CCOL_TriList::iMaxTris%3C1D02090302.attr preserve=no  public: int {UA} 0
      int iMaxTris;
      //## end CCOL_TriList::iMaxTris%3C1D02090302.attr

      //## Attribute: iNumTris%3C1D020F02F7
      //## begin CCOL_TriList::iNumTris%3C1D020F02F7.attr preserve=no  public: int {UA} 0
      int iNumTris;
      //## end CCOL_TriList::iNumTris%3C1D020F02F7.attr

      //## Attribute: poVXs%3CCD0FD80292
      //## begin CCOL_TriList::poVXs%3CCD0FD80292.attr preserve=no  public: CVect3 * {UA} NULL
      CVect3 *poVXs;
      //## end CCOL_TriList::poVXs%3CCD0FD80292.attr

      //## Attribute: poVNs%3CCD0FDE03A9
      //## begin CCOL_TriList::poVNs%3CCD0FDE03A9.attr preserve=no  public: CVect3 * {UA} NULL
      CVect3 *poVNs;
      //## end CCOL_TriList::poVNs%3CCD0FDE03A9.attr

      //## Attribute: piMats%3CCD0FE7004F
      //## begin CCOL_TriList::piMats%3CCD0FE7004F.attr preserve=no  public: int * {UA} NULL
      int *piMats;
      //## end CCOL_TriList::piMats%3CCD0FE7004F.attr

      //## Attribute: pfFrameFacts%3CCD0FEC024B
      //## begin CCOL_TriList::pfFrameFacts%3CCD0FEC024B.attr preserve=no  public: float * {UA} NULL
      float *pfFrameFacts;
      //## end CCOL_TriList::pfFrameFacts%3CCD0FEC024B.attr

    // Additional Public Declarations
      //## begin CCOL_TriList%3C1D01EF00DE.public preserve=yes
      //## end CCOL_TriList%3C1D01EF00DE.public

  protected:
    // Additional Protected Declarations
      //## begin CCOL_TriList%3C1D01EF00DE.protected preserve=yes
      //## end CCOL_TriList%3C1D01EF00DE.protected

  private:
    // Additional Private Declarations
      //## begin CCOL_TriList%3C1D01EF00DE.private preserve=yes
      //## end CCOL_TriList%3C1D01EF00DE.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOL_TriList%3C1D01EF00DE.implementation preserve=yes
      //## end CCOL_TriList%3C1D01EF00DE.implementation

};

//## begin CCOL_TriList%3C1D01EF00DE.postscript preserve=yes
//## end CCOL_TriList%3C1D01EF00DE.postscript

// Class CCOL_TriList 


//## Other Operations (inline)
inline void CCOL_TriList::Reset ()
{
  //## begin CCOL_TriList::Reset%1008534187.body preserve=yes
  	iNumTris = 0;
  //## end CCOL_TriList::Reset%1008534187.body
}

inline int CCOL_TriList::iFreeTris ()
{
  //## begin CCOL_TriList::iFreeTris%1008534188.body preserve=yes
	return(iMaxTris - iNumTris);
  //## end CCOL_TriList::iFreeTris%1008534188.body
}

inline int CCOL_TriList::iAddTri (CVect3* _poVX, CVect3& _roVN, int _iMat, float _fFrameFact)
{
  //## begin CCOL_TriList::iAddTri%1009406734.body preserve=yes
	return (iAddTri (_poVX[0],_poVX[1],_poVX[2],_roVN,_iMat,_fFrameFact) );
  //## end CCOL_TriList::iAddTri%1009406734.body
}

inline int CCOL_TriList::iAddTri (CVect3& _roVX0, CVect3& _roVX1, CVect3& _roVX2, CVect3& _roVN, int _iMat, float _fFrameFact)
{
  //## begin CCOL_TriList::iAddTri%1008534186.body preserve=yes
   	assert (poVXs && "NULL triangle vertex array");

	if (iNumTris == iMaxTris) return(-1);

	poVXs[iNumTris*3+0].Assign(_roVX0);
	poVXs[iNumTris*3+1].Assign(_roVX1);
	poVXs[iNumTris*3+2].Assign(_roVX2);

	poVNs[iNumTris].Assign(_roVN);
	
	piMats[iNumTris]   = _iMat;
	pfFrameFacts[iNumTris] = _fFrameFact;

	iNumTris++;
	return(iNumTris-1);

  //## end CCOL_TriList::iAddTri%1008534186.body
}

//## begin module%3C1D01EF00DE.epilog preserve=yes
//## end module%3C1D01EF00DE.epilog


#endif
