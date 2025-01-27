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
#include "GammaE_FileSys.h"
#include "GammaE_Mem.h"
#include "GammaE_Math.h"

// CGraphBV_FileIO
#include "CGraphBV_FileIO.h"

// -----------------------------------------------------------------------------
CGGraphBV* CGraphBV_FileIO::pLoadGraphBV(CGFile& _oFile)
{
    unsigned int uiObjID;
    unsigned int uiBlockLen;

    // Read object identifier
    uiObjID = _oFile.uiRead();
    uiBlockLen = _oFile.uiRead();

    switch ( uiObjID )
    {
        case MAKE_RIFF_ID('B','S','P','H'):
        {
            CGVect3 oCenter;
            float fRadius;
            _oFile.ReadArray(oCenter.V(), 3);
            fRadius = _oFile.fRead();

            CGGraphBVSphere* pSph = mNew CGGraphBVSphere;
            pSph->Init(oCenter,fRadius);
            return (pSph);
        }
        break;

        case MAKE_RIFF_ID('B','B','O','X'):
        {
            CGVect3 oMaxs,oMins;
            _oFile.ReadArray(oMaxs.V(), 3);
            _oFile.ReadArray(oMins.V(), 3);
            _oFile.Skip(sizeof(CGVect3)*8);

            CGGraphBVAABB* pAABB = mNew CGGraphBVAABB;
            pAABB->Init(oMaxs, oMins);
            return (pAABB);
        }
        break;

        case MAKE_RIFF_ID('B','C','Y','L'):
        {
            CGVect3 oCenter;
            float fRadius;
            float fHeight;

            _oFile.ReadArray(oCenter.V(), 3);
            fHeight = _oFile.fRead();
            fRadius = _oFile.fRead();

            CGGraphBVCylinder* pCyl = mNew CGGraphBVCylinder;
            pCyl->Init(oCenter, fRadius, fHeight);
            return (pCyl);
        }
        break;
    }

    return (NULL);
}

int CGraphBV_FileIO::iSaveGraphBV (CGFile& _oFile, CGGraphBV* _pGBV)
{

    switch ( _pGBV->eGetTypeID() )
    {
        case EGBoundingVolumeType::BVT_SPHERE:
        {
            CGGraphBVSphere* pSph = (CGGraphBVSphere*)_pGBV;
            CGVect3 oCenter = pSph->oGetCenter();

            CGFileUtils::BeginRIFFBlock(MAKE_RIFF_ID('B','S','P','H'),_oFile);
                _oFile.WriteArray(oCenter.V(), 3);
                _oFile.Write(pSph->oGetSphere().fGetRadius());
            CGFileUtils::EndRIFFBlock(_oFile);
        }
        break;

        case EGBoundingVolumeType::BVT_AABB:
        {
            CGGraphBVAABB* pAABB = (CGGraphBVAABB*)_pGBV;
            CGVect3 oMaxs = pAABB->oGetMax();
            CGVect3 oMins = pAABB->oGetMin();
            const CGVect3* pVXs = pAABB->poGetPoints();

            CGFileUtils::BeginRIFFBlock(MAKE_RIFF_ID('B','B','O','X'),_oFile);
                _oFile.WriteArray(oMaxs.V(), 3);
                _oFile.WriteArray(oMins.V(), 3);
                _oFile.WriteArray((float*)pVXs, 8 * 3);
            CGFileUtils::EndRIFFBlock(_oFile);
        }
        break;

        case EGBoundingVolumeType::BVT_CYLINDER:
        {
            CGGraphBVCylinder* pCylinder = (CGGraphBVCylinder*)_pGBV;
            CGVect3 oCenter = pCylinder->oGetCenter();

            CGFileUtils::BeginRIFFBlock(MAKE_RIFF_ID('B','C','Y','L'),_oFile);
                _oFile.WriteArray(oCenter.V(), 3);
                _oFile.Write(pCylinder->GetCylinder().fGetHeight());
                _oFile.Write(pCylinder->GetCylinder().fGetRadius());
            CGFileUtils::EndRIFFBlock(_oFile);
        }
        break;
    }

    return (RES_OP_OK);
}

// Additional Declarations
