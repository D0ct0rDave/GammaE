// ----------------------------------------------------------------------------
#ifndef SCNUt_MeshCompacter_h
#define SCNUt_MeshCompacter_h 1
// ----------------------------------------------------------------------------

// GammaE_E3D
#include "GammaE_E3D.h"
// SCNUt_TriScene
#include "SCNUt_TriScene.h"
// ----------------------------------------------------------------------------
typedef struct{
	uint m_uiTri;
	uint m_uiVX;
}TVertexRef;

class CCompactMeshData
{
	public:
		
		CMesh*				m_poMesh;
		
		// Inverse table
		CGDynArray<TVertexRef>	m_oInvTable;	
};
// ----------------------------------------------------------------------------
//	Toma una escena con n triángulos y 3*n vertices, y
//	genera una malla de m <=3*n vertices.
class SCNUt_MeshCompacter 
{
	public:

		SCNUt_MeshCompacter();
		~SCNUt_MeshCompacter();

		CMesh* poCompactMesh(const SCNUt_TriScene& _oScene);
		void CompactMesh(const SCNUt_TriScene& _oScene,CCompactMeshData* _poData);

	protected:

		uint uiInsertVertex(CMesh *Mesh, CVect3 &VX, CVect2& UV, CVect4 &VC, CVect3 &VN);
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------