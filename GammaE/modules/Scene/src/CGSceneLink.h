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

#ifndef CGSceneLink_h
#define CGSceneLink_h 1

// CGSceneWarehouse
#include "Scene\CGSceneWarehouse.h"
// CGSceneGen
#include "Scene\CGSceneGen.h"

// Util para tener referencias a objetos en el mundo, o en
// un fichero. Las referencias son a objetos almacenados en
// la Warehouse de los objetos.

class CGSceneLink : public CGSceneGen
{
    public:
        CGSceneLink();

        virtual ~CGSceneLink();

        void Link(int _iObjWHIdx, CGSceneWarehouse* _pObjWH);

        void Unlink();

        virtual CGraphBV* poGetBoundVol();

        virtual void ComputeBoundVol();

        virtual void Render();

        // Additional Public Declarations

    protected:
        // Data Members for Class Attributes

        int iObjWHIdx;

        CGSceneWarehouse* pObjWH;

        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:   // Additional Implementation Declarations
};

// Class CGSceneLink

#endif
