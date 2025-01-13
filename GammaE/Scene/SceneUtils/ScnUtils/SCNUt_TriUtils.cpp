//## begin module%3C76D5340057.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C76D5340057.cm

//## begin module%3C76D5340057.cp preserve=no
//## end module%3C76D5340057.cp

//## Module: SCNUt_TriUtils%3C76D5340057; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnUtils\SCNUt_TriUtils.cpp

//## begin module%3C76D5340057.additionalIncludes preserve=no
//## end module%3C76D5340057.additionalIncludes

//## begin module%3C76D5340057.includes preserve=yes
//## end module%3C76D5340057.includes

// SCNUt_TriUtils
#include "Scene\SceneUtils\ScnUtils\SCNUt_TriUtils.h"
//## begin module%3C76D5340057.additionalDeclarations preserve=yes
//## end module%3C76D5340057.additionalDeclarations


// Class SCNUt_TriUtils 

SCNUt_TriUtils::SCNUt_TriUtils()
  //## begin SCNUt_TriUtils::SCNUt_TriUtils%.hasinit preserve=no
  //## end SCNUt_TriUtils::SCNUt_TriUtils%.hasinit
  //## begin SCNUt_TriUtils::SCNUt_TriUtils%.initialization preserve=yes
  //## end SCNUt_TriUtils::SCNUt_TriUtils%.initialization
{
  //## begin SCNUt_TriUtils::SCNUt_TriUtils%.body preserve=yes
  //## end SCNUt_TriUtils::SCNUt_TriUtils%.body
}


SCNUt_TriUtils::~SCNUt_TriUtils()
{
  //## begin SCNUt_TriUtils::~SCNUt_TriUtils%.body preserve=yes
  //## end SCNUt_TriUtils::~SCNUt_TriUtils%.body
}



//## Other Operations (implementation)
void SCNUt_TriUtils::MinimizeMappingOffset (SCNUt_Triangle& _roTri)
{
  //## begin SCNUt_TriUtils::MinimizeMappingOffset%1014421760.body preserve=yes
  	#define TILE_LIMIT	8.0f

	float fUMin,fVMin,fUMax,fVMax;
	float fIntUMin,fIntVMin;
	int   iVX;
	
	fUMin = _roTri.UVs[0].U();
	if (_roTri.UVs[1].U() < fUMin) fUMin = _roTri.UVs[1].U();
	if (_roTri.UVs[2].U() < fUMin) fUMin = _roTri.UVs[2].U();
	
	fVMin = _roTri.UVs[0].V();
	if (_roTri.UVs[1].V() < fVMin) fVMin = _roTri.UVs[1].V();
	if (_roTri.UVs[2].V() < fVMin) fVMin = _roTri.UVs[2].V();

	fIntUMin = (int)fUMin;
	fIntVMin = (int)fVMin;

	_roTri.UVs[0].Sub(fIntUMin,fIntVMin);
	_roTri.UVs[1].Sub(fIntUMin,fIntVMin);
	_roTri.UVs[2].Sub(fIntUMin,fIntVMin);	

/*
	// avoid much tiling on textures
	fUMax = _roTri.UVs[0].U();
	if (_roTri.UVs[1].U() > fUMax) fUMax = _roTri.UVs[1].U();
	if (_roTri.UVs[2].U() > fUMax) fUMax = _roTri.UVs[2].U();
	
	fVMax = _roTri.UVs[0].V();
	if (_roTri.UVs[1].V() > fVMax) fVMax = _roTri.UVs[1].V();
	if (_roTri.UVs[2].V() > fVMax) fVMax = _roTri.UVs[2].V();
	
	for (iVX=0;iVX<3;iVX++)
	{
		if (_roTri.UVs[iVX].U() > TILE_LIMIT) 
			_roTri.UVs[iVX].SetU(_roTri.UVs[iVX].U()/fUMax);
		if (_roTri.UVs[iVX].V() > TILE_LIMIT) 
			_roTri.UVs[iVX].SetV(_roTri.UVs[iVX].V()/fVMax);
	}
*/
  //## end SCNUt_TriUtils::MinimizeMappingOffset%1014421760.body
}

void SCNUt_TriUtils::ChangeWinding (SCNUt_Triangle& _roTri)
{
  //## begin SCNUt_TriUtils::ChangeWinding%1014421761.body preserve=yes
	SCNUt_Triangle AuxTri = _roTri;
	
	_roTri.VXs[1].Assign(AuxTri.VXs[2]);
	_roTri.VXs[2].Assign(AuxTri.VXs[1]);

	_roTri.VCs[1].Assign(AuxTri.VCs[2]);
	_roTri.VCs[2].Assign(AuxTri.VCs[1]);

	_roTri.UVs[1].Assign(AuxTri.UVs[2]);
	_roTri.UVs[2].Assign(AuxTri.UVs[1]);

	_roTri.VNs[1].Assign(AuxTri.VNs[2]);
	_roTri.VNs[2].Assign(AuxTri.VNs[1]);

	// Swap dot prods
	_roTri.DProds[1] = AuxTri.DProds[2];
	_roTri.DProds[2] = AuxTri.DProds[1];
	
	// Swap vertex sides
	_roTri.VertexSide[1] = AuxTri.VertexSide[2];
	_roTri.VertexSide[2] = AuxTri.VertexSide[1];
  //## end SCNUt_TriUtils::ChangeWinding%1014421761.body
}

void SCNUt_TriUtils::GetQ2UVCoords (CVect3& _roPnt, CVect3& _roXAxis, CVect3& _roYAxis, float _fUOfs, float _fVOfs, float _fUScl, float _fVScl, float* _pfU, float* _pfV)
{
  //## begin SCNUt_TriUtils::GetQ2UVCoords%1014767413.body preserve=yes
	// ----------------------------------------------------------
	*_pfU =(_roPnt.X()*_roXAxis.X() + 
			_roPnt.Y()*_roXAxis.Y() + 
			_roPnt.Z()*_roXAxis.Z() + _fUOfs) * _fUScl;
	
	*_pfV =(_roPnt.X()*_roYAxis.X() + 
			_roPnt.Y()*_roYAxis.Y() + 
			_roPnt.Z()*_roYAxis.Z() + _fVOfs) * _fVScl;
  //## end SCNUt_TriUtils::GetQ2UVCoords%1014767413.body
}

// Additional Declarations
  //## begin SCNUt_TriUtils%3C76D5340057.declarations preserve=yes
  //## end SCNUt_TriUtils%3C76D5340057.declarations

//## begin module%3C76D5340057.epilog preserve=yes
//## end module%3C76D5340057.epilog
