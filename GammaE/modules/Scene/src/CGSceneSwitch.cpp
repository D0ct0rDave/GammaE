// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#include <string.h>
#include "GammaE_Mem.h"
// ----------------------------------------------------------------------------
#include "CGSceneSwitch.h"
// ----------------------------------------------------------------------------
CGSceneSwitch::CGSceneSwitch() :
    m_bEnabled(true),
    m_poObj(NULL)
{
    m_eNodeType = SNT_Switch;
}
// ----------------------------------------------------------------------------
CGSceneSwitch::~CGSceneSwitch()
{
    if ( m_poObj )
        m_poObj->Deref();
}
// ----------------------------------------------------------------------------
CGGraphBV* CGSceneSwitch::poGetBV()
{
    if (m_poObj)
    {
        return(m_poObj->poGetBV());
    }
    else
    {
        return(NULL);
    }
}
// ----------------------------------------------------------------------------
