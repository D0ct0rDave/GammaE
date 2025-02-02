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

#ifndef CSkyDome_h
#define CSkyDome_h 1

// CGSceneLeaf
#include "GammaE_Scene.h"

class CSkyDome : public CGSceneLeaf
{
    public:
        CSkyDome();

        virtual ~CSkyDome();

        void SetRotation(float _fRot);

        void SetRadius(float _fRadius);

        void SetAxis(CGVect3 _Axis);

        void SetPosition(CGVect3 _Pos);

        void CreateDome(bool _bFogAffected, int _iNumVSlices, int _iNumHSlices, int _iStartVSlice, int _iEndVSlice, float _fUTiling, float _fVTiling);

        virtual void Render();

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Data Members for Class Attributes

        float fRadius;

        float fRot;

        CGVect3 Axis;

        CGVect3 Pos;

        bool FogAffected;

        // Additional Private Declarations
        CGMesh* m_poSkyDomeMesh;
    private:                    // Additional Implementation Declarations
};

// Class CSkyDome

#endif
