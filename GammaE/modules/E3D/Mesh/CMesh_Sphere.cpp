//## begin module%3CCD399302BD.cm preserve=no
//## end module%3CCD399302BD.cm

//## begin module%3CCD399302BD.cp preserve=no
//## end module%3CCD399302BD.cp

//## Module: CMesh_Sphere%3CCD399302BD; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\Mesh\CMesh_Sphere.cpp

//## begin module%3CCD399302BD.additionalIncludes preserve=no
//## end module%3CCD399302BD.additionalIncludes

//## begin module%3CCD399302BD.includes preserve=yes
//## end module%3CCD399302BD.includes

// CMesh_Sphere
#include "E3D\Mesh\CMesh_Sphere.h"
//## begin module%3CCD399302BD.additionalDeclarations preserve=yes
//## end module%3CCD399302BD.additionalDeclarations


// Class CMesh_Sphere 

CMesh_Sphere::CMesh_Sphere()
  //## begin CMesh_Sphere::CMesh_Sphere%.hasinit preserve=no
  //## end CMesh_Sphere::CMesh_Sphere%.hasinit
  //## begin CMesh_Sphere::CMesh_Sphere%.initialization preserve=yes
  //## end CMesh_Sphere::CMesh_Sphere%.initialization
{
  //## begin CMesh_Sphere::CMesh_Sphere%.body preserve=yes
	Init(16,1.0f);
  //## end CMesh_Sphere::CMesh_Sphere%.body
}

CMesh_Sphere::CMesh_Sphere (int _iNumSlices, float _fRadius)
  //## begin CMesh_Sphere::CMesh_Sphere%1020082679.hasinit preserve=no
  //## end CMesh_Sphere::CMesh_Sphere%1020082679.hasinit
  //## begin CMesh_Sphere::CMesh_Sphere%1020082679.initialization preserve=yes
  //## end CMesh_Sphere::CMesh_Sphere%1020082679.initialization
{
  //## begin CMesh_Sphere::CMesh_Sphere%1020082679.body preserve=yes
	Init(_iNumSlices,_fRadius);
  //## end CMesh_Sphere::CMesh_Sphere%1020082679.body
}


CMesh_Sphere::~CMesh_Sphere()
{
  //## begin CMesh_Sphere::~CMesh_Sphere%.body preserve=yes
  //## end CMesh_Sphere::~CMesh_Sphere%.body
}



//## Other Operations (implementation)
void CMesh_Sphere::Init (int _iNumSlices, float _fRadius)
{
  //## begin CMesh_Sphere::Init%1020082680.body preserve=yes
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
			VCs[iIdx].V4(1.0f,1.0f,1.0f,1.0f);
			VNs[iIdx].Assign(VXs[iIdx]);	// VN = Normalized(Pos - Origin) // Origin=(0,0,0)
			VNs[iIdx].Normalize();
			iIdx++;

			VXs[iIdx].V3(x2,y2,z2);
			UVs[iIdx].V2(u,v + fVStep);
			VCs[iIdx].V4(1.0f,1.0f,1.0f,1.0f);
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

  //## end CMesh_Sphere::Init%1020082680.body
}

// Additional Declarations
  //## begin CMesh_Sphere%3CCD399302BD.declarations preserve=yes
  //## end CMesh_Sphere%3CCD399302BD.declarations

//## begin module%3CCD399302BD.epilog preserve=yes
//## end module%3CCD399302BD.epilog
