//## begin module%3C0ED22E0331.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C0ED22E0331.cm

//## begin module%3C0ED22E0331.cp preserve=no
//## end module%3C0ED22E0331.cp

//## Module: CCOL_Scn_TriListGen%3C0ED22E0331; Pseudo Package body
//## Source file: i:\Projects\GammaE\Collision\COL_TriList\CCOL_Scn_TriListGen.cpp

//## begin module%3C0ED22E0331.additionalIncludes preserve=no
//## end module%3C0ED22E0331.additionalIncludes

//## begin module%3C0ED22E0331.includes preserve=yes
//## end module%3C0ED22E0331.includes

// CCOL_Scn_TriListGen
#include "Collision\COL_TriList\CCOL_Scn_TriListGen.h"
//## begin module%3C0ED22E0331.additionalDeclarations preserve=yes



inline void TEST_Triangle(CVect3 *_poVXs,int _iTri,int &_riTris,CMesh* _poMesh,int _iMat, CCOL_TriList& _roTriList,CVect3 &_roPos,float _fSqrRadius)
{
	CTriangle	oTri;	
	float		fSqrDist;
	
	
	if (_poMesh->TNs)
		oTri.Init(_poVXs,_poMesh->TNs[_iTri]);	
	else
	{
		oTri.Init(_poVXs);
		oTri.Normal.Normalize();
	}
	oTri.ComputeAll();


	fSqrDist = MATH_Utils::fTriPointSqDistance(oTri,_roPos);
	if ( fSqrDist < _fSqrRadius )
	{
		_roTriList.iAddTri(oTri.VXs,oTri.Normal,_iMat,0.0f);
		_riTris ++;
	}
}



//## end module%3C0ED22E0331.additionalDeclarations


// Class CCOL_Scn_TriListGen 

CCOL_Scn_TriListGen::CCOL_Scn_TriListGen()
  //## begin CCOL_Scn_TriListGen::CCOL_Scn_TriListGen%.hasinit preserve=no
  //## end CCOL_Scn_TriListGen::CCOL_Scn_TriListGen%.hasinit
  //## begin CCOL_Scn_TriListGen::CCOL_Scn_TriListGen%.initialization preserve=yes
  //## end CCOL_Scn_TriListGen::CCOL_Scn_TriListGen%.initialization
{
  //## begin CCOL_Scn_TriListGen::CCOL_Scn_TriListGen%.body preserve=yes
  //## end CCOL_Scn_TriListGen::CCOL_Scn_TriListGen%.body
}


CCOL_Scn_TriListGen::~CCOL_Scn_TriListGen()
{
  //## begin CCOL_Scn_TriListGen::~CCOL_Scn_TriListGen%.body preserve=yes
  //## end CCOL_Scn_TriListGen::~CCOL_Scn_TriListGen%.body
}



//## Other Operations (implementation)
int CCOL_Scn_TriListGen::GetTriList (CCOL_TriList& _roTriList, CVect3& _roPos, float _fRadius)
{
  //## begin CCOL_Scn_TriListGen::GetTriList%1007604292.body preserve=yes
	if (! iNumMeshes) return(0);

	int	iMesh;
	int iNumTris = 0;
	
	// Get triangles
	for (iMesh=0;((iMesh<iNumMeshes) && _roTriList.iFreeTris());iMesh++)
		iNumTris += GetTrisFromMesh(_roTriList,poMeshes[iMesh],piMats[iMesh],_roPos,_fRadius);

	return(iNumTris);
  //## end CCOL_Scn_TriListGen::GetTriList%1007604292.body
}

int CCOL_Scn_TriListGen::GetTrisFromMesh (CCOL_TriList& _roTriList, CMesh* _poMesh, int _iMat, CVect3& _roPos, float _fRadius)
{
  //## begin CCOL_Scn_TriListGen::GetTrisFromMesh%1008711903.body preserve=yes
	if (! _roTriList.iFreeTris()) return(0);

	int				cTri;
	CVect3			VXs[3];	
	CVect3			*pVXs;	
	int				iTris = 0;
	float			fSqRadius = _SQ_( _fRadius );	

	switch (_poMesh->eMeshType)
	{		
		case E3D_MESH_NONE:			return(0);
									break;
		// -------------------------------------------------------------------------------------
		case E3D_MESH_TRIS:			
		{
			for (cTri=0;((cTri<_poMesh->usNumPrims) && _roTriList.iFreeTris());cTri++)
			{
				VXs[0].Assign( _poMesh->VXs[ _poMesh->Idxs[cTri*3+0] ]);
				VXs[1].Assign( _poMesh->VXs[ _poMesh->Idxs[cTri*3+1] ]);
				VXs[2].Assign( _poMesh->VXs[ _poMesh->Idxs[cTri*3+2] ]);
				
				TEST_Triangle(VXs,cTri,iTris,_poMesh,_iMat,_roTriList,_roPos,fSqRadius);
			}
		}
		break;
		
		// -------------------------------------------------------------------------------------
		case E3D_MESH_QUADS:		
		{
			for (cTri=0;((cTri<_poMesh->usNumPrims) && (_roTriList.iFreeTris()>2));cTri++)
			{
				// First quad triangle 
				VXs[0].Assign(_poMesh->VXs[ _poMesh->Idxs[cTri*4+0] ]);
				VXs[1].Assign(_poMesh->VXs[ _poMesh->Idxs[cTri*4+1] ]);
				VXs[2].Assign(_poMesh->VXs[ _poMesh->Idxs[cTri*4+3] ]);

				TEST_Triangle(VXs,cTri,iTris,_poMesh,_iMat,_roTriList,_roPos,fSqRadius);
				
				// Second quad triangle 
				VXs[0].Assign(_poMesh->VXs[ _poMesh->Idxs[cTri*4+1] ]);
				VXs[1].Assign(_poMesh->VXs[ _poMesh->Idxs[cTri*4+3] ]);
				VXs[2].Assign(_poMesh->VXs[ _poMesh->Idxs[cTri*4+2] ]);

				TEST_Triangle(VXs,cTri,iTris,_poMesh,_iMat,_roTriList,_roPos,fSqRadius);
			}
		}
		break;

		// -------------------------------------------------------------------------------------
		case E3D_MESH_TRIFANS:		return(0);
									break;
		// -------------------------------------------------------------------------------------
		case E3D_MESH_TRISTRIPS:	return(0);
									break;
		// -------------------------------------------------------------------------------------
		case E3D_MESH_QUADSTRIPS:	return(0);
									break;
		
		// -------------------------------------------------------------------------------------
		case E3D_MESH_NITRIS:
		{
			pVXs = _poMesh->VXs;
			for (cTri=0;((cTri<_poMesh->usNumPrims) && _roTriList.iFreeTris());cTri++)
			{
				TEST_Triangle(pVXs,cTri,iTris,_poMesh,_iMat,_roTriList,_roPos,fSqRadius);
				pVXs += 3;
			}
		}
		break;

		// -------------------------------------------------------------------------------------
		case E3D_MESH_NIQUADS:		
		{
			for (cTri=0;((cTri<_poMesh->usNumPrims) && (_roTriList.iFreeTris()>2));cTri++)
			{
				// First quad triangle 
				VXs[0].Assign( _poMesh->VXs[cTri*4+0] );
				VXs[1].Assign( _poMesh->VXs[cTri*4+1] );
				VXs[2].Assign( _poMesh->VXs[cTri*4+3] );

				TEST_Triangle(VXs,cTri,iTris,_poMesh,_iMat,_roTriList,_roPos,fSqRadius);

				// Second quad triangle 
				VXs[0].Assign( _poMesh->VXs[ cTri*4+1 ] );
				VXs[1].Assign( _poMesh->VXs[ cTri*4+3 ] );
				VXs[2].Assign( _poMesh->VXs[ cTri*4+2 ] );

				TEST_Triangle(VXs,cTri,iTris,_poMesh,_iMat,_roTriList,_roPos,fSqRadius);
			}
		}
		break;

		// -------------------------------------------------------------------------------------
		case E3D_MESH_NITRISTRIP:
		break;
	}

	return (iTris);	
  //## end CCOL_Scn_TriListGen::GetTrisFromMesh%1008711903.body
}

// Additional Declarations
  //## begin CCOL_Scn_TriListGen%3C0ED22E0331.declarations preserve=yes
  //## end CCOL_Scn_TriListGen%3C0ED22E0331.declarations

//## begin module%3C0ED22E0331.epilog preserve=yes
//## end module%3C0ED22E0331.epilog
