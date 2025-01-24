//	  %X% %Q% %Z% %W%

#ifndef e3DObjectTypeID_h
#define e3DObjectTypeID_h 1

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
    e3DObj_CompiledLeaf,     // 16
    e3DObj_ScreenRect,

} e3DObjectTypeID;

#endif
