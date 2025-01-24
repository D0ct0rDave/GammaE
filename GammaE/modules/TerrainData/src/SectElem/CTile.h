//	  %X% %Q% %Z% %W%



#ifndef CTile_h
#define CTile_h 1



// CSectElem
#include "SectElem\CSectElem.h"




class CTile : public CSectElem  {
    
  public:
          CTile();

          ~CTile();


                virtual unsigned long ByteSize ();

            virtual void * Get ();

            virtual void Set (void *_Value);

            virtual CSectElem * CreateClass ();

    
            int GetTileIdx ();
      void SetTileIdx (int value);

            int GetTransitionType ();
      void SetTransitionType (int value);

            int GetTransTileIdx ();
      void SetTransTileIdx (int value);

            int GetRotationType ();
      void SetRotationType (int value);

            bool GetInvisible ();
      void SetInvisible (bool value);

            int GetOldTransition ();
      void SetOldTransition (int value);

    // Data Members for Class Attributes

            int TileIdx;
      
            int TransitionType;
      
            int TransTileIdx;
      
            int RotationType;
      
            bool Invisible;
      
            int OldTransition;
      
    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CTile 


inline int CTile::GetTransTileIdx ()
{
    return TransTileIdx;
}



#endif
