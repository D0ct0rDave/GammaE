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
#include "CGSceneMux.h"
// ----------------------------------------------------------------------------
CGSceneMux::CGSceneMux() : m_bSelected(NULL)
{
    m_eNodeType = SNT_Mux;
}
// ----------------------------------------------------------------------------
void CGSceneMux::Init(uint _uiMaxSubObjects)
{
    CGSceneGroup::Init(_uiMaxSubObjects);
    m_bSelected.Init(_uiMaxSubObjects);

    // Create the array and initialize it
    for ( uint i = 0; i < _uiMaxSubObjects; i++ )
        m_bSelected.iAdd( true );
}
// ----------------------------------------------------------------------------
void CGSceneMux::SelectAll()
{
    for ( uint i = 0; i < m_poSubObj.uiNumElems(); i++ ) m_bSelected[i] = true;
}
// ----------------------------------------------------------------------------
void CGSceneMux::SelectNone()
{
    for ( uint i = 0; i < m_poSubObj.uiNumElems(); i++ ) m_bSelected[i] = false;
}
// ----------------------------------------------------------------------------
void CGSceneMux::Select(uint _uiIdx)
{
    assert(_uiIdx < m_poSubObj.uiNumElems() && "Mux index out of bounds");
    m_bSelected[_uiIdx] = true;
}
// ----------------------------------------------------------------------------
void CGSceneMux::Deselect(uint _uiIdx)
{
    assert(_uiIdx < m_poSubObj.uiNumElems() && "Mux index out of bounds");
    m_bSelected[_uiIdx] = false;
}
// ----------------------------------------------------------------------------
bool CGSceneMux::bIsSelected(uint _uiIdx)
{
    assert(_uiIdx < m_poSubObj.uiNumElems() && "Mux index out of bounds");

    return (m_bSelected[_uiIdx]);
}
// ----------------------------------------------------------------------------
