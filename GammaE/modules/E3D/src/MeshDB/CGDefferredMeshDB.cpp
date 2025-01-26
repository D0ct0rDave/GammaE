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
#include "GammaE_Mem.h"
#include "MeshDB\CGDefferredMeshDB.h"
#include "Shaders/CGShader.h"
// ----------------------------------------------------------------------------
int SortDMEntries( const void* a, const void* b)
{
    // Sort first by material, and then by mesh
    CGDefferredMeshEntry* poDMa = NULL;
    CGDefferredMeshEntry* poDMb = NULL;

    poDMa = (CGDefferredMeshEntry*)a;
    poDMb = (CGDefferredMeshEntry*)b;

    // Sort by transparency
    if ( ( !poDMa->poShader->bIsTransparent() ) && ( poDMb->poShader->bIsTransparent() ) ) return(-1);
    if ( ( poDMa->poShader->bIsTransparent() ) && ( !poDMb->poShader->bIsTransparent() ) ) return(1);

    // Sort by material
    if ( (pointer)poDMa->poShader < (pointer)poDMb->poShader ) return(-1);
    if ( (pointer)poDMa->poShader > (pointer)poDMb->poShader ) return(1);

    // Sort by mesh
    if ( (pointer)poDMa->poMesh < (pointer)poDMb->poMesh ) return(-1);
    if ( (pointer)poDMa->poMesh > (pointer)poDMb->poMesh ) return(1);

    return(0);
}
// ----------------------------------------------------------------------------
CGDefferredMeshDB::CGDefferredMeshDB()
{
}
// ----------------------------------------------------------------------------
CGDefferredMeshDB::~CGDefferredMeshDB()
{
    m_oMeshDB.Clear();
}
// ----------------------------------------------------------------------------
void CGDefferredMeshDB::Init (uint _uiMaxEntries)
{
    m_oMeshDB.Init(_uiMaxEntries);
}
// ----------------------------------------------------------------------------
bool CGDefferredMeshDB::bInsertDefferredObject(CGBaseMesh* _poMesh, CGShader* _poShader,const CGMatrix4x4& _oMatrix, uint _uiLights)
{
    if ( m_oMeshDB.uiNumElems() == m_oMeshDB.uiMaxElems() ) return(false);

    CGDefferredMeshEntry oDME;

    oDME.poMesh = _poMesh;
    oDME.poShader = _poShader;
    oDME.oMatrix = _oMatrix;
    oDME.uiLights = _uiLights;

    m_oMeshDB.iAdd(oDME);
    return(true);
}
// ----------------------------------------------------------------------------
void CGDefferredMeshDB::Invalidate ()
{
    m_oMeshDB.Clear();
}
// ----------------------------------------------------------------------------
const CGDefferredMeshEntry& CGDefferredMeshDB::oGetObject(uint _uiEntry)
{
    assert ( ( _uiEntry < m_oMeshDB.uiNumElems() ) && "MeshDB Index out of bounds" );
    return (m_oMeshDB[_uiEntry]);
}
// ----------------------------------------------------------------------------
uint CGDefferredMeshDB::uiNumObjects()
{
    return ( m_oMeshDB.uiNumElems() );
}
// ----------------------------------------------------------------------------
void CGDefferredMeshDB::Sort ()
{
    // Sort entries by material and then by mesh
    qsort(m_oMeshDB.poBuff(),m_oMeshDB.uiNumElems(),sizeof(CGDefferredMeshEntry),SortDMEntries);
}
// ----------------------------------------------------------------------------
