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

#ifndef CGSceneCompiledLeafH
#define CGSceneCompiledLeafH

// CGSceneNode
#include "CGSceneNode.h"

class CGSceneCompiledLeaf : public CGSceneNode
{
    public:
        CGSceneCompiledLeaf();

        /// Constructor with initialization parameters
        CGSceneCompiledLeaf(CGCompiledMesh* _poCMesh,CGShader* _poShader);

        /// Initializes the node
        void Init(CGCompiledMesh* _poCMesh, CGShader* _poShader)
        {
            m_poCMesh = _poCMesh;
            m_poShader = _poShader;
        }

        /// Retrieves the compiled mesh associated to this node
        void SetCMesh(CGCompiledMesh* _poCMesh)
        {
            m_poCMesh = _poCMesh;
        }

        /// Retrieves the compiled mesh for this node
        CGCompiledMesh* poGetCMesh()
        {
            return(m_poCMesh);
        }

        /// Sets the shader for this node
        void SetShader(CGShader* _poShader)
        {
            m_poShader = _poShader;
        }

        /// Retrieves the shader associated to this node
        CGShader* poGetShader()
        {
            return(m_poShader);
        }

        // General Processing Functionalities
        virtual void Accept(CGSceneVisitor* _poVisitor)
        {
            _poVisitor->Visit(this);
        }

    protected:

        CGCompiledMesh* m_poCMesh;
        CGShader* m_poShader;
};



#endif
