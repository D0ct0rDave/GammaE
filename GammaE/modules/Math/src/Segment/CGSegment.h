// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGSegmentH
#define CGSegmentH
// ----------------------------------------------------------------------------
#include "..\Vector\CGVect3.h"
// ----------------------------------------------------------------------------
class CGSegment
{
    public:

        void Init(CGVect3& _oIni, CGVect3& _oEnd);

        CGVect3 ProjectPoint(CGVect3& _oPoint);

    protected:

        CGVect3 oIni;
        CGVect3 oEnd;
};
// ----------------------------------------------------------------------------
inline void CGSegment::Init (CGVect3& _oIni, CGVect3& _oEnd)
{
    oIni.Assign(_oIni);
    oEnd.Assign(_oEnd);
}
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
