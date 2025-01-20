//## begin module%3ACA2D230154.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3ACA2D230154.cm

//## begin module%3ACA2D230154.cp preserve=no
//## end module%3ACA2D230154.cp

//## Module: CHeadUpDisplay%3ACA2D230154; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\2D_Objects\CHeadUpDisplay.cpp

//## begin module%3ACA2D230154.additionalIncludes preserve=no
//## end module%3ACA2D230154.additionalIncludes

//## begin module%3ACA2D230154.includes preserve=yes
//## end module%3ACA2D230154.includes

// CHeadUpDisplay
#include "Scene\2D_Objects\CHeadUpDisplay.h"
//## begin module%3ACA2D230154.additionalDeclarations preserve=yes
//## end module%3ACA2D230154.additionalDeclarations


// Class CHeadUpDisplay 


CHeadUpDisplay::CHeadUpDisplay()
  //## begin CHeadUpDisplay::CHeadUpDisplay%.hasinit preserve=no
      : ObjPos(NULL)
  //## end CHeadUpDisplay::CHeadUpDisplay%.hasinit
  //## begin CHeadUpDisplay::CHeadUpDisplay%.initialization preserve=yes
  //## end CHeadUpDisplay::CHeadUpDisplay%.initialization
{
  //## begin CHeadUpDisplay::CHeadUpDisplay%.body preserve=yes
	bFrustumTest = false;
  //## end CHeadUpDisplay::CHeadUpDisplay%.body
}


CHeadUpDisplay::~CHeadUpDisplay()
{
  //## begin CHeadUpDisplay::~CHeadUpDisplay%.body preserve=yes
	if (ObjPos) delete []ObjPos;	
  //## end CHeadUpDisplay::~CHeadUpDisplay%.body
}



//## Other Operations (implementation)
void CHeadUpDisplay::AddObject (CObject3D *Obj, float x, float y, float tx, float ty)
{
  //## begin CHeadUpDisplay::AddObject%986334606.body preserve=yes
	int   iObj   = CObject3D_Node::iAddObject(Obj);	

	if (iObj>=0) 
	{
		ObjPos[iObj].x  = x;
		ObjPos[iObj].y  = y;
		ObjPos[iObj].tx = tx;
		ObjPos[iObj].ty = ty;
	}
  //## end CHeadUpDisplay::AddObject%986334606.body
}

void CHeadUpDisplay::Invalidate ()
{
  //## begin CHeadUpDisplay::Invalidate%986334607.body preserve=yes
  //## end CHeadUpDisplay::Invalidate%986334607.body
}

void CHeadUpDisplay::Render ()
{
  //## begin CHeadUpDisplay::Render%986334608.body preserve=yes
	int					cObj;
	
	float fRatio		= gpoE3DRenderer->fGetAspectRatio();
	float fRatioOffset	= - (fRatio - 1.0f)*0.5f;
		
	float				TX,TY,TZ;
	float				XTrans,YTrans,ZTrans;

	CGraphBV			*BVol;

	bool				bDefMode;
	
	// Save Render State
	bDefMode = gpoE3DRenderer->UsingDefferredMode();	

		// Setup our Render State
		gpoE3DRenderer->DisableDefferredMode();		

		// glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

		// A partir de ahora trabajamos con coordenadas de pantalla normalizadas
		
		// Render all the objects
		for (cObj=0;cObj<iNumSubObjs();cObj++)		
		{
			if (poSubObj[cObj])
			{				
				gpoE3DRenderer->PushMatrix();

				BVol = poSubObj[cObj]->poGetBoundVol();

				TX = BVol->GetRange(0);	if (! TX) TX = 1.0f;
				TY = BVol->GetRange(1);	if (! TY) TY = 1.0f;
				TZ = BVol->GetRange(2);	if (! TZ) TZ = 1.0f;

				XTrans    = -BVol->GetCenter().X();
				YTrans    = -BVol->GetCenter().Y();
				ZTrans    = -BVol->GetCenter().Z();

				// Translate to final position
				gpoE3DRenderer->Translate(ObjPos[cObj].x + fRatioOffset,ObjPos[cObj].y,0);

				// Move the object to the left/top corner: screen oringin (<> world origin !)
				gpoE3DRenderer->Translate(-0.5 + (ObjPos[cObj].tx*fRatio)/2,-0.5+ ObjPos[cObj].ty/2,0);
				
				// Rescale to the desired object size
				gpoE3DRenderer->Scale    (ObjPos[cObj].tx*fRatio,ObjPos[cObj].ty,1);
				
				// Rescale to the range -0.5..0.5
				gpoE3DRenderer->Scale    (1.0f/TX,1.0f/TY,1.0f/TZ);

				// Center object at origin
				gpoE3DRenderer->Translate(XTrans,YTrans,ZTrans);

				// Render the object
				poSubObj[cObj]->Render();

				gpoE3DRenderer->PopMatrix();
			}
		}
	
		// glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

	// Restore previous render state	
	if (bDefMode) gpoE3DRenderer->EnableDefferredMode();
	
  //## end CHeadUpDisplay::Render%986334608.body
}

void CHeadUpDisplay::Init (int _NumSubObjects)
{
  //## begin CHeadUpDisplay::Init%986334609.body preserve=yes
	CObject3D_Node::Init(_NumSubObjects);
	ObjPos  = new THUDObjPosEntry[_NumSubObjects];
  //## end CHeadUpDisplay::Init%986334609.body
}

int CHeadUpDisplay::iCulled ()
{
  //## begin CHeadUpDisplay::iCulled%1006904818.body preserve=yes
  return(0);
  //## end CHeadUpDisplay::iCulled%1006904818.body
}

// Additional Declarations
  //## begin CHeadUpDisplay%3ACA2D230154.declarations preserve=yes
  //## end CHeadUpDisplay%3ACA2D230154.declarations

//## begin module%3ACA2D230154.epilog preserve=yes
//## end module%3ACA2D230154.epilog
