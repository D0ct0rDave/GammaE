//-----------------------------------------------------------------------------
#ifndef CDefferredMeshDB_h
#define CDefferredMeshDB_h 1
//-----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "GammaE_Math.h"
#include "Shaders/CE3D_Shader.h"
#include "E3D_Enums.h"
//-----------------------------------------------------------------------------
class CDefferredMeshEntry 
{
	public:

		/// Mesh type
		E3D_MeshType	eMeshType;

		/// The geometry itself
		void*			poMesh;

		/// Precomputed matrix for this object (Camera * Model)
		CMatrix4x4		oMatrix;

		/// Shader to render this mesh
		CE3D_Shader*	poShader;
		
		/// Number of lights (???)
		uint			uiLights;
};
//-----------------------------------------------------------------------------
class CDefferredMeshDB 
{   
	public:

		CDefferredMeshDB();

		~CDefferredMeshDB();
	
		/// Initialize the deferred object database to a maximum of elements
		void Init(uint _uiMaxEntries = 1024);
		
		/// Inserts an object in the database
		bool bInsertDefferredObject(void* _poMesh,E3D_MeshType _eMT,CE3D_Shader* _poShader,const CMatrix4x4& _oMatrix,uint _uiLights);
		
		/// Clears all the elements at a given moment of the database 
		void Invalidate ();
		
		/// Retrieves the given object in the database
		const CDefferredMeshEntry& oGetObject(uint _uiEntry);
		
		/// Retrieves the total amount of objects in the database
		uint uiNumObjects();

		/// Performs the sorting of the elements of the database
		void Sort ();

	protected:
		/// The database structure
		CGStArray<CDefferredMeshEntry> m_oMeshDB;
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------

