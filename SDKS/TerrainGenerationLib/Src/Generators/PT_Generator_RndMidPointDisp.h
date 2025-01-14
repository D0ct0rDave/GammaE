//---------------------------------------------------------------------------
#ifndef PT_Generator_RndMidPointDisp_h
#define PT_Generator_RndMidPointDisp_h 1
//---------------------------------------------------------------------------
#include "Generators/PT_Generator.h"
#include "Evaluators2/Evaluator2D.h"
//---------------------------------------------------------------------------
class PT_Generator_RndMidPointDisp :public PT_Generator
{
  public:
      virtual ~PT_Generator_RndMidPointDisp();


      void SetBaseFunc (TEvaluator2D *_BaseFunc);

      void Generate (PT_HeightField *HF);

  protected:
    // Data Members for Class Attributes

      TEvaluator2D *BaseFunc;

  private:

      const TEvaluator2D * GetBaseFunc () const
      {
        return BaseFunc;
      }
};
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
