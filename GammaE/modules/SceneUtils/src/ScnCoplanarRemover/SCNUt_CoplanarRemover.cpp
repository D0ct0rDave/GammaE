



#include "Gammae_Math.h"
#include "GammaE_Mem.h"
#include "Gammae_Collision.h"
#include <string.h>

// SCNUt_CoplanarRemover
#include "ScnCoplanarRemover\SCNUt_CoplanarRemover.h"
int ClassifyTriangles(CVect3 *_poSrcVXs,CVect3 *_poDstVXs)
{
	int iInside = 0;

	CTriangle	oSrcTri,oDstTri;
	
	oSrcTri.Init(_poSrcVXs);
	oSrcTri.ComputeAll();
	
	oDstTri.Init(_poDstVXs);
	oDstTri.ComputeAll();

	CVect3 oDiff;
	oDiff.Assign(oDstTri.Normal);
	oDiff.Sub   (oSrcTri.Normal);
	if (oDiff.fModule() < 0.1f) return(0);

	float fSrcArea = oSrcTri.Normal.fModule();
	float fDstArea = oDstTri.Normal.fModule();

	const float THRESHOLD_DIST = 1e-5f;

	// Test triangle area	
	
	
	if ( fSrcArea > fDstArea) 
	{
		// First look if dst triangle falls completely inside the source triangle bounding box
		CGraphBV_Box oSrcBox;
		oSrcBox.Compute(_poSrcVXs,3);

		if ((! CCOL_ST_Box::iTestPoint(oSrcBox.Vol.Maxs,oSrcBox.Vol.Mins,_poDstVXs[0])) ||
			(! CCOL_ST_Box::iTestPoint(oSrcBox.Vol.Maxs,oSrcBox.Vol.Mins,_poDstVXs[1])) ||
			(! CCOL_ST_Box::iTestPoint(oSrcBox.Vol.Maxs,oSrcBox.Vol.Mins,_poDstVXs[2]))) return(false);

		oSrcTri.Normal.Normalize();

		if (MATH_Utils::fTriPointSqDistance(oSrcTri,_poDstVXs[0]) < THRESHOLD_DIST) iInside ++;
		if (MATH_Utils::fTriPointSqDistance(oSrcTri,_poDstVXs[1]) < THRESHOLD_DIST) iInside ++;
		if (MATH_Utils::fTriPointSqDistance(oSrcTri,_poDstVXs[2]) < THRESHOLD_DIST) iInside ++;
		
		if (iInside >= 2)
		{
			return(1);	// Src must survive			
		}
		else
			return(0);
	}
	else
	{
		// First look if src triangle falls completely inside the destination triangle bounding box
		CGraphBV_Box oDstBox;
		oDstBox.Compute(_poDstVXs,3);

		if ((! CCOL_ST_Box::iTestPoint(oDstBox.Vol.Maxs,oDstBox.Vol.Mins,_poSrcVXs[0])) ||
			(! CCOL_ST_Box::iTestPoint(oDstBox.Vol.Maxs,oDstBox.Vol.Mins,_poSrcVXs[1])) ||
			(! CCOL_ST_Box::iTestPoint(oDstBox.Vol.Maxs,oDstBox.Vol.Mins,_poSrcVXs[2]))) return(false);

		oDstTri.Normal.Normalize();

		if (MATH_Utils::fTriPointSqDistance(oDstTri,_poSrcVXs[0]) < THRESHOLD_DIST) iInside ++;
		if (MATH_Utils::fTriPointSqDistance(oDstTri,_poSrcVXs[1]) < THRESHOLD_DIST) iInside ++;
		if (MATH_Utils::fTriPointSqDistance(oDstTri,_poSrcVXs[2]) < THRESHOLD_DIST) iInside ++;
		 
		if (iInside >= 2)
			return(2);	// Dst must survive
		else
			return(0);
	}
}


// Class SCNUt_CoplanarRemover 

SCNUt_CoplanarRemover::SCNUt_CoplanarRemover()
        {
}


SCNUt_CoplanarRemover::~SCNUt_CoplanarRemover()
{
}



SCNUt_TriScene * SCNUt_CoplanarRemover::RemoveCoplanars (SCNUt_TriScene *_poScn)
{
  	if (!_poScn->NumTris) return (NULL);

	int		cI,cJ;
	CPlane	oSrcPlane,oDstPlane;	
	bool	*pbToRemove = mNew bool	[_poScn->NumTris];

	
	// Initialize ToRemove list
	memset(pbToRemove,0,_poScn->NumTris*sizeof(bool));

	
	// Select triangles to remove
	for (cJ=0;cJ<_poScn->NumTris;cJ++)
	{
		oSrcPlane.GenerateFromPoints(_poScn->Tris[cJ].VXs[0],
									 _poScn->Tris[cJ].VXs[1],
									 _poScn->Tris[cJ].VXs[2]);

		for (cI=cJ+1;cI<_poScn->NumTris;cI++)
		// for (cI=0;cI<_poScn->NumTris;cI++)
		{
			if (! pbToRemove[cI])
			{
				oDstPlane.GenerateFromPoints(_poScn->Tris[cI].VXs[0],
											 _poScn->Tris[cI].VXs[1],
											 _poScn->Tris[cI].VXs[2]);

				if (oSrcPlane.Coplanar(oDstPlane))
				{
					// Look what of the triangles is completelly contained inside 
					// the other
					int iClass = ClassifyTriangles(_poScn->Tris[cJ].VXs,_poScn->Tris[cI].VXs);
					
					if (iClass)
					{
						if (iClass == 1)
						{
							// Src in Dst
							pbToRemove[cJ] = true;
							// Continue testing with this triangle, because we
							// can still remove some other tris
						}
						else
						{
							// Dst in Src
							pbToRemove[cI] = true;
							// _poScn->Tris[cI].VCs[0].V4(1.0f,0.0f,1.0f,0.0f);
							// _poScn->Tris[cI].VCs[1].V4(1.0f,0.0f,1.0f,0.0f);
							// _poScn->Tris[cI].VCs[2].V4(1.0f,0.0f,1.0f,0.0f);

						}
					}
				}
			}
		}
	}


	// Count the number of final triangles
	int iNumTris = 0;	
	for (cJ=0;cJ<_poScn->NumTris;cJ++)
	{
		if (! pbToRemove[cJ]) iNumTris++;
	}


	// Create and copy the final triangles to the new triangle scene
	SCNUt_TriScene *poNewScn = mNew SCNUt_TriScene;
	poNewScn->Init(iNumTris);
	
	cI=0;
	for (cJ=0;cJ<_poScn->NumTris;cJ++)
	{
		if (! pbToRemove[cJ])
		{
			poNewScn->Tris[cI] =_poScn->Tris[cJ];
			cI++;
		}
	}

	mDel []pbToRemove;
	return(poNewScn);
}

// Additional Declarations
    
