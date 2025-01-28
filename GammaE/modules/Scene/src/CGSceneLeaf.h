// ----------------------------------------------------------------------------
/*! \class CGSceneLeaf
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGSceneLeafH
#define CGSceneLeafH
// ----------------------------------------------------------------------------
#include "CGSceneNode.h"
// ----------------------------------------------------------------------------
class CGSceneLeaf : public CGSceneNode
{
    public:
        CGSceneLeaf();

        virtual ~CGSceneLeaf();

        // / Deletes the information stored in the leaf node.
        virtual void Clear();

        // / Sets the mesh for this specific leaf node.
        void SetMesh(CGBaseMesh* _poMesh)
        {
            m_poMesh = _poMesh;
        }

        // / Retrieves the mesh associated to this leaf node.
        CGBaseMesh* poGetMesh()
        {
            return(m_poMesh);
        }

        // / Sets the shader to be used by this leaf node.
        void SetShader(CGShader* _poShader)
        {
            m_poShader = _poShader;
        }

        // / Retrieves the shader used by this leaf node.
        CGShader* poGetShader()
        {
            return(m_poShader);
        }

        // / Returns the node bounding volume.
        virtual CGGraphBV* poGetBV()
        {
            return(m_poMesh->poGetBV());
        }

        // / General Processing Functionalities
        virtual void Accept(CGSceneVisitor* _poVisitor)
        {
            _poVisitor->Visit(this);
        }

    private:

        CGBaseMesh* m_poMesh;
        CGShader* m_poShader;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
