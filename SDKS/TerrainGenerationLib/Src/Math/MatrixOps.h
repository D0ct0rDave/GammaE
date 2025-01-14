//---------------------------------------------------------------------------
#ifndef MatrixOpsH
#define MatrixOpsH
//---------------------------------------------------------------------------
void  FindMaxMinMatrixValues(float *Matrix,unsigned int uiROWS,unsigned int uiCOLS,float *Max,float *Min);
void  RescaleMatrix(float *Matrix,unsigned int uiROWS,unsigned int uiCOLS);
void  ClampMatrix(float *Matrix,unsigned int uiROWS,unsigned int uiCOLS);
void  CopyMatrixs(float *SrcMatrix,float *DstMatrix,unsigned int uiROWS,unsigned int uiCOLS);
void  SumMatrixs(float *SrcMatrix,float *DstMatrix,unsigned int uiROWS,unsigned int uiCOLS);
void  MultiplyMatrixs(float *SrcMatrix,float *DstMatrix,unsigned int uiROWS,unsigned int uiCOLS);
void  InvertMatrix(float *Matrix,unsigned int uiROWS,unsigned int uiCOLS);
void  InterpolateMatrixs(float *SrcMatrix,float *DstMatrix,float *FactMatrix,unsigned int uiROWS,unsigned int uiCOLS);
float GetMatrixBilinearValue(float *Matrix,unsigned int uiROWS,unsigned int uiCOLS,float cX,float cY); 
//---------------------------------------------------------------------------
#endif
 