// ----------------------------------------------------------------------------
/*! \file GFileSysEnums
 *  \brief Common enumerations used in the file system module.
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef GFileSysEnumsH
#define GFileSysEnumsH
// ----------------------------------------------------------------------------

// / Open modes
typedef enum
{
    FOM_NONE,

    FOM_READ,
    FOM_WRITE,

    FOM_NUM,
}EFileOpenMode;

// / Seek modes
typedef enum
{
    FSM_NONE,

    FSM_SET,
    FSM_CUR,
    FSM_END,

    FSM_NUM
} EFileSeekMode;

// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
