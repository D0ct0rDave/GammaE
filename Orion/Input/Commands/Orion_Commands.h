// ----------------------------------------------------------------------------
#ifndef Orion_CommandsH
#define Orion_CommandsH
// ----------------------------------------------------------------------------

enum KEYCommand_Type {

	KCMD_NONE,

    KCMD_FORWARD,
    KCMD_BACKWARD,
    KCMD_UP,
    KCMD_DOWN,
    KCMD_LEFT,
    KCMD_RIGHT ,
	KCMD_JUMP,

	KCMD_TURNUP,
    KCMD_TURNDOWN,
    KCMD_TURNLEFT,
    KCMD_TURNRIGHT,

	KCMD_GENMOVE,			// Generic moving : i.e. for mouse or joystick

	KCMD_BUTTON0,
	KCMD_BUTTON1,
	KCMD_BUTTON2,
	KCMD_BUTTON3,
	KCMD_BUTTON4,

	KCMD_EXIT,

	KCMD_CAMFORWARD,
    KCMD_CAMBACKWARD,
    KCMD_CAMUP,
    KCMD_CAMDOWN,
    KCMD_CAMLEFT,
    KCMD_CAMRIGHT,

	KCMD_SELECT,
	KCMD_SELW0,
	KCMD_SELW1,
	KCMD_SELW2,
	KCMD_SELW3,
	KCMD_SELW4,
	KCMD_SELW5,
	KCMD_SELW6,
	KCMD_SELW7,
	KCMD_SELW8,
	
	KCMD_FUNC0,
	KCMD_FUNC1,
	KCMD_FUNC2,
	KCMD_FUNC3,
	KCMD_FUNC4,
	KCMD_FUNC5,
	KCMD_FUNC6,
	KCMD_FUNC7,
	KCMD_FUNC8,
	KCMD_FUNC9,

	KCMD_TOGGLECONSOLE,
	KCMD_SCREENSHOT,

    KCMD_NUMKEYCOMMANDS
};

// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
