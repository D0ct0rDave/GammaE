//## begin module%3C7E12950340.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7E12950340.cm

//## begin module%3C7E12950340.cp preserve=no
//## end module%3C7E12950340.cp

//## Module: eFileOS_SeekMode%3C7E12950340; Pseudo Package specification
//## Source file: i:\Projects\GammaE\FileSys\OSFile\eFileOS_SeekMode.h

#ifndef eFileOS_SeekMode_h
#define eFileOS_SeekMode_h 1

//## begin module%3C7E12950340.additionalIncludes preserve=no
//## end module%3C7E12950340.additionalIncludes

//## begin module%3C7E12950340.includes preserve=yes
//## end module%3C7E12950340.includes

//## begin module%3C7E12950340.additionalDeclarations preserve=yes
//## end module%3C7E12950340.additionalDeclarations


//## begin eFileOS_SeekMode%3C7E12950340.preface preserve=yes
//## end eFileOS_SeekMode%3C7E12950340.preface

//## Class: eFileOS_SeekMode%3C7E12950340
//## Category: FileSys::OSFile%3C7E120001FB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum
{
    eOSF_SM_Set,    // 0
    eOSF_SM_Cur,    // 1
    eOSF_SM_End     // 2
} eFileOS_SeekMode;

//## begin eFileOS_SeekMode%3C7E12950340.postscript preserve=yes
//## end eFileOS_SeekMode%3C7E12950340.postscript

//## begin module%3C7E12950340.epilog preserve=yes
//## end module%3C7E12950340.epilog


#endif
