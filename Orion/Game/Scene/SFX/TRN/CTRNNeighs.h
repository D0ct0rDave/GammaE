#ifndef CTRNNeighsH
#define CTRNNeighsH

#include "GammaE.h"

class CTRNNeighs
{
	public:		
		static CMesh *GetNeighs(CVect3 &_roPos,float _fRadius);

	protected:
		static void BuildMesh(float *_pfHF,unsigned int _uiTX,unsigned int _uiTY,float _fOfsX,float _fOfsY);

	protected:
		static CMesh goNGMesh;
};
#endif
