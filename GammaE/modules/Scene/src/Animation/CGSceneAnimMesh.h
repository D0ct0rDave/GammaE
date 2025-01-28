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
// --------------------------------------------------------------------------------
#include "CGSceneLeaf.h"

// CGSceneAnimGen
#include "Animation\CGSceneAnimNode.h"
// --------------------------------------------------------------------------------
class CGSceneAnimMesh : public CGSceneAnimNode
{
    public:
        CGSceneAnimMesh();
        virtual ~CGSceneAnimMesh();

        // / Sets up the data inside the animated object
        void Setup(CGMesh* _poStartupMesh, uint _uiNumStates, uint _uiNumVerticesPerState);

        // Sets the animation between 2 states (frames) interpolated by a factor.
        virtual void SetAnimState(uint _uiSrc, uint _uiDst, float _fFactor);

        // Return the number of states this object has
        virtual uint uiGetNumStates() const;

        // / Recompute the bounding volume of all the frames
        virtual void ComputeStatesBVols();

        // Return the bounding volume of the object for the given state
        virtual CGGraphBV* poGetStateBVol(int _iState);

        // / Returns the number of vertices per frame
        uint uiGetNumFrameVXs();

        // / Retrieves the startup frame
        CGMesh* poGetMesh();

        // / Retrieves the array of vertices
        CGVect3* poGetVertices();

        // / Retrieves the array where the normals are stored
        CGVect3* poGetNormals();
        
        // / Sets the shader to be used by this leaf node.
        void SetShader(CGShader* _poShader);

        // / Retrieves the shader used by this leaf node.
        CGShader* poGetShader();    

        // / Returns the node bounding volume.
        virtual CGGraphBV* poGetBV();

        // General Processing Functionalities
        virtual void Accept(CGSceneVisitor* _poVisitor)
        {
            _poVisitor->Visit(this);
        }

    protected:

        CGVect3* m_poFrameVXs;
        CGVect3* m_poFrameVNs;

        CGMesh* m_poMesh;
        CGShader* m_poShader;

        uint m_uiNumStates;
        uint m_uiNumVerticesPerState;

        CGStArray<CGGraphBV*> m_poStateBVs;
};
// --------------------------------------------------------------------------------
#endif
// --------------------------------------------------------------------------------
