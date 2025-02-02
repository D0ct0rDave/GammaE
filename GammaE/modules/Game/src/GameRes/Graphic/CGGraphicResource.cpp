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
// -----------------------------------------------------------------------------
#include "CGGraphicResource.h"
// -----------------------------------------------------------------------------
CGControlPoint* CGGraphicResource::poGetCP(const CGString& _sCPName)
{
    for ( int i = 0; i < m_oCPs.uiNumElems(); i++ )
        if ( m_oCPs[i].m_sName == _sCPName )
            return (&m_oCPs[i]);

    return (NULL);
}
// -----------------------------------------------------------------------------
