// ----------------------------------------------------------------------------
/*! \class CGSceneNode
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGSceneNodeH
#define CGSceneNodeH
// ----------------------------------------------------------------------------
#include "GammaE_E3D.h"
#include "GammaE_Misc.h"
#include "GSceneEnums.h"
#include "Visitors/CGSceneVisitor.h"
// ----------------------------------------------------------------------------
class CGSceneNode : public CGReferenceCounter
{
    public:

        CGSceneNode();
        virtual ~CGSceneNode();

        // / Generic function to perform processing functionalities.
        virtual void Accept(CGSceneVisitor* _poVisitor) = 0;

        // / Dereferences the current node and frees resources if no more references are active.
        virtual void Deref();

        // / Returns the node bounding volume.
        CGGraphBV* poGetBV()
        {
            return (m_poBV);
        }

        // / Sets the node bounding volume. 
        void SetBV(CGGraphBV* _poBV)
        {
            m_poBV = _poBV;
        }

        // / Returns the node type.
        ESceneNodeType eGetNodeType()
        {
            return(m_eNodeType);
        }

        // Returns whether the object is currently visible or not
        virtual bool bIsVisible();

    protected:

        CGGraphBV* m_poBV;
        ESceneNodeType m_eNodeType;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
