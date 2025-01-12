//## begin module%3BD71A790383.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BD71A790383.cm

//## begin module%3BD71A790383.cp preserve=no
//## end module%3BD71A790383.cp

//## Module: CE3D_Camera%3BD71A790383; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Viewing\Camera\CE3D_Camera.h

#ifndef CE3D_Camera_h
#define CE3D_Camera_h 1

//## begin module%3BD71A790383.additionalIncludes preserve=no
//## end module%3BD71A790383.additionalIncludes

//## begin module%3BD71A790383.includes preserve=yes
//## end module%3BD71A790383.includes

// GammaE_Math
#include "Math\GammaE_Math.h"
//## begin module%3BD71A790383.additionalDeclarations preserve=yes
//## end module%3BD71A790383.additionalDeclarations


//## begin CE3D_Camera%3BD71A790383.preface preserve=yes
//## end CE3D_Camera%3BD71A790383.preface

//## Class: CE3D_Camera%3BD71A790383
//## Category: E3D::Viewing::Camera%3A9AD6830186
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BD8A10C004A;GammaE_Math { -> }

class CE3D_Camera 
{
  //## begin CE3D_Camera%3BD71A790383.initialDeclarations preserve=yes
  //## end CE3D_Camera%3BD71A790383.initialDeclarations

  public:
    //## Constructors (generated)
      CE3D_Camera();

    //## Destructor (generated)
      ~CE3D_Camera();


    //## Other Operations (specified)
      //## Operation: SetPos%1003953249
      void SetPos (float _fcX, float _fcY, float _fcZ);

      //## Operation: SetDir%1003953250
      void SetDir (float _fPitch, float _fYaw, float _fRoll);

      //## Operation: SetVectors%1003953251
      void SetVectors (CVect3& cDir, CVect3& cUp, CVect3& cSide);

      //## Operation: LookAt%1003953252
      void LookAt (CVect3& Center);

    // Data Members for Class Attributes

      //## Attribute: Pos%3BD71A990053
      //## begin CE3D_Camera::Pos%3BD71A990053.attr preserve=no  public: CVect3 {UA} 
      CVect3 Pos;
      //## end CE3D_Camera::Pos%3BD71A990053.attr

      //## Attribute: Dir%3BD71A9E03C2
      //## begin CE3D_Camera::Dir%3BD71A9E03C2.attr preserve=no  public: CVect3 {UA} 
      CVect3 Dir;
      //## end CE3D_Camera::Dir%3BD71A9E03C2.attr

      //## Attribute: Side%3BD71AA40230
      //## begin CE3D_Camera::Side%3BD71AA40230.attr preserve=no  public: CVect3 {UA} 
      CVect3 Side;
      //## end CE3D_Camera::Side%3BD71AA40230.attr

      //## Attribute: Up%3BD71AA8019F
      //## begin CE3D_Camera::Up%3BD71AA8019F.attr preserve=no  public: CVect3 {UA} 
      CVect3 Up;
      //## end CE3D_Camera::Up%3BD71AA8019F.attr

    // Additional Public Declarations
      //## begin CE3D_Camera%3BD71A790383.public preserve=yes
      //## end CE3D_Camera%3BD71A790383.public

  protected:
    // Additional Protected Declarations
      //## begin CE3D_Camera%3BD71A790383.protected preserve=yes
      //## end CE3D_Camera%3BD71A790383.protected

  private:
    // Additional Private Declarations
      //## begin CE3D_Camera%3BD71A790383.private preserve=yes
      //## end CE3D_Camera%3BD71A790383.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CE3D_Camera%3BD71A790383.implementation preserve=yes
      //## end CE3D_Camera%3BD71A790383.implementation

};

//## begin CE3D_Camera%3BD71A790383.postscript preserve=yes
//## end CE3D_Camera%3BD71A790383.postscript

// Class CE3D_Camera 

//## begin module%3BD71A790383.epilog preserve=yes
//## end module%3BD71A790383.epilog


#endif
