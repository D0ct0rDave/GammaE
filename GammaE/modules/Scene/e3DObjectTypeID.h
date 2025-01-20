//## begin module%3B8BA7380079.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B8BA7380079.cm

//## begin module%3B8BA7380079.cp preserve=no
//## end module%3B8BA7380079.cp

//## Module: e3DObjectTypeID%3B8BA7380079; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\e3DObjectTypeID.h

#ifndef e3DObjectTypeID_h
#define e3DObjectTypeID_h 1

//## begin module%3B8BA7380079.additionalIncludes preserve=no
//## end module%3B8BA7380079.additionalIncludes

//## begin module%3B8BA7380079.includes preserve=yes
//## end module%3B8BA7380079.includes

//## begin module%3B8BA7380079.additionalDeclarations preserve=yes
//## end module%3B8BA7380079.additionalDeclarations


//## begin e3DObjectTypeID%3B8BA7380079.preface preserve=yes
//## end e3DObjectTypeID%3B8BA7380079.preface

//## Class: e3DObjectTypeID%3B8BA7380079
//## Category: Scene%3AA2567D00C8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum
{
    e3DObj_NULL,    // 0
    e3DObj_Gen,    // 1
    e3DObj_Leaf,    // 2
    e3DObj_Node,    // 3
    e3DObj_Transf,    // 4
    e3DObj_Anim_Begin,    // 5
    e3DObj_AnimGen,    // 6
    e3DObj_AnimNode,    // 7
    e3DObj_AnimMesh,    // 8
    e3DObj_AnimTransf,    // 9
    e3DObj_AnimCfg,    // 10
    e3DObj_AnimCfgMgr,    // 11
    e3DObj_Anim_End,    // 12
    e3DObj_Camera,    // 13
    e3DObj_Mux,    // 14
    e3DObj_BSPNode,    // 15
    e3DObj_CompiledLeaf     // 16
} e3DObjectTypeID;

//## begin e3DObjectTypeID%3B8BA7380079.postscript preserve=yes
//## end e3DObjectTypeID%3B8BA7380079.postscript

//## begin module%3B8BA7380079.epilog preserve=yes
//## end module%3B8BA7380079.epilog


#endif
