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
// %X% %Q% %Z% %W%

#ifndef SCNUt_SceneCompiler_h
#define SCNUt_SceneCompiler_h 1

// CGSceneNode
#include "GammaE_Scene.h"
#include "GammaE_E3D.h"

class SCNUt_SceneCompiler
{
    public:
        SCNUt_SceneCompiler();

        ~SCNUt_SceneCompiler();

        CGGraphBV* poCreateBoundVol ()
        {
            return( CGGraphBVFactory::poCreate() );
        }

        void CompileScene(CGSceneNode* _poScn);

    private:
        // Data Members for Class Attributes
        void CompileMeshInLeaf(CGSceneLeaf* _poLeaf);
};

#endif
