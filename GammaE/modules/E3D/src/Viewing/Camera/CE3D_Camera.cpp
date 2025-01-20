




// CE3D_Camera
#include "Viewing\Camera\CE3D_Camera.h"


// Class CE3D_Camera 







void CE3D_Camera::SetPos (float _fcX, float _fcY, float _fcZ)
{
  	Pos.V3(_fcX,_fcY,_fcZ);
}

void CE3D_Camera::SetDir (float _fPitch, float _fYaw, float _fRoll)
{
    float cosP,cosY,cosR;
    float sinP,sinY,sinR;

    cosP = cosf(_fPitch);
    sinP = sinf(_fPitch);
    cosY = cosf(_fYaw);
    sinY = sinf(_fYaw);
    cosR = cosf(_fRoll);
    sinR = sinf(_fRoll);

    // Forward vector
    Dir.x = sinY*cosP;
    Dir.y = sinP;
    Dir.z = cosP*(-cosY);

    // Up vector
    Up.x = -cosY*sinR - sinY*sinP*cosR;
    Up.y = cosP*cosR;
    Up.z = -sinY*sinR - sinP*cosR*(-cosY);

    // Side vector
    Side.CrossProd(Dir,Up);	
}

void CE3D_Camera::SetVectors (CVect3& cDir, CVect3& cUp, CVect3& cSide)
{
  	Dir.Assign(cDir);
	Up.Assign(cUp);
	Side.Assign(cSide);
}

void CE3D_Camera::LookAt (CVect3& Center)
{
      Dir.Assign(Center);
	Dir.Sub(Pos);
	Dir.Normalize();
}

// Additional Declarations
    
