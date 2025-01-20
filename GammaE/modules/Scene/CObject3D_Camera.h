//## begin module%3AF714B70168.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AF714B70168.cm

//## begin module%3AF714B70168.cp preserve=no
//## end module%3AF714B70168.cp

//## Module: CObject3D_Camera%3AF714B70168; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\CObject3D_Camera.h

#ifndef CObject3D_Camera_h
#define CObject3D_Camera_h 1

//## begin module%3AF714B70168.additionalIncludes preserve=no
//## end module%3AF714B70168.additionalIncludes

//## begin module%3AF714B70168.includes preserve=yes
//## end module%3AF714B70168.includes

// CObject3D_Node
#include "Scene\CObject3D_Node.h"
//## begin module%3AF714B70168.additionalDeclarations preserve=yes
//## end module%3AF714B70168.additionalDeclarations


//## begin CObject3D_Camera%3AF714B70168.preface preserve=yes
//## end CObject3D_Camera%3AF714B70168.preface

//## Class: CObject3D_Camera%3AF714B70168
//## Category: Scene%3AA2567D00C8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CObject3D_Camera : public CObject3D_Node  //## Inherits: <unnamed>%3AF7155D0190
{
  //## begin CObject3D_Camera%3AF714B70168.initialDeclarations preserve=yes
  //## end CObject3D_Camera%3AF714B70168.initialDeclarations

  public:
    //## Constructors (generated)
      CObject3D_Camera();

    //## Destructor (generated)
      virtual ~CObject3D_Camera();


    //## Other Operations (specified)
      //## Operation: PreRender%1018461832
      virtual void PreRender ();

      //## Operation: Render%989269076
      virtual void Render ();

      //## Operation: PostRender%1018461833
      virtual void PostRender ();

      //## Operation: SetCamera%1018461835
      void SetCamera (CE3D_Camera* _poCamera);

      //## Operation: SetViewport%1018461837
      void SetViewport (CE3D_Viewport* _poViewport);

      //## Operation: SetProjector%1018461839
      void SetProjector (CE3D_Projector* _poProjector);

      //## Operation: poGetCamera%1018461834
      CE3D_Camera* poGetCamera ();

      //## Operation: poGetViewport%1018461836
      CE3D_Viewport * poGetViewport ();

      //## Operation: poGetProjector%1018461838
      CE3D_Projector* poGetProjector ();

    // Data Members for Class Attributes

      //## Attribute: poCam%3BD879EE03B2
      //## begin CObject3D_Camera::poCam%3BD879EE03B2.attr preserve=no  public: CE3D_Camera * {UA} NULL
      CE3D_Camera *poCam;
      //## end CObject3D_Camera::poCam%3BD879EE03B2.attr

      //## Attribute: poProj%3BD879F700D0
      //## begin CObject3D_Camera::poProj%3BD879F700D0.attr preserve=no  public: CE3D_Projector * {UA} NULL
      CE3D_Projector *poProj;
      //## end CObject3D_Camera::poProj%3BD879F700D0.attr

      //## Attribute: poVpt%3BD87A0D01B8
      //## begin CObject3D_Camera::poVpt%3BD87A0D01B8.attr preserve=no  public: CE3D_Viewport * {UA} NULL
      CE3D_Viewport *poVpt;
      //## end CObject3D_Camera::poVpt%3BD87A0D01B8.attr

    // Additional Public Declarations
      //## begin CObject3D_Camera%3AF714B70168.public preserve=yes
      //## end CObject3D_Camera%3AF714B70168.public

  protected:
    // Additional Protected Declarations
      //## begin CObject3D_Camera%3AF714B70168.protected preserve=yes
      //## end CObject3D_Camera%3AF714B70168.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: poOldCam%3CB4B47201BC
      //## begin CObject3D_Camera::poOldCam%3CB4B47201BC.attr preserve=no  private: CE3D_Camera * {UA} NULL
      CE3D_Camera *poOldCam;
      //## end CObject3D_Camera::poOldCam%3CB4B47201BC.attr

      //## Attribute: poOldProj%3CB4B47C03B5
      //## begin CObject3D_Camera::poOldProj%3CB4B47C03B5.attr preserve=no  private: CE3D_Projector * {UA} NULL
      CE3D_Projector *poOldProj;
      //## end CObject3D_Camera::poOldProj%3CB4B47C03B5.attr

      //## Attribute: poOldVpt%3CB4B4870194
      //## begin CObject3D_Camera::poOldVpt%3CB4B4870194.attr preserve=no  private: CE3D_Viewport* {UA} NULL
      CE3D_Viewport* poOldVpt;
      //## end CObject3D_Camera::poOldVpt%3CB4B4870194.attr

    // Additional Private Declarations
      //## begin CObject3D_Camera%3AF714B70168.private preserve=yes
      //## end CObject3D_Camera%3AF714B70168.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CObject3D_Camera%3AF714B70168.implementation preserve=yes
      //## end CObject3D_Camera%3AF714B70168.implementation

};

//## begin CObject3D_Camera%3AF714B70168.postscript preserve=yes
//## end CObject3D_Camera%3AF714B70168.postscript

// Class CObject3D_Camera 


//## Other Operations (inline)
inline void CObject3D_Camera::SetCamera (CE3D_Camera* _poCamera)
{
  //## begin CObject3D_Camera::SetCamera%1018461835.body preserve=yes
	poCam = _poCamera;
  //## end CObject3D_Camera::SetCamera%1018461835.body
}

inline void CObject3D_Camera::SetViewport (CE3D_Viewport* _poViewport)
{
  //## begin CObject3D_Camera::SetViewport%1018461837.body preserve=yes
	poVpt = _poViewport;
  //## end CObject3D_Camera::SetViewport%1018461837.body
}

inline void CObject3D_Camera::SetProjector (CE3D_Projector* _poProjector)
{
  //## begin CObject3D_Camera::SetProjector%1018461839.body preserve=yes
	poProj = _poProjector;
  //## end CObject3D_Camera::SetProjector%1018461839.body
}

inline CE3D_Camera* CObject3D_Camera::poGetCamera ()
{
  //## begin CObject3D_Camera::poGetCamera%1018461834.body preserve=yes
	return(poCam);
  //## end CObject3D_Camera::poGetCamera%1018461834.body
}

inline CE3D_Viewport * CObject3D_Camera::poGetViewport ()
{
  //## begin CObject3D_Camera::poGetViewport%1018461836.body preserve=yes
	return(poVpt);
  //## end CObject3D_Camera::poGetViewport%1018461836.body
}

inline CE3D_Projector* CObject3D_Camera::poGetProjector ()
{
  //## begin CObject3D_Camera::poGetProjector%1018461838.body preserve=yes
	return(poProj);
  //## end CObject3D_Camera::poGetProjector%1018461838.body
}

//## begin module%3AF714B70168.epilog preserve=yes
//## end module%3AF714B70168.epilog


#endif
