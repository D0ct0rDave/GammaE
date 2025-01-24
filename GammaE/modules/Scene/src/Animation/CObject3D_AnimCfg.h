//	  %X% %Q% %Z% %W%

#ifndef CObject3D_AnimCfg_h
#define CObject3D_AnimCfg_h 1

// CObject3D_AnimCfgGen
#include "Animation\CObject3D_AnimCfgGen.h"
// TFrameAnimation
#include "Animation\TFrameAnimation.h"
// CObject3D_AnimGen
#include "Animation\CObject3D_AnimGen.h"

class CObject3D_AnimCfg : public CObject3D_AnimCfgGen
{

public: CObject3D_AnimCfg();

    virtual ~CObject3D_AnimCfg();

    void CreateFrameAnims (int _iNumFrameAnims);

    void SetupFrameAnim (int _iFrameAnim, int _iInitialFrame, int _iFinalFrame, float _fFrameAnimTime, bool _bLoop);

    virtual void SetFrameAnim (int iFrameAnim);

    virtual CGraphBV *poGetBoundVol ();

    virtual void ComputeBoundVol ();

    virtual void Render ();

    CObject3D_AnimGen *GetAnimObj ();

    void SetAnimObj (CObject3D_AnimGen *_poAnimObj);

    TFrameAnimation *GetFrameAnim ();

    // Data Members for Class Attributes

    int iNumFrameAnims;

    int iCurrentFrameAnim;

    float fCurrentTime;

    int iLastFrame;

    // Data Members for Associations

    CObject3D_AnimGen *AnimObj;

    TFrameAnimation *FrameAnim;

     // Additional Public Declarations
protected:
     // Additional Protected Declarations
private:
     // Additional Private Declarations
private:
    // Additional Implementation Declarations
};

// Class CObject3D_AnimCfg

inline CObject3D_AnimGen *CObject3D_AnimCfg::GetAnimObj ()
{
    return( AnimObj );
}

inline void CObject3D_AnimCfg::SetAnimObj (CObject3D_AnimGen *_poAnimObj)
{
    AnimObj = _poAnimObj;
    AnimObj->Ref();
}

inline TFrameAnimation *CObject3D_AnimCfg::GetFrameAnim ()
{
    return FrameAnim;
}

#endif // ifndef CObject3D_AnimCfg_h
