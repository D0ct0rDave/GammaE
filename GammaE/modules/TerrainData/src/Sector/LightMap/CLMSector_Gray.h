//	  %X% %Q% %Z% %W%



#ifndef CLMSector_Gray_h
#define CLMSector_Gray_h 1



// CLMSector
#include "Sector\CLMSector.h"




class CLMSector_Gray : public CLMSector  {
    
  public:
          CLMSector_Gray();

          virtual ~CLMSector_Gray();


                virtual CSectElem & GetValue (int _X, int _Y);

            virtual void SetValue (int _X, int _Y, CSectElem &_Value);

            virtual CSector * CreateClass ();

            virtual unsigned long ElemArraySize (int _iResolution);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CLMSector_Gray 



#endif
