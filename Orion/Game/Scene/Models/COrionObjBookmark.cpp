// -----------------------------------------------------------
#include "COrionObjBookmark.h"
#include "GammaE.h"

// -----------------------------------------------------------
CStArray <TOrionObj*> COrionObjBookmark::gObjBookmark;

// -----------------------------------------------------------
TOrionObj *poLoadOrionObject(char *_szFilename)
{
	TOrionObj		*poOObj;
	CFile			oFile;
	TControlPoint	oCP; 

    if (! oFile.iOpen (_szFilename,"rb")) return(NULL);

	unsigned int uiID;
	unsigned int uiBlockSize;
	unsigned int uiNumCPs;

	uiID        = oFile.iRead();
	uiBlockSize = oFile.iRead();

	if (uiID != MAKE_RIFF_ID('O','O','B','J')) return(NULL);
	
	// Create orion obj
	poOObj = mNew TOrionObj;
	poOObj->oCPs.Clear();
	

	// Load number of control points
	uiNumCPs = oFile.iRead();
	
	// Load the control points
    for (int i=0;i<uiNumCPs;i++)
    {
        oFile.ReadCharArray (oCP.szName,8);
        oFile.ReadFloatArray(oCP.oPos.v,3);
		
		// Add the control point to the list
		poOObj->oCPs.iAdd(oCP);
    }


	// Read the model
	CLoaderGEM oLoader;
	uiID        = oFile.iRead();
	uiBlockSize = oFile.iRead();
	
	if (uiID == GEM_FILE_IDENTIFIER)
		poOObj->poModel = oLoader.pLoad(oFile);
	else
		poOObj->poModel = NULL;
	
	oFile.Close();

	return(poOObj);    
}
// -----------------------------------------------------------
COrionObjBookmark::COrionObjBookmark()
{
}
// -----------------------------------------------------------
COrionObjBookmark::~COrionObjBookmark()
{
}
// -----------------------------------------------------------
// Usar los nombres como mejor convenga. Si se quiere utilizar
// Top Bottom como subtipo hacerlo, si no se quiere utilizar
// pues no. UTILIZAR A LIBRE ELECCION.
// Utilizar el tipo como mejor convenga, para poner particulas,
// Flares, o cualquier cosa
// -----------------------------------------------------------
void COrionObjBookmark::ProcessControlPoints()
{
	TControlPoint *poCP;
	for (int iObj=0;iObj<gObjBookmark.iNumElems();iObj++)
	{
		for (int iCP=0;iCP<gObjBookmark[iObj]->oCPs.iNumElems();iCP++)
		{
			poCP = &gObjBookmark[iObj]->oCPs[iCP];

			// Direction
			if (poCP->szName[0] == 'F')
				poCP->ucDir = 0;
	   else if (poCP->szName[0] == 'B')
				poCP->ucDir = 1;
	   else		
				poCP->ucDir = 2;

			// Type
			if (! strncmp(&poCP->szName[4],"REA",3))	// Reactors
			{
				poCP->ucCPType  = 0;
				poCP->ucSubType = 0;
			}
	   
	   else if (! strncmp(&poCP->szName[4],"CAN",3))	// Cannons
			{
				poCP->ucCPType = 1;					

				// Subtype
				if (poCP->szName[2] == 'T')
					poCP->ucSubType = 0;				// Top

		   else if (poCP->szName[2] == 'B')
					poCP->ucSubType = 1;				// Bottom

		   else if (poCP->szName[2] == 'M')
					poCP->ucSubType = 2;				// Middle
		   else
					poCP->ucSubType = 3;				// Other
			}

	   else if (! strcmp(poCP->szName,"LASER"))			// Laser
			{		
				poCP->ucCPType  = 2;					
				poCP->ucSubType = 4;
			}
	   else if (! strcmp(poCP->szName,"ELASER"))		// ELaser
			{		
				poCP->ucCPType  = 2;
				poCP->ucSubType = 5;
			}
	   else if (! strcmp(poCP->szName,"PLASMA"))		// Plasma
			{		
				poCP->ucCPType  = 2;
				poCP->ucSubType = 6;
			}
	   else if (! strcmp(poCP->szName,"BLUELIT"))
			{		
				poCP->ucCPType  = 2;
				poCP->ucSubType = 10;
			}
	   else if (! strncmp(poCP->szName,"BLINKLIT",8))
			{		
				poCP->ucCPType  = 2;
				poCP->ucSubType = 11;
			}
	   else if (! strncmp(poCP->szName,"FLIKLIT",8))
			{		
				poCP->ucCPType  = 2;
				poCP->ucSubType = 12;
			}
	   else
			{
				poCP->ucCPType = 3;						// Other
			}
		}
	}
}
// -----------------------------------------------------------
void COrionObjBookmark::AddObject(char *_szFilename)
{
	TOrionObj *poOObj;
	poOObj = poLoadOrionObject(_szFilename);	

	if (poOObj)
	{
		gObjBookmark.iAdd(poOObj);		// Add to the object database
		// mDel poOObj;					// Delete the instance
	}
}
// -----------------------------------------------------------
void COrionObjBookmark::LoadObjects(char *_szMapFilename)
{
	gObjBookmark.Init(256);
	AddObject(_szMapFilename);

	AddObject("base/models/players/spyda/spyda.shp");
	AddObject("base/models/enemies/persecutor/persecutor.shp");

	AddObject("base/models/weapons/blaster/blaster.shp");
	AddObject("base/models/weapons/missile/missile.shp");
	AddObject("base/models/weapons/napalm/barrel.shp");
	AddObject("base/models/weapons/laser/laser.shp");
	AddObject("base/models/weapons/elaser/elaser.shp");
	AddObject("base/models/weapons/plasma/plasma.shp");

	AddObject("base/models/objects/powerup/powerup.shp");
	AddObject("base/models/objects/pw_laser/pw_laser.shp");
	AddObject("base/models/objects/pw_hblaster/pw_hblaster.shp");
	AddObject("base/models/objects/pw_chaingun/pw_chaingun.shp");
	AddObject("base/models/objects/pw_railgun/pw_railgun.shp");
	AddObject("base/models/objects/pw_bfg/pw_bfg.shp");
	AddObject("base/models/objects/pw_homming/pw_homming.shp");
	AddObject("base/models/objects/pw_napalm/pw_napalm.shp");
	AddObject("base/models/objects/pw_concussion/pw_concussion.shp");

	ProcessControlPoints();
}
// -----------------------------------------------------------