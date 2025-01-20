//## begin module%3C509C6E0260.cm preserve=no
//## end module%3C509C6E0260.cm

//## begin module%3C509C6E0260.cp preserve=no
//## end module%3C509C6E0260.cp

//## Module: CDefferredMeshDB%3C509C6E0260; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\MeshDB\CDefferredMeshDB.cpp

//## begin module%3C509C6E0260.additionalIncludes preserve=no
//## end module%3C509C6E0260.additionalIncludes

//## begin module%3C509C6E0260.includes preserve=yes
#include "Memory/GammaE_Mem.h"
#include <stdlib.h>
//## end module%3C509C6E0260.includes

// CDefferredMeshDB
#include "E3D\MeshDB\CDefferredMeshDB.h"
//## begin module%3C509C6E0260.additionalDeclarations preserve=yes


int SortDMEntries( const void *a, const void *b)
{
	// Sort first by material, and then by mesh
	static TDefferredMeshEntry *poDMa,*poDMb;

	poDMa = (TDefferredMeshEntry *)a;
	poDMb = (TDefferredMeshEntry *)b;

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

//## end module%3C509C6E0260.additionalDeclarations


// Class CDefferredMeshDB 





CDefferredMeshDB::CDefferredMeshDB()
  //## begin CDefferredMeshDB::CDefferredMeshDB%.hasinit preserve=no
  //## end CDefferredMeshDB::CDefferredMeshDB%.hasinit
  //## begin CDefferredMeshDB::CDefferredMeshDB%.initialization preserve=yes
  //## end CDefferredMeshDB::CDefferredMeshDB%.initialization
{
  //## begin CDefferredMeshDB::CDefferredMeshDB%.body preserve=yes
  //## end CDefferredMeshDB::CDefferredMeshDB%.body
}


CDefferredMeshDB::~CDefferredMeshDB()
{
  //## begin CDefferredMeshDB::~CDefferredMeshDB%.body preserve=yes
  //## end CDefferredMeshDB::~CDefferredMeshDB%.body
}



//## Other Operations (implementation)
void CDefferredMeshDB::Init (int _iNumEntries)
{
  //## begin CDefferredMeshDB::Init%1011911195.body preserve=yes
	iMaxEntries = _iNumEntries;
	iNumEntries = 0;

	MeshDB = mNew TDefferredMeshEntry[iMaxEntries];
  //## end CDefferredMeshDB::Init%1011911195.body
}

void CDefferredMeshDB::InsertDefferredObject (void* _poMesh, eE3D_MeshType _eMT, CE3D_Shader* _poShader, CMatrix4x4& _roMatrix, unsigned int _uiLights)
{
  //## begin CDefferredMeshDB::InsertDefferredObject%1011911196.body preserve=yes
	assert (MeshDB && "NULL Mesh database");
	if (iNumEntries == iMaxEntries) return;
		
	MeshDB[iNumEntries].poMesh    = _poMesh;
	MeshDB[iNumEntries].eMeshType = _eMT;
	MeshDB[iNumEntries].poShader  = _poShader;
	MeshDB[iNumEntries].oMatrix   = _roMatrix;
	MeshDB[iNumEntries].uiLights  = _uiLights;

	iNumEntries++;
  //## end CDefferredMeshDB::InsertDefferredObject%1011911196.body
}

void CDefferredMeshDB::Invalidate ()
{
  //## begin CDefferredMeshDB::Invalidate%1011911197.body preserve=yes
	iNumEntries = 0;
  //## end CDefferredMeshDB::Invalidate%1011911197.body
}

eE3D_MeshType CDefferredMeshDB::eGetObject (int _iEntry, void *&_rpMesh, CE3D_Shader* &_rpoShader, CMatrix4x4* &_rpoMatrix, unsigned int& _ruiLights)
{
  //## begin CDefferredMeshDB::eGetObject%1011911198.body preserve=yes
	assert (MeshDB && "NULL Mesh database");
	assert ((_iEntry<iNumEntries) && "MeshDB Index out of bounds");

	_rpMesh		=  MeshDB[_iEntry].poMesh;
	_rpoMatrix	= &MeshDB[_iEntry].oMatrix;
	_rpoShader  =  MeshDB[_iEntry].poShader;
	_ruiLights 	=  MeshDB[_iEntry].uiLights;

	return (MeshDB[_iEntry].eMeshType);
  //## end CDefferredMeshDB::eGetObject%1011911198.body
}

void CDefferredMeshDB::Sort ()
{
  //## begin CDefferredMeshDB::Sort%1020152547.body preserve=yes
	
	// Sort entries by material and then by mesh
	qsort(MeshDB, iNumEntries, sizeof(TDefferredMeshEntry), SortDMEntries);

  //## end CDefferredMeshDB::Sort%1020152547.body
}

// Additional Declarations
  //## begin CDefferredMeshDB%3C509C6E0260.declarations preserve=yes
  //## end CDefferredMeshDB%3C509C6E0260.declarations

//## begin module%3C509C6E0260.epilog preserve=yes
//## end module%3C509C6E0260.epilog
