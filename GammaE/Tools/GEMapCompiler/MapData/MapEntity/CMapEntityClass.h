//## begin module%3C742919007D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C742919007D.cm

//## begin module%3C742919007D.cp preserve=no
//## end module%3C742919007D.cp

//## Module: CMapEntityClass%3C742919007D; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\MapData\MapEntity\CMapEntityClass.h

#ifndef CMapEntityClass_h
#define CMapEntityClass_h 1

//## begin module%3C742919007D.additionalIncludes preserve=no
//## end module%3C742919007D.additionalIncludes

//## begin module%3C742919007D.includes preserve=yes
//## end module%3C742919007D.includes

//## begin module%3C742919007D.additionalDeclarations preserve=yes
//## end module%3C742919007D.additionalDeclarations


//## begin CMapEntityClass%3C742919007D.preface preserve=yes
//## end CMapEntityClass%3C742919007D.preface

//## Class: CMapEntityClass%3C742919007D
//## Category: Tools::GEMapCompiler::MapData::MapEntity%3C7428F80364
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum
{
    eMapEnt_NULL,    // 0
    eMapEnt_World,    // 1
    eMapEnt_Sound,    // 2
    eMapEnt_Light,    // 3
    eMapEnt_Monster,    // 4
    eMapEnt_PowerUp,    // 5
    eMapEnt_Item,    // 6
    eMapEnt_Trigger,    // 7
    eMapEnt_Target,    // 8
    eMapEnt_TargetMultiple,    // 9
    eMapEnt_Platform,    // 10
    eMapEnt_SrcPoint,    // 11
    eMapEnt_DstPoint,    // 12
    eMapEnt_PlayerStart,    // 13
    eMapEnt_NumClasses     // 14
} CMapEntityClass;

//## begin CMapEntityClass%3C742919007D.postscript preserve=yes
//## end CMapEntityClass%3C742919007D.postscript

//## begin module%3C742919007D.epilog preserve=yes
//## end module%3C742919007D.epilog


#endif
