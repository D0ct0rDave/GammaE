//---------------------------------------------------------------------------
#ifndef PT_Generator_Evaluator_h
#define PT_Generator_Evaluator_h 1
//---------------------------------------------------------------------------
#include "Generators/PT_Generator.h"
#include "Evaluators2/Evaluator2D.h"
//---------------------------------------------------------------------------
class PT_Generator_Evaluator : public PT_Generator
{
  public:
      virtual ~PT_Generator_Evaluator();


      void Generate (PT_HeightField *HF);

      void SetEvaluator (TEvaluator2D *_Evaluator);

  protected:
    // Data Members for Class Attributes

      TEvaluator2D *Evaluator;

  public:
      const TEvaluator2D * GetEvaluator () const{return Evaluator;}
};
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
