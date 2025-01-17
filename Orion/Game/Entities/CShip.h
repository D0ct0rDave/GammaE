#ifndef CShip_h
#define CShip_h 1

#include "GammaE.h"
// #include "Game/Entities/CGPGraphicEntity.h"
#include "Game/Entities/COrionEnt.h"

// ----------------------------------------------------------------------------
#define		MFLAG_FW		0x01
#define		MFLAG_BK		0x02
#define		MFLAG_RT		0x04
#define		MFLAG_LF		0x08

#define		MFLAG_FWBK	(MFLAG_FW | MFLAG_BK)
#define		MFLAG_LFRT	(MFLAG_LF | MFLAG_RT)
#define		MFLAG_LFFW	(MFLAG_LF | MFLAG_FW)
#define		MFLAG_LFBK  (MFLAG_LF | MFLAG_BK)
#define		MFLAG_RTFW	(MFLAG_RT | MFLAG_FW)
#define		MFLAG_RTBK  (MFLAG_RT | MFLAG_BK)

// Yaw left
#define		MFLAG_YL		0x10	
// Yaw right
#define		MFLAG_YR		0x20	
// Pitch up
#define		MFLAG_PU		0x40
// Pitch down
#define		MFLAG_PD		0x80

#define		MFLAG_RURD	(MFLAG_RU | MFLAG_RD)
#define		MFLAG_YUYD  (MFLAG_YU | MFLAG_YD)

// ----------------------------------------------------------------------------
inline bool bExclusiveFlags(int iFlags,int Flag)
{
	return(iFlags == Flag);
}

// ----------------------------------------------------------------------------
class CShip : public COrionEnt
{  
	public:
		 CShip();
		~CShip();
	
		virtual void Think		(float _fDelta);
		virtual void ProcessCmds(float _fDelta);
		virtual void Interact	(float _fDelta);
		virtual void ComputeCollisionResponse ();

		virtual void NotifyTargetCollision(COrionEnt *_poTarget);
		virtual void ReceiveImpact(float _fImpactFactor,COrionEnt *_poInflictor);

		void SetShipProps(float _fAccel,float _fDecel,float _fMaxSpeed,float _fDYaw,float _fDPitch,float _fEnergy,float _fShield);

	public:
		float		fEnergy;
		float		fShield;
		float		fSpeed;
		float		fTime;

	protected:
		float	fMaxSpeed;
		float	fAccel;
		float	fDecel;
		float   fDYaw;
		float   fDPitch;

		int		iMFlags;			// Movement flags

	private:
	private: //## implementation
};

inline void CShip::SetShipProps(float _fAccel,float _fDecel,float _fMaxSpeed,float _fDYaw,float _fDPitch,float _fEnergy,float _fShield)
{
	// -------------------------------
	// Caracteristicas de las naves
	// -------------------------------
	fAccel    = _fAccel;
	fDecel    = _fDecel;
	fSpeed    = 0;
	fMaxSpeed = _fMaxSpeed;						

	fDYaw     =  _fDYaw*_PI_OVER_180_;		// Capacidad de giro lateral
	fDPitch   =  _fDPitch*_PI_OVER_180_;	// Capacidad de giro vertical

	fEnergy	  = _fEnergy;
	fShield   = _fShield;
}
// ----------------------------------------------------------------------------
#endif
