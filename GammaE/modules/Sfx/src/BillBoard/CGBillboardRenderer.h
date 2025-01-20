// ----------------------------------------------------------------------------
#ifndef CGBillboardRenderer_h
#define CGBillboardRenderer_h 1
// ----------------------------------------------------------------------------
#include "GammaE_Scene.h"
// ----------------------------------------------------------------------------
class CGBillboardRenderer : public CObject3D_Leaf
{               
	public:

		/// Creates the billboard renderer and initializes it.
		CGBillboardRenderer(uint _uiMaxShaderLists,uint _uiMaxBillboards);

		/// Reset the list of billboards
		void Reset();

		/// Starts adding billboards to a the list associated to the given shaders
		void Begin(CE3D_Shader* _poShader);

		/// Adds a billboard list to the current list
		void AddBillboards(CVect3* _poVX,CVect2* _poUV,CGColor* _poVC,uint _uiNumBillboards);

		/// Ends the process of adding billboards to the current shader
		void End();

		/// Renders the current lists of billboards
		virtual void Render();

	protected:

		/// The billboard data node
		class CGBillboardNode;
		class CGBillboardNode
		{
			public:
				CVect3	m_oVX[4];
				CVect2	m_oUV[4];
				CGColor m_oVC[4];

				CGBillboardNode* m_poNext;
		};

		/// The list of billboards for a given shader
		class CGBBRListNode
		{
			public:
				/// The shader for this list
				CE3D_Shader* m_poShader;

				/// The first billboard of this list
				CGBillboardNode* m_poFirst;
		};

		/// Sorts the list of billboards by shader
		CGStArray <CGBBRListNode>	m_oBBRL;

		/// Pool of billboards
		CGStArray <CGBillboardNode> m_oBBPool;

		/// Pool of geometry
		CMesh						m_oGeoPool;

		/// Array of meshes that will store the geometry during rendering
		CGStArray <CMesh>			m_oMeshes;

		/// The current list where we are adding billboards
		uint						m_uiCurList;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
