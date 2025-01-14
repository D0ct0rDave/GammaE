//## begin module%3CD6F5C002C8.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CD6F5C002C8.cm

//## begin module%3CD6F5C002C8.cp preserve=no
//## end module%3CD6F5C002C8.cp

//## Module: CGPGraphicEntity%3CD6F5C002C8; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\Entities\CGPGraphicEntity.cpp

//## begin module%3CD6F5C002C8.additionalIncludes preserve=no
//## end module%3CD6F5C002C8.additionalIncludes

//## begin module%3CD6F5C002C8.includes preserve=yes
//## end module%3CD6F5C002C8.includes

// CGPGraphicEntity
#include "Game\Entities\CGPGraphicEntity.h"
//## begin module%3CD6F5C002C8.additionalDeclarations preserve=yes
//## end module%3CD6F5C002C8.additionalDeclarations


// Class CGPGraphicEntity 






CGPGraphicEntity::CGPGraphicEntity()
  //## begin CGPGraphicEntity::CGPGraphicEntity%.hasinit preserve=no
  //## end CGPGraphicEntity::CGPGraphicEntity%.hasinit
  //## begin CGPGraphicEntity::CGPGraphicEntity%.initialization preserve=yes
  //## end CGPGraphicEntity::CGPGraphicEntity%.initialization
{
  //## begin CGPGraphicEntity::CGPGraphicEntity%.body preserve=yes
  //## end CGPGraphicEntity::CGPGraphicEntity%.body
}


CGPGraphicEntity::~CGPGraphicEntity()
{
  //## begin CGPGraphicEntity::~CGPGraphicEntity%.body preserve=yes
  //## end CGPGraphicEntity::~CGPGraphicEntity%.body
}



//## Other Operations (implementation)
void CGPGraphicEntity::SetAngles (float _fRoll, float _fYaw, float _fPitch)
{
  //## begin CGPGraphicEntity::SetAngles%1020720914.body preserve=yes

	// Set player angles
	CMatrix4x4	M;	
	CVect3		oDir,oUp,oSide,oAux;

	M.LoadIdentity();	
	M.Rotate3f(0,_fYaw* _PI_OVER_180_,_fRoll* _PI_OVER_180_);

	// Dir vector
	oAux.V3(0.0f,1.0f,0.0f);
	M.TransformVector(oAux);
	oDir.Assign(oAux);
	oDir.Normalize();

	// Side vector
	oAux.V3(1.0f,0.0f,0.0f);
	M.TransformVector(oAux);
	oSide.Assign(oAux);
	oSide.Normalize();

	// Up vector
	oAux.V3(0.0f,0.0f,1.0f);
	M.TransformVector(oAux);
	oUp.Assign(oAux);
	oUp.Normalize();

	// Set model angles
	poModel->Setup( poModel->roPos(),oDir,oSide,oUp);

  //## end CGPGraphicEntity::SetAngles%1020720914.body
}

// Additional Declarations
  //## begin CGPGraphicEntity%3CD6F5C002C8.declarations preserve=yes
  //## end CGPGraphicEntity%3CD6F5C002C8.declarations

//## begin module%3CD6F5C002C8.epilog preserve=yes
//## end module%3CD6F5C002C8.epilog
