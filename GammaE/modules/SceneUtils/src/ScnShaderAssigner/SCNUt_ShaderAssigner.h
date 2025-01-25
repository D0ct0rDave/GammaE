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

#ifndef SCNUt_ShaderAssigner_h
#define SCNUt_ShaderAssigner_h 1

#include "GammaE_Scene.h"

// CGSceneNode

class SCNUt_ShaderAssigner
{
    public:
        SCNUt_ShaderAssigner();

        ~SCNUt_ShaderAssigner();

        void AssignShader(CGShader* _poShader, CGSceneNode* _poObj);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class SCNUt_ShaderAssigner

#endif
