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
#include "CGPSIManager.h"
#include "CGPSysGenWH.h"
// ----------------------------------------------------------------------------
// Special node to which renders all the selfhandled particle system instances
class CGPSIManagerNode : public CGSceneGroup
{
    public:
        // General Processing Functionalities.
        virtual void Accept(CGSceneVisitor* _poVisitor)
        {
            if (_poVisitor == CGSCNVRenderer::I())
            {
                // Update the PSIManager
                CGPSIManager::I()->Update(CGRenderer::I()->oGetStats().m_fDelta);
            }

            _poVisitor->Visit(this);
        }
};
// ----------------------------------------------------------------------------
#define INVALID_INDEX 0xffffffff
// ----------------------------------------------------------------------------
CGPSIManager::CGPSIManager()
{
    m_poRenderingNode = mNew CGPSIManagerNode();
    ( (CGPSIManagerNode*)m_poRenderingNode )->Init( 100 );
}
// ----------------------------------------------------------------------------
uint CGPSIManager::uiCreatePool(const CGString& _sType,uint _uiMaxInstances)
{
    CGParticleSystemGenerator* poPSG = CGPSysGenWH::I()->poFind(_sType);
    if ( poPSG == NULL ) return(-1);

    TPSIPool* poPSIs = mNew TPSIPool;
    poPSIs->Init(_uiMaxInstances);

    // Create instances for this specific particle system instance
    for ( uint i = 0; i < _uiMaxInstances; i++ )
    {
        TPSIData oData;

        oData.m_bFree = true;
        oData.m_bAutoManaged = false;
        oData.m_poPSI = mNew CGParticleSystemInstance(poPSG);
        oData.m_poTransf = mNew CGSceneTransf;
        oData.m_poTransf->SetObject( oData.m_poPSI );
        oData.m_uiNodeIdx = INVALID_INDEX;

        poPSIs->iAdd( oData );
    }

    // Add the pool to the pool table
    return( m_oPool.uiAddVar(_sType,poPSIs) );
}
// ----------------------------------------------------------------------------
CGPSIManager::TPSIData* CGPSIManager::poGetFreeInstance(uint _uiType)
{
    if ( _uiType > m_oPool.uiNumElems() ) return(NULL);
    TPSIPool* poPool = m_oPool[_uiType];

    for ( uint i = 0; i < poPool->uiNumElems(); i++ )
        if ( (*poPool)[i].m_bFree )
            return(&(*poPool)[i]);

    return(NULL);
}
// ----------------------------------------------------------------------------
CGParticleSystemInstance* CGPSIManager::poGet(const CGString& _sType)
{
    int iIdx = m_oPool.iGetIdx(_sType);
    return( poGet(iIdx) );
}
// ----------------------------------------------------------------------------
CGSceneTransf* CGPSIManager::poGet(const CGString& _sType,float _fEnergy,const CGVect3& _oPos)
{
    int iIdx = m_oPool.iGetIdx(_sType);
    return( poGet(iIdx,_fEnergy,_oPos) );
}
// ----------------------------------------------------------------------------
CGParticleSystemInstance* CGPSIManager::poGet(uint _uiType)
{
    TPSIData* poInst = poGetFreeInstance(_uiType);
    if ( poInst == NULL ) return(NULL);

    poInst->m_bFree = false;
    poInst->m_bAutoManaged = false;
    poInst->m_poPSI->Regenerate(true);
    poInst->m_poPSI->Enable();

    return(poInst->m_poPSI);
}
// ----------------------------------------------------------------------------
CGSceneTransf* CGPSIManager::poGet(uint _uiType,float _fEnergy,const CGVect3& _oPos)
{
    TPSIData* poInst = poGetFreeInstance(_uiType);
    if ( poInst == NULL ) return(NULL);

    poInst->m_fEnergy = _fEnergy;
    poInst->m_bFree = false;
    poInst->m_bAutoManaged = true;
    poInst->m_poTransf->SetPos(_oPos);
    poInst->m_poPSI->Enable();
    poInst->m_poPSI->Regenerate(true);

    // Add this PSI to the node of the Particle Instance Manager
    poInst->m_uiNodeIdx = ( (CGPSIManagerNode*)m_poRenderingNode )->iAddObject( poInst->m_poTransf );

    return(poInst->m_poTransf);
}
// ----------------------------------------------------------------------------
void CGPSIManager::Release(TPSIData* _poPSID)
{
    _poPSID->m_bFree = true;
    _poPSID->m_bAutoManaged = false;

    if ( _poPSID->m_uiNodeIdx != INVALID_INDEX )
    {
        // Increase reference counting to avoid automatic deletion on rendering node
        _poPSID->m_poTransf->Ref();

        ( (CGPSIManagerNode*)m_poRenderingNode )->DelObject( _poPSID->m_uiNodeIdx );

        _poPSID->m_uiNodeIdx = INVALID_INDEX;
        _poPSID->m_poPSI->Disable();
    }
}
// ----------------------------------------------------------------------------
void CGPSIManager::Release(CGParticleSystemInstance* _poPSI)
{
    for ( uint j = 0; j < m_oPool.uiNumElems(); j++ )
    {
        TPSIPool* poPool = m_oPool[j];

        for ( uint i = 0; i < poPool->uiNumElems(); i++ )
            if ( (*poPool)[i].m_poPSI == _poPSI )
                Release( &(*poPool)[i] );
    }
}
// ----------------------------------------------------------------------------
void CGPSIManager::Update(float _fDeltaT)
{
    for ( uint j = 0; j < m_oPool.uiNumElems(); j++ )
    {
        TPSIPool* poPool = m_oPool[j];

        for ( uint i = 0; i < poPool->uiNumElems(); i++ )
        {
            if ( (!(*poPool)[i].m_bFree) && (*poPool)[i].m_bAutoManaged )
            {
                if ( (*poPool)[i].m_fEnergy <= 0.0f )
                {
                    if ( (*poPool)[i].m_poPSI->bRegenerate() )
                        (*poPool)[i].m_poPSI->Regenerate(false);
                    else
                    {
                        // Wait until all the particles lose their energy
                        if ( (*poPool)[i].m_poPSI->uiLiveParticles() == 0 )
                            Release( &(*poPool)[i] );
                    }
                }
                else
                    (*poPool)[i].m_fEnergy -= _fDeltaT;
            }
        }
    }
}
// ----------------------------------------------------------------------------
