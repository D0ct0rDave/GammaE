//## begin module%3C3081310184.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C3081310184.cm

//## begin module%3C3081310184.cp preserve=no
//## end module%3C3081310184.cp

//## Module: SCNUt_Stripifier%3C3081310184; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnStripifier\SCNUt_Stripifier.cpp

//## begin module%3C3081310184.additionalIncludes preserve=no
//## end module%3C3081310184.additionalIncludes

//## begin module%3C3081310184.includes preserve=yes
#include <string.h>
#include "Memory/GammaE_Mem.h"
//## end module%3C3081310184.includes

// SCNUt_Stripifier
#include "Scene\SceneUtils\ScnStripifier\SCNUt_Stripifier.h"
//## begin module%3C3081310184.additionalDeclarations preserve=yes
//## end module%3C3081310184.additionalDeclarations


// Class SCNUt_Stripifier 

SCNUt_Stripifier::SCNUt_Stripifier()
  //## begin SCNUt_Stripifier::SCNUt_Stripifier%.hasinit preserve=no
  //## end SCNUt_Stripifier::SCNUt_Stripifier%.hasinit
  //## begin SCNUt_Stripifier::SCNUt_Stripifier%.initialization preserve=yes
  //## end SCNUt_Stripifier::SCNUt_Stripifier%.initialization
{
  //## begin SCNUt_Stripifier::SCNUt_Stripifier%.body preserve=yes
  //## end SCNUt_Stripifier::SCNUt_Stripifier%.body
}


SCNUt_Stripifier::~SCNUt_Stripifier()
{
  //## begin SCNUt_Stripifier::~SCNUt_Stripifier%.body preserve=yes
  //## end SCNUt_Stripifier::~SCNUt_Stripifier%.body
}



//## Other Operations (implementation)
CMesh * SCNUt_Stripifier::poStripifyMesh (CMesh *_poMesh)
{
  //## begin SCNUt_Stripifier::poStripifyMesh%1009811891.body preserve=yes
	if (! _poMesh) return(NULL);

	/*
	SCNUt_EdgeBuilder		oEB;
	SCNUt_EdgeList			*poEList;	
	poEList = oEB.poBuild(_poMesh,poOMesh);
	*/

	CMesh					*poOMesh;
	CMesh					*poFMesh;
	SCNUt_AdjTriListBuilder	oATLBuilder;
	SCNUt_AdjTriList		*poATL;

	poATL   = oATLBuilder.poBuild(_poMesh,poOMesh);
	poFMesh = poStripify(poOMesh,poATL);

	// Delete auxiliary mesh
	mDel poOMesh;

	// Delete Adjacent Triangle List
	mDel poATL;

	// Return result mesh
	return(poFMesh);
  //## end SCNUt_Stripifier::poStripifyMesh%1009811891.body
}

CMesh * SCNUt_Stripifier::poStripifyTriScene (SCNUt_TriScene *_poTS)
{
  //## begin SCNUt_Stripifier::poStripifyTriScene%1009811892.body preserve=yes
	return(NULL);
  //## end SCNUt_Stripifier::poStripifyTriScene%1009811892.body
}

CMesh * SCNUt_Stripifier::poStripify (CMesh* _poMesh, SCNUt_AdjTriList* _poATL)
{
  //## begin SCNUt_Stripifier::poStripify%1009920807.body preserve=yes
	CMesh	*PMesh;
	int		iNumTris;
	int		iCurrentTri;
	int		iNeigh;
	int		iNeighTri;
	int		iStripIdx;
	int		iNumStrips;
	int		iNeighVX;

    // Create a mesh only to store strip indexes
	PMesh	= mNew CMesh;
	PMesh->Init(0,_poMesh->usNumPrims*5,E3D_MESH_TRISTRIPS,MESH_FIELD_INDEXES);

    // Initialize counters
	iNumStrips	= 0;
	iStripIdx	= 0;
	iNumTris	= _poMesh->usNumPrims;	

	while (iNumTris)
	{
		// Select the starting triangle
		iCurrentTri = iSelectStartingTri(_poATL);
		if (iCurrentTri == -1) 
			return(PMesh);

		// Linking with previous strips???
		if (iStripIdx>0)			
			PMesh->Idxs[iStripIdx++] = _poMesh->Idxs[ iCurrentTri*3+0];		// repeat first strip index	

		// setup strip vertexs
		PMesh->Idxs[ iStripIdx++ ] = _poMesh->Idxs[ iCurrentTri*3+0 ];
		PMesh->Idxs[ iStripIdx++ ] = _poMesh->Idxs[ iCurrentTri*3+1 ];
		PMesh->Idxs[ iStripIdx++ ] = _poMesh->Idxs[ iCurrentTri*3+2 ];
	
		// This triangle has been visited
		_poATL->Tri[iCurrentTri].Visited = true;
		iNumTris--;

		// ---------------------------------------------------------------------
		// BEGIN: Generate a full strip
		// ---------------------------------------------------------------------		
	
		// Select direction
        //iCurrentTri = -1; // Force 1 strip per triangle
		while (iCurrentTri != -1)
		{
			iNeigh		= iSelectBestNeigh(_poATL,iCurrentTri);
			
			if (iNeigh != -1)
			{
				// Get the neighbour triangle
				iNeighTri	= _poATL->Tri[iCurrentTri].Neigh[iNeigh];
				iNeighVX	= iGetNonCommonVertex (_poMesh,iCurrentTri,iNeighTri);

				if (iNeighVX != -1) 
					PMesh->Idxs[iStripIdx++] = _poMesh->Idxs[ iNeighTri*3+iNeighVX ];
				else
					iNeighVX = 0;

				// This triangle has been visited
				_poATL->Tri[iNeighTri].Visited = true;
				iCurrentTri = iNeighTri;
				iNumTris--;
			}
			else
				iCurrentTri = -1;
		}

		iNumStrips++;
		// ---------------------------------------------------------------------
		// END: Generate a full strip
		// ---------------------------------------------------------------------		
	
		// Are there more strips?
		if (iNumTris)
        {
			PMesh->Idxs[iStripIdx] = PMesh->Idxs[iStripIdx-1];   // repeat last strip index
            iStripIdx ++;
        }
	}
	
	// ---------------------------------------------------------------------
	// Generate the final mesh
	// ---------------------------------------------------------------------
	CMesh	*poResMesh;
	int		iIdx;

    poResMesh = mNew CMesh;
	poResMesh->Init(_poMesh->usNumVerts,iStripIdx-2,E3D_MESH_TRISTRIPS,MESH_FIELD_ALL);

	memcpy(poResMesh->VXs,_poMesh->VXs,_poMesh->usNumVerts*sizeof(CVect3));
	memcpy(poResMesh->VNs,_poMesh->VNs,_poMesh->usNumVerts*sizeof(CVect3));
	memcpy(poResMesh->VCs,_poMesh->VCs,_poMesh->usNumVerts*sizeof(CVect4));
	memcpy(poResMesh->UVs,_poMesh->UVs,_poMesh->usNumVerts*sizeof(CVect2));
	memcpy(poResMesh->Idxs,PMesh->Idxs,iStripIdx*sizeof(short));
	poResMesh->ComputeBoundVol();

	// Free auxiliary mesh
	mDel PMesh;

	return (poResMesh);
  //## end SCNUt_Stripifier::poStripify%1009920807.body
}

int SCNUt_Stripifier::iSelectStartingTri (SCNUt_AdjTriList *_poATL)
{
  //## begin SCNUt_Stripifier::iSelectStartingTri%1009920808.body preserve=yes
	int		iTri;
	int		iMaxNeighs;
	int		iSelTri;
	
	int		iDstNeighs;
	int		iDNeigh;
	int		iDTriNeigh;

	iMaxNeighs = 0;
	iSelTri    = -1;
	for (iTri=0;iTri<_poATL->iNumTris;iTri++)
	{
		if (! _poATL->Tri[iTri].Visited)
		{
			// count the number of visitable neighbours from this triangle
			iDstNeighs = 0;
			for (iDNeigh=0;iDNeigh<_poATL->Tri[iTri].iNumNeighs;iDNeigh++)
			{
				iDTriNeigh = _poATL->Tri[iTri].Neigh[iDNeigh];
				if (! _poATL->Tri[iDTriNeigh].Visited) iDstNeighs++;
			}

			// Update best neighbour
			if (iDstNeighs >= iMaxNeighs)
			{
				iSelTri    = iTri;
				iMaxNeighs = iDstNeighs;
			}
		}
	}

	return (iSelTri);
  //## end SCNUt_Stripifier::iSelectStartingTri%1009920808.body
}

int SCNUt_Stripifier::iSelectBestNeigh (SCNUt_AdjTriList *_poATL, int _iSrcTri)
{
  //## begin SCNUt_Stripifier::iSelectBestNeigh%1009920809.body preserve=yes

	// This function returns the best neighbour for a given source triangle
	// The best neighbour is the triangle neighbour that has the most visitable
	// neighbours

	int		iNeigh;
	int		iBestNeigh;
	int		iMaxNeighs;
	int		iTriNeigh;
	
	int		iDstNeighs;
	int		iDNeigh;
	int		iDTriNeigh;
	
	iBestNeigh = -1;
	iMaxNeighs =  0;
	
	for (iNeigh=0;iNeigh<_poATL->Tri[_iSrcTri].iNumNeighs;iNeigh++)
	{
		// Get the destination triangle neighbour
		iTriNeigh = _poATL->Tri[_iSrcTri].Neigh[iNeigh];
		
		// If this neighbourg has not been visited previously
		if (! _poATL->Tri[iTriNeigh].Visited)
		{
			// count the number of visitable neighbours from this neighbour
			iDstNeighs = 0;
			for (iDNeigh=0;iDNeigh<_poATL->Tri[iTriNeigh].iNumNeighs;iDNeigh++)
			{
				iDTriNeigh = _poATL->Tri[iTriNeigh].Neigh[iDNeigh];
				if (! _poATL->Tri[iDTriNeigh].Visited) iDstNeighs++;
			}

			// Update best neighbour
			if (iDstNeighs >= iMaxNeighs)
			{
				iBestNeigh = iNeigh;
				iMaxNeighs = iDstNeighs;
			}
		}
	}

	return(iBestNeigh);
  //## end SCNUt_Stripifier::iSelectBestNeigh%1009920809.body
}

int SCNUt_Stripifier::iGetNonCommonVertex (CMesh* _SrcMesh, int _iSrcTri, int _iDstTri)
{
  //## begin SCNUt_Stripifier::iGetNonCommonVertex%1009920812.body preserve=yes
	int cI;
	
	for (cI=0;cI<3;cI++)
	{
		if (
			(_SrcMesh->Idxs[_iDstTri*3+cI] != _SrcMesh->Idxs[_iSrcTri*3+0]) &&
			(_SrcMesh->Idxs[_iDstTri*3+cI] != _SrcMesh->Idxs[_iSrcTri*3+1]) &&
			(_SrcMesh->Idxs[_iDstTri*3+cI] != _SrcMesh->Idxs[_iSrcTri*3+2])
			)

			return (cI);
	}

	return (-1);
  //## end SCNUt_Stripifier::iGetNonCommonVertex%1009920812.body
}

// Additional Declarations
  //## begin SCNUt_Stripifier%3C3081310184.declarations preserve=yes
  //## end SCNUt_Stripifier%3C3081310184.declarations

//## begin module%3C3081310184.epilog preserve=yes
//## end module%3C3081310184.epilog