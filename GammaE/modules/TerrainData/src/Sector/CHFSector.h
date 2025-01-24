//	  %X% %Q% %Z% %W%



#ifndef CHFSector_h
#define CHFSector_h 1



// CSector
#include "Sector\CSector.h"
// CHeight
#include "SectElem\CHeight.h"





class CHFSector : public CSector  {
    
  public:
          CHFSector();

          virtual ~CHFSector();


                virtual float GetMaxHeight ();

            virtual float GetMinHeight ();

            virtual void RecomputeMaxMins ();

            //	Sets the value of a specific element inside the data
      virtual void SetValue (int _X, int _Y, CSectElem &_Value);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Data Members for Class Attributes

                  float MaxHeight;
      
                  float MinHeight;
      
                  bool bRecomputeMaxMins;
      
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CHFSector 



#endif
