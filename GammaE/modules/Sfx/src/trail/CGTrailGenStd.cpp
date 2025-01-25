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
#include "CGTrailGenStd.h"
#include "CGTrailInstance.h"
// ----------------------------------------------------------------------------
class CGTrailStd : public CGTrail
{
    public:
        CGTrailStd(uint _uiMaxPoints);
        virtual void SetPos(const CGVect3& _oPos);
        virtual void Update(float _fDeltaT);

        void AddPoint(const CGVect3& _oPos);

    public:
        // /
        CCurve m_oCurve;
        CGStArray <CGVect3> m_oPoints;
        CGStArray <CGVect3> m_fTimes;
        CCurve m_oTimeCurve;

        // runtime fields
    public:
        float m_fIniEnergy;
        float m_fIniSize;
        float m_fEndSize;

        float m_fInitialUpdateTime;
        float m_fUpdateTime;

        CGVect3 m_oLastPoint;
};
// ----------------------------------------------------------------------------
CGTrailStd::CGTrailStd(uint _uiMaxPoints)
{
    m_oPoints.Init(_uiMaxPoints);
    m_fTimes.Init(_uiMaxPoints);
    m_oCurve.Init(m_oPoints.poBuff(),_uiMaxPoints);
    m_oTimeCurve.Init(m_fTimes.poBuff(),_uiMaxPoints);
}
// ----------------------------------------------------------------------------
void CGTrailStd::SetPos(const CGVect3& _oPos)
{
    // Update head conditions
    CGVect3 oPos(_oPos.x * 2.1f - 1.0f, _oPos.y * 1.8f - 1.0f,-2.0f);

    // Time to update ?
    if ( m_fUpdateTime <= 0.0f )
    {
        // Time to update the curve control points!
        if ( m_oPoints.uiNumElems() == 0 )
        {
            // Add the point to the list
            AddPoint(oPos);
            m_oLastPoint = oPos;
        }
        else
        {
            // Set previous updated point as the last point
            // m_oPoints[m_oPoints.uiNumElems()-2] = m_oLastPoint;
            m_oPoints[m_oPoints.uiNumElems() - 1] = m_oLastPoint;

            // Add the new point
            AddPoint(oPos);
            m_oLastPoint = oPos;
        }

        // Reset the timer
        m_fUpdateTime = m_fInitialUpdateTime;
    }
    else
    {
        // Substitute the last point by this
        // m_oPoints[m_oPoints.uiNumElems()-2] = oPos;
        if ( m_oPoints.uiNumElems() > 0 )
        {
            m_oPoints[m_oPoints.uiNumElems() - 1] = oPos;
            // m_oPoints[m_oPoints.uiNumElems()-2] = oPos;
        }
    }
}
// ----------------------------------------------------------------------------
void CGTrailStd::AddPoint(const CGVect3& _oPos)
{
    if ( m_oPoints.uiNumElems() == m_oPoints.uiMaxElems() )
    {
        m_oPoints.Del(0);
        m_fTimes.Del(0);
    }

    // Add the point to the list
/*
    if (m_oPoints.uiNumElems()>0)
    {
        m_oPoints.Del( m_oPoints.uiNumElems() -1);
    }

    m_oPoints.iAdd(_oPos);
 */
    m_oPoints.iAdd(_oPos);

    // Set point initial energy
    CGVect3 oT;
    oT.x = m_fIniEnergy;
    m_fTimes.iAdd( oT );

    m_oCurve.Init( m_oPoints.poBuff(), m_oPoints.uiNumElems() );
    m_oTimeCurve.Init( m_fTimes.poBuff(), m_fTimes.uiNumElems() );
}
// ----------------------------------------------------------------------------
void CGTrailStd::Update(float _fDeltaT)
{
    // Update times
    uint i = 0;
    while ( i < m_fTimes.uiNumElems() )
    {
        m_fTimes[i].x -= _fDeltaT;

        if ( m_fTimes[i].x <= 0.0f )
            m_fTimes[i].x = 0.0f;

        i++;
    }

    // Update UpdateTime
    m_fUpdateTime -= _fDeltaT;

    if ( m_fUpdateTime <= 0.0f )
        m_fUpdateTime = 0.0f;
}
// ----------------------------------------------------------------------------
CGTrail* CGTrailGenStd::poCreateInstanceData()
{
    CGTrailStd* poStd = mNew CGTrailStd(m_uiMaxPoints);
    return(poStd);
}
// ----------------------------------------------------------------------------
void CGTrailGenStd::InitTrail(CGTrail* _poTrail)
{
    CGTrailStd* poTrail = (CGTrailStd*)_poTrail;

    // Set initial energy
    poTrail->m_fIniEnergy = m_fIniEnergy * (1.0f + MATH_fSRand() * m_fRndEnergy);
    float f1OverEnergy = 1.0f / poTrail->m_fIniEnergy;

    // Initialize Size
    poTrail->m_fIniSize = m_fIniSize * (1.0f + MATH_fSRand() * m_fIniRndSize);
    poTrail->m_fEndSize = m_fEndSize * (1.0f + MATH_fSRand() * m_fEndRndSize);

    poTrail->m_fUpdateTime = 0.0f;                      // Add first point at the very begining
    poTrail->m_fInitialUpdateTime = m_fUpdateTime;
}
// ----------------------------------------------------------------------------
void CGTrailGenStd::UpdateTrail(CGTrail* _poTrail,float _fDeltaT)
{
    CGTrailStd* poTrail = (CGTrailStd*)_poTrail;
    poTrail->Update(_fDeltaT);
}
// ----------------------------------------------------------------------------
void CGTrailGenStd::InitInstance(CGTrailInstance* _poInst)
{
    CGTrailStd* poData = (CGTrailStd*)_poInst->poGetTrailData();
    InitTrail(poData);
}
// ----------------------------------------------------------------------------
void CGTrailGenStd::UpdateInstance(CGTrailInstance* _poInst,float _fDeltaT)
{
    CGTrailStd* poTrail = (CGTrailStd*)_poInst->poGetTrailData();

    // Also adds new pending points
    UpdateTrail(poTrail,_fDeltaT);

    if ( poTrail->m_oPoints.uiNumElems() < 4 ) return;

    // Generate geometry
    CGVect3 oVX[4];
    CVect2 oUV[4];
    CGColor oVC[4];

    CGVect3 oP1,oU1;
    CGVect3 oT;
    float fFact;
    CGColor oColor1;

    uint uiNumSubdivisions = m_uiMaxDivisions * ( (float)poTrail->m_oPoints.uiNumElems() / (float)m_uiMaxPoints );

    float fStep = 1.0f / (float)uiNumSubdivisions;
    float fX = 1.0f;

    CGVect3 oP0 = poTrail->m_oCurve.oPos( 1.0f );

    uint uiNumBBs = 0;
    bool bLastBB = false;
    while ( (bLastBB == false) && (uiNumBBs < uiNumSubdivisions) )
    {
        CGVect3 oP1 = poTrail->m_oCurve.oPos(fX - fStep);
        oT = poTrail->m_oTimeCurve.oPos(fX - fStep);
        fFact = 1.0f - (oT.x / poTrail->m_fIniEnergy);

        // Last billboard ???
        bLastBB = (oT.x <= 0.0f);

        oU1 = oP1;
        oU1.Sub(oP0);

        // Generate an up vector
        float aux = oU1.y;
        oU1.y = -oU1.x;
        oU1.x = aux;
        oU1.Normalize();

        // Size
        oU1.Scale( MATH_fLerp(poTrail->m_fIniSize,poTrail->m_fEndSize,fFact) );

        // the color
        oColor1.Lerp(m_oIniColor,m_oEndColor,fFact);

        // The first one cannot be computed, so use the same as the second point
        if ( fX == 1.0f )
        {
            // Get first point
            oVX[0] = oP0;
            oVX[0].Sub(oU1);
            oVX[1] = oP0;
            oVX[1].Add(oU1);

            oUV[0].V2(1.0f,0.0f);
            oUV[1].V2(1.0f,1.0f);

            oVC[0] = oColor1;
            oVC[1] = oColor1;
        }
        else
        {
            oVX[0] = oVX[3];
            oVX[1] = oVX[2];

            oUV[0] = oUV[3];
            oUV[1] = oUV[2];

            oVC[0] = oVC[3];
            oVC[1] = oVC[2];
        }

        // Build geometry
        oVX[2] = oP1;
        oVX[2].Add(oU1);
        oVX[3] = oP1;
        oVX[3].Sub(oU1);

        oUV[2].V2(fX - fStep,1.0f);
        oUV[3].V2(fX - fStep,0.0f);

        oVC[2] = oColor1;
        oVC[3] = oColor1;

        m_poBBR->AddBillboards(oVX,oUV,oVC,1);

        // Next loop
        oP0 = oP1;
        fX -= fStep;
        uiNumBBs++;
    }

    /*
       // Draw control points
       for (uint i=0;i<poTrail->m_oPoints.uiNumElems();i++)
       {
        CGVect3 oX = CGVect3::oX();
        CGVect3 oY = CGVect3::oY();
        oX.Scale(0.05f);
        oY.Scale(0.05f);

        // Build geometry
        oVX[0] = poTrail->m_oPoints[i]; oVX[0].Sub(oX);	oVX[0].Sub(oY);
        oVX[1] = poTrail->m_oPoints[i]; oVX[1].Sub(oX);	oVX[1].Add(oY);
        oVX[2] = poTrail->m_oPoints[i]; oVX[2].Add(oX);	oVX[2].Add(oY);
        oVX[3] = poTrail->m_oPoints[i]; oVX[3].Add(oX);	oVX[3].Sub(oY);

        oUV[0].V2(0.0f,0.0f);
        oUV[1].V2(0.0f,1.0f);
        oUV[2].V2(1.0f,1.0f);
        oUV[3].V2(1.0f,0.0f);

        oVC[0].Set(1,1,1,1);
        oVC[1].Set(1,1,1,1);
        oVC[2].Set(1,1,1,1);
        oVC[3].Set(1,1,1,1);

        m_poBBR->AddBillboards(oVX,oUV,oVC,1);
       }
     */
}
// ----------------------------------------------------------------------------
