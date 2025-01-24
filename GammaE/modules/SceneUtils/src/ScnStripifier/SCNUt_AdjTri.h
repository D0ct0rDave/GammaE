//	  %X% %Q% %Z% %W%



#ifndef SCNUt_AdjTri_h
#define SCNUt_AdjTri_h 1







class SCNUt_AdjTri 
{
    
  public:
          SCNUt_AdjTri();

          ~SCNUt_AdjTri();


                void AddNeigh (int _iIdx);

    // Data Members for Class Attributes

                  int iNumNeighs;
      
                  int *Neigh;
      
                  bool Visited;
      
    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class SCNUt_AdjTri 



#endif
