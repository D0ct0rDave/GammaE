#include "GammaE_Mem.h"

// CObject3D_AnimCfg
#include "Animation\CObject3D_AnimCfg.h"

// Class CObject3D_AnimCfg

CObject3D_AnimCfg::CObject3D_AnimCfg()
    : iNumFrameAnims(0), iCurrentFrameAnim(0), fCurrentTime(0), iLastFrame(-1)
{
    TypeID = e3DObj_AnimCfg;
}

CObject3D_AnimCfg::~CObject3D_AnimCfg()
{
    if (FrameAnim)
        mDel [] FrameAnim;

    if (AnimObj)
        AnimObj->Deref();
}

void CObject3D_AnimCfg::CreateFrameAnims (int _iNumFrameAnims)
{
    iNumFrameAnims = _iNumFrameAnims;
    FrameAnim = mNew TFrameAnimation[_iNumFrameAnims];
}

void CObject3D_AnimCfg::SetupFrameAnim (int _iFrameAnim, int _iInitialFrame, int _iFinalFrame, float _fFrameAnimTime, bool _bLoop)
{
    assert (FrameAnim && "NULL frame anim");
    assert ( ( _iFrameAnim < iNumFrameAnims ) && "Object out of bounds" );

    FrameAnim[_iFrameAnim].InitialFrame = _iInitialFrame;
    FrameAnim[_iFrameAnim].FinalFrame   = _iFinalFrame;
    FrameAnim[_iFrameAnim].TotalTime    = _fFrameAnimTime;
    FrameAnim[_iFrameAnim].bLoop        = _bLoop;

    if (_iFinalFrame > _iInitialFrame)
        FrameAnim[_iFrameAnim].FrameTime = _fFrameAnimTime / ( _iFinalFrame - _iInitialFrame + 1 );
    else
        FrameAnim[_iFrameAnim].FrameTime = 10000000.0f;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   // x/0	infinite

}

void CObject3D_AnimCfg::SetFrameAnim (int iFrameAnim)
{
    iCurrentFrameAnim = iFrameAnim;
    fCurrentTime      = 0;
}

CGraphBV *CObject3D_AnimCfg::poGetBoundVol ()
{
    return( AnimObj->poGetBoundVol() );
}

void CObject3D_AnimCfg::ComputeBoundVol ()
{
   AnimObj->ComputeBoundVol();
}

void CObject3D_AnimCfg::Render ()
{
    assert ( FrameAnim );

    if (CGRenderer::I()->REStats.iCurrentFrame != iLastFrame)
    {
        iLastFrame = CGRenderer::I()->REStats.iCurrentFrame;

        unsigned int iCurrFrame;
        unsigned int iNextFrame;
        unsigned int iRealFrame;

        float fFactor;
        float fFrameAnimTime;
        float fFrame;

         // Tiempo total desde la primera llamada a GetMesh
        fCurrentTime += CGRenderer::I()->REStats.DTime;

         // Tiempo transcurrido dentro de la actual animación
        fFrameAnimTime = fmod(fCurrentTime,FrameAnim[iCurrentFrameAnim].TotalTime);

         // Frame que toca relativo al frame inicial de la animación
        fFrame     = fFrameAnimTime / FrameAnim[iCurrentFrameAnim].FrameTime;
        iCurrFrame = (int) fFrame;

         // Factor de cercanía hacia el siguiente frame: (->1 muy cerca de siguiente frame)
        fFactor    = fFrame - iCurrFrame;

         // Frame real dentro de la tabla de frames
        iRealFrame = FrameAnim[iCurrentFrameAnim].InitialFrame + iCurrFrame;

         // Setup next frame
        if (iRealFrame >= FrameAnim[iCurrentFrameAnim].FinalFrame)
        {
            if (FrameAnim[iCurrentFrameAnim ].bLoop)
                iNextFrame = FrameAnim[iCurrentFrameAnim ].InitialFrame;
            else
            {
                iNextFrame = FrameAnim[iCurrentFrameAnim].FinalFrame - 1;
                fFactor = 0.0f;
            }
        }
        else
            iNextFrame = iRealFrame + 1;

        AnimObj->SetAnimState(iRealFrame,iNextFrame,fFactor);
    }

    AnimObj->Render();
} // Render

// Additional Declarations
