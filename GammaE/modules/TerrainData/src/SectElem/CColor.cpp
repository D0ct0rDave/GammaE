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
#include "GammaE_Mem.h"

// CColor
#include "SectElem\CColor.h"
float C_fCosFactor;

// Class CColor

CColor::CColor()
{
}

CColor::~CColor()
{
}

unsigned long CColor::ByteSize ()
{
    return ( 4 * sizeof(float) );
}

CSectElem & CColor::Sum (CSectElem &a, CSectElem &b)
{
    Value[0] = ( (float*)a.Get() )[0] + ( (float*)b.Get() )[0];
    Value[1] = ( (float*)a.Get() )[1] + ( (float*)b.Get() )[1];
    Value[2] = ( (float*)a.Get() )[2] + ( (float*)b.Get() )[2];
    Value[3] = ( (float*)a.Get() )[3] + ( (float*)b.Get() )[3];

    return (*this);
}

CSectElem & CColor::Mult (CSectElem &a, CSectElem &b)
{
    Value[0] = ( (float*)a.Get() )[0] * ( (float*)b.Get() )[0];
    Value[1] = ( (float*)a.Get() )[1] * ( (float*)b.Get() )[1];
    Value[2] = ( (float*)a.Get() )[2] * ( (float*)b.Get() )[2];
    Value[3] = ( (float*)a.Get() )[3] * ( (float*)b.Get() )[3];

    return (*this);
}

CSectElem & CColor::LinInterpolate (CSectElem &a, CSectElem &b, float fFactor)
{
    // Res = a*(1-f) + b*f = a - af + bf = a + (b-a)*f

    Value[0] = ( (float*)a.Get() )[0] + ( ( (float*)b.Get() )[0] - ( (float*)a.Get() )[0] ) * fFactor;
    Value[1] = ( (float*)a.Get() )[1] + ( ( (float*)b.Get() )[1] - ( (float*)a.Get() )[1] ) * fFactor;
    Value[2] = ( (float*)a.Get() )[2] + ( ( (float*)b.Get() )[2] - ( (float*)a.Get() )[2] ) * fFactor;
    Value[3] = ( (float*)a.Get() )[3] + ( ( (float*)b.Get() )[3] - ( (float*)a.Get() )[3] ) * fFactor;

    return (*this);
}

CSectElem & CColor::CosInterpolate (CSectElem &a, CSectElem &b, float fFactor)
{
    // Res = a*( 1 - cos((1-f)*PI/2) ) + b * cos((1-f)*PI/2)
    // Res = a*( cos(f*PI/2) ) + b (1 - cos(f* PI/2);
    // Res = b  + (a -b)*cos(f*PI/2);

    C_fCosFactor = (float)cos(fFactor * _PI2_);

    Value[0] = ( (float*)b.Get() )[0] + ( ( (float*)a.Get() )[0] - ( (float*)b.Get() )[0] ) * C_fCosFactor;
    Value[1] = ( (float*)b.Get() )[1] + ( ( (float*)a.Get() )[1] - ( (float*)b.Get() )[1] ) * C_fCosFactor;
    Value[2] = ( (float*)b.Get() )[2] + ( ( (float*)a.Get() )[2] - ( (float*)b.Get() )[2] ) * C_fCosFactor;
    Value[3] = ( (float*)b.Get() )[3] + ( ( (float*)a.Get() )[3] - ( (float*)b.Get() )[3] ) * C_fCosFactor;

    return (*this);
}

CSectElem* CColor::CreateClass ()
{
    return ( mNew CColor() );
}

CSectElem & CColor::Clear ()
{
    Value[0] = 0;
    Value[1] = 0;
    Value[2] = 0;
    Value[3] = 0;

    return (*this);
}

CSectElem & CColor::Add (CSectElem &a)
{
    Value[0] += ( (float*)a.Get() )[0];
    Value[1] += ( (float*)a.Get() )[1];
    Value[2] += ( (float*)a.Get() )[2];
    Value[3] += ( (float*)a.Get() )[3];

    return (*this);
}

CSectElem & CColor::Mult (CSectElem &a)
{
    Value[0] *= ( (float*)a.Get() )[0];
    Value[1] *= ( (float*)a.Get() )[1];
    Value[2] *= ( (float*)a.Get() )[2];
    Value[3] *= ( (float*)a.Get() )[3];

    return (*this);
}

CSectElem & CColor::Scale (float a)
{
    Value[0] *= a;
    Value[1] *= a;
    Value[2] *= a;
    Value[3] *= a;

    return (*this);
}

// Additional Declarations
