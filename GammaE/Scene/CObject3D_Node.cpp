//## begin module%3AAC0C32006E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AAC0C32006E.cm

//## begin module%3AAC0C32006E.cp preserve=no
//## end module%3AAC0C32006E.cp

//## Module: CObject3D_Node%3AAC0C32006E; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\CObject3D_Node.cpp

//## begin module%3AAC0C32006E.additionalIncludes preserve=no
//## end module%3AAC0C32006E.additionalIncludes

//## begin module%3AAC0C32006E.includes preserve=yes
#include <assert.h>
#include "memory/gammae_mem.h"
//## end module%3AAC0C32006E.includes

// CObject3D_Node
#include "Scene\CObject3D_Node.h"
//## begin module%3AAC0C32006E.additionalDeclarations preserve=yes
//## end module%3AAC0C32006E.additionalDeclarations


// Class CObject3D_Node 




CObject3D_Node::CObject3D_Node()
  //## begin CObject3D_Node::CObject3D_Node%.hasinit preserve=no
  //## end CObject3D_Node::CObject3D_Node%.hasinit
  //## begin CObject3D_Node::CObject3D_Node%.initialization preserve=yes
  //## end CObject3D_Node::CObject3D_Node%.initialization
{
  //## begin CObject3D_Node::CObject3D_Node%.body preserve=yes
	TypeID		= e3DObj_Node;

	BVol		= CGraphBV_Manager::poCreate();
	bFrustumTest= true;
  //## end CObject3D_Node::CObject3D_Node%.body
}

CObject3D_Node::CObject3D_Node (int _iInitialSubObjs)
  //## begin CObject3D_Node::CObject3D_Node%1019380666.hasinit preserve=no
  //## end CObject3D_Node::CObject3D_Node%1019380666.hasinit
  //## begin CObject3D_Node::CObject3D_Node%1019380666.initialization preserve=yes
  //## end CObject3D_Node::CObject3D_Node%1019380666.initialization
{
  //## begin CObject3D_Node::CObject3D_Node%1019380666.body preserve=yes
	CObject3D_Node();
	Init(_iInitialSubObjs);
  //## end CObject3D_Node::CObject3D_Node%1019380666.body
}


CObject3D_Node::~CObject3D_Node()
{
  //## begin CObject3D_Node::~CObject3D_Node%.body preserve=yes
	Clear();
  //## end CObject3D_Node::~CObject3D_Node%.body
}



//## Other Operations (implementation)
void CObject3D_Node::Init (int _iInitialSubObjs)
{
  //## begin CObject3D_Node::Init%984427108.body preserve=yes
	poSubObj.SetReallocFactor(_iInitialSubObjs);
	//poSubObj.iAdd(NULL);

	/*
	MaxSubObjects = _MaxSubObjects;
	SubObj        = mNew CObject3D *[MaxSubObjects];		
	for (int cObj=0;cObj<MaxSubObjects;cObj++)	SubObj[cObj] = NULL;
	*/

	// poSubObj.
  //## end CObject3D_Node::Init%984427108.body
}

void CObject3D_Node::Clear ()
{
  //## begin CObject3D_Node::Clear%986154962.body preserve=yes
	int cObj;

	// Free SubObj
	for (cObj=0;cObj<poSubObj.iNumElems();cObj++)
	{
		if (poSubObj[cObj])
			poSubObj[cObj]->UnReference();
	}
	poSubObj.Clear();
  //## end CObject3D_Node::Clear%986154962.body
}

CGraphBV * CObject3D_Node::poGetBoundVol ()
{
  //## begin CObject3D_Node::poGetBoundVol%984427103.body preserve=yes
  	return( BVol);
  //## end CObject3D_Node::poGetBoundVol%984427103.body
}

void CObject3D_Node::ComputeBoundVol ()
{
  //## begin CObject3D_Node::ComputeBoundVol%984427104.body preserve=yes
  
	// Las bounding boxes de los objetos deben tener en cuenta
	// las transformaciones que se deben realizar en los nodos 
	// hijos. Probar a transformar la BoundingBox mediante la
	// matriz asociada al nodo. Despues volver a obtener
	// los max y los mins, para volver a tener una AABB

	int			cObj;
	float		fXSide,fYSide,fZSide;
    CVect3		Maxs,Mins,Center;
	CGraphBV	*BV;

    Mins.V3( 1000000000, 1000000000, 1000000000);
    Maxs.V3(-1000000000,-1000000000,-1000000000);

    for (cObj=0;cObj<poSubObj.iNumElems();cObj++)
    {
		if (poSubObj[cObj])
		{
			// Compute the AABB for the object
			poSubObj[cObj]->ComputeBoundVol();
			BV = poSubObj[cObj]->poGetBoundVol();

			// Get object properties				
			fXSide = BV->GetRange(0)*0.5f;
			fYSide = BV->GetRange(1)*0.5f;
			fZSide = BV->GetRange(2)*0.5f;			
			Center = BV->GetCenter();
			
			// Compute Maxs/Mins vectors
			if ( Center.X() + fXSide > Maxs.X() ) Maxs.SetX(Center.X() + fXSide);
			if ( Center.X() - fXSide < Mins.X() ) Mins.SetX(Center.X() - fXSide);

			if ( Center.Y() + fYSide > Maxs.Y() ) Maxs.SetY(Center.Y() + fYSide);
			if ( Center.Y() - fYSide < Mins.Y() ) Mins.SetY(Center.Y() - fYSide);
			
			if ( Center.Z() + fZSide > Maxs.Z() ) Maxs.SetZ(Center.Z() + fZSide);
			if ( Center.Z() - fZSide < Mins.Z() ) Mins.SetZ(Center.Z() - fZSide);
		}
    }

	BVol->Init(Maxs,Mins);	
  //## end CObject3D_Node::ComputeBoundVol%984427104.body
}

void CObject3D_Node::DelObject (int _iPos)
{
  //## begin CObject3D_Node::DelObject%996702770.body preserve=yes
	assert( (_iPos<poSubObj.iNumElems()) && "Object out of bounds");

	if (poSubObj[_iPos])
	{
		poSubObj[_iPos]->UnReference();		
		poSubObj[_iPos] = NULL;
	}	
  //## end CObject3D_Node::DelObject%996702770.body
}

int CObject3D_Node::iAddObject (CObject3D* _poObj)
{
  //## begin CObject3D_Node::iAddObject%996522678.body preserve=yes
	poSubObj.iAdd(_poObj);
	return(poSubObj.iNumElems()-1);
  //## end CObject3D_Node::iAddObject%996522678.body
}

void CObject3D_Node::SetObject (CObject3D* _poObj, int _iPos)
{
  //## begin CObject3D_Node::SetObject%984427106.body preserve=yes
	assert( (_iPos<poSubObj.iNumElems()) && "Object out of bounds");
	assert( _poObj && "Setting a NULL Subobject");
	
	poSubObj[_iPos] = _poObj;
	_poObj->Reference();
  //## end CObject3D_Node::SetObject%984427106.body
}

CObject3D* CObject3D_Node::poGetObject (int _iPos)
{
  //## begin CObject3D_Node::poGetObject%984427107.body preserve=yes
	assert( (_iPos<poSubObj.iNumElems()) && "Object out of bounds");	
	return( poSubObj[_iPos] );
  //## end CObject3D_Node::poGetObject%984427107.body
}

void CObject3D_Node::Render ()
{
  //## begin CObject3D_Node::Render%984427105.body preserve=yes

	if ( bVisible() )
	{
		int	cObj;
		for (cObj=0;cObj<poSubObj.iNumElems();cObj++)
			if (poSubObj[cObj])
				poSubObj[cObj]->Render();
	}

  //## end CObject3D_Node::Render%984427105.body
}

int CObject3D_Node::iNumSubObjs ()
{
  //## begin CObject3D_Node::iNumSubObjs%1010017301.body preserve=yes	
	int iNumSubObjs;
	int cObj;

	iNumSubObjs = 0;
	for (cObj=0;cObj<poSubObj.iNumElems();cObj++)
		if (poSubObj[cObj]) iNumSubObjs++;

	return(iNumSubObjs);
  //## end CObject3D_Node::iNumSubObjs%1010017301.body
}

// Additional Declarations
  //## begin CObject3D_Node%3AAC0C32006E.declarations preserve=yes
  //## end CObject3D_Node%3AAC0C32006E.declarations

//## begin module%3AAC0C32006E.epilog preserve=yes
//## end module%3AAC0C32006E.epilog


// Detached code regions:
// WARNING: this code will be lost if code is regenerated.
#if 0
//## begin CObject3D_Node::iGetMaxSubObjects%999339053.body preserve=no
	return (MaxSubObjects);
//## end CObject3D_Node::iGetMaxSubObjects%999339053.body

#endif
