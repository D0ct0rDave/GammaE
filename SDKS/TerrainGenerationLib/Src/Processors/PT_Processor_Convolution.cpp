//---------------------------------------------------------------------------
#include "PT_Processor_Convolution.h"
//---------------------------------------------------------------------------
PT_Processor_Convolution::PT_Processor_Convolution()
{
    pMatrix = 0;
    uiDims  = 0;
}
//---------------------------------------------------------------------------
PT_Processor_Convolution::~PT_Processor_Convolution()
{

}
//---------------------------------------------------------------------------
void PT_Processor_Convolution::Process(PT_HeightField *HF)
{
    int cI,cJ,cK,cL;
    int iWnd = (uiDims-1)/2;
    float fHeight,fTemp,fSum;

    for (cJ=iWnd;cJ<= HF->GetTY()-iWnd;cJ++)
        for (cI=iWnd;cI<= HF->GetTY()-iWnd;cI++)
        {
            fTemp = 0;
            for (cL=cJ-iWnd;cL<=cJ+iWnd;cL++)
                for (cK=cI-iWnd;cK<=cI+iWnd;cK++)
                    fTemp += HF->GetHeight(cL,cK) * pMatrix[(cL-cJ+iWnd)*uiDims + (cK-cI+iWnd)];

            fSum = 0;
            for (cL=iWnd;cL<uiDims;cL++)
                for (cK=iWnd;cK<uiDims;cK++)
                    fSum += pMatrix[cL*iWnd+cK];

            if ( fSum != 0 ) fTemp /= fSum;
            if ( fTemp<0   ) fTemp = 0;
            if ( fTemp>1.0f) fTemp = 1.0f;

            pDstHF->SetHeight(cI,cJ,fTemp);
        }
}
//---------------------------------------------------------------------------
void PT_Processor_Convolution::SetConvolutionMatrix(unsigned int _uiDims,float *_pMatrix)
{
    pMatrix  = _pMatrix;
    uiDims   = _uiDims;
}
//---------------------------------------------------------------------------
void PT_Processor_Convolution::SetDestinationHF(PT_HeightField *HF)
{
    pDstHF = HF;
}
//---------------------------------------------------------------------------
