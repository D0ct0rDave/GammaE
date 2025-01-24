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

#include "Memory/GammaE_Mem.h"
#include <string.h>

// CCOL_CSysEntry
#include "Collision\CollisionSystem\CCOL_CSysEntry.h"

// Class CCOL_CSysEntry

CCOL_CSysEntry::CCOL_CSysEntry()
    : pbTested(NULL), iNumTests(0)
{
}

CCOL_CSysEntry::~CCOL_CSysEntry()
{
}

void CCOL_CSysEntry::Tested (int _iIdx)
{
    assert ( pbTested && "NULL Testing array");
    assert ( (_iIdx < iNumTests) && "Test index out of bounds" );
    pbTested[_iIdx] = true;
}

bool CCOL_CSysEntry::bTested (int _iIdx)
{
    assert ( pbTested && "NULL Testing array");
    assert ( (_iIdx < iNumTests) && "Test index out of bounds" );
    return(pbTested[_iIdx]);
}

void CCOL_CSysEntry::Init (int _iNumTests)
{
    iNumTests = _iNumTests;
    pbTested = mNew bool[_iNumTests];
}

void CCOL_CSysEntry::Reset ()
{
    assert ( pbTested && "NULL Testing array");
    memset( pbTested,0,iNumTests * sizeof(bool) );

    ColObj->Reset();
}

// Additional Declarations
