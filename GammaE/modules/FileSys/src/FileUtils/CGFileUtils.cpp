// ----------------------------------------------------------------------------
/*! \class CGFileUtils
 *  \brief Utility class to ease the creation of RIFF blocks on disk files.
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#include "FileUtils\CGFileUtils.h"
// ----------------------------------------------------------------------------
CGDynArray <uint> CGFileUtils::m_uiBlockLenPos;
// ----------------------------------------------------------------------------
void CGFileUtils::BeginRIFFBlock (uint _uiID, const CGFile& _oFile)
{
    // Write RIFF identifier.
    _oFile.Write( (int)_uiID );

    // Adds the current file position to the "stack".
    m_uiBlockLenPos.uiAdd( _oFile.uiPos() );

    // Write invalid RIFF Blocklenght. Later we'll correct this.
    _oFile.Write( (int)_uiID );
}
// ----------------------------------------------------------------------------
void CGFileUtils::EndRIFFBlock (const CGFile& _oFile)
{
    uint uiIdx = m_uiBlockLenPos.uiNumElems() - 1;
    uint uiBlockLenght = _oFile.uiPos() - (m_uiBlockLenPos[ uiIdx ] + 4);

    // set file position pointing to RIFF BlockLenght
    _oFile.iSeek(m_uiBlockLenPos[ uiIdx ],FSM_SET);

    // write BlockLenght
    _oFile.Write( (int)uiBlockLenght );

    // skip RIFF block data
    _oFile.iSeek(uiBlockLenght,FSM_CUR);
}
// ----------------------------------------------------------------------------
