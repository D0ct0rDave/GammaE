// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
#include "CGTrailManager.h"
#include "CGTrailGenStd.h"
#include "CGTrailGenWH.h"
// ----------------------------------------------------------------------------
// Special node to which renders all the selfhandled particle system instances
class CGTrailManagerNode : public CGSceneGroup
{
    public:
        virtual void Render()
        {
            // Update the Manager
            CGTrailManager::I()->Update( CGRenderer::I()->oGetStats().m_fDelta);

            // Render all the objects of the PSI
            CGTrailManager::I()->m_poSceneNodeRenderer->Render();
        }
};
// ----------------------------------------------------------------------------
void CGTrailManager::Init()
{
    // The renderer for all billboards of the trails
    m_poSceneNodeRenderer = mNew CGBillboardRenderer(128,1000);

    // The scene node to render the trails
    m_poSceneNode = mNew CGTrailManagerNode;
}
// ----------------------------------------------------------------------------
CGTrailInstance* CGTrailManager::poGet(const CGString& _sType)
{
    CGTrailInstance* poInst = NULL;

    int iIdx = m_oGIList.iGetIdx(_sType);
    if ( iIdx == -1 )
    {
        // Find the generator
        CGTrailGenerator* poTG = CGTrailGenWH::I()->poFind(_sType);
        if ( poTG == NULL )
            return(NULL);

        // Create a (generator / instances) pair
        CGGenInstsPair* poGIP = mNew CGGenInstsPair;

        poGIP->m_poTG = poTG;
        poGIP->m_poTG->SetBillboardRenderer(m_poSceneNodeRenderer);
/*
        poGIP->m_poTG->SetMaxDivisions(100);
        poGIP->m_poTG->SetMaxPoints(25);
        poGIP->m_poTG->SetShader( CGShaderWH::I()->poCreateShader("particletex2alpha") );
        poGIP->m_poTG->SetEnergyPars(1.0f,0.0f);

        CGColor oIni(1,1,0.2,1);
        CGColor oEnd(1,0.2,0,0);
        ((CGTrailGenStd*)poGIP->m_poTG)->SetColorPars(oIni,oEnd);
        ((CGTrailGenStd*)poGIP->m_poTG)->SetScalePars(0.01f,0.0f,0.2f,0.0f);
 */
        // Create the list of instances
        poGIP->m_oInsts.Init(100);

        // Create the trail instance
        poInst = mNew CGTrailInstance(poGIP->m_poTG);
        poInst->Reinit();

        // Add the instance to the instance list
        poGIP->m_oInsts.iAdd(poInst);

        // Add this to the list of (Generator / instances) pair lists
        m_oGIList.uiAddVar(_sType, poGIP );
    }
    else
    {
        CGGenInstsPair* poGIP = m_oGIList[iIdx];

        // Create the trail instance
        poInst = mNew CGTrailInstance( poGIP->m_poTG );

        // Add the instance to the instance list
        poGIP->m_oInsts.iAdd(poInst);
    }

    return(poInst);
}
// ----------------------------------------------------------------------------
void CGTrailManager::Update(float _fDeltaT)
{
    m_poSceneNodeRenderer->Reset();

    for ( uint j = 0; j < m_oGIList.uiNumElems(); j++ )
    {
        CGGenInstsPair* poGIP = m_oGIList[j];

        m_poSceneNodeRenderer->Begin( poGIP->m_poTG->poGetShader() );

        for ( uint i = 0; i < poGIP->m_oInsts.uiNumElems(); i++ )
            poGIP->m_oInsts[i]->Update();

        m_poSceneNodeRenderer->End();
    }
}
// ----------------------------------------------------------------------------
