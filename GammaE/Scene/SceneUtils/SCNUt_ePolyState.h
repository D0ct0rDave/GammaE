//## begin module%3BDDF4A40230.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BDDF4A40230.cm

//## begin module%3BDDF4A40230.cp preserve=no
//## end module%3BDDF4A40230.cp

//## Module: SCNUt_ePolyState%3BDDF4A40230; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\SCNUt_ePolyState.h

#ifndef SCNUt_ePolyState_h
#define SCNUt_ePolyState_h 1

//## begin module%3BDDF4A40230.additionalIncludes preserve=no
//## end module%3BDDF4A40230.additionalIncludes

//## begin module%3BDDF4A40230.includes preserve=yes
//## end module%3BDDF4A40230.includes

//## begin module%3BDDF4A40230.additionalDeclarations preserve=yes
//## end module%3BDDF4A40230.additionalDeclarations


//## begin SCNUt_ePolyState%3BDDF4A40230.preface preserve=yes
//## end SCNUt_ePolyState%3BDDF4A40230.preface

//## Class: SCNUt_ePolyState%3BDDF4A40230
//## Category: Scene::SceneUtils%3AC22916003C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum
{
    POLYSTATE_NONE,    // 0
    POLYSTATE_FRONT,    // 1
    POLYSTATE_BACK,    // 2
    POLYSTATE_OVER,    // 3
    POLYSTATE_ONEOVER,    // 4
    POLYSTATE_TWOOVER,    // 5
    POLYSTATE_CROSS1,    // 6
    POLYSTATE_CROSS2,    // 7
    POLYSTATE_NUMSTATES     // 8
} SCNUt_ePolyState;

//## begin SCNUt_ePolyState%3BDDF4A40230.postscript preserve=yes
//## end SCNUt_ePolyState%3BDDF4A40230.postscript

//## begin module%3BDDF4A40230.epilog preserve=yes
//## end module%3BDDF4A40230.epilog


#endif
