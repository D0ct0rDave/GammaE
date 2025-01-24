// ----------------------------------------------------------------------------
#ifndef CGTrailGenStd_h
#define CGTrailGenStd_h 1
// ----------------------------------------------------------------------------
#include "GammaE_Scene.h"
#include "BillBoard/CGBillboardRenderer.h"
#include "CGTrailGenerator.h"
// ----------------------------------------------------------------------------
class CGTrailGenStd : public CGTrailGenerator
{
	public:

		CGTrailGenStd() {};

		/// Initializes the trail generator
		virtual void Init(){};

		/// Creates a trail structure specific to the generator.
		virtual CGTrail* poCreateInstanceData();

        /// Generates the geometry associated for  the given instance
        virtual void UpdateInstance(CGTrailInstance* _poInst,float _fDeltaT);

		/// Initializes an independent instance
		virtual void InitInstance(CGTrailInstance* _poInst);

        /// Sets the initial and final color of the trail
        void SetColorPars(const CGColor& _oIniColor,const CGColor& _oEndColor)
        {
			m_oIniColor = _oIniColor;
			m_oEndColor = _oEndColor;
        }

        /// Sets the initial and random factor for the size
        void SetSizePars(float _fIniSize,float _fIniRndSize,float _fEndSize,float _fEndRndSize)
        {
			m_fIniSize		= _fIniSize;
			m_fIniRndSize	= _fIniRndSize;
			m_fEndSize		= _fEndSize;
			m_fEndRndSize	= _fEndRndSize;
        }
        
		/// Sets the time need to accept a new point as a control point for the trail
        void SetUpdateTimePar(float _fUpdateTime)
        {
			m_fUpdateTime = _fUpdateTime;
        }

	protected:
		
		/// Initializes an independent trail
		virtual void InitTrail(CGTrail* _poTrail);

		/// Updates an independent trail
		virtual void UpdateTrail(CGTrail* _poTrail,float _fDeltaT);
	
	protected:
		/// Initial color
		CGColor m_oIniColor;
		
		/// End Color
		CGColor m_oEndColor;
		
		/// Initial Size
		float	m_fIniSize;

		/// Random Initial Size Factor
		float	m_fIniRndSize;
		
		/// Final Size
		float	m_fEndSize;
		
		/// Random Final Size
		float	m_fEndRndSize;
		
		/// The time need to accept a new positions as a control point
		float m_fUpdateTime;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
