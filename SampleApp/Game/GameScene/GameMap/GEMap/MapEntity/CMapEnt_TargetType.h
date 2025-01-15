//## begin module%3CDC0E6803E7.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CDC0E6803E7.cm

//## begin module%3CDC0E6803E7.cp preserve=no
//## end module%3CDC0E6803E7.cp

//## Module: CMapEnt_TargetType%3CDC0E6803E7; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\MapData\MapEntity\CMapEnt_TargetType.h

#ifndef CMapEnt_TargetType_h
#define CMapEnt_TargetType_h 1

//## begin module%3CDC0E6803E7.additionalIncludes preserve=no
//## end module%3CDC0E6803E7.additionalIncludes

//## begin module%3CDC0E6803E7.includes preserve=yes
//## end module%3CDC0E6803E7.includes

//## begin module%3CDC0E6803E7.additionalDeclarations preserve=yes
//## end module%3CDC0E6803E7.additionalDeclarations


//## begin CMapEnt_TargetType%3CDC0E6803E7.preface preserve=yes
//## end CMapEnt_TargetType%3CDC0E6803E7.preface

//## Class: CMapEnt_TargetType%3CDC0E6803E7
//## Category: Tools::GEMapCompiler::MapData::MapEntity%3C7428F80364
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum
{
    eMapEnt_TT_Translate,    // 0
    eMapEnt_TT_Rotate,    // 1
    eMapEnt_TT_Disappear,    // 2
    eMapEnt_TT_Appear,    // 3
    eMapEnt_TT_None     // 4
} CMapEnt_TargetType;

//## begin CMapEnt_TargetType%3CDC0E6803E7.postscript preserve=yes
//## end CMapEnt_TargetType%3CDC0E6803E7.postscript

//## begin module%3CDC0E6803E7.epilog preserve=yes
//## end module%3CDC0E6803E7.epilog


#endif
