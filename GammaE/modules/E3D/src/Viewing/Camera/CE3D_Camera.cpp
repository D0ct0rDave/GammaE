//## begin module%3BD71A790383.cm preserve=no
//## end module%3BD71A790383.cm

//## begin module%3BD71A790383.cp preserve=no
//## end module%3BD71A790383.cp

//## Module: CE3D_Camera%3BD71A790383; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\Viewing\Camera\CE3D_Camera.cpp

//## begin module%3BD71A790383.additionalIncludes preserve=no
//## end module%3BD71A790383.additionalIncludes

//## begin module%3BD71A790383.includes preserve=yes
//## end module%3BD71A790383.includes

// CE3D_Camera
#include "E3D\Viewing\Camera\CE3D_Camera.h"
//## begin module%3BD71A790383.additionalDeclarations preserve=yes
//## end module%3BD71A790383.additionalDeclarations


// Class CE3D_Camera 






CE3D_Camera::CE3D_Camera()
  //## begin CE3D_Camera::CE3D_Camera%.hasinit preserve=no
  //## end CE3D_Camera::CE3D_Camera%.hasinit
  //## begin CE3D_Camera::CE3D_Camera%.initialization preserve=yes
  //## end CE3D_Camera::CE3D_Camera%.initialization
{
  //## begin CE3D_Camera::CE3D_Camera%.body preserve=yes
  //## end CE3D_Camera::CE3D_Camera%.body
}


CE3D_Camera::~CE3D_Camera()
{
  //## begin CE3D_Camera::~CE3D_Camera%.body preserve=yes
  //## end CE3D_Camera::~CE3D_Camera%.body
}



//## Other Operations (implementation)
void CE3D_Camera::SetPos (float _fcX, float _fcY, float _fcZ)
{
  //## begin CE3D_Camera::SetPos%1003953249.body preserve=yes
	Pos.V3(_fcX,_fcY,_fcZ);
  //## end CE3D_Camera::SetPos%1003953249.body
}

void CE3D_Camera::SetDir (float _fPitch, float _fYaw, float _fRoll)
{
  //## begin CE3D_Camera::SetDir%1003953250.body preserve=yes
  	float cosP,cosY,cosR;
    float sinP,sinY,sinR;

    cosP = cosf(_fPitch);
    sinP = sinf(_fPitch);
    cosY = cosf(_fYaw);
    sinY = sinf(_fYaw);
    cosR = cosf(_fRoll);
    sinR = sinf(_fRoll);

    // Forward vector
    Dir.v[0] = sinY*cosP;
    Dir.v[1] = sinP;
    Dir.v[2] = cosP*(-cosY);

    // Up vector
    Up.v[0] = -cosY*sinR - sinY*sinP*cosR;
    Up.v[1] = cosP*cosR;
    Up.v[2] = -sinY*sinR - sinP*cosR*(-cosY);

    // Side vector
    Side.CrossProd(Dir,Up);	
  //## end CE3D_Camera::SetDir%1003953250.body
}

void CE3D_Camera::SetVectors (CVect3& cDir, CVect3& cUp, CVect3& cSide)
{
  //## begin CE3D_Camera::SetVectors%1003953251.body preserve=yes
	Dir.Assign(cDir);
	Up.Assign(cUp);
	Side.Assign(cSide);
  //## end CE3D_Camera::SetVectors%1003953251.body
}

void CE3D_Camera::LookAt (CVect3& Center)
{
  //## begin CE3D_Camera::LookAt%1003953252.body preserve=yes
    Dir.Assign(Center);
	Dir.Sub(Pos);
	Dir.Normalize();
  //## end CE3D_Camera::LookAt%1003953252.body
}

// Additional Declarations
  //## begin CE3D_Camera%3BD71A790383.declarations preserve=yes
  //## end CE3D_Camera%3BD71A790383.declarations

//## begin module%3BD71A790383.epilog preserve=yes
//## end module%3BD71A790383.epilog
