




// CEval_Binary
#include "MATH_Evaluator\CEval_Binary.h"
#include "GammaE_Mem.h"


// Class CEval_Binary 



CEval_Binary::CEval_Binary()
        : OperandA(NULL), OperandB(NULL)
      {
}


CEval_Binary::~CEval_Binary()
{
  	if (OperandA) mDel OperandA;
	if (OperandB) mDel OperandB;
}


// Additional Declarations
    
