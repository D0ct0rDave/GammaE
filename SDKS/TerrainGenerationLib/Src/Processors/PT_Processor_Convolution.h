//---------------------------------------------------------------------------
#ifndef PT_Processor_ConvolutionH
#define PT_Processor_ConvolutionH
//---------------------------------------------------------------------------
#include "PT_Processor.h"
//---------------------------------------------------------------------------
class PT_Processor_Convolution : public PT_Processor
{
  public:
       PT_Processor_Convolution();
      ~PT_Processor_Convolution();

      virtual void Process(PT_HeightField *HF);
      virtual void SetConvolutionMatrix(unsigned int _uiDims,float *_pMatrix);
      virtual void SetDestinationHF(PT_HeightField *HF);

  protected:
      // Data Members for Class Attributes
      unsigned int       uiDims;
      float             *pMatrix;
      PT_HeightField    *pDstHF;
};
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
