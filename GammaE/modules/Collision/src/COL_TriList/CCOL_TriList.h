//	  %X% %Q% %Z% %W%



#ifndef CCOL_TriList_h
#define CCOL_TriList_h 1



// GammaE_Math
#include "GammaE_Math.h"





class CCOL_TriList 
{
    
  public:
          CCOL_TriList();

          ~CCOL_TriList();


                void Init (int _iMaxTris);

            void Reset ();

            int iFreeTris ();

            int iAddTri (CVect3* _poVX, CVect3& _oVN, int _iMat, float _fFrameFact);

            int iAddTri (CVect3& _oVX0, CVect3& _oVX1, CVect3& _oVX2, CVect3& _oVN, int _iMat, float _fFrameFact);

    // Data Members for Class Attributes

                  int iMaxTris;
      
                  int iNumTris;
      
                  CVect3 *poVXs;
      
                  CVect3 *poVNs;
      
                  int *piMats;
      
                  float *pfFrameFacts;
      
    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CCOL_TriList 


inline void CCOL_TriList::Reset ()
{
    	iNumTris = 0;
}

inline int CCOL_TriList::iFreeTris ()
{
  	return(iMaxTris - iNumTris);
}

inline int CCOL_TriList::iAddTri (CVect3* _poVX, CVect3& _oVN, int _iMat, float _fFrameFact)
{
  	return (iAddTri (_poVX[0],_poVX[1],_poVX[2],_oVN,_iMat,_fFrameFact) );
}

inline int CCOL_TriList::iAddTri (CVect3& _oVX0, CVect3& _oVX1, CVect3& _oVX2, CVect3& _oVN, int _iMat, float _fFrameFact)
{
     	assert (poVXs && "NULL triangle vertex array");

	if (iNumTris == iMaxTris) return(-1);

	poVXs[iNumTris*3+0].Assign(_oVX0);
	poVXs[iNumTris*3+1].Assign(_oVX1);
	poVXs[iNumTris*3+2].Assign(_oVX2);

	poVNs[iNumTris].Assign(_oVN);
	
	piMats[iNumTris]   = _iMat;
	pfFrameFacts[iNumTris] = _fFrameFact;

	iNumTris++;
	return(iNumTris-1);

}



#endif