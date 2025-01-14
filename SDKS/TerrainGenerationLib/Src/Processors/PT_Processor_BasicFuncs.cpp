/****************************************************************
 *                                                              *
 * Module Name : PT_Processor_BasicFuncs                        *
 * Author      : David Márquez de la Cruz                       *
 * CreationDate: 29/01/01 23:08:15                              *
 * Description :                                                *
 * LOG         :                                                *
 *                                                              *
 ****************************************************************/

// -----------------------------------------------------------------------------
#include "Processors/PT_Processor_BasicFuncs.h"
#include "Math/MMath.h"

// -----------------------------------------------------------------------------
// Class PT_Processor_BasicFuncs
// -----------------------------------------------------------------------------
PT_Processor_BasicFuncs::~PT_Processor_BasicFuncs()
{
}
// -----------------------------------------------------------------------------
void PT_Processor_BasicFuncs::Process(PT_HeightField *HF)
{
	switch (OpType)
    {
    	case 0:	Clamp     (HF);     break;
        case 1: Normalize (HF);     break;
        case 2: InvertClamp    (HF);break;
      	case 3: InvertNormalize(HF);break;
    }
}
// -----------------------------------------------------------------------------
void PT_Processor_BasicFuncs::Copy(PT_HeightField *HFa, PT_HeightField *HFb)
{
	if (
    	(HFa->GetTX() == HFb->GetTX()) &&
        (HFa->GetTY() == HFb->GetTY())
       )
    {
    	unsigned int cI,cJ;

        for (cJ=0;cJ<HFa->GetTY();cJ++)
	        for (cI=0;cI<HFa->GetTX();cI++)
             	HFa->SetHeight(cI,cJ,HFb->GetHeight(cI,cJ));
    }
}
// -----------------------------------------------------------------------------
void PT_Processor_BasicFuncs::Multiply (PT_HeightField *HFa, PT_HeightField *HFb)
{
	if (
    	(HFa->GetTX() == HFb->GetTX()) &&
        (HFa->GetTY() == HFb->GetTY())
       )
    {
    	unsigned int cI,cJ;

        for (cJ=0;cJ<HFa->GetTY();cJ++)
	        for (cI=0;cI<HFa->GetTX();cI++)
             	HFa->SetHeight(cI,cJ,HFa->GetHeight(cI,cJ) *
                                     HFb->GetHeight(cI,cJ));
    }
}
// -----------------------------------------------------------------------------
void PT_Processor_BasicFuncs::Add (PT_HeightField *HFa, PT_HeightField *HFb)
{
	if ((! HFa) || ( ! HFb)) return;

	if (
    	(HFa->GetTX() == HFb->GetTX()) &&
        (HFa->GetTY() == HFb->GetTY())
       )
    {
    	unsigned int cI,cJ;

        for (cJ=0;cJ<HFa->GetTY();cJ++)
	        for (cI=0;cI<HFa->GetTX();cI++)
             	HFa->SetHeight(cI,cJ,HFa->GetHeight(cI,cJ) +
                					 HFb->GetHeight(cI,cJ));
    }
}
// -----------------------------------------------------------------------------
void PT_Processor_BasicFuncs::Rescale(PT_HeightField *HF,float Scale)
{
	if (! HF) return;

	unsigned int cI,cJ;
    for (cJ=0;cJ<HF->GetTY();cJ++)
        for (cI=0;cI<HF->GetTX();cI++)
            HF->SetHeight(cI,cJ,HF->GetHeight(cI,cJ) * Scale);
}
// -----------------------------------------------------------------------------
void PT_Processor_BasicFuncs::Displace(PT_HeightField *HF,float Displacement)
{
	unsigned int cI,cJ;
    for (cJ=0;cJ<HF->GetTY();cJ++)
        for (cI=0;cI<HF->GetTX();cI++)
            HF->SetHeight(cI,cJ,HF->GetHeight(cI,cJ) + Displacement);
}
// -----------------------------------------------------------------------------
void PT_Processor_BasicFuncs::Clamp(PT_HeightField *HF)
{
	if (! HF) return;
    if ((HF->GetMin()==0) && (HF->GetMax() - HF->GetMin()==1)) return;

	unsigned int cI,cJ;

    for (cJ=0;cJ<HF->GetTY();cJ++)
        for (cI=0;cI<HF->GetTX();cI++)
            HF->SetHeight(cI,cJ,MMath_Clamp(HF->GetHeight(cI,cJ),0.0f,1.0f));
}
// -----------------------------------------------------------------------------
void PT_Processor_BasicFuncs::Normalize (PT_HeightField *HF)
{
	if (! HF) return;
    if ((HF->GetMin()==0) && (HF->GetMax() - HF->GetMin()==1)) return;

	unsigned int cI,cJ;
    float fMinValue = HF->GetMin();
    float fInvRange;

    if (HF->GetRange()) fInvRange = 1.0f/HF->GetRange(); else fInvRange = 1.0f;

    for (cJ=0;cJ<HF->GetTY();cJ++)
        for (cI=0;cI<HF->GetTX();cI++)
            HF->SetHeight(cI,cJ,(HF->GetHeight(cI,cJ)-fMinValue) * fInvRange);
}
// -----------------------------------------------------------------------------
void PT_Processor_BasicFuncs::InvertNormalize(PT_HeightField *HF)
{
	if (! HF) return;
    Normalize(HF);

	unsigned int cI,cJ;
    for (cJ=0;cJ<HF->GetTY();cJ++)
        for (cI=0;cI<HF->GetTX();cI++)
            HF->SetHeight(cI,cJ,1.0f - HF->GetHeight(cI,cJ) );
}
// -----------------------------------------------------------------------------
void PT_Processor_BasicFuncs::InvertClamp(PT_HeightField *HF)
{
	if (! HF) return;
    Clamp(HF);

	unsigned int cI,cJ;
    for (cJ=0;cJ<HF->GetTY();cJ++)
        for (cI=0;cI<HF->GetTX();cI++)
            HF->SetHeight(cI,cJ,1.0f - HF->GetHeight(cI,cJ) );
}
// -----------------------------------------------------------------------------
void PT_Processor_BasicFuncs::Interpolate(PT_HeightField *HFa,PT_HeightField *HFb,PT_HeightField *HFm)
{
	if (
    	(HFa->GetTX() == HFb->GetTX()) && (HFb->GetTX() == HFm->GetTX()) &&
        (HFa->GetTY() == HFb->GetTY()) && (HFb->GetTY() == HFm->GetTY())
       )
    {
    	unsigned int cI,cJ;

        for (cJ=0;cJ<HFa->GetTY();cJ++)
            for (cI=0;cI<HFa->GetTX();cI++)
                HFa->SetHeight(cI,cJ,
                    MMath_Lerp(
                        HFm->GetHeight(cI,cJ),
                        HFa->GetHeight(cI,cJ),
                        HFb->GetHeight(cI,cJ)
                    )
                );
	}
}
// -----------------------------------------------------------------------------
