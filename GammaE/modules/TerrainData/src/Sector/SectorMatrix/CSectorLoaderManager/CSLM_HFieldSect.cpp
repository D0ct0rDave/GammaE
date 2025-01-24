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

// CSLM_HFieldSect
#include "Sector\SectorMatrix\CSectorLoaderManager\CSLM_HFieldSect.h"

// Class CSLM_HFieldSect

CSLM_HFieldSect::CSLM_HFieldSect()
{
}

CSLM_HFieldSect::~CSLM_HFieldSect()
{
}

CSector* CSLM_HFieldSect::poCreateClass (FILE* _FD)
{
    if ( !_FD ) return(NULL);

    unsigned int uiID;
    unsigned int uiBlockLenght;

    fread(&uiID,4,1,_FD);
    fread(&uiBlockLenght,4,1,_FD);

    switch ( uiID )
    {
        case MAKE_RIFF_ID('H','S','F','N'): return( mNew( CHFSector_FN ) );
        break;

        default:
        return(NULL);
    }

    return(NULL);
}

// Additional Declarations
