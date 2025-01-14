//## begin module%3B6089B502E4.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B6089B502E4.cm

//## begin module%3B6089B502E4.cp preserve=no
//## end module%3B6089B502E4.cp

//## Module: ePlayerCommands%3B6089B502E4; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\Entities\Player\ePlayerCommands.h

#ifndef ePlayerCommands_h
#define ePlayerCommands_h 1

//## begin module%3B6089B502E4.additionalIncludes preserve=no
//## end module%3B6089B502E4.additionalIncludes

//## begin module%3B6089B502E4.includes preserve=yes
//## end module%3B6089B502E4.includes

//## begin module%3B6089B502E4.additionalDeclarations preserve=yes
//## end module%3B6089B502E4.additionalDeclarations


//## begin ePlayerCommands%3B6089B502E4.preface preserve=yes
//## end ePlayerCommands%3B6089B502E4.preface

//## Class: ePlayerCommands%3B6089B502E4
//## Category: Game::Entities::Player%3B62D1730046
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum
{
    PC_None = 0,
    PC_Forward = 1,
    PC_Backward = 2,
    PC_Left = 3,
    PC_Right = 4,
    PC_Up = 5,
    PC_Down = 6,
    PC_Jump = 7,
    PC_Crouch = 8,
    PC_Shot = 9,
    PC_Roll = 10,
    PC_Yaw = 11 
} ePlayerCommands;

//## begin ePlayerCommands%3B6089B502E4.postscript preserve=yes
//## end ePlayerCommands%3B6089B502E4.postscript

//## begin module%3B6089B502E4.epilog preserve=yes
//## end module%3B6089B502E4.epilog


#endif
