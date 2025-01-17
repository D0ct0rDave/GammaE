#ifndef CGameCamera_h
#define CGameCamera_h 1

#include "Game/Entities/CGameEntity.h"

class CGameCamera : public CGameEntity  //## Inherits: <unnamed>%3C1D29E9021B
{

  public:
      CGameCamera();

      ~CGameCamera();


      virtual void Think (float fDelta);

      float CorrectCamHeight (CVect3 &Src, CVect3 &Dst);

      void SetCamera (CE3D_Camera *_Cam);

      CVect3 Dir;
      CVect3 Up;
      CVect3 Side;

  protected:

  private:
      CE3D_Camera *Cam;

  private:
};


#endif
