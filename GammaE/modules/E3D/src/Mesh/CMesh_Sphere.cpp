




// CMesh_Sphere
#include "Mesh\CMesh_Sphere.h"


// Class CMesh_Sphere 

CMesh_Sphere::CMesh_Sphere()
        {
  	Init(16,1.0f);
}

CMesh_Sphere::CMesh_Sphere (int _iNumSlices, float _fRadius)
        {
  	Init(_iNumSlices,_fRadius);
}


CMesh_Sphere::~CMesh_Sphere()
{
}



void CMesh_Sphere::Init (int _iNumSlices, float _fRadius)
{
  	CMesh::Init(_iNumSlices*_iNumSlices*2,_iNumSlices*_iNumSlices*2-2,
				E3D_MESH_NITRISTRIP,MESH_FIELD_ALL);

	int	  cI,cJ,iIdx;

	float theta1,theta2,theta3;
    float cs_t1,cs_t2,cs_t3;
    float sn_t1,sn_t2,sn_t3;     

	float x1,y1,z1;
	float x2,y2,z2;	
	float u,v;

	float fRhoStep = ( _PI_) / (_iNumSlices);
    float fPhiStep = (_2PI_) / _iNumSlices;     

	float fUStep = 1.0f / _iNumSlices;
    float fVStep = 1.0f / _iNumSlices;
		
	iIdx = 0;
		
	v      = 0.0f;
    theta1 = - _PI2_;
    theta2 = theta1 + fRhoStep;    
	  
	for (cJ=0;cJ<_iNumSlices;cJ++)
    {			 
		cs_t1  = cosf(theta1);
		cs_t2  = cosf(theta2);
	    sn_t1  = sinf(theta1);
		sn_t2  = sinf(theta2);       

        u      = 0;
        theta3 = 0.0f;

        for (cI=0;cI<_iNumSlices;cI++)
        {
            cs_t3 = cosf(theta3);
            sn_t3 = sinf(theta3);    
				         
			x1 = _fRadius * cs_t1 * cs_t3;
            y1 = _fRadius * cs_t1 * sn_t3;
            z1 = _fRadius * sn_t1;             
				
			x2 = _fRadius * cs_t2 * cs_t3;
            y2 = _fRadius * cs_t2 * sn_t3;
            z2 = _fRadius * sn_t2;                 
			
			VXs[iIdx].V3(x1,y1,z1);
			UVs[iIdx].V2(u,v);
			VCs[iIdx].Set(1.0f,1.0f,1.0f,1.0f);
			VNs[iIdx].Assign(VXs[iIdx]);	// VN = Normalized(Pos - Origin) // Origin=(0,0,0)
			VNs[iIdx].Normalize();
			iIdx++;

			VXs[iIdx].V3(x2,y2,z2);
			UVs[iIdx].V2(u,v + fVStep);
			VCs[iIdx].Set(1.0f,1.0f,1.0f,1.0f);
			VNs[iIdx].Assign(VXs[iIdx]);	// VN = Normalized(Pos - Origin) // Origin=(0,0,0)
			VNs[iIdx].Normalize();
			iIdx++;

			u      += fUStep;
            theta3 += fPhiStep;
}            
		
		v      += fVStep;
        theta1 += fRhoStep;
        theta2 += fRhoStep;
}	

}

// Additional Declarations
    
