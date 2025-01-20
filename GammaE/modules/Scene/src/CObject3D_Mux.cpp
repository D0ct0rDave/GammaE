// ----------------------------------------------------------------------------
#include <string.h>
#include "GammaE_Mem.h"
// ----------------------------------------------------------------------------
#include "CObject3D_Mux.h"
// ----------------------------------------------------------------------------
CObject3D_Mux::CObject3D_Mux() : m_bSelected(NULL)
{
    TypeID = e3DObj_Mux;
}
// ----------------------------------------------------------------------------
CObject3D_Mux::~CObject3D_Mux()
{
    if(m_bSelected) mDel [] m_bSelected;
}
// ----------------------------------------------------------------------------
void CObject3D_Mux::Init(uint _uiMaxSubObjects)
{
   CObject3D_Node::Init(_uiMaxSubObjects);

     // Create the array and initialize it
    m_bSelected = mNew bool[_uiMaxSubObjects];

    for (uint i = 0; i < _uiMaxSubObjects; i++) m_bSelected[i] = true;
}
// ----------------------------------------------------------------------------
void CObject3D_Mux::Render()
{
    for(uint cObj = 0; cObj < poSubObj.uiNumElems(); cObj++)
        if ( ( poSubObj[cObj] ) && ( m_bSelected[cObj] ) )
            poSubObj[cObj]->Render();
}
// ----------------------------------------------------------------------------
void CObject3D_Mux::SelectAll()
{
    assert(m_bSelected && "NULL mux selection array");

    for (uint i = 0; i < poSubObj.uiNumElems(); i++) m_bSelected[i] = true;
}
// ----------------------------------------------------------------------------
void CObject3D_Mux::SelectNone()
{
    assert(m_bSelected && "NULL mux selection array");

    for (uint i = 0; i < poSubObj.uiNumElems(); i++) m_bSelected[i] = false;
}
// ----------------------------------------------------------------------------
void CObject3D_Mux::Select(uint _uiIdx)
{
    assert(m_bSelected && "NULL mux selection array");
    assert(_uiIdx < poSubObj.uiNumElems() && "Mux index out of bounds");
    m_bSelected[_uiIdx] = true;
}
// ----------------------------------------------------------------------------
void CObject3D_Mux::Deselect(uint _uiIdx)
{
    assert(m_bSelected && "NULL mux selection array");
    assert(_uiIdx < poSubObj.uiNumElems() && "Mux index out of bounds");
    m_bSelected[_uiIdx] = false;
}
// ----------------------------------------------------------------------------
bool CObject3D_Mux::bIsSelected(uint _uiIdx)
{
    assert(m_bSelected && "NULL mux selection array");
    assert(_uiIdx < poSubObj.uiNumElems() && "Mux index out of bounds");

    return ( m_bSelected[_uiIdx] );
}
// ----------------------------------------------------------------------------
