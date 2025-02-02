// ----------------------------------------------------------------------------
/*! \class CGSceneVisitor
 *  \brief Base class to provide visitor functionality over a scene graph.
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGSceneVisitorH
#define CGSceneVisitorH
// ---------------------------------------------------------------------
// Every time a new object is created, which has new configurable properties
// (not runtime variables) the author should place the respective visit method here
// ---------------------------------------------------------------------

// Classes to visit
class CGSceneNode;
class CGSceneBSPNode;
class CGSceneCamera;
class CGSceneInstance;
class CGSceneLeaf;
class CGSceneMux;
class CGSceneGroup;
class CGSceneScreenRect;
class CGSceneSwitch;
class CGSceneTransf;
class CGSceneAnimNode;
class CGSceneAnimMesh;
class CGSceneAnimGroup;
class CGSceneAnimTransf;
class CGSceneAnimActionSet;

// ---------------------------------------------------------------------
class CGSceneVisitor
{
    public:

        virtual void Visit(CGSceneNode* _poNode) = 0;

        virtual void Visit(CGSceneBSPNode* _poNode) = 0;

        virtual void Visit(CGSceneCamera* _poNode) = 0;

        virtual void Visit(CGSceneInstance* _poNode) = 0;

        virtual void Visit(CGSceneLeaf* _poNode) = 0;

        virtual void Visit(CGSceneMux* _poNode) = 0;

        virtual void Visit(CGSceneGroup* _poNode) = 0;

        virtual void Visit(CGSceneScreenRect* _poNode) = 0;

        virtual void Visit(CGSceneSwitch* _poNode) = 0;

        virtual void Visit(CGSceneTransf* _poNode) = 0;

        virtual void Visit(CGSceneAnimNode* _poNode) = 0;

        virtual void Visit(CGSceneAnimMesh* _poNode) = 0;

        virtual void Visit(CGSceneAnimGroup* _poNode) = 0;

        virtual void Visit(CGSceneAnimTransf* _poNode) = 0;

        virtual void Visit(CGSceneAnimActionSet* _poNode) = 0;
};
// ---------------------------------------------------------------------
#endif
// ---------------------------------------------------------------------
