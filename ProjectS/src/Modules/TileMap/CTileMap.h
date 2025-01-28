//---------------------------------------------------------------------------
#ifndef CTileMapH
#define CTileMapH
//---------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "GammaE.h"
//---------------------------------------------------------------------------
#define TILEMAP_MAJOR_VERSION    2
#define TILEMAP_MINOR_VERSION    0

#define TILEMAP_OBJ_IDENTIFIER   MAKE_RIFF_ID('T','M','A','P')
//---------------------------------------------------------------------------
#define TM_RFLAGS_ROTATION_MASK         0x03
#define TM_RFLAGS_NO_ROTATION           0x00
#define TM_RFLAGS_ROTATION_90           0x01
#define TM_RFLAGS_ROTATION_180          0x02
#define TM_RFLAGS_ROTATION_270          0x03
#define TM_RFLAGS_ROTATION_SHIFTBITS    0x00

#define TM_RFLAGS_TRANSITION_MASK               0xf0
#define TM_RFLAGS_TRANSITION_NO_TRANSITION      0x00
//---------------------------------------------------------------------------
class CTileMap
{
public:
        CTileMap();
        CTileMap(uint _uiWidth,uint _uiHeight);
        ~CTileMap();
        CTileMap& operator = (CTileMap& Src);

        void Init(uint _uiWidth,uint _uiHeight);

        bool bLoad(const CGString& _sFilename);          // Load the data as a single file
        bool bLoadWithHandler(CGFile* _poFD);            // Load data from an opened file
        
        bool bSave(const CGString& _s) const;            // Save the data as a single file
        bool bSaveWithHandler(CGFile* _poFD) const;      // Save data to an opened file

    	// Get/Set tile indexes
        void SetAt(uint _cX,uint _cY,uint _uiTexIndex);
        uint uiGetAt(uint _cX,uint _cY) const;

        // Get/Set flags
        void SetFlagsAt(uint _cX,uint _cY,uint _uiFlags);
        uint uiGetFlagsAt(uint _cX,uint _cY) const;

        uint uiGetWidth() const;
        uint uiGetHeight() const;

private:

        void DeallocateData();

        uint m_uiWidth;
        uint m_uiHeight;

        unsigned char *m_pucTiles;
        uint  *m_puiFlags;
};
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
