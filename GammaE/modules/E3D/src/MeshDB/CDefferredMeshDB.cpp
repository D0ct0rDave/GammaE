#include "GammaE_Mem.h"
#include "MeshDB\CDefferredMeshDB.h"
//-----------------------------------------------------------------------------
int SortDMEntries( const void *a, const void *b)
{
	// Sort first by material, and then by mesh
	static CDefferredMeshEntry *poDMa,*poDMb;

	poDMa = (CDefferredMeshEntry *)a;
	poDMb = (CDefferredMeshEntry *)b;

	// Sort by transparency
	if ((! poDMa->poShader->bIsTransparent()) && (poDMb->poShader->bIsTransparent()) )  return(-1);
	if ((  poDMa->poShader->bIsTransparent()) && (! poDMb->poShader->bIsTransparent()) ) return(1);

	// Sort by material
	if ((int)poDMa->poShader < (int)poDMb->poShader)	return(-1);
	if ((int)poDMa->poShader > (int)poDMb->poShader)	return(1);
	
	// Sort by mesh
	if ((int)poDMa->poMesh < (int)poDMb->poMesh)		return(-1);
	if ((int)poDMa->poMesh > (int)poDMb->poMesh)		return(1);

	return(0);
}
//-----------------------------------------------------------------------------
CDefferredMeshDB::CDefferredMeshDB()
{
}
//-----------------------------------------------------------------------------
CDefferredMeshDB::~CDefferredMeshDB()
{
	m_oMeshDB.Clear();
}
//-----------------------------------------------------------------------------
void CDefferredMeshDB::Init (uint _uiMaxEntries)
{
	m_oMeshDB.Init(_uiMaxEntries);
}
//-----------------------------------------------------------------------------
bool CDefferredMeshDB::bInsertDefferredObject(void* _poMesh, E3D_MeshType _eMT, CE3D_Shader* _poShader,const CMatrix4x4& _oMatrix, unsigned int _uiLights)
{
	if (m_oMeshDB.uiNumElems() == m_oMeshDB.uiMaxElems()) return(false);

	CDefferredMeshEntry oDME;

	oDME.poMesh			= _poMesh;
	oDME.eMeshType		= _eMT;
	oDME.poShader		= _poShader;
	oDME.oMatrix		= _oMatrix;
	oDME.uiLights		= _uiLights;
	
	m_oMeshDB.iAdd(oDME);
	return(true);
}
//-----------------------------------------------------------------------------
void CDefferredMeshDB::Invalidate ()
{
	m_oMeshDB.Clear();
}
//-----------------------------------------------------------------------------
const CDefferredMeshEntry& CDefferredMeshDB::oGetObject(uint _uiEntry)
{
	assert ((_uiEntry>=m_oMeshDB.uiNumElems()) && "MeshDB Index out of bounds");
	return ( m_oMeshDB[_uiEntry] );
}
//-----------------------------------------------------------------------------
uint CDefferredMeshDB::uiNumObjects()
{
	return (m_oMeshDB.uiNumElems());
}
//-----------------------------------------------------------------------------
void CDefferredMeshDB::Sort ()
{ 	
	// Sort entries by material and then by mesh
	qsort(m_oMeshDB.poBuff(),m_oMeshDB.uiNumElems(),sizeof(CDefferredMeshEntry),SortDMEntries);
}
//-----------------------------------------------------------------------------
