//## begin module%3C29310E01C5.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C29310E01C5.cm

//## begin module%3C29310E01C5.cp preserve=no
//## end module%3C29310E01C5.cp

//## Module: CCOL_MT_CommonMesh%3C29310E01C5; Pseudo Package body
//## Source file: i:\Projects\GammaE\Collision\COL_Testers\COL_SceneTest\COL_MeshTest\CCOL_MT_CommonMesh.cpp

//## begin module%3C29310E01C5.additionalIncludes preserve=no
//## end module%3C29310E01C5.additionalIncludes

//## begin module%3C29310E01C5.includes preserve=yes
//## end module%3C29310E01C5.includes

// CCOL_ColState
#include "Collision\CollisionSystem\CCOL_ColState.h"
// CCOL_MT_CommonMesh
#include "Collision\COL_Testers\COL_SceneTest\COL_MeshTest\CCOL_MT_CommonMesh.h"
//## begin module%3C29310E01C5.additionalDeclarations preserve=yes



inline void TEST_Triangle(CVect3 *_poVXs,int _iTri,int &_riTris,CMesh* _poMesh,int _iMat,CGraphBV* _poBVol, CCOL_TriList& _roTriList)
{
	CTriangle	oTri;
	float		fTime;

	
	
	if (_poMesh->TNs)
		oTri.Init(_poVXs,_poMesh->TNs[_iTri]);	
	else
	{
		oTri.Init(_poVXs);
		oTri.Normal.Normalize();
	}
	oTri.ComputeAll();



	fTime = CCOL_DT_ColTester::fTestTriangle(_poBVol,oTri);

	if (fTime>=0.0f)
	{
		_roTriList.iAddTri(oTri.VXs,oTri.Normal,_iMat,fTime);
		_riTris++;
	}
}


//## end module%3C29310E01C5.additionalDeclarations


// Class CCOL_MT_CommonMesh 

CCOL_MT_CommonMesh::CCOL_MT_CommonMesh()
  //## begin CCOL_MT_CommonMesh::CCOL_MT_CommonMesh%.hasinit preserve=no
  //## end CCOL_MT_CommonMesh::CCOL_MT_CommonMesh%.hasinit
  //## begin CCOL_MT_CommonMesh::CCOL_MT_CommonMesh%.initialization preserve=yes
  //## end CCOL_MT_CommonMesh::CCOL_MT_CommonMesh%.initialization
{
  //## begin CCOL_MT_CommonMesh::CCOL_MT_CommonMesh%.body preserve=yes
  //## end CCOL_MT_CommonMesh::CCOL_MT_CommonMesh%.body
}


CCOL_MT_CommonMesh::~CCOL_MT_CommonMesh()
{
  //## begin CCOL_MT_CommonMesh::~CCOL_MT_CommonMesh%.body preserve=yes
  //## end CCOL_MT_CommonMesh::~CCOL_MT_CommonMesh%.body
}



//## Other Operations (implementation)
int CCOL_MT_CommonMesh::iTestCollision (CMesh* _poMesh, int _iMat, CGraphBV* _poBVol, CCOL_TriList& _roTriList)
{
  //## begin CCOL_MT_CommonMesh::iTestCollision%1009321162.body preserve=yes
	if (! _poMesh)				 return(0);
	if (! _roTriList.iFreeTris()) return(0);

	int				cTri;
	CTriangle		Tri;
	CVect3			VXs[3];
	CVect3			VN;
	CVect3			*pVXs;	
	float			fSqDist;
	int				iTris = 0;
	float			fTime;

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

				TEST_Triangle(VXs,cTri,iTris,_poMesh,_iMat,_poBVol,_roTriList);
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

				TEST_Triangle(VXs,cTri,iTris,_poMesh,_iMat,_poBVol,_roTriList);

				// Second quad triangle 
				VXs[0].Assign(_poMesh->VXs[ _poMesh->Idxs[cTri*4+1] ]);
				VXs[1].Assign(_poMesh->VXs[ _poMesh->Idxs[cTri*4+3] ]);
				VXs[2].Assign(_poMesh->VXs[ _poMesh->Idxs[cTri*4+2] ]);

				TEST_Triangle(VXs,cTri,iTris,_poMesh,_iMat,_poBVol,_roTriList);
			}
		}
		break;

		// -------------------------------------------------------------------------------------
		case E3D_MESH_TRIFANS:		return(0);
									break;
		// -------------------------------------------------------------------------------------
		case E3D_MESH_TRISTRIPS:
		{
			for (cTri=0;((cTri<_poMesh->usNumPrims) && _roTriList.iFreeTris());cTri++)
			{
				VXs[0].Assign( _poMesh->VXs[_poMesh->Idxs[cTri  ] ]);
				VXs[1].Assign( _poMesh->VXs[_poMesh->Idxs[cTri+1] ]);
				VXs[2].Assign( _poMesh->VXs[_poMesh->Idxs[cTri+2] ]);

				TEST_Triangle(VXs,cTri,iTris,_poMesh,_iMat,_poBVol,_roTriList);
			}
		}
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
				TEST_Triangle(pVXs,cTri,iTris,_poMesh,_iMat,_poBVol,_roTriList);
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

				TEST_Triangle(VXs,cTri,iTris,_poMesh,_iMat,_poBVol,_roTriList);

				// Second quad triangle 
				VXs[0].Assign( _poMesh->VXs[ cTri*4+1 ] );
				VXs[1].Assign( _poMesh->VXs[ cTri*4+3 ] );
				VXs[2].Assign( _poMesh->VXs[ cTri*4+2 ] );

				TEST_Triangle(VXs,cTri,iTris,_poMesh,_iMat,_poBVol,_roTriList);
			}
		}
		break;

		// -------------------------------------------------------------------------------------
		case E3D_MESH_NITRISTRIP:
			
			for (cTri=0;((cTri<_poMesh->usNumPrims) && _roTriList.iFreeTris());cTri++)
			{
				VXs[0].Assign( _poMesh->VXs[cTri  ] );
				VXs[1].Assign( _poMesh->VXs[cTri+1] );
				VXs[2].Assign( _poMesh->VXs[cTri+2] );

				TEST_Triangle(VXs,cTri,iTris,_poMesh,_iMat,_poBVol,_roTriList);
			}

		break;
	}

	return (iTris);	
  //## end CCOL_MT_CommonMesh::iTestCollision%1009321162.body
}

// Additional Declarations
  //## begin CCOL_MT_CommonMesh%3C29310E01C5.declarations preserve=yes
  //## end CCOL_MT_CommonMesh%3C29310E01C5.declarations

//## begin module%3C29310E01C5.epilog preserve=yes
//## end module%3C29310E01C5.epilog
