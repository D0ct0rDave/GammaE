//## begin module%3C76E0B701A9.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C76E0B701A9.cm

//## begin module%3C76E0B701A9.cp preserve=no
//## end module%3C76E0B701A9.cp

//## Module: SCNUt_SceneBuilder%3C76E0B701A9; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\SceneBuilder\SCNUt_SceneBuilder.cpp

//## begin module%3C76E0B701A9.additionalIncludes preserve=no
//## end module%3C76E0B701A9.additionalIncludes

//## begin module%3C76E0B701A9.includes preserve=yes
#include "memory/gammae_mem.h"
//## end module%3C76E0B701A9.includes

// SCNUt_SceneBuilder
#include "Scene\SceneUtils\SceneBuilder\SCNUt_SceneBuilder.h"
//## begin module%3C76E0B701A9.additionalDeclarations preserve=yes
//## end module%3C76E0B701A9.additionalDeclarations


// Class SCNUt_SceneBuilder 

SCNUt_SceneBuilder::SCNUt_SceneBuilder()
  //## begin SCNUt_SceneBuilder::SCNUt_SceneBuilder%.hasinit preserve=no
  //## end SCNUt_SceneBuilder::SCNUt_SceneBuilder%.hasinit
  //## begin SCNUt_SceneBuilder::SCNUt_SceneBuilder%.initialization preserve=yes
  //## end SCNUt_SceneBuilder::SCNUt_SceneBuilder%.initialization
{
  //## begin SCNUt_SceneBuilder::SCNUt_SceneBuilder%.body preserve=yes
  //## end SCNUt_SceneBuilder::SCNUt_SceneBuilder%.body
}


SCNUt_SceneBuilder::~SCNUt_SceneBuilder()
{
  //## begin SCNUt_SceneBuilder::~SCNUt_SceneBuilder%.body preserve=yes
  //## end SCNUt_SceneBuilder::~SCNUt_SceneBuilder%.body
}



//## Other Operations (implementation)
CObject3D * SCNUt_SceneBuilder::poBuildScene (SCNUt_TriScene& _roScene, SCNUt_MaterialTable &_roMatTable)
{
  //## begin SCNUt_SceneBuilder::poBuildScene%1014423918.body preserve=yes
	if (! _roScene.NumTris) return(NULL);
	if (! _roScene.Tris   ) return(NULL);

	CObject3D_Node		*poNode;
	CObject3D_Leaf		*poLeaf;
	CMesh				*poMesh;
	int					iMesh;

	SCNUt_MeshCompacter oMComp;

	SCNUt_TriSceneSeparator oTSep;	
	oTSep.SeparateScene(_roScene);
	  
	// Generate main node
    if (oTSep.NumMeshes>1)
    {
        poNode = mNew CObject3D_Node;
        poNode->Init(oTSep.NumMeshes);

        // Add every subobject
        for (iMesh=0;iMesh<oTSep.NumMeshes ;iMesh++)
        {
            poMesh = oMComp.CompactMesh( oTSep.Meshes[iMesh] );

            poLeaf = mNew CObject3D_Leaf;
            poLeaf->SetMesh  (poMesh);
            poLeaf->SetShader( _roMatTable.poGetShader(oTSep.piMatIdx[iMesh]) );

            // Add the new compacted mesh
            poNode->iAddObject(poLeaf);
        }

	    return(poNode);
    }
    else
    {
        poMesh = oMComp.CompactMesh( oTSep.Meshes[0] );

        poLeaf = mNew CObject3D_Leaf;
        poLeaf->SetMesh  (poMesh);
        poLeaf->SetShader( _roMatTable.poGetShader(oTSep.piMatIdx[0]) );
        
        return(poLeaf);
    }
  //## end SCNUt_SceneBuilder::poBuildScene%1014423918.body
}

// Additional Declarations
  //## begin SCNUt_SceneBuilder%3C76E0B701A9.declarations preserve=yes
  //## end SCNUt_SceneBuilder%3C76E0B701A9.declarations

//## begin module%3C76E0B701A9.epilog preserve=yes
//## end module%3C76E0B701A9.epilog
