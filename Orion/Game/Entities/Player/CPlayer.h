#ifndef CPlayer_h
#define CPlayer_h 1

#include "GammaE.h"
#include "Game/Entities/CShip.h"

typedef enum
{
    PC_None,
    PC_Forward,
    PC_Backward,
    PC_Left,
    PC_Right,
    PC_Up,
    PC_Down,
    PC_Jump,
    PC_Crouch,
    PC_ShotPrim,
	PC_ShotSec,
    PC_Roll,
    PC_Yaw,
	PC_TurnLeft,
	PC_TurnRight,
	PC_TurnUp,
	PC_TurnDown,
	PC_Select,

	PC_SelW0,
	PC_SelW1,
	PC_SelW2,
	PC_SelW3,
	PC_SelW4,
	PC_SelW5,
	PC_SelW6,
	PC_SelW7,
	PC_SelW8,
	PC_SelW9,

} ePlayerCommands;

typedef enum
{
    PS_Idle      = 0,
    PS_Accel     = 1,
    PS_Bracking  = 2,    
    PS_Attacking = 8,
    PS_Flying    = 12

} ePlayerState;


#define CMF_FORWARD		0x0001
#define CMF_BACKWARD	0x0002
#define CMF_UP			0x0004
#define CMF_DOWN		0x0008
#define CMF_LEFT		0x0010
#define CMF_RIGHT		0x0020



#define PWF_OPT1		0x00000001
#define PWF_OPT2		0x00000002
#define PWF_OPT3		0x00000004
#define PWF_OPT4		0x00000008
#define PWF_OPT5		0x00000010

// More commands
#define		MFLAG_ATTACK1		0x0100
#define		MFLAG_ATTACK2		0x0200
#define		MFLAG_SELECT		0x0400

#define		MFLAG_SEL_BLAST		0x00010000
#define		MFLAG_SEL_LASER		0x00020000
#define		MFLAG_SEL_HBLAST	0x00040000
#define		MFLAG_SEL_CHAINGUN	0x00080000
#define		MFLAG_SEL_RAIL		0x00100000
#define		MFLAG_SEL_BFG		0x00200000
#define		MFLAG_SEL_HOMMING	0x00400000
#define		MFLAG_SEL_NAPALM	0x00800000
#define		MFLAG_SEL_CONC		0x01000000


class CPlayer : public CShip
{  
	public:
		 CPlayer();
		~CPlayer();

		virtual void Fire ();
		virtual void FireSec ();
		virtual void Select  ();
		virtual void ChangeWeapon(int _iWeapon);
		
		virtual void Think(float _fDelta);
		virtual void ProcessCmds(float _fDelta);
		virtual void ControlCmds (int _iCmd, bool _bEnabled, float _fValue);
		virtual void NotifyTargetCollision(COrionEnt *_poTarget);

		void InitPlayer(char *_szPlayerName,int _iPlayerIdx,int _iModelIdx,CVect3 &_roCenter);
	
	public:
		// Game play fields
		char			szName[64];			// The player name
		int				iScore;
		float			fTime;
		unsigned int	uiWeapFlags;
		int				iOpt;				// Current weapon option
		int				iPWIdx;
		int				iSWIdx;
		short			sAmmo[9];	// Ammonition

	protected:
		float			fPShotTime;	// Primary weapon shot time
		float			fSShotTime; // Secondary weapon shot time
};

#endif
