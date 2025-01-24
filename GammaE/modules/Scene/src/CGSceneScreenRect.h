// ----------------------------------------------------------------------------
/*! \class CGSceneScreenRect
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGSceneScreenRectH
#define CGSceneScreenRectH
// ----------------------------------------------------------------------------
#include "CGSceneNode.h"
// ----------------------------------------------------------------------------
class CGSceneScreenRect : public CGSceneNode
{
    public:
        CGSceneScreenRect();
        virtual ~CGSceneScreenRect();

        // / Sets the screen rectangle represented by this object.
        virtual void SetRect(float _fX,float _fY,float _fTX,float _fTY);

        // / Sets the shader used by the object.
        virtual void SetShader(CGShader* _poShader)
        {
            m_poShader = _poShader;
        }

        // / Retrieves the shader used by the object.
        CGShader* poGetShader()
        {
            return (m_poShader);
        }

        // General Processing Functionalities.
        virtual void Accept(CGSceneVisitor* _poVisitor)
        {
            _poVisitor->Visit(this);
        }

        // / Retrieves the matrix associated to the current node.
        const CGMatrix4x4& oGetMatrix()
        {
            return(m_oMat);
        }

        // / Retrieves the mesh associated to the object.
        CGBaseMesh* poGetMesh()
        {
            return(m_poMesh);
        }

    protected:

        CGBaseMesh* m_poMesh;
        CGShader* m_poShader;
        CGMatrix4x4 m_oMat;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
