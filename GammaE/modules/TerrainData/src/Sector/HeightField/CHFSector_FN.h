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

#ifndef CHFSector_FN_h
#define CHFSector_FN_h 1

// CHFSector
#include "Sector\CHFSector.h"

class CHFSector_FN : public CHFSector
{
    public:
        CHFSector_FN();

        virtual ~CHFSector_FN();

        virtual CSectElem & GetValue(int _X, int _Y);

        virtual void SetValue(int _X, int _Y, CSectElem &_Value);

        virtual CSector* CreateClass();

        virtual unsigned long ElemArraySize(int _iResolution);

        // Gets the raw data of a given LOD
        virtual void GetLODData(int _iLOD, void* _pData);

        virtual CSectElem & GetValueF(float _fX, float _fY);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class CHFSector_FN

#endif
