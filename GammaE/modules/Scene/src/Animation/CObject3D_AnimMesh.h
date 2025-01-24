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
#ifndef CGSceneAnimMeshH
#define CGSceneAnimMeshH
// --------------------------------------------------------------------------------CGSceneLeaf
#include "CGSceneLeaf.h"

// CGSceneAnimGen
#include "Animation\CGSceneAnimObject.h"
// --------------------------------------------------------------------------------
class CGSceneAnimMesh : public CGSceneAnimObject
{
    public:
        CGSceneAnimMesh();
        virtual ~CGSceneAnimMesh();

        // / Sets up the data inside the animated object
        void Setup(CGMesh* _poStartupMesh,CGVect3* _poVXs,CGVect3* _poVNs)
        {
            m_poMesh = _poStartupMesh;
            m_poFrameVXs = _poVXs;
            m_poFrameVNs = _poVNs;
        }

        // / Recompute the bounding volume of all the frames
        virtual void ComputeBoundVols()
        {
            assert(false && "Not implemented!!");
        }

        // / Returns the number of vertices per frame
        uint uiGetNumFrameVXs()
        {
            return (m_poMesh->m_usNumVXs);
        }

        // / Retrieves the startup frame
        CGMesh* poGetMesh()
        {
            return(m_poMesh);
        }

        // / Retrieves the array of vertices
        CGVect3* poGetVertexs()
        {
            return (m_poFrameVXs);
        }

        // / Retrieves the array where the normals are stored
        CGVect3* poGetNormals()
        {
            return (m_poFrameVNs);
        }

        // General Processing Functionalities
        virtual void Accept(CGSceneVisitor* _poVisitor)
        {
            _poVisitor->Visit(this);
        }

    protected:

        CGVect3* m_poFrameVXs;
        CGVect3* m_poFrameVNs;

        CGMesh* m_poMesh;
};
// --------------------------------------------------------------------------------
#endif
// --------------------------------------------------------------------------------
