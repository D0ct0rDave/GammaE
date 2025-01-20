




// SCNUt_TriUtils
#include "ScnUtils\SCNUt_TriUtils.h"


// Class SCNUt_TriUtils 

SCNUt_TriUtils::SCNUt_TriUtils()
        {
}


SCNUt_TriUtils::~SCNUt_TriUtils()
{
}



void SCNUt_TriUtils::MinimizeMappingOffset (SCNUt_Triangle& _oTri)
{
    	#define TILE_LIMIT	8.0f

	float fUMin,fVMin,fUMax,fVMax;
	float fIntUMin,fIntVMin;
	int   iVX;
	
	fUMin = _oTri.UVs[0].x;
	if (_oTri.UVs[1].x < fUMin) fUMin = _oTri.UVs[1].x;
	if (_oTri.UVs[2].x < fUMin) fUMin = _oTri.UVs[2].x;
	
	fVMin = _oTri.UVs[0].y;
	if (_oTri.UVs[1].y < fVMin) fVMin = _oTri.UVs[1].y;
	if (_oTri.UVs[2].y < fVMin) fVMin = _oTri.UVs[2].y;

	fIntUMin = (int)fUMin;
	fIntVMin = (int)fVMin;

	_oTri.UVs[0].Sub(fIntUMin,fIntVMin);
	_oTri.UVs[1].Sub(fIntUMin,fIntVMin);
	_oTri.UVs[2].Sub(fIntUMin,fIntVMin);	

/*
	// avoid much tiling on textures
	fUMax = _oTri.UVs[0].U();
	if (_oTri.UVs[1].U() > fUMax) fUMax = _oTri.UVs[1].U();
	if (_oTri.UVs[2].U() > fUMax) fUMax = _oTri.UVs[2].U();
	
	fVMax = _oTri.UVs[0].V();
	if (_oTri.UVs[1].V() > fVMax) fVMax = _oTri.UVs[1].V();
	if (_oTri.UVs[2].V() > fVMax) fVMax = _oTri.UVs[2].V();
	
	for (iVX=0;iVX<3;iVX++)
	{
		if (_oTri.UVs[iVX].U() > TILE_LIMIT) 
			_oTri.UVs[iVX].SetU(_oTri.UVs[iVX].U()/fUMax);
		if (_oTri.UVs[iVX].V() > TILE_LIMIT) 
			_oTri.UVs[iVX].SetV(_oTri.UVs[iVX].V()/fVMax);
	}
*/
}

void SCNUt_TriUtils::ChangeWinding (SCNUt_Triangle& _oTri)
{
  	SCNUt_Triangle AuxTri = _oTri;
	
	_oTri.VXs[1].Assign(AuxTri.VXs[2]);
	_oTri.VXs[2].Assign(AuxTri.VXs[1]);

	_oTri.VCs[1].Assign(AuxTri.VCs[2]);
	_oTri.VCs[2].Assign(AuxTri.VCs[1]);

	_oTri.UVs[1].Assign(AuxTri.UVs[2]);
	_oTri.UVs[2].Assign(AuxTri.UVs[1]);

	_oTri.VNs[1].Assign(AuxTri.VNs[2]);
	_oTri.VNs[2].Assign(AuxTri.VNs[1]);

	// Swap dot prods
	_oTri.DProds[1] = AuxTri.DProds[2];
	_oTri.DProds[2] = AuxTri.DProds[1];
	
	// Swap vertex sides
	_oTri.VertexSide[1] = AuxTri.VertexSide[2];
	_oTri.VertexSide[2] = AuxTri.VertexSide[1];
}

void SCNUt_TriUtils::GetQ2UVCoords (CVect3& _oPnt, CVect3& _oXAxis, CVect3& _oYAxis, float _fUOfs, float _fVOfs, float _fUScl, float _fVScl, float* _pfU, float* _pfV)
{
  	// ----------------------------------------------------------
	*_pfU =(_oPnt.x*_oXAxis.x + 
			_oPnt.y*_oXAxis.y + 
			_oPnt.z*_oXAxis.z + _fUOfs) * _fUScl;
	
	*_pfV =(_oPnt.x*_oYAxis.x + 
			_oPnt.y*_oYAxis.y + 
			_oPnt.z*_oYAxis.z + _fVOfs) * _fVScl;
}

// Additional Declarations
    
