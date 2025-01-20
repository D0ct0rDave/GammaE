//## begin module%3C0C21B2015B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C0C21B2015B.cm

//## begin module%3C0C21B2015B.cp preserve=no
//## end module%3C0C21B2015B.cp

//## Module: MATH_Common%3C0C21B2015B; Pseudo Package body
//## Source file: i:\Projects\GammaE\Math\MATH_Other\MATH_Common.cpp

//## begin module%3C0C21B2015B.additionalIncludes preserve=no
//## end module%3C0C21B2015B.additionalIncludes

//## begin module%3C0C21B2015B.includes preserve=yes
#include <stdlib.h>
#include <math.h>
#ifdef __BORLANDC__
#define sqrtf sqrt
#endif
//## end module%3C0C21B2015B.includes

// MATH_Common
#include "Math\MATH_Other\MATH_Common.h"
//## begin module%3C0C21B2015B.additionalDeclarations preserve=yes

//---------------------------------------------------------------------------
union MATH_FastSqrtUnion
{
	float 		  d;
    unsigned long i;
};

// declare table of square roots
static bool			MATH_SqrtBuilt = false;
static unsigned int MATH_FastSqrtTable[0x10000];

void MATH_BuildSqrtTable()
{
	unsigned long		i;
    MATH_FastSqrtUnion	s;

    for (i = 1; i <= 0x7FFF; i++)
    {
	    // Build a float with the bit pattern i as mantissa
    	// and an exponent of 0, stored as 127
        s.i = (i << 8) | (0x7F << 23);
	    s.d = (float)sqrt(s.d);

    	// Take the square root then strip the first 7 bits of
	    // the mantissa into the table
	    MATH_FastSqrtTable[i + 0x8000] = (s.i & 0x7FFFFF);

	    // Repeat the process, this time with an exponent of 1,
        // stored as 128
    	s.i = (i << 8) | (0x80 << 23);
        s.d = (float)sqrt(s.d);
    	MATH_FastSqrtTable[i] = (s.i & 0x7FFFFF);
    }

    MATH_FastSqrtTable[0] = 0x1f800000;
    MATH_SqrtBuilt        = true;
}
//## end module%3C0C21B2015B.additionalDeclarations


// Class MATH_Common 

MATH_Common::MATH_Common()
  //## begin MATH_Common::MATH_Common%.hasinit preserve=no
  //## end MATH_Common::MATH_Common%.hasinit
  //## begin MATH_Common::MATH_Common%.initialization preserve=yes
  //## end MATH_Common::MATH_Common%.initialization
{
  //## begin MATH_Common::MATH_Common%.body preserve=yes
  //## end MATH_Common::MATH_Common%.body
}


MATH_Common::~MATH_Common()
{
  //## begin MATH_Common::~MATH_Common%.body preserve=yes
  //## end MATH_Common::~MATH_Common%.body
}



//## Other Operations (implementation)
float MATH_Common::fRand ()
{
  //## begin MATH_Common::fRand%1007421153.body preserve=yes
	return ((float)rand()/(float)RAND_MAX);
  //## end MATH_Common::fRand%1007421153.body
}

float MATH_Common::fSqrt (float _fValue)
{
  //## begin MATH_Common::fSqrt%1008711892.body preserve=yes
	return(sqrtf(_fValue));

	if (! MATH_SqrtBuilt) MATH_BuildSqrtTable();

	*(int*)&_fValue = MATH_FastSqrtTable[(*(int *)&_fValue >> 8) & 0xFFFF] ^ ((((*(int*)&_fValue - 0x3F800000) >> 1) + 0x3F800000) & 0x7F800000);

	return _fValue;
  //## end MATH_Common::fSqrt%1008711892.body
}

// Additional Declarations
  //## begin MATH_Common%3C0C21B2015B.declarations preserve=yes
  //## end MATH_Common%3C0C21B2015B.declarations

//## begin module%3C0C21B2015B.epilog preserve=yes
//## end module%3C0C21B2015B.epilog
