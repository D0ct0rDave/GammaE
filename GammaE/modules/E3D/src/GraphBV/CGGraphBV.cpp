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
#include "GraphBV\CGGraphBV.h"

void CGGraphBV::Copy(const CGGraphBV& _oSrc)
{
    Init(_oSrc.oGetMax(), _oSrc.oGetMin() );
}

const CGVect3& CGGraphBV::GetExtents() const
{
    static CGVect3 oExtents;
    
    oExtents.Set( GetRange(0),GetRange(1),GetRange(2) );
    oExtents.Scale(0.5f);

    return(oExtents);
}

const CGVect3& CGGraphBV::oGetMax() const
{
    static CGVect3 oMax;

    oMax.Assign( GetCenter() );
    oMax.Add( GetExtents() );

    return(oMax);
}

const CGVect3& CGGraphBV::oGetMin() const
{
    static CGVect3 oMin;

    oMin.Assign( GetCenter() );
    oMin.Sub( GetExtents() );

    return(oMin);
}

// Additional Declarations
