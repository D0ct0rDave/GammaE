//	  %X% %Q% %Z% %W%





// CCOL_Scn_TriListGen
#include "COL_TriList\CCOL_Scn_TriListGen.h"



inline void TEST_Triangle(CVect3 *_poVXs,int _iTri,int &_iTris,CMesh* _poMesh,int _iMat, CCOL_TriList& _oTriList,CVect3 &_oPos,float _fSqrRadius)
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


	fSqrDist = MATH_Utils::fTriPointSqDistance(oTri,_oPos);
	if ( fSqrDist < _fSqrRadius )
	{
		_oTriList.iAddTri(oTri.VXs,oTri.Normal,_iMat,0.0f);
		_iTris ++;
	}
}





// Class CCOL_Scn_TriListGen 

CCOL_Scn_TriListGen::CCOL_Scn_TriListGen()
        {
}


CCOL_Scn_TriListGen::~CCOL_Scn_TriListGen()
{
}



int CCOL_Scn_TriListGen::GetTriList (CCOL_TriList& _oTriList, CVect3& _oPos, float _fRadius)
{
  	if (! iNumMeshes) return(0);

	int	iMesh;
	int iNumTris = 0;
	
	// Get triangles
	for (iMesh=0;((iMesh<iNumMeshes) && _oTriList.iFreeTris());iMesh++)
		iNumTris += GetTrisFromMesh(_oTriList,poMeshes[iMesh],piMats[iMesh],_oPos,_fRadius);

	return(iNumTris);
}

int CCOL_Scn_TriListGen::GetTrisFromMesh (CCOL_TriList& _oTriList, CMesh* _poMesh, int _iMat, CVect3& _oPos, float _fRadius)
{
  	if (! _oTriList.iFreeTris()) return(0);

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
			for (cTri=0;((cTri<_poMesh->usNumPrims) && _oTriList.iFreeTris());cTri++)
			{
				VXs[0].Assign( _poMesh->VXs[ _poMesh->Idxs[cTri*3+0] ]);
				VXs[1].Assign( _poMesh->VXs[ _poMesh->Idxs[cTri*3+1] ]);
				VXs[2].Assign( _poMesh->VXs[ _poMesh->Idxs[cTri*3+2] ]);
				
				TEST_Triangle(VXs,cTri,iTris,_poMesh,_iMat,_oTriList,_oPos,fSqRadius);
			}
		}
		break;
		
		// -------------------------------------------------------------------------------------
		case E3D_MESH_QUADS:		
		{
			for (cTri=0;((cTri<_poMesh->usNumPrims) && (_oTriList.iFreeTris()>2));cTri++)
			{
				// First quad triangle 
				VXs[0].Assign(_poMesh->VXs[ _poMesh->Idxs[cTri*4+0] ]);
				VXs[1].Assign(_poMesh->VXs[ _poMesh->Idxs[cTri*4+1] ]);
				VXs[2].Assign(_poMesh->VXs[ _poMesh->Idxs[cTri*4+3] ]);

				TEST_Triangle(VXs,cTri,iTris,_poMesh,_iMat,_oTriList,_oPos,fSqRadius);
				
				// Second quad triangle 
				VXs[0].Assign(_poMesh->VXs[ _poMesh->Idxs[cTri*4+1] ]);
				VXs[1].Assign(_poMesh->VXs[ _poMesh->Idxs[cTri*4+3] ]);
				VXs[2].Assign(_poMesh->VXs[ _poMesh->Idxs[cTri*4+2] ]);

				TEST_Triangle(VXs,cTri,iTris,_poMesh,_iMat,_oTriList,_oPos,fSqRadius);
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
			for (cTri=0;((cTri<_poMesh->usNumPrims) && _oTriList.iFreeTris());cTri++)
			{
				TEST_Triangle(pVXs,cTri,iTris,_poMesh,_iMat,_oTriList,_oPos,fSqRadius);
				pVXs += 3;
			}
		}
		break;

		// -------------------------------------------------------------------------------------
		case E3D_MESH_NIQUADS:		
		{
			for (cTri=0;((cTri<_poMesh->usNumPrims) && (_oTriList.iFreeTris()>2));cTri++)
			{
				// First quad triangle 
				VXs[0].Assign( _poMesh->VXs[cTri*4+0] );
				VXs[1].Assign( _poMesh->VXs[cTri*4+1] );
				VXs[2].Assign( _poMesh->VXs[cTri*4+3] );

				TEST_Triangle(VXs,cTri,iTris,_poMesh,_iMat,_oTriList,_oPos,fSqRadius);

				// Second quad triangle 
				VXs[0].Assign( _poMesh->VXs[ cTri*4+1 ] );
				VXs[1].Assign( _poMesh->VXs[ cTri*4+3 ] );
				VXs[2].Assign( _poMesh->VXs[ cTri*4+2 ] );

				TEST_Triangle(VXs,cTri,iTris,_poMesh,_iMat,_oTriList,_oPos,fSqRadius);
			}
		}
		break;

		// -------------------------------------------------------------------------------------
		case E3D_MESH_NITRISTRIP:
		break;
	}

	return (iTris);	
}

// Additional Declarations
    
