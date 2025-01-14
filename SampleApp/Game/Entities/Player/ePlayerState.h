//## begin module%3B6087BD0168.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B6087BD0168.cm

//## begin module%3B6087BD0168.cp preserve=no
//## end module%3B6087BD0168.cp

//## Module: ePlayerState%3B6087BD0168; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\Entities\Player\ePlayerState.h

#ifndef ePlayerState_h
#define ePlayerState_h 1

//## begin module%3B6087BD0168.additionalIncludes preserve=no
//## end module%3B6087BD0168.additionalIncludes

//## begin module%3B6087BD0168.includes preserve=yes
//## end module%3B6087BD0168.includes

//## begin module%3B6087BD0168.additionalDeclarations preserve=yes
//## end module%3B6087BD0168.additionalDeclarations


//## begin ePlayerState%3B6087BD0168.preface preserve=yes
//## end ePlayerState%3B6087BD0168.preface

//## Class: ePlayerState%3B6087BD0168
//## Category: Game::Entities::Player%3B62D1730046
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum
{
    PS_Idle = 0,
    PS_Running = 1,
    PS_Walking = 2,
    PS_Jumping = 4,
    PS_Attacking = 8,
    PS_Flying = 12 
} ePlayerState;

//## begin ePlayerState%3B6087BD0168.postscript preserve=yes
//## end ePlayerState%3B6087BD0168.postscript

//## begin module%3B6087BD0168.epilog preserve=yes
//## end module%3B6087BD0168.epilog


#endif
