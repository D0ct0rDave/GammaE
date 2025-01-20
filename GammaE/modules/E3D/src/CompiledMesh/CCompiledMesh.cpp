




// CCompiledMesh
#include "CompiledMesh\CCompiledMesh.h"


// Class CCompiledMesh 






CCompiledMesh::CCompiledMesh()
        : iID(-1), poBV(NULL), usNumVerts(0), usNumPrims(0), eMeshType(E3D_MESH_NONE)
      {
}


CCompiledMesh::~CCompiledMesh()
{
}



void CCompiledMesh::poCopyBV (CGraphBV *_poBV)
{
  
	// Save current BV creation mode
	eGraphBV_TypeID eOldBVMode = CGraphBV_Manager::eGetBVMode();	
	
	// Setup source BV type
	CGraphBV_Manager::SetBVMode(_poBV->eGetTypeID());

	poBV = CGraphBV_Manager::poCreate();
	poBV->Copy(_poBV);
	
	// Restore previous BV creation mode
	CGraphBV_Manager::SetBVMode(eOldBVMode);

}

// Additional Declarations
    
