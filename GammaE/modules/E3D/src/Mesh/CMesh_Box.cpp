




// CMesh_Box
#include "Mesh\CMesh_Box.h"


// Class CMesh_Box 

CMesh_Box::CMesh_Box()
        {
  
  	CMesh::Init(8,12,E3D_MESH_TRIS,MESH_FIELD_ALL);	

    // Setup vertex data
    VXs[0].V3(-1,-1, 1);
    VXs[1].V3(-1, 1, 1);
    VXs[2].V3( 1, 1, 1);
    VXs[3].V3( 1,-1, 1);
    VXs[4].V3(-1,-1,-1);
    VXs[5].V3(-1, 1,-1);
    VXs[6].V3( 1, 1,-1);
    VXs[7].V3( 1,-1,-1);

    // Setup Normal data
    VNs[0].V3(-1,-1, 1);
    VNs[1].V3(-1, 1, 1);
    VNs[2].V3( 1, 1, 1);
    VNs[3].V3( 1,-1, 1);
    VNs[4].V3(-1,-1,-1);
    VNs[5].V3(-1, 1,-1);
    VNs[6].V3( 1, 1,-1);
    VNs[7].V3( 1,-1,-1);

	// Setup colors
	VCs[0].Set(1,1,1,1);
	VCs[1].Set(1,1,1,1);
	VCs[2].Set(1,1,1,1);
	VCs[3].Set(1,1,1,1);
	VCs[4].Set(1,1,1,1);
	VCs[5].Set(1,1,1,1);
	VCs[6].Set(1,1,1,1);
	VCs[7].Set(1,1,1,1);

    for (int cNorm = 0;cNorm < usNumVerts;cNorm++) VNs[cNorm].Normalize();

    // Setup UV data
    UVs[ 0].V2(1,0);
	UVs[ 1].V2(1,1);
	UVs[ 2].V2(0,1);
	UVs[ 3].V2(0,0);
	UVs[ 4].V2(1,0);
	UVs[ 5].V2(1,1);
	UVs[ 6].V2(0,1);
	UVs[ 7].V2(0,0);

    // Setup triangle data
   
	// Cara posterior
    Idxs[ 0*3+0] = 1;	Idxs[ 0*3+1] = 0;	Idxs[ 0*3+2]= 3;	
	Idxs[ 1*3+0] = 1;	Idxs[ 1*3+1] = 3;	Idxs[ 1*3+2]= 2;	
 
    // Cara anterior
    Idxs[ 2*3+0] = 6;	Idxs[ 2*3+1] = 7;	Idxs[ 2*3+2]= 4;	
	Idxs[ 3*3+0] = 6;	Idxs[ 3*3+1] = 4;	Idxs[ 3*3+2]= 5;	
    
    // Cara derecha
    Idxs[ 4*3+0] = 2;	Idxs[ 4*3+1] = 3;	Idxs[ 4*3+2]= 7;	
	Idxs[ 5*3+0] = 2;	Idxs[ 5*3+1] = 7;	Idxs[ 5*3+2]= 6;	

    // Cara izquierda
    Idxs[ 6*3+0] = 5;	Idxs[ 6*3+1] = 4;	Idxs[ 6*3+2]= 0;	
	Idxs[ 7*3+0] = 5;	Idxs[ 7*3+1] = 0;	Idxs[ 7*3+2]= 1;	
    
    // Cara superior
    Idxs[ 8*3+0] = 5;	Idxs[ 8*3+1] = 1;	Idxs[ 8*3+2]= 2;	
	Idxs[ 9*3+0] = 5;	Idxs[ 9*3+1] = 5;	Idxs[ 9*3+2]= 6;	
    
	// Cara inferior
    Idxs[10*3+0] = 0;	Idxs[10*3+1] = 4;	Idxs[10*3+2]= 7;	
	Idxs[11*3+0] = 0;	Idxs[11*3+1] = 7;	Idxs[11*3+2]= 3;	

}


CMesh_Box::~CMesh_Box()
{
}


// Additional Declarations
    
