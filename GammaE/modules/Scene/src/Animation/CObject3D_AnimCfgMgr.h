//	  %X% %Q% %Z% %W%

#ifndef CObject3D_AnimCfgMgr_h
#define CObject3D_AnimCfgMgr_h 1

// CObject3D_AnimCfgGen
#include "Animation\CObject3D_AnimCfgGen.h"
// CObject3D_AnimCfg
#include "Animation\CObject3D_AnimCfg.h"

class CObject3D_AnimCfgMgr : public CObject3D_AnimCfgGen
{

public: CObject3D_AnimCfgMgr();

    virtual ~CObject3D_AnimCfgMgr();

    void Init (int _iMaxAnimObjs);

    virtual void SetFrameAnim (int _iFrameAnim);

    virtual CGraphBV *poGetBoundVol ();

    virtual void ComputeBoundVol ();

    virtual void Render ();

    int AddAnimObj (CObject3D_AnimCfg *_pAnimObj);

    // Data Members for Class Attributes

    int iNumAnimObjs;

    int iMaxAnimObjs;

    CObject3D_AnimCfg * *pAnimObjs;

    int iCurrentFrame;

     // Additional Public Declarations
protected:
     // Additional Protected Declarations
private:
     // Additional Private Declarations
private:
    // Additional Implementation Declarations
};

// Class CObject3D_AnimCfgMgr

#endif // ifndef CObject3D_AnimCfgMgr_h
