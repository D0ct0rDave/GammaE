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
#include "CGGraphicResourceWH.h"
// ----------------------------------------------------------------------------
CGGraphicResource* CGGraphicResourceWH::poLoadResource(const CGString& _sFilename)
{
    CGGraphicResource* poBObj;
    CFile oFile;
    CGControlPoint oCP;

    if ( !oFile.bOpen( (char*)_sFilename.szString(),"rb" ) ) return(NULL);

    // Stablish alternate texture path
    CGString sDir = ExtractFileDir(_sFilename);
    CMipMapWH::I()->AlternatePath( sDir );

    //
    unsigned int uiID;
    unsigned int uiBlockSize;
    unsigned int uiNumCPs;

    uiID = oFile.iRead();
    uiBlockSize = oFile.iRead();

    if ( uiID != MAKE_RIFF_ID('B','O','B','J') )
    {
        if ( uiID != GEM_FILE_IDENTIFIER ) return(NULL);

        // Create an Extended 3D Object
        poBObj = mNew CGGraphicResource;
        poBObj->m_oCPs.Clear();

        oFile.uiSeek(-8,eFile_SM_Cur);
    }
    else
    {
        // Create orion obj
        poBObj = mNew CGGraphicResource;
        poBObj->m_oCPs.Clear();

        // Load number of control points
        uiNumCPs = oFile.iRead();

        // Load the control points
        for ( int i = 0; i < uiNumCPs; i++ )
        {
            char szStr[9];
            oFile.ReadCharArray (szStr,8);
            oCP.m_sName = CGString(szStr);

            oFile.ReadFloatArray( (float*)oCP.m_oPos.V(),3 );

            // Add the control point to the list
            poBObj->m_oCPs.uiAdd(oCP);
        }
    }

    // Read the model
    CLoaderGEM oLoader;
    uiID = oFile.iRead();
    uiBlockSize = oFile.iRead();

    if ( uiID == GEM_FILE_IDENTIFIER )
    {
        poBObj->Model( oLoader.poLoad(oFile) );
        poBObj->poModel()->Ref();                    // Avoid being deleted by an instance
        poBObj->poModel()->ComputeBoundVol();
    }
    else
        poBObj->Model(NULL);

    oFile.Close();

    // Restore alternate path to default
    CMipMapWH::I()->AlternatePath( "" );

    return(poBObj);
}
// ----------------------------------------------------------------------------
