#include "CTileMap.h"

// -------------------------------------------------------------
CTileMap::CTileMap()
{
}
// -------------------------------------------------------------
CTileMap::CTileMap(uint _uiTX,uint _uiTY)
{
	Init(_uiTX,_uiTY);
}
// -------------------------------------------------------------
CTileMap::~CTileMap()
{
    DeallocateData();
}
// -------------------------------------------------------------
void CTileMap::Init(uint _uiTX,uint _uiTY)
{
    DeallocateData();

    m_uiWidth = _uiTX;
    m_uiHeight = _uiTY;

    m_pucTiles = (unsigned char *)MEMAlloc(m_uiWidth*m_uiHeight);
    m_puiFlags = (uint *)MEMAlloc(m_uiWidth*m_uiHeight*sizeof(uint));

    memset(m_pucTiles, 0, m_uiWidth*m_uiHeight);
    memset(m_puiFlags, 0, m_uiWidth*m_uiHeight*sizeof(uint));
}
// -------------------------------------------------------------
void CTileMap::DeallocateData()
{
    if (m_pucTiles != NULL)
    {
        MEMFree(m_pucTiles);
    }

    if (m_puiFlags != NULL)
    {
        MEMFree(m_puiFlags);
    }
}
// -------------------------------------------------------------
CTileMap& CTileMap::operator = (CTileMap& Src)
{
    DeallocateData();

    Init(Src.m_uiWidth,Src.m_uiHeight);

    memcpy(m_pucTiles,Src.m_pucTiles,m_uiWidth*m_uiHeight);
    memcpy(m_puiFlags,Src.m_puiFlags,m_uiWidth*m_uiHeight*sizeof(uint));

    return *this;
}
// -------------------------------------------------------------
// Set/Get tile indices
// -------------------------------------------------------------
void CTileMap::SetAt(uint _cX,uint _cY,uint _uiTexIndex)
{
    m_pucTiles[_cY*m_uiWidth + _cX] = _uiTexIndex;
}
// -------------------------------------------------------------
uint CTileMap::uiGetAt(uint _cX,uint _cY) const
{
    return ( m_pucTiles[_cY*m_uiWidth + _cX] );
}
// -------------------------------------------------------------
// Get/Set all the flags
void CTileMap::SetFlagsAt(uint _cX,uint _cY,uint _uiFlags)
{
    m_puiFlags[_cY*m_uiWidth + _cX] = _uiFlags;
}
// -------------------------------------------------------------
uint CTileMap::uiGetFlagsAt(uint _cX,uint _cY) const
{
    return( m_puiFlags[_cY*m_uiWidth + _cX] );
}

//---------------------------------------------------------------------------
// Disk functions
//---------------------------------------------------------------------------
bool CTileMap::bLoad(const CGString& _sFilename)
{
    CGFile oFD;
    int Res;

    if (_sFilename == "")
    {
        CGSystemLC::I()->Error("%s:%s %s", "TM-LD00","No TileMap filename provided.", _sFilename.szString());
        return(false);
    }

    if (!oFD.bOpen(_sFilename, EFileOpenMode::FOM_READ))
    {
        CGSystemLC::I()->Error("%s:%s %s", "TM-LD01","Unable to load file", _sFilename.szString());
        return(false);
    }

    bool bRes = bLoadWithHandler(&oFD);

    oFD.Close();
    return(bRes);
}
//---------------------------------------------------------------------------
bool CTileMap::bSave(const CGString& _sFilename) const
{
    CGFile oFD;

    if (_sFilename == "")
    {
        CGSystemLC::I()->Error("%s:%s %s", "TM-LD00", "No TileMap filename provided.", _sFilename.szString());
        return(false);
    }

    if (!oFD.bOpen(_sFilename, EFileOpenMode::FOM_WRITE))
    {
        CGSystemLC::I()->Error("%s:%s %s", "TM-SV01", "Unable to save file", _sFilename.szString());
        return(false);
    }

    bool bRes = bSaveWithHandler(&oFD);

    oFD.Close();
    return(bRes);
}
//---------------------------------------------------------------------------
bool CTileMap::bLoadWithHandler(CGFile* _poFD)
{
    // Read identifier
    unsigned long ulID = _poFD->uiRead();
    if (ulID != TILEMAP_OBJ_IDENTIFIER)
    {
        CGSystemLC::I()->Error("%s:%s", "TM-LD02","Bad TileMap object identifier");
        return(false);
    }

    // Read block lenght
    uint uiBlockLenght = _poFD->uiRead();

    // Read object version
    unsigned char ucMajorVersion = _poFD->ucRead();
    unsigned char ucMinorVersion = _poFD->ucRead();

    if ((ucMajorVersion > TILEMAP_MAJOR_VERSION) || ((ucMajorVersion == TILEMAP_MAJOR_VERSION) && (ucMinorVersion > TILEMAP_MAJOR_VERSION)) )
    {
        CGSystemLC::I()->Error("%s:%s","TM-LDH03","Incorrect TileMap version number.");
        return(false);
    }

    // Read header
    m_uiWidth = _poFD->uiRead();
    m_uiHeight = _poFD->uiRead();

    // Allocate memory
    Init(m_uiWidth,m_uiHeight);

    _poFD->uiReadData((pointer)m_pucTiles,m_uiWidth*m_uiHeight);
    _poFD->uiReadData((pointer)m_puiFlags,m_uiWidth*m_uiHeight*sizeof(uint));

    return (true);
}
//---------------------------------------------------------------------------
bool CTileMap::bSaveWithHandler(CGFile* _poFD) const
{
    unsigned long ulID = TILEMAP_OBJ_IDENTIFIER;
    unsigned char ucMajorVersion = TILEMAP_MAJOR_VERSION;
    unsigned char ucMinorVersion = TILEMAP_MINOR_VERSION;

    // Write identifier
    _poFD->Write((uint)ulID);

    // Write block length
    uint uiBlockLenght = 2 + 4 + 4 + m_uiWidth * m_uiHeight + m_uiWidth * m_uiHeight * sizeof(uint);
    _poFD->Write(uiBlockLenght);

    // Write object version
    _poFD->Write(ucMajorVersion);
    _poFD->Write(ucMinorVersion);

    // Write header
    _poFD->Write(m_uiWidth);
    _poFD->Write(m_uiHeight);

    _poFD->uiWriteData((pointer)m_pucTiles, m_uiWidth * m_uiHeight);
    _poFD->uiWriteData((pointer)m_puiFlags, m_uiWidth * m_uiHeight * sizeof(uint));

    return (true);
}
//---------------------------------------------------------------------------
uint CTileMap::uiGetWidth() const
{
    return m_uiWidth;
}
//---------------------------------------------------------------------------
uint CTileMap::uiGetHeight() const
{
    return m_uiHeight;
}
//---------------------------------------------------------------------------
