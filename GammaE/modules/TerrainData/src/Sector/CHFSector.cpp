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
// CHFSector
#include "Sector\CHFSector.h"

// Class CHFSector

CHFSector::CHFSector()
    : MaxHeight(0), MinHeight(0), bRecomputeMaxMins(true)
{
}

CHFSector::~CHFSector()
{
}

float CHFSector::GetMaxHeight ()
{
    if ( bRecomputeMaxMins ) RecomputeMaxMins();
    return (MaxHeight);
}

float CHFSector::GetMinHeight ()
{
    if ( bRecomputeMaxMins ) RecomputeMaxMins();
    return (MinHeight);
}

void CHFSector::RecomputeMaxMins ()
{
    int cI,cJ;
    float fHeight;

    MaxHeight = -1.0E09f;
    MinHeight = 1.0E09f;
    for ( cJ = 0; cJ < Resolution; cJ++ )
        for ( cI = 0; cI < Resolution; cI++ )
        {
            fHeight = *(float*)GetValue(cI,cJ).Get();

            if ( fHeight > MaxHeight ) MaxHeight = fHeight;
            if ( fHeight < MinHeight ) MinHeight = fHeight;
        }

    bRecomputeMaxMins = false;
}

void CHFSector::SetValue (int _X, int _Y, CSectElem &_Value)
{
    bRecomputeMaxMins = true;
}

// Additional Declarations
