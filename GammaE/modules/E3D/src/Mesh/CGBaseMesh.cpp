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
#include "Mesh\CGBaseMesh.h"
// ----------------------------------------------------------------------------
CGBaseMesh::CGBaseMesh() :
    m_eMeshType(E3D_MT_None),
    m_poBV(NULL),
    m_uiNumVXs(0),
    m_uiNumPrims(0),
    m_ePrimitiveType(E3D_PT_NONE)
{
}
// ----------------------------------------------------------------------------
