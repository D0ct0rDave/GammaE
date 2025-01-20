//## begin module%3C2BD21F003A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C2BD21F003A.cm

//## begin module%3C2BD21F003A.cp preserve=no
//## end module%3C2BD21F003A.cp

//## Module: SCNUt_TransformTriScene%3C2BD21F003A; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\TransfTriScn\SCNUt_TransformTriScene.cpp

//## begin module%3C2BD21F003A.additionalIncludes preserve=no
//## end module%3C2BD21F003A.additionalIncludes

//## begin module%3C2BD21F003A.includes preserve=yes
//## end module%3C2BD21F003A.includes

// SCNUt_TransformTriScene
#include "Scene\SceneUtils\TransfTriScn\SCNUt_TransformTriScene.h"
//## begin module%3C2BD21F003A.additionalDeclarations preserve=yes
//## end module%3C2BD21F003A.additionalDeclarations


// Class SCNUt_TransformTriScene 

SCNUt_TransformTriScene::SCNUt_TransformTriScene()
  //## begin SCNUt_TransformTriScene::SCNUt_TransformTriScene%.hasinit preserve=no
  //## end SCNUt_TransformTriScene::SCNUt_TransformTriScene%.hasinit
  //## begin SCNUt_TransformTriScene::SCNUt_TransformTriScene%.initialization preserve=yes
  //## end SCNUt_TransformTriScene::SCNUt_TransformTriScene%.initialization
{
  //## begin SCNUt_TransformTriScene::SCNUt_TransformTriScene%.body preserve=yes
  //## end SCNUt_TransformTriScene::SCNUt_TransformTriScene%.body
}


SCNUt_TransformTriScene::~SCNUt_TransformTriScene()
{
  //## begin SCNUt_TransformTriScene::~SCNUt_TransformTriScene%.body preserve=yes
  //## end SCNUt_TransformTriScene::~SCNUt_TransformTriScene%.body
}



//## Other Operations (implementation)
void SCNUt_TransformTriScene::Transform (SCNUt_TriScene& _roTriScn, CMatrix4x4& _roMatrix)
{
  //## begin SCNUt_TransformTriScene::Transform%1009496921.body preserve=yes

	int iTri;
	for (iTri=0;iTri<_roTriScn.NumTris;iTri++)
	{
		// Transform points
		_roMatrix.TransformPoint(_roTriScn.Tris[iTri].VXs[0]);
		_roMatrix.TransformPoint(_roTriScn.Tris[iTri].VXs[1]);
		_roMatrix.TransformPoint(_roTriScn.Tris[iTri].VXs[2]);

		// Transform normals
		_roMatrix.TransformVector(_roTriScn.Tris[iTri].VNs[0]);
		_roMatrix.TransformVector(_roTriScn.Tris[iTri].VNs[1]);
		_roMatrix.TransformVector(_roTriScn.Tris[iTri].VNs[2]);
	}

  //## end SCNUt_TransformTriScene::Transform%1009496921.body
}

// Additional Declarations
  //## begin SCNUt_TransformTriScene%3C2BD21F003A.declarations preserve=yes
  //## end SCNUt_TransformTriScene%3C2BD21F003A.declarations

//## begin module%3C2BD21F003A.epilog preserve=yes
//## end module%3C2BD21F003A.epilog
