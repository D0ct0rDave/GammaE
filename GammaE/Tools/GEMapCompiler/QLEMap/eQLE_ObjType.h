//## begin module%3CA0F4B90378.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CA0F4B90378.cm

//## begin module%3CA0F4B90378.cp preserve=no
//## end module%3CA0F4B90378.cp

//## Module: eQLE_ObjType%3CA0F4B90378; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\QLEMap\eQLE_ObjType.h

#ifndef eQLE_ObjType_h
#define eQLE_ObjType_h 1

//## begin module%3CA0F4B90378.additionalIncludes preserve=no
//## end module%3CA0F4B90378.additionalIncludes

//## begin module%3CA0F4B90378.includes preserve=yes
//## end module%3CA0F4B90378.includes

//## begin module%3CA0F4B90378.additionalDeclarations preserve=yes
//## end module%3CA0F4B90378.additionalDeclarations


//## begin eQLE_ObjType%3CA0F4B90378.preface preserve=yes
//## end eQLE_ObjType%3CA0F4B90378.preface

//## Class: eQLE_ObjType%3CA0F4B90378
//## Category: Tools::GEMapCompiler::QLEMap%3CA0F45D0394
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum
{
    eQLEOT_None,    // 0
    eQLEOT_Brush,    // 1
    eQLEOT_ObjList,    // 2
    eQLEOT_Entity,    // 3
    eQLEOT_ObjListAndEntity,    // 4
    eQLEOT_Num     // 5
} eQLE_ObjType;

//## begin eQLE_ObjType%3CA0F4B90378.postscript preserve=yes
//## end eQLE_ObjType%3CA0F4B90378.postscript

//## begin module%3CA0F4B90378.epilog preserve=yes
//## end module%3CA0F4B90378.epilog


#endif
