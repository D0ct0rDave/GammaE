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
    CGFile oFile;
    CGControlPoint oCP;

    if ( !oFile.bOpen( (char*)_sFilename.szString(), EFileOpenMode::FOM_READ) ) return(NULL);

    // Stablish alternate texture path
    CGString sDir = Utils::ExtractFileDir(_sFilename);
    CGMipMapWH::I()->AlternatePath( sDir );

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

        oFile.iSeek( - 8, EFileSeekMode::FSM_CUR);
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
            oFile.ReadArray(szStr, 8);
            oCP.m_sName = CGString(szStr);

            oFile.ReadArray((float*)oCP.m_oPos.V(),3 );

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
        poBObj->SetModel( oLoader.poLoad(oFile) );
        poBObj->poGetModel()->Ref();                    // Avoid being deleted by an instance

        CGSCNVBoundVolBuilder::I()->Visit(poBObj->poGetModel());
    }
    else
        poBObj->SetModel(NULL);

    oFile.Close();

    // Restore alternate path to default
    CGMipMapWH::I()->AlternatePath( "" );

    return(poBObj);
}
// ----------------------------------------------------------------------------
