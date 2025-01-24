



#include "GammaE_Mem.h"

// SCNUt_SceneBuilder
#include "SceneBuilder\SCNUt_SceneBuilder.h"


// Class SCNUt_SceneBuilder 

SCNUt_SceneBuilder::SCNUt_SceneBuilder()
        {
}


SCNUt_SceneBuilder::~SCNUt_SceneBuilder()
{
}



CObject3D * SCNUt_SceneBuilder::poBuildScene (SCNUt_TriScene& _oScene, SCNUt_MaterialTable &_oMatTable)
{
  	if (! _oScene.NumTris) return(NULL);
	if (! _oScene.Tris   ) return(NULL);

	CObject3D_Node		*poNode;
	CObject3D_Leaf		*poLeaf;
	CMesh				*poMesh;
	int					iMesh;

	SCNUt_MeshCompacter oMComp;

	SCNUt_TriSceneSeparator oTSep;	
	oTSep.SeparateScene(_oScene);
	  
	// Generate main node
    if (oTSep.NumMeshes>1)
    {
        poNode = mNew CObject3D_Node;
        poNode->Init(oTSep.NumMeshes);

        // Add every subobject
        for (iMesh=0;iMesh<oTSep.NumMeshes ;iMesh++)
        {
            poMesh = oMComp.poCompactMesh( oTSep.Meshes[iMesh] );

            poLeaf = mNew CObject3D_Leaf;
            poLeaf->SetMesh  (poMesh);
            poLeaf->SetShader( _oMatTable.poGet(oTSep.piMatIdx[iMesh]) );

            // Add the new compacted mesh
            poNode->iAddObject(poLeaf);
}

	    return(poNode);
}
    else
    {
        poMesh = oMComp.poCompactMesh( oTSep.Meshes[0] );

        poLeaf = mNew CObject3D_Leaf;
        poLeaf->SetMesh  (poMesh);
        
        CE3D_Shader* poShader = _oMatTable.poGet(oTSep.piMatIdx[0]);
        poLeaf->SetShader( poShader );
        
        return(poLeaf);
}
}

// Additional Declarations
    
