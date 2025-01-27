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
#include "GammaE_Misc.h"
#include "GammaE_Scene.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// SCNUt_TriSceneSaver
#include "TriScnSaver\SCNUt_TriSceneSaver.h"

// Class SCNUt_TriSceneSaver

SCNUt_TriSceneSaver::SCNUt_TriSceneSaver()
    : pszMaterials(NULL), iNumMaterials(0)
{
}

SCNUt_TriSceneSaver::~SCNUt_TriSceneSaver()
{
}

void SCNUt_TriSceneSaver::Save(char* _szFilename,SCNUt_TriScene* _poScn,SCNUt_MaterialTable* _poMT)
{
    CGFile oFile;

    if ( !oFile.bOpen(_szFilename, EFileOpenMode::FOM_WRITE) )
    {
        return;
    }

    // ----------------------------------------------------------------
    oFile.WriteText("BEGIN TRIn");
    oFile.WriteText("{\n");

    // ----------------------------------------------------------------
    oFile.WriteText( "	BEGIN MATERIALS %d\n",_poMT->uiNumElems() );
    oFile.WriteText("	{\n");
    if ( _poMT->uiNumElems() == 0 )
    {
        oFile.WriteText("		1 NULL\n");
    }
    else
    {
        for ( uint i = 0; i < _poMT->uiNumElems(); i++ )
        {
            CGShader* poShader = _poMT->poGet(i);
            const char* szName = CGShaderWH::I()->sGetName( poShader ).szString();
            oFile.WriteText("		%d %s\n",i + 1,szName);          // 1 based
        }
    }

    oFile.WriteText("	}\n");
    oFile.WriteText("	END MATERIALS\n");
    oFile.WriteText("\n");
    // ----------------------------------------------------------------

    oFile.WriteText("	BEGIN TRIS %d\n", _poScn->NumTris);
    oFile.WriteText("	{\n");
    for ( uint i = 0; i < _poScn->NumTris; i++ )
    {
        oFile.WriteText("		{\n");
        //
        oFile.WriteText("			<%d>\n",_poScn->Tris[i].Material + 1);    // 1 based
        oFile.WriteText("			<%.4f %.4f %.4f><%.4f %.4f %.4f><%.4f %.4f %.4f>\n",
                        _poScn->Tris[i].VXs[0].x,_poScn->Tris[i].VXs[0].y,_poScn->Tris[i].VXs[0].z,
                        _poScn->Tris[i].VXs[1].x,_poScn->Tris[i].VXs[1].y,_poScn->Tris[i].VXs[1].z,
                        _poScn->Tris[i].VXs[2].x,_poScn->Tris[i].VXs[2].y,_poScn->Tris[i].VXs[2].z );

        oFile.WriteText("			<%.4f %.4f %.4f><%.4f %.4f %.4f><%.4f %.4f %.4f>\n",
                        _poScn->Tris[i].VNs[0].x,_poScn->Tris[i].VNs[0].y,_poScn->Tris[i].VNs[0].z,
                        _poScn->Tris[i].VNs[1].x,_poScn->Tris[i].VNs[1].y,_poScn->Tris[i].VNs[1].z,
                        _poScn->Tris[i].VNs[2].x,_poScn->Tris[i].VNs[2].y,_poScn->Tris[i].VNs[2].z );

        oFile.WriteText("			<%.0f %.0f %.0f><%.0f %.0f %.0f><%.0f %.0f %.0f>\n",
                        _poScn->Tris[i].VCs[0].x * 255.0f,_poScn->Tris[i].VCs[0].y * 255.0f,_poScn->Tris[i].VCs[0].z * 255.0f,
                        _poScn->Tris[i].VCs[1].x * 255.0f,_poScn->Tris[i].VCs[1].y * 255.0f,_poScn->Tris[i].VCs[1].z * 255.0f,
                        _poScn->Tris[i].VCs[2].x * 255.0f,_poScn->Tris[i].VCs[2].y * 255.0f,_poScn->Tris[i].VCs[2].z * 255.0f );

        oFile.WriteText("			<%.4f %.4f><%.4f %.4f><%.4f %.4f>\n",
                        _poScn->Tris[i].UVs[0].x,_poScn->Tris[i].UVs[0].y,
                        _poScn->Tris[i].UVs[1].x,_poScn->Tris[i].UVs[1].y,
                        _poScn->Tris[i].UVs[2].x,_poScn->Tris[i].UVs[2].y);

        oFile.WriteText("		}\n");
    }
    oFile.WriteText("	}\n");
    oFile.WriteText("	END TRIS\n");

    // ----------------------------------------------------------------
    oFile.WriteText("}\n");
    oFile.WriteText("END TRIn");

    // ----------------------------------------------------------------
    oFile.Close();
}

// Additional Declarations
