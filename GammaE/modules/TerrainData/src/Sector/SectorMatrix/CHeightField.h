//	  %X% %Q% %Z% %W%



#ifndef CHeightField_h
#define CHeightField_h 1



// CSectorMatrix
#include "Sector\SectorMatrix\CSectorMatrix.h"
// CHFSector_FN
#include "Sector\HeightField\CHFSector_FN.h"
// CSLM_HFieldSect
#include "Sector\SectorMatrix\CSectorLoaderManager\CSLM_HFieldSect.h"

typedef struct{
	float fMaxHeight;	
	float fMinHeight;
}THeightFieldData;






class CHeightField : public CSectorMatrix  {
    
  public:
          CHeightField();

          virtual ~CHeightField();


                virtual CSector * CreateClass ();

            virtual void Init (int _SecsPerRow, int _SecsPerCol, int _SectorRes, int _SectorType, bool _b21);

            virtual unsigned long DataSize ();

            virtual float GetMaxHeight ();

            virtual float GetMinHeight ();

            virtual void SetValue (int _X, int _Y, CSectElem &_Value);

            virtual void SetValueFromSect (int _iSect, int _X, int _Y, CSectElem &_Value);

            void RecomputeMaxMins ();

            //	Generates a new object with  data corresponding to a
      //	given LOD
      virtual CSector * GenerateLOD (int _iLOD);

            virtual CSectElem & GetValueF (float _fX, float _fY);

    // Additional Public Declarations
            
  protected:
    // Data Members for Class Attributes

                  THeightFieldData HFData;
      
    // Additional Protected Declarations
            
  private:
    // Data Members for Class Attributes

                  bool bRecomputeMaxMins;
      
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CHeightField 



#endif
