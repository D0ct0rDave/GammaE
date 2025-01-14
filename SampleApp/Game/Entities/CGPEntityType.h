//## begin module%3C16848001C2.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C16848001C2.cm

//## begin module%3C16848001C2.cp preserve=no
//## end module%3C16848001C2.cp

//## Module: CGPEntityType%3C16848001C2; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\Entities\CGPEntityType.h

#ifndef CGPEntityType_h
#define CGPEntityType_h 1

//## begin module%3C16848001C2.additionalIncludes preserve=no
//## end module%3C16848001C2.additionalIncludes

//## begin module%3C16848001C2.includes preserve=yes
//## end module%3C16848001C2.includes

//## begin module%3C16848001C2.additionalDeclarations preserve=yes
//## end module%3C16848001C2.additionalDeclarations


//## begin CGPEntityType%3C16848001C2.preface preserve=yes
//## end CGPEntityType%3C16848001C2.preface

//## Class: CGPEntityType%3C16848001C2
//## Category: Game::Entities%3B5DE99E0136
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum
{
    CGPET_Map,    // 0
    CGPET_Terrain,    // 1
    CGPET_Camera,    // 2
    CGPET_Player,    // 3
    CGPET_Platform     // 4
} CGPEntityType;

//## begin CGPEntityType%3C16848001C2.postscript preserve=yes
//## end CGPEntityType%3C16848001C2.postscript

//## begin module%3C16848001C2.epilog preserve=yes
//## end module%3C16848001C2.epilog


#endif
