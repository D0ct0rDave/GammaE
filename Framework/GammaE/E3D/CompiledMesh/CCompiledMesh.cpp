//## begin module%3C50874F011A.cm preserve=no
//## end module%3C50874F011A.cm

//## begin module%3C50874F011A.cp preserve=no
//## end module%3C50874F011A.cp

//## Module: CCompiledMesh%3C50874F011A; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\CompiledMesh\CCompiledMesh.cpp

//## begin module%3C50874F011A.additionalIncludes preserve=no
//## end module%3C50874F011A.additionalIncludes

//## begin module%3C50874F011A.includes preserve=yes
//## end module%3C50874F011A.includes

// CCompiledMesh
#include "E3D\CompiledMesh\CCompiledMesh.h"
//## begin module%3C50874F011A.additionalDeclarations preserve=yes
//## end module%3C50874F011A.additionalDeclarations


// Class CCompiledMesh 






CCompiledMesh::CCompiledMesh()
  //## begin CCompiledMesh::CCompiledMesh%.hasinit preserve=no
      : iID(-1), poBV(NULL), usNumVerts(0), usNumPrims(0), eMeshType(E3D_MESH_NONE)
  //## end CCompiledMesh::CCompiledMesh%.hasinit
  //## begin CCompiledMesh::CCompiledMesh%.initialization preserve=yes
  //## end CCompiledMesh::CCompiledMesh%.initialization
{
  //## begin CCompiledMesh::CCompiledMesh%.body preserve=yes
  //## end CCompiledMesh::CCompiledMesh%.body
}


CCompiledMesh::~CCompiledMesh()
{
  //## begin CCompiledMesh::~CCompiledMesh%.body preserve=yes
  //## end CCompiledMesh::~CCompiledMesh%.body
}



//## Other Operations (implementation)
void CCompiledMesh::poCopyBV (CGraphBV *_poBV)
{
  //## begin CCompiledMesh::poCopyBV%1011911193.body preserve=yes

	// Save current BV creation mode
	eGraphBV_TypeID eOldBVMode = CGraphBV_Manager::eGetBVMode();	
	
	// Setup source BV type
	CGraphBV_Manager::SetBVMode(_poBV->eGetTypeID());

	poBV = CGraphBV_Manager::poCreate();
	poBV->Copy(_poBV);
	
	// Restore previous BV creation mode
	CGraphBV_Manager::SetBVMode(eOldBVMode);

  //## end CCompiledMesh::poCopyBV%1011911193.body
}

// Additional Declarations
  //## begin CCompiledMesh%3C50874F011A.declarations preserve=yes
  //## end CCompiledMesh%3C50874F011A.declarations

//## begin module%3C50874F011A.epilog preserve=yes
//## end module%3C50874F011A.epilog
