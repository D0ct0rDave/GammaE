//	  %X% %Q% %Z% %W%



#ifndef CGBillboard_AxisAlign_h
#define CGBillboard_AxisAlign_h 1



// CGBillboard
#include "Billboard\CGBillboard.h"




class CGBillboard_AxisAlign : public CGBillboard  {
    
  public:
          CGBillboard_AxisAlign();

          ~CGBillboard_AxisAlign();


                void SetAxis (bool x, bool y, bool z);

            virtual void Render ();

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Data Members for Class Attributes

                  int Flags;
      
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CGBillboard_AxisAlign 



#endif
