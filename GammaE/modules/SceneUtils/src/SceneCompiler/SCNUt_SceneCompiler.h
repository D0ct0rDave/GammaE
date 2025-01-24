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

class SCNUt_SceneCompiler
{
    public:
        SCNUt_SceneCompiler();

        ~SCNUt_SceneCompiler();

        CGraphBV* poCreateBoundVol ()
        {
            return( CGraphBV_Manager::poCreate() );
        }

        void CompileScene(CGSceneNode* _poScn);

        void SetNULLMaterials(bool _bNULL);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Data Members for Class Attributes

        bool bNULLMaterials;

        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class SCNUt_SceneCompiler

inline void SCNUt_SceneCompiler::SetNULLMaterials (bool _bNULL)
{
    bNULLMaterials = _bNULL;
}

#endif
