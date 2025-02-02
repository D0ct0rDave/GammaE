// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
#include "CGNETTimeStampList.h"
// ----------------------------------------------------------------------------
CGNETTimeStampList::CGNETTimeStampList()
{
    m_oTSL.Init(16);
}

CGNETTimeStampList::~CGNETTimeStampList()
{
    m_oTSL.Clear();
}

bool CGNETTimeStampList::bExists(uint _uiTimeStamp)
{
    for ( int i = 0; i < m_oTSL.uiNumElems(); i++ )
    {
        if ( m_oTSL[i] == _uiTimeStamp )
            return(true);
    }

    return(false);
}

void CGNETTimeStampList::Add(uint _uiTimeStamp)
{
    if ( m_oTSL.uiNumElems() == m_oTSL.uiMaxElems() )
        m_oTSL.Del(0);

    m_oTSL.iAdd(_uiTimeStamp);
}
// ----------------------------------------------------------------------------
