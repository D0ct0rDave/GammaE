// ----------------------------------------------------------------------------
/*! \class CGSceneTransf
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGSceneTransfH
#define CGSceneTransfH
// ----------------------------------------------------------------------------

#include "CGSceneNode.h"

// ----------------------------------------------------------------------------
class CGSceneTransf : public CGSceneNode
{
    public:

        CGSceneTransf();
        virtual ~CGSceneTransf();

        // / Sets the position for this transform node.
        void SetPos(const CGVect3& _oPos);

        // / Retrieves the position for this transform node.
        const CGVect3& oPos();

        // / Sets the direction for this transform node.
        void SetDir(const CGVect3& _oDir);

        // / Retrieves the direction for this transform node.
        const CGVect3& oDir();

        // / Sets the up vector for this transform node.
        void SetUp(const CGVect3& _oUp);

        // / Retrieves the up vector for this transform node.
        const CGVect3& oUp();

        // / Sets the side vector for this transform node.
        void SetSide(const CGVect3& _oSide);

        // / Retrieves the side vector for this transform node.
        const CGVect3& oSide();

        // / Sets up all the components for this transformation node.
        void Setup(const CGVect3& _oPos, const CGVect3& _oDir, const CGVect3& _oSide, const CGVect3& _oUp);

        // / Sets up the transformation through a matrix.
        void SetTransf(const CGMatrix4x4& _oTransf);

        // / Retrieves the transformation matrix of the object.
        const CGMatrix4x4& oTransf ()
        {
            return(m_oTransf);
        }

        // / Sets the object who will receive the transformation.
        void SetObject(CGSceneNode* _poObj);

        // / Retrieves the object who will receive the transformation.
        CGSceneNode* poGetObject();
        
        // Sets the bounding volume of the object
        void SetBV(CGGraphBV* _poBV);

        // / Returns the node bounding volume.
        virtual CGGraphBV* poGetBV();

        // General Processing Functionalities
        virtual void Accept(CGSceneVisitor* _poVisitor)
        {
            _poVisitor->Visit(this);
        }

    protected:

        void SetupTransformation();

        CGMatrix4x4 m_oTransf;

        CGVect3 m_oPos;
        CGVect3 m_oDir;
        CGVect3 m_oUp;
        CGVect3 m_oSide;

        CGSceneNode* m_poObj;
        CGGraphBV* m_poBV;
};

// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
