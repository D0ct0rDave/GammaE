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
#ifndef CGCoronaGenStd_h
#define CGCoronaGenStd_h 1
// ----------------------------------------------------------------------------
#include "GammaE_Scene.h"
#include "BillBoard/CGBillboardRenderer.h"
#include "CGCoronaGenerator.h"
// ----------------------------------------------------------------------------
typedef enum ECoronaFunction
{
    CF_None,

    CF_Sin,

    CF_NumFuncs
};
// ----------------------------------------------------------------------------
class CGCoronaGenStd : public CGCoronaGenerator
{
    public:

        CGCoronaGenStd()
        {
        }

        // / Initializes the corona generator
        virtual void Init()
        {
        }

        // / Creates a corona structure specific to the generator.
        virtual CGCorona* poCreateInstanceData();

        // / Generates the geometry associated for the given instance
        virtual void UpdateInstance(CGCoronaInstance* _poInst,float _fDeltaT);

        // / Initializes an independent instance
        virtual void InitInstance(CGCoronaInstance* _poInst);

        // / Sets the initial and final color of the corona
        void SetColorPars(const CGColor& _oIniColor,const CGColor& _oEndColor)
        {
            m_oIniColor = _oIniColor;
            m_oEndColor = _oEndColor;
        }

        // / Sets the parameters of the modification function of the corona
        void SetFuncPars(ECoronaFunction _eCF,float _fFreq)
        {
            m_eCF = _eCF;
            m_fFreq = _fFreq;
        }

        // / Sets the initial and final factor for the size
        void SetSizePars(float _fIniSize,float _fEndSize)
        {
            m_fIniSize = _fIniSize;
            m_fEndSize = _fEndSize;
        }

    protected:

        // / Updates an independent corona
        virtual void UpdateCorona(CGCorona* _poTrail,float _fDeltaT);

    protected:

        // / Initial color
        CGColor m_oIniColor;

        // / End Color
        CGColor m_oEndColor;

        // / Initial Size
        float m_fIniSize;

        // / Final Size
        float m_fEndSize;

        // / Frequency of the modification function
        float m_fFreq;

        // / Corona function
        ECoronaFunction m_eCF;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
