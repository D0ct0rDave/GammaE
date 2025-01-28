//---------------------------------------------------------------------------
#ifndef TexMapH
#define TexMapH
//---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//---------------------------------------------------------------------------
#define     TEXMAP_MAJOR_VERSION    2
#define     TEXMAP_MINOR_VERSION    0

#define     TEXMAP_OBJ_IDENTIFIER   MAKE_RIFF_ID('T','M','A','P')
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
class TTexMap
{
public:
        TTexMap         ();
        TTexMap         (unsigned int _uiTX,unsigned int _uiTY);
        ~TTexMap        ();
        TTexMap& operator = (TTexMap& Src);

        void    Init       (unsigned int _uiTX,unsigned int _uiTY);


        int Load                (char *Filename);           // Load the data as a single file
        int Save                (char *Filename);           // Save the data as a single file
    	int SaveWithHandler     (FILE *fd);                 // Save data to an opened file
	    int LoadWithHandler     (FILE *fd);                 // Load data from an opened file


    	// Get/Set tile indexes
        void            SetAt  (unsigned int _cX,unsigned int _cY,unsigned int _uiTexIndex);
        unsigned int    uiGetAt(unsigned int _cX,unsigned int _cY);

        // Get/Set flags
        void            SetFlagsAt     (unsigned int _cX,unsigned int _cY,unsigned int _uiFlags);
        unsigned int    uiGetFlagsAt   (unsigned int _cX,unsigned int _cY);

    	unsigned int  uiTX;	        // Width
	    unsigned int  uiTY;	        // Heigth

private:

        void DeallocateData();
        bool Initialized;


        unsigned char *pucTiles;
        unsigned int  *puiFlags;
};
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
