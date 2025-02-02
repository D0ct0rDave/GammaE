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

#ifndef SCNUt_TriSceneAccumulator_h
#define SCNUt_TriSceneAccumulator_h 1

// SCNUt_TriScene
#include "SCNUt_TriScene.h"

class SCNUt_TriSceneAccumulator : public SCNUt_TriScene
{
    public:
        SCNUt_TriSceneAccumulator();

        ~SCNUt_TriSceneAccumulator();

        void AddTriScene(SCNUt_TriScene* _poScn);

        virtual void Init(int _iNumTris);

        virtual void Init(int _iNumTris, int _iRealloc);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Data Members for Class Attributes

        int iMaxTris;

        int iRealloc;

        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class SCNUt_TriSceneAccumulator

#endif
