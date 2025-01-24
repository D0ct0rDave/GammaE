// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#include "GammaE_Mem.h"
#include "Animation\CGSceneAnimCfg.h"
// --------------------------------------------------------------------------------
CGSceneAnimCfg::CGSceneAnimCfg()
{
    TypeID = OBJ3D_AnimCfg;
}
// --------------------------------------------------------------------------------
CGSceneAnimCfg::~CGSceneAnimCfg()
{
    m_oActions.Clear();
}
// --------------------------------------------------------------------------------
/*
   void CGSceneAnimCfg::Render ()
   {
    assert ( FrameAnim );

    if (CGRenderer::I()->REStats.iCurrentFrame != iLastFrame)
    {
        iLastFrame = CGRenderer::I()->REStats.iCurrentFrame;

        uint iCurrFrame;
        uint iNextFrame;
        uint iRealFrame;

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
                iNextFrame = FrameAnim[iCurrentFrameAnim].FinalFrame-1;
                fFactor = 0.0f;
            }
        }
        else
            iNextFrame = iRealFrame+1;

        AnimObj->SetAnimState(iRealFrame,iNextFrame,fFactor);
    }

    AnimObj->Render();
   }
 */
// --------------------------------------------------------------------------------
CGraphBV* CGSceneAnimCfg::poGetBoundVol()
{
    return( poGetAnimObj()->poGetKeyFrameBVol(0) );
}
// --------------------------------------------------------------------------------
