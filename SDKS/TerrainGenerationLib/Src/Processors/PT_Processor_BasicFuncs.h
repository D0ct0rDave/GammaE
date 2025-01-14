//---------------------------------------------------------------------------
#ifndef PT_Processor_BasicFuncs_h
#define PT_Processor_BasicFuncs_h 1
//---------------------------------------------------------------------------
#include "Processors/PT_Processor.h"
//---------------------------------------------------------------------------
/****************************************************************
 *                                                              *
 * Module Name : Not available                                  *
 * Author      :                                                *
 * CreationDate: 28/01/01 16:53:10                              *
 * Description :                                                *
 * LOG         :                                                *
 *                                                              *
 ****************************************************************/
 
class PT_Processor_BasicFuncs : public PT_Processor
{
  public:
      virtual ~PT_Processor_BasicFuncs();
      virtual void Process(PT_HeightField *HF);

      void Copy      (PT_HeightField *HFa, PT_HeightField *HFb);
      void Multiply  (PT_HeightField *HFa, PT_HeightField *HFb);
      void Add 		 (PT_HeightField *HFa, PT_HeightField *HFb);

      void Rescale   (PT_HeightField *HF,float Scale);
      void Displace  (PT_HeightField *HF,float Displacement);

      void Clamp     (PT_HeightField *HF);
      void Normalize (PT_HeightField *HF);
      void InvertNormalize(PT_HeightField *HF);
      void InvertClamp(PT_HeightField *HF);      

	  void Interpolate(PT_HeightField *HFa,
      	   			   PT_HeightField *HFb,
                       PT_HeightField *HFm);
  protected:
      // Data Members for Class Attributes
      unsigned int OpType;

  public:
      inline unsigned int GetOpType (){return OpType;}
      inline void         SetOpType (unsigned int _uiOpType){OpType = _uiOpType;}
};
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
