//## begin module%3BA90F7A0337.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BA90F7A0337.cm

//## begin module%3BA90F7A0337.cp preserve=no
//## end module%3BA90F7A0337.cp

//## Module: eGraphBV_TypeID%3BA90F7A0337; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\BoundingVolume\GraphBoundVol\eGraphBV_TypeID.h

#ifndef eGraphBV_TypeID_h
#define eGraphBV_TypeID_h 1

//## begin module%3BA90F7A0337.additionalIncludes preserve=no
//## end module%3BA90F7A0337.additionalIncludes

//## begin module%3BA90F7A0337.includes preserve=yes
//## end module%3BA90F7A0337.includes

//## begin module%3BA90F7A0337.additionalDeclarations preserve=yes
//## end module%3BA90F7A0337.additionalDeclarations


//## begin eGraphBV_TypeID%3BA90F7A0337.preface preserve=yes
//## end eGraphBV_TypeID%3BA90F7A0337.preface

//## Class: eGraphBV_TypeID%3BA90F7A0337
//## Category: E3D::BoundingVolume::GraphBoundVol%3B7060820104
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum
{
    eGraphBV,    // 0
    eGraphBV_Sphere,    // 1
    eGraphBV_Box,    // 2
    eGraphBV_Cylinder,    // 3
    eGraphBV_Point     // 4
} eGraphBV_TypeID;

//## begin eGraphBV_TypeID%3BA90F7A0337.postscript preserve=yes
//## end eGraphBV_TypeID%3BA90F7A0337.postscript

//## begin module%3BA90F7A0337.epilog preserve=yes
//## end module%3BA90F7A0337.epilog


#endif
