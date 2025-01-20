//## begin module%3CD50F090024.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CD50F090024.cm

//## begin module%3CD50F090024.cp preserve=no
//## end module%3CD50F090024.cp

//## Module: SCNUt_VisibilityTester%3CD50F090024; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnVisibilityTester\SCNUt_VisibilityTester.cpp

//## begin module%3CD50F090024.additionalIncludes preserve=no
//## end module%3CD50F090024.additionalIncludes

//## begin module%3CD50F090024.includes preserve=yes
#include "memory/Gammae_Mem.h"
//## end module%3CD50F090024.includes

// SCNUt_TransformTriScene
#include "Scene\SceneUtils\TransfTriScn\SCNUt_TransformTriScene.h"
// SCNUt_VisibilityTester
#include "Scene\SceneUtils\ScnVisibilityTester\SCNUt_VisibilityTester.h"
//## begin module%3CD50F090024.additionalDeclarations preserve=yes
//## end module%3CD50F090024.additionalDeclarations


// Class SCNUt_VisibilityTester 

SCNUt_VisibilityTester::SCNUt_VisibilityTester()
  //## begin SCNUt_VisibilityTester::SCNUt_VisibilityTester%.hasinit preserve=no
  //## end SCNUt_VisibilityTester::SCNUt_VisibilityTester%.hasinit
  //## begin SCNUt_VisibilityTester::SCNUt_VisibilityTester%.initialization preserve=yes
  //## end SCNUt_VisibilityTester::SCNUt_VisibilityTester%.initialization
{
  //## begin SCNUt_VisibilityTester::SCNUt_VisibilityTester%.body preserve=yes
  //## end SCNUt_VisibilityTester::SCNUt_VisibilityTester%.body
}


SCNUt_VisibilityTester::~SCNUt_VisibilityTester()
{
  //## begin SCNUt_VisibilityTester::~SCNUt_VisibilityTester%.body preserve=yes
  //## end SCNUt_VisibilityTester::~SCNUt_VisibilityTester%.body
}



//## Other Operations (implementation)
bool SCNUt_VisibilityTester::bIsVisible (SCNUt_TriScene* _poTScn, CVect3& _roIni, CVect3& _roEnd)
{
  //## begin SCNUt_VisibilityTester::bIsVisible%1020591281.body preserve=yes
	CRay oRay;
	
	oRay.InitFromPoints(_roIni,_roEnd);
	oRay.Dir.Normalize();					
	
	return(bRayToPos(oRay,_roEnd,_poTScn));
  //## end SCNUt_VisibilityTester::bIsVisible%1020591281.body
}

bool SCNUt_VisibilityTester::bRayToPos (CRay& _roRay, CVect3& _roPos, SCNUt_TriScene* _poTScn)
{
  //## begin SCNUt_VisibilityTester::bRayToPos%1020591284.body preserve=yes
  	if (! _poTScn)			return(false);
	if (! _poTScn->NumTris)	return(false);
	if (! _poTScn->Tris)	return(false);
		
	// For all those triangles, compute intersection point,
	int				iTri;
	CTriangle		oTri;
	CVect3			oPoint;
	float			fMaxDist;
	float			fCurDist;

	fMaxDist = _roRay.Origin.Distance(_roPos);

	for (iTri=0;iTri<_poTScn->NumTris;iTri++)
	{
		oTri.Init(_poTScn->Tris[iTri].VXs);
		oTri.ComputeAll();
		oTri.Normal.Normalize();

		if (MATH_Utils::iTestSegTriIntersection(_roRay,oTri,oPoint))
		{
			fCurDist = _roRay.Origin.Distance(oPoint);
			if (fCurDist + 1e-1f < fMaxDist) 
				return(false);
		}
	}

	return(true);
  //## end SCNUt_VisibilityTester::bRayToPos%1020591284.body
}

// Additional Declarations
  //## begin SCNUt_VisibilityTester%3CD50F090024.declarations preserve=yes
  //## end SCNUt_VisibilityTester%3CD50F090024.declarations

//## begin module%3CD50F090024.epilog preserve=yes
//## end module%3CD50F090024.epilog


// Detached code regions:
// WARNING: this code will be lost if code is regenerated.
#if 0
#endif
