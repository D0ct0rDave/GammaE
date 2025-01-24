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

#ifndef CE3D_ShWH_Entry_h
#define CE3D_ShWH_Entry_h 1

// CE3D_Shader
#include "E3D\Shaders\CE3D_Shader.h"

class CE3D_ShWH_Entry
{
    public:
        CE3D_ShWH_Entry();

        ~CE3D_ShWH_Entry();

        // Data Members for Class Attributes

        bool bValid;

        CE3D_Shader* poShader;

        char szName[256];

        int iId;

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:   // Additional Implementation Declarations
};

// Class CE3D_ShWH_Entry

#endif
