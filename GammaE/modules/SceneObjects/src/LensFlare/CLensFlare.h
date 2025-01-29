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

#ifndef CLensFlare_h
#define CLensFlare_h 1

// CLensFlare_Elem
#include "LensFlare\CLensFlare_Elem.h"
// CGSceneNode
#include "GammaE_Scene.h"

class CLensFlare : public CGSceneNode
{
    public:
        CLensFlare();

        virtual ~CLensFlare();

        void InitLensFlare(int _iNumElems, CGVect3 _SunPos);

        void SetupFlareElem(int _iElem, float _fSize, float _fDist, CGColor _Color, CGShader* _pMat);

        void UpdateMesh();

        virtual void Render();

        virtual CGGraphBV* poGetBV();

        bool bVisible();

        void UpdateState();

        // / Generic function to perform processing functionalities.
        virtual void Accept(CGSceneVisitor* _poVisitor);

    private:
        // Data Members for Class Attributes

        CLensFlare_Elem* FlareElems;

        int iNumElems;

        CGMeshRect* MeshArray;

        int iLensFlareState;

        float fVisFact;

        CGVect3 oPrjSun;

        CGVect3 oSunPos;

        CGVect3 oScrPos;

        CGMatrix4x4 oViewMat;

        CGMatrix4x4 oPrjMat;
};

// Class CLensFlare

#endif
