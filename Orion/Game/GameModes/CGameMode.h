#ifndef CGameModeH
#define CGameModeH

class CGameMode
{
	public:	 CGameMode();
			~CGameMode();
			virtual void Init();
			virtual void Loop();
};

#endif