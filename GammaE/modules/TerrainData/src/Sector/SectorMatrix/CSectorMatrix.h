//	  %X% %Q% %Z% %W%



#ifndef CSectorMatrix_h
#define CSectorMatrix_h 1


#include <assert.h>

// CSector
#include "Sector\CSector.h"
// CSectorLoaderManager
#include "Sector\SectorMatrix\CSectorLoaderManager\CSectorLoaderManager.h"




class CSectorMatrix : public CSector  {
    
  public:
          CSectorMatrix();

          virtual ~CSectorMatrix();

          const CSectorMatrix & operator=(const CSectorMatrix &right);


                virtual int iLoadWithHandler (FILE *_FD);

            virtual int iSaveWithHandler (FILE *_FD);

            virtual void Invalidate ();

            virtual void Init (int _SecsPerRow, int _SecsPerCol);

            virtual void Init (int _SecsPerRow, int _SecsPerCol, int _SectorRes, int _SectorType, bool _b21);

            virtual void Init (int _iRes, bool _b21);

            virtual CSectElem & GetValue (int _X, int _Y);

            virtual void SetValue (int _X, int _Y, CSectElem &_Value);

            virtual CSectElem & GetValueFromSect (int _iSect, int _X, int _Y);

            virtual void SetValueFromSect (int _iSect, int _X, int _Y, CSectElem &_Value);

            virtual unsigned long ByteSize ();

            virtual CSector * GetSector (int _iSect);

            virtual CSector * GetSector (int _iSectX, int _iSectY);

            virtual int iGetSecsPerRow ();

            virtual int iGetSecsPerCol ();

            virtual int iGetDataType ();

            //	Generates a new object with  data corresponding to a
      //	given LOD
      virtual CSector * GenerateLOD (int _iLOD);

            void SetVGenMethod (EGenerationMethod value);

    // Data Members for Associations

                        CSectorLoaderManager *poSectManager;
      
    // Additional Public Declarations
            
  protected:
    // Data Members for Class Attributes

                  int SecsPerRow;
      
                  int SecsPerCol;
      
                  CSector* *SectArray;
      
    // Additional Protected Declarations
            
  private:
    // Data Members for Class Attributes

                  int iDataType;
      
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CSectorMatrix 


inline CSector * CSectorMatrix::GetSector (int _iSect)
{
      assert(SectArray && "NULL Sector array in sector matrix");
	return ( SectArray[_iSect] );
}

inline CSector * CSectorMatrix::GetSector (int _iSectX, int _iSectY)
{
  	return ( GetSector(_iSectY*SecsPerRow + _iSectX) );
}

inline int CSectorMatrix::iGetSecsPerRow ()
{
  	return (SecsPerRow);
}

inline int CSectorMatrix::iGetSecsPerCol ()
{
  	return (SecsPerCol);
}

inline int CSectorMatrix::iGetDataType ()
{
  	return ( iDataType );
}



#endif
