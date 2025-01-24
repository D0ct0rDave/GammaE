//	  %X% %Q% %Z% %W%



#ifndef CLightElem_h
#define CLightElem_h 1



// CSectElem
#include "SectElem\CSectElem.h"




class CLightElem : public CSectElem  {
    
  public:
          CLightElem();

          ~CLightElem();


                virtual unsigned long ByteSize ();

            virtual CSectElem & Sum (CSectElem &a, CSectElem &b);

            virtual CSectElem & Mult (CSectElem &a, CSectElem &b);

            virtual CSectElem & LinInterpolate (CSectElem &a, CSectElem &b, float fFactor);

            virtual CSectElem & CosInterpolate (CSectElem &a, CSectElem &b, float fFactor);

            virtual void * Get ();

            virtual void Set (void *_Value);

            virtual CSectElem * CreateClass ();

            virtual CSectElem & Clear ();

            virtual CSectElem & Add (CSectElem &a);

            virtual CSectElem & Mult (CSectElem &a);

            virtual CSectElem & Scale (float a);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Data Members for Class Attributes

                  float Value[3];
      
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CLightElem 


inline void * CLightElem::Get ()
{
  	return((void *)&Value);
}

inline void CLightElem::Set (void *_Value)
{
    	Value[0] = ((float *)(_Value))[0];
	Value[1] = ((float *)(_Value))[1];
	Value[2] = ((float *)(_Value))[2];
}



#endif
