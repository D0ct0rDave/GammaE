// ---------------------------------------------------------------
#ifndef MenuLoopH
#define MenuLoopH
// ---------------------------------------------------------------
typedef enum eMENUState{
	MENUST_NONE,	
	MENUST_MAIN,
	MENUST_NEWGAME,
	MENUST_MISSION,
	MENUST_LOADGAME,
	MENUST_CREDITS,
	MENUST_QUIT,
	MENUST_NUM_STATES
};

extern eMENUState eMenuState;

void MenuLoop_Init();
void MenuLoop_Destroy();

bool MenuLoop_OnIdle();

// ---------------------------------------------------------------
#endif
// ---------------------------------------------------------------