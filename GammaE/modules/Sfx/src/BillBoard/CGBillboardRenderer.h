// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
#ifndef CGBillboardRenderer_h
#define CGBillboardRenderer_h 1
// ----------------------------------------------------------------------------
#include "GammaE_Scene.h"
// ----------------------------------------------------------------------------
class CGBillboardRenderer : public CGSceneLeaf
{
    public:

        // / Creates the billboard renderer and initializes it.
        CGBillboardRenderer(uint _uiMaxShaderLists,uint _uiMaxBillboards);

        // / Reset the list of billboards
        void Reset();

        // / Starts adding billboards to a the list associated to the given shaders
        void Begin(CGShader* _poShader);

        // / Adds a billboard list to the current list
        void AddBillboards(CGVect3* _poVX,CGVect2* _poUV,CGColor* _poVC,uint _uiNumBillboards);

        // / Ends the process of adding billboards to the current shader
        void End();

        // / Renders the current lists of billboards
        virtual void Render();

    protected:

        // / The billboard data node
        class CGBillboardNode;
        class CGBillboardNode
        {
            public:
                CGVect3 m_oVX[4];
                CGVect2 m_oUV[4];
                CGColor m_oVC[4];

                CGBillboardNode* m_poNext;
        };

        // / The list of billboards for a given shader
        class CGBBRListNode
        {
            public:
                // / The shader for this list
                CGShader* m_poShader;

                // / The first billboard of this list
                CGBillboardNode* m_poFirst;
        };

        // / Sorts the list of billboards by shader
        CGStArray <CGBBRListNode> m_oBBRL;

        // / Pool of billboards
        CGStArray <CGBillboardNode> m_oBBPool;

        // / Pool of geometry
        CGMesh m_oGeoPool;

        // / Array of meshes that will store the geometry during rendering
        CGStArray<CGUnmanagedMesh> m_oMeshes;

        // / The current list where we are adding billboards
        uint m_uiCurList;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
