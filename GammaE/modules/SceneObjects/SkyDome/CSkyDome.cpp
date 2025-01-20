//## begin module%3BB0F0530382.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BB0F0530382.cm

//## begin module%3BB0F0530382.cp preserve=no
//## end module%3BB0F0530382.cp

//## Module: CSkyDome%3BB0F0530382; Pseudo Package body
//## Source file: i:\Projects\GammaE\SceneObjects\SkyDome\CSkyDome.cpp

//## begin module%3BB0F0530382.additionalIncludes preserve=no
//## end module%3BB0F0530382.additionalIncludes

//## begin module%3BB0F0530382.includes preserve=yes
//## end module%3BB0F0530382.includes

// CSkyDome
#include "SceneObjects\SkyDome\CSkyDome.h"
//## begin module%3BB0F0530382.additionalDeclarations preserve=yes
//## end module%3BB0F0530382.additionalDeclarations


// Class CSkyDome 







CSkyDome::CSkyDome()
  //## begin CSkyDome::CSkyDome%.hasinit preserve=no
      : fRadius(0.0f), fRot(0.0f), FogAffected(false)
  //## end CSkyDome::CSkyDome%.hasinit
  //## begin CSkyDome::CSkyDome%.initialization preserve=yes
  //## end CSkyDome::CSkyDome%.initialization
{
  //## begin CSkyDome::CSkyDome%.body preserve=yes
  //## end CSkyDome::CSkyDome%.body
}


CSkyDome::~CSkyDome()
{
  //## begin CSkyDome::~CSkyDome%.body preserve=yes
	mDel poMesh;
  //## end CSkyDome::~CSkyDome%.body
}



//## Other Operations (implementation)
void CSkyDome::SetRotation (float _fRot)
{
  //## begin CSkyDome::SetRotation%1001451998.body preserve=yes
	fRot = _fRot;
  //## end CSkyDome::SetRotation%1001451998.body
}

void CSkyDome::SetRadius (float _fRadius)
{
  //## begin CSkyDome::SetRadius%1001452000.body preserve=yes
	fRadius = _fRadius;
  //## end CSkyDome::SetRadius%1001452000.body
}

void CSkyDome::SetAxis (CVect3 _Axis)
{
  //## begin CSkyDome::SetAxis%1001452001.body preserve=yes
	Axis.Assign(_Axis);
  //## end CSkyDome::SetAxis%1001452001.body
}

void CSkyDome::SetPosition (CVect3 _Pos)
{
  //## begin CSkyDome::SetPosition%1001452002.body preserve=yes
	Pos.Assign(_Pos);
  //## end CSkyDome::SetPosition%1001452002.body
}

void CSkyDome::CreateDome (bool _bFogAffected, int _iNumVSlices, int _iNumHSlices, int _iStartVSlice, int _iEndVSlice, float _fUTiling, float _fVTiling)
{
  //## begin CSkyDome::CreateDome%1001452003.body preserve=yes
	poMesh = mNew CMesh();
	poMesh->Init((_iEndVSlice-_iStartVSlice)*(_iNumHSlices+1)*2,
			   (_iEndVSlice-_iStartVSlice)*(_iNumHSlices+1)*2-2,
			   E3D_MESH_NITRISTRIP,
			   MESH_FIELD_VERTEXS | MESH_FIELD_UVCOORDS);

	int	  cI,cJ,iIdx; 


	float theta1,theta2,theta3;
    float cs_t1,cs_t2,cs_t3;
    float sn_t1,sn_t2,sn_t3;     

	float x1,y1,z1;
	float x2,y2,z2;	
	float u,v;

	float fRhoStep = ( _PI_) / _iNumVSlices;
    float fPhiStep = (_2PI_) / _iNumHSlices;     

	float fUStep = 1.0f / _iNumHSlices;
    float fVStep = 1.0f / _iNumVSlices;
		
	iIdx = 0;
		
	v      = 0.0f;
    theta1 = (float)_iStartVSlice*fRhoStep - _PI2_;
    theta2 = theta1 + fRhoStep;    
	  
	for (cJ=_iStartVSlice;cJ<_iEndVSlice;cJ++)
    {			 
		cs_t1  = cos(theta1);
		cs_t2  = cos(theta2);
	    sn_t1  = sin(theta1);
		sn_t2  = sin(theta2);       

        u      = 0;
        theta3 = 0.0f;

        for (cI=0;cI<=_iNumHSlices;cI++)
        {
            cs_t3 = cos(theta3);
            sn_t3 = sin(theta3);    
				         
			x1 = cs_t1 * cs_t3;
            y1 = cs_t1 * sn_t3;
            z1 = sn_t1;             
				
			x2 = cs_t2 * cs_t3;
            y2 = cs_t2 * sn_t3;
            z2 = sn_t2;                 
			
			poMesh->VXs[iIdx].V3(x1,y1,z1);
			poMesh->UVs[iIdx].V2(u*_fUTiling,v*_fVTiling);
			iIdx++;

			poMesh->VXs[iIdx].V3(x2,y2,z2);
			poMesh->UVs[iIdx].V2(u*_fUTiling,(v + fVStep)*_fVTiling);
			
			iIdx++;


			u      += fUStep;
            theta3 += fPhiStep;
        }            
		
		v      += fVStep;
        theta1 += fRhoStep;
        theta2 += fRhoStep;
    }	
	
	// Fog affects skydome?
	FogAffected = _bFogAffected;
  //## end CSkyDome::CreateDome%1001452003.body
}

void CSkyDome::Render ()
{
  //## begin CSkyDome::Render%1001452004.body preserve=yes	
	if (! FogAffected)
		gpoE3DRenderer->SetFogPars(eE3D_FM_None,0,0,0,NULL);

	gpoE3DRenderer->PushMatrix();

	gpoE3DRenderer->Translate(Pos.X(),Pos.Y(),Pos.Z());
	gpoE3DRenderer->Rotate(fRot,Axis.X(),Axis.Y(),Axis.Z());
	gpoE3DRenderer->Scale(fRadius,fRadius,fRadius);

	CObject3D_Leaf::Render();

	gpoE3DRenderer->PopMatrix();
	
	if (! FogAffected)	
		gpoE3DRenderer->SetFogPars(eE3D_FM_Last,0,0,0,NULL);	 
  //## end CSkyDome::Render%1001452004.body
}

// Additional Declarations
  //## begin CSkyDome%3BB0F0530382.declarations preserve=yes
  //## end CSkyDome%3BB0F0530382.declarations

//## begin module%3BB0F0530382.epilog preserve=yes
//## end module%3BB0F0530382.epilog
