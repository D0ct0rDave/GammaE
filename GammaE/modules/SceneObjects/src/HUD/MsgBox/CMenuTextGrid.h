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
#ifndef CMenuTextGridH
#define CMenuTextGridH

#include "GammaE_E3D.h"

class CMenuTextGrid : public CGMesh
{
    public:
        CMenuTextGrid();

        void Init(int _iCols,int _iMaxRows);
        void Reset();
        void WriteText(char* _szText,CGColor _oColor,float _fAlpha);

    protected:
        void WriteChar(float _fX,float _fY, CGColor _oColor,char _cA);
        void WriteXY(float _fXOfs, float _fYOfs, CGColor _oColor,char* _szText);

        int iCols;
        int iMaxRows;
        int iCurRow;
};

#endif
