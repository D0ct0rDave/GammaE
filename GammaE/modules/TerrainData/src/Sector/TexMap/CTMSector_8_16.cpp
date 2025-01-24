// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
#include "GammaE_Mem.h"

// CTMSector_8_16
#include "Sector\TexMap\CTMSector_8_16.h"
#define         TM_RFLAGS_TRANSITIONTEX_MASK        0x00ff
#define         TM_RFLAGS_TRANSITIONTEX_SHIFTBITS   0

#define         TM_RFLAGS_TRANSITION_MASK           0x0300
#define         TM_RFLAGS_TRANSITION_SHIFTBITS      8

#define         TM_RFLAGS_ROTATION_MASK             0x0c00
#define         TM_RFLAGS_ROTATION_SHIFTBITS        10

#define         TM_RFLAGS_INVISTILE_MASK            0x1000
#define         TM_RFLAGS_INVISTILE_SHIFTBITS       12

#define         TMAP_IDX_OFFSET                     (Resolution * Resolution * 2)
#define         TMAP_FLAG_OFFSET                    (0)

CTile T;

unsigned char ucTile;
unsigned short usFlag;
unsigned char* pucTile;
unsigned short* pusFlag;

// Class CTMSector_8_16

CTMSector_8_16::CTMSector_8_16()
{
    ulID = MAKE_RIFF_ID('T','M','C','S');
}

CTMSector_8_16::~CTMSector_8_16()
{
}

CSector* CTMSector_8_16::CreateClass ()
{
    return ( mNew CTMSector_8_16() );
}

unsigned long CTMSector_8_16::ElemArraySize (int _iResolution)
{
    return ( (1 + 2) * _iResolution * _iResolution );
}

CSectElem & CTMSector_8_16::GetValue (int _X, int _Y)
{
    ucTile = ( (unsigned char*)pData )[TMAP_IDX_OFFSET + _Y * Resolution + _X];
    usFlag = ( (unsigned short*)pData )[TMAP_FLAG_OFFSET + _Y * Resolution + _X];

    T.SetTileIdx        (  ucTile );
    T.SetRotationType   ( (usFlag & TM_RFLAGS_ROTATION_MASK) >> TM_RFLAGS_ROTATION_SHIFTBITS );
    T.SetTransitionType ( (usFlag & TM_RFLAGS_TRANSITION_MASK) >> TM_RFLAGS_TRANSITION_SHIFTBITS );
    T.SetTransTileIdx   ( (usFlag & TM_RFLAGS_TRANSITIONTEX_MASK) >> TM_RFLAGS_TRANSITIONTEX_SHIFTBITS );
    T.SetInvisible      ( (usFlag & TM_RFLAGS_INVISTILE_MASK) >> TM_RFLAGS_INVISTILE_SHIFTBITS );

    return(T);
}

void CTMSector_8_16::SetValue (int _X, int _Y, CSectElem &_Value)
{
    pucTile = &( (unsigned char*)pData )[TMAP_IDX_OFFSET + _Y * Resolution + _X];
    pusFlag = &( (unsigned short*)pData )[TMAP_FLAG_OFFSET + _Y * Resolution + _X];

    *pusFlag = ( (*(CTile*)&_Value).GetRotationType() << TM_RFLAGS_ROTATION_SHIFTBITS ) |
               ( (*(CTile*)&_Value).GetTransitionType() << TM_RFLAGS_TRANSITION_SHIFTBITS ) |
               ( (*(CTile*)&_Value).GetTransTileIdx() << TM_RFLAGS_TRANSITIONTEX_SHIFTBITS ) |
               ( (*(CTile*)&_Value).GetInvisible() << TM_RFLAGS_INVISTILE_SHIFTBITS );

    *pucTile = (*(CTile*)&_Value).GetTileIdx();
}

// Additional Declarations
