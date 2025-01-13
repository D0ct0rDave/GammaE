//## begin module%3C7E18DB005A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7E18DB005A.cm

//## begin module%3C7E18DB005A.cp preserve=no
//## end module%3C7E18DB005A.cp

//## Module: eFile_SeekMode%3C7E18DB005A; Pseudo Package specification
//## Source file: i:\Projects\GammaE\FileSys\FileManager\eFile_SeekMode.h

#ifndef eFile_SeekMode_h
#define eFile_SeekMode_h 1

//## begin module%3C7E18DB005A.additionalIncludes preserve=no
//## end module%3C7E18DB005A.additionalIncludes

//## begin module%3C7E18DB005A.includes preserve=yes
//## end module%3C7E18DB005A.includes

//## begin module%3C7E18DB005A.additionalDeclarations preserve=yes
//## end module%3C7E18DB005A.additionalDeclarations


//## begin eFile_SeekMode%3C7E18DB005A.preface preserve=yes
//## end eFile_SeekMode%3C7E18DB005A.preface

//## Class: eFile_SeekMode%3C7E18DB005A
//## Category: FileSys::FileManager%3C7E13D00112
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum
{
    eFile_SM_Set,    // 0
    eFile_SM_Cur,    // 1
    eFile_SM_End     // 2
} eFile_SeekMode;

//## begin eFile_SeekMode%3C7E18DB005A.postscript preserve=yes
//## end eFile_SeekMode%3C7E18DB005A.postscript

//## begin module%3C7E18DB005A.epilog preserve=yes
//## end module%3C7E18DB005A.epilog


#endif
