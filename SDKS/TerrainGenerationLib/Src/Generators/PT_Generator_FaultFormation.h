//---------------------------------------------------------------------------
#ifndef PT_Generator_FaultFormation_h
#define PT_Generator_FaultFormation_h 1
//---------------------------------------------------------------------------
#include "Generators/PT_Generator.h"
//---------------------------------------------------------------------------

class PT_Generator_FaultFormation : public PT_Generator
{
  public:
      virtual ~PT_Generator_FaultFormation();


      void Generate (PT_HeightField *HF);

  protected:
  private:
};

//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
