//---------------------------------------------------------------------------
#include <math.h>
// #include "MathG.h"

#include "Generators/PT_Generator_Evaluator.h"
#include "Math/Vect2.h"
//---------------------------------------------------------------------------
// Class PT_Generator_Evaluator
//---------------------------------------------------------------------------
PT_Generator_Evaluator::~PT_Generator_Evaluator()
{
	delete Evaluator;
}
//---------------------------------------------------------------------------
void PT_Generator_Evaluator::Generate(PT_HeightField *HF)
{
	unsigned int cI,cJ;
    float 		 Value;

    float		 WScaleW = pow(2.0f,Scale) / HF->GetTX();
    float		 WScaleH = pow(2.0f,Scale) / HF->GetTY();

    float		 CHalfTX = HF->GetTX()/2;
    float 		 CHalfTY = HF->GetTY()/2;
    TVect2		 Pos;

    for (cJ=0;cJ<HF->GetTY();cJ++)
	    for (cI=0;cI<HF->GetTX();cI++)
        {
        	// Coordenadas en el sistema nuevo
            Pos.v[0] = (float)(cI-CHalfTX)*WScaleW;
            Pos.v[1] = (float)(cJ-CHalfTY)*WScaleH;

            // Obtener coordenadas relativas al sistema original (sin rotacion)
            Pos = V2_Rotate(Pos,Angle);

            Pos.v[0] += OfsX;
            Pos.v[1] += OfsY;

            Value  =  Evaluator->GetValue(Pos.v[0],Pos.v[1]);
            HF->SetHeight(cI,cJ,Value);
        }
}
//---------------------------------------------------------------------------
void PT_Generator_Evaluator::SetEvaluator (TEvaluator2D *_Evaluator)
{
  	Evaluator = _Evaluator;
}
//---------------------------------------------------------------------------
