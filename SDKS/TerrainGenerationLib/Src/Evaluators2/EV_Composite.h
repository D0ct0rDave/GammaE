//---------------------------------------------------------------------------
#ifndef EV_CompositeH
#define EV_CompositeH
//---------------------------------------------------------------------------
#include "Evaluator2D.h"
//---------------------------------------------------------------------------
class TEvaluator2D_Composite : TEvaluator2D
{
	public:	virtual void SetBaseFunc(TEvaluator2D *Evaluator);

    protected:
            TEvaluator2D *BaseFunc;
};
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------