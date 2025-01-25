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

#ifndef CGraphBV_Manager_h
#define CGraphBV_Manager_h 1

// CGBoundingVolume
#include "BoundingVolume\GraphBoundVol\CGBoundingVolume.h"
// eGraphBV_TypeID
#include "BoundingVolume\GraphBoundVol\eGraphBV_TypeID.h"

class CGraphBV_Manager
{
    public:
        CGraphBV_Manager();

        ~CGraphBV_Manager();

        static CGBoundingVolume* poCreate();

        static void SetBVMode(eGraphBV_TypeID _eMode);

        static eGraphBV_TypeID eGetBVMode();

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Data Members for Class Attributes

        static eGraphBV_TypeID eCreationMode;

        // Additional Private Declarations

    private:   // Additional Implementation Declarations
};

// Class CGraphBV_Manager

inline void CGraphBV_Manager::SetBVMode (eGraphBV_TypeID _eMode)
{
    eCreationMode = _eMode;
}

inline eGraphBV_TypeID CGraphBV_Manager::eGetBVMode ()
{
    return (eCreationMode);
}

#endif
