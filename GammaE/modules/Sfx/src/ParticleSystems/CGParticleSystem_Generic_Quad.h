// -----------------------------------------------------------------------------
#ifndef CGParticleSystem_Generic_Quad_h
#define CGParticleSystem_Generic_Quad_h 1
// -----------------------------------------------------------------------------
#include "ParticleSystems\CGParticleSystem_Generic.h"
// -----------------------------------------------------------------------------
typedef struct{
	
	CVect3 Pos;
	
	CVect3 Speed;	
	CVect3 OldSpeed;
	
	CVect4 Color;

	float  fSize;
	float  fEnergy;

}TParticle_Quad;
// -----------------------------------------------------------------------------
class CGParticleSystem_Generic_Quad : public CGParticleSystem_Generic
{   
	public:
		CGParticleSystem_Generic_Quad();

		virtual ~CGParticleSystem_Generic_Quad();


		virtual void InitPS (int _iMaxParticles, bool _bZOrder, bool _bDisableZBuffer);

		virtual void InitParticle (int iPart);

		virtual void UpdateParticle (int iPart);

		virtual void UpdatePS (CMatrix4x4* _ViewMatrix);

	protected:
		TParticle_Quad *pParts;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
