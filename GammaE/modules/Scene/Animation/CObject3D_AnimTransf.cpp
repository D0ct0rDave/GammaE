//## begin module%3B9E18660043.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B9E18660043.cm

//## begin module%3B9E18660043.cp preserve=no
//## end module%3B9E18660043.cp

//## Module: CObject3D_AnimTransf%3B9E18660043; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\Animation\CObject3D_AnimTransf.cpp

//## begin module%3B9E18660043.additionalIncludes preserve=no
//## end module%3B9E18660043.additionalIncludes

//## begin module%3B9E18660043.includes preserve=yes
//## end module%3B9E18660043.includes

// CObject3D_AnimTransf
#include "Scene\Animation\CObject3D_AnimTransf.h"
//## begin module%3B9E18660043.additionalDeclarations preserve=yes
//## end module%3B9E18660043.additionalDeclarations


// Class CObject3D_AnimTransf 



CObject3D_AnimTransf::CObject3D_AnimTransf()
  //## begin CObject3D_AnimTransf::CObject3D_AnimTransf%.hasinit preserve=no
      : pTransStates(NULL)
  //## end CObject3D_AnimTransf::CObject3D_AnimTransf%.hasinit
  //## begin CObject3D_AnimTransf::CObject3D_AnimTransf%.initialization preserve=yes
  //## end CObject3D_AnimTransf::CObject3D_AnimTransf%.initialization
{
  //## begin CObject3D_AnimTransf::CObject3D_AnimTransf%.body preserve=yes
	TypeID = e3DObj_AnimTransf;
  //## end CObject3D_AnimTransf::CObject3D_AnimTransf%.body
}


CObject3D_AnimTransf::~CObject3D_AnimTransf()
{
  //## begin CObject3D_AnimTransf::~CObject3D_AnimTransf%.body preserve=yes
	if (pTransStates) delete []pTransStates;
  //## end CObject3D_AnimTransf::~CObject3D_AnimTransf%.body
}



//## Other Operations (implementation)
void CObject3D_AnimTransf::CreateStates (int _iNumStates)
{
  //## begin CObject3D_AnimTransf::CreateStates%1000332374.body preserve=yes
	iNumStates   = _iNumStates;
	pTransStates = new CMatrix4x4[iNumStates];
  //## end CObject3D_AnimTransf::CreateStates%1000332374.body
}

CGraphBV* CObject3D_AnimTransf::poGetBoundVol ()
{
  //## begin CObject3D_AnimTransf::poGetBoundVol%1000205759.body preserve=yes
	return (BVol);
  //## end CObject3D_AnimTransf::poGetBoundVol%1000205759.body
}

void CObject3D_AnimTransf::ComputeBoundVol ()
{
  //## begin CObject3D_AnimTransf::ComputeBoundVol%1000205760.body preserve=yes
	if (! BVol)
	{
		CVect3 Max,Min;
		
		Max.V3(0,0,0);
		Min.V3(0,0,0);

		BVol = CGraphBV_Manager::poCreate();
		BVol->Init(Max,Min);
	}
  //## end CObject3D_AnimTransf::ComputeBoundVol%1000205760.body
}

void CObject3D_AnimTransf::Render ()
{
  //## begin CObject3D_AnimTransf::Render%1000205761.body preserve=yes
	gpoE3DRenderer->MultiplyMatrix(&Trans);
  //## end CObject3D_AnimTransf::Render%1000205761.body
}

void CObject3D_AnimTransf::SetAnimState (int _iSrc, int _iDst, float _fFactor)
{
  //## begin CObject3D_AnimTransf::SetAnimState%1000245732.body preserve=yes
	assert (pTransStates       && "NULL Transform state array");
	
	// HACK!!! No slerp quaternion code
	// if (_fFactor > 0.5f) _fFactor = 1.0f; else _fFactor = 0.0f;
	
	if (iNumStates == 1)
	{
		Trans = pTransStates[0];
	}
	else
	{
		if (_iSrc >= iNumStates) _iSrc = iNumStates-1;
		if (_iDst >= iNumStates) _iDst = iNumStates-1;		

		if ((_iSrc != _iDst) && (_fFactor>0.0f))
		{
			if (_fFactor < 1.0f)
			{
				CQuaternion SrcQuat,DstQuat,ResQuat;
				CVect4		SrcPos,DstPos,ResPos;
				
				// Interpolate rotations
				SrcQuat.FromMatrix( pTransStates[_iSrc] );
				DstQuat.FromMatrix( pTransStates[_iDst] );

				ResQuat.Slerp(SrcQuat,DstQuat,_fFactor);
				Trans = ResQuat.ToMatrix();

				// Interpolate positions
				SrcPos = pTransStates[_iSrc].GetColVector(3);
				DstPos = pTransStates[_iDst].GetColVector(3);

				ResPos.Interpolate(SrcPos,DstPos,_fFactor);	

				Trans.Set(0,3,ResPos.X());
				Trans.Set(1,3,ResPos.Y());
				Trans.Set(2,3,ResPos.Z());
			}
			else
			{
				Trans = pTransStates[_iDst];
			}
		}
		else	
			Trans = pTransStates[_iSrc];
	}
  //## end CObject3D_AnimTransf::SetAnimState%1000245732.body
}

CGraphBV * CObject3D_AnimTransf::poGetStateBVol (int _iState)
{
  //## begin CObject3D_AnimTransf::poGetStateBVol%1000479978.body preserve=yes
  
	return (BVol);
		
  //## end CObject3D_AnimTransf::poGetStateBVol%1000479978.body
}

// Additional Declarations
  //## begin CObject3D_AnimTransf%3B9E18660043.declarations preserve=yes
  //## end CObject3D_AnimTransf%3B9E18660043.declarations

//## begin module%3B9E18660043.epilog preserve=yes
//## end module%3B9E18660043.epilog
