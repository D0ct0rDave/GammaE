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

#ifndef SCNUt_TriSceneSaver_h
#define SCNUt_TriSceneSaver_h 1

// SCNUt_TriScene
#include "SCNUt_TriScene.h"
#include "SCNUt_MaterialTable.h"

class SCNUt_TriSceneSaver
{
    public:
        SCNUt_TriSceneSaver();

        ~SCNUt_TriSceneSaver();

        void Save(char* _szFilename,SCNUt_TriScene* _poScn,SCNUt_MaterialTable* _poMT);

        // Data Members for Class Attributes

        char* * pszMaterials;

        int iNumMaterials;

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class SCNUt_TriSceneSaver

#endif
