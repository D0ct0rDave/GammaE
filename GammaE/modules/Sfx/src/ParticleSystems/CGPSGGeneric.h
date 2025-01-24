// -----------------------------------------------------------------------------
#ifndef CGPSGGeneric_h
#define CGPSGGeneric_h 1
// -----------------------------------------------------------------------------

#include "CGParticleSystemGenerator.h"
#include "GammaE_E3D.h"

// -----------------------------------------------------------------------------
class CGPSGGeneric : public CGParticleSystemGenerator
{
	public:

		/// Sets color values for the generated particles. Initial Color is modulated by IRandomness, Final Color, is modulated by FRandomness
		void SetColorsPars(CGColor _oInitialColor, CGColor _oFinalColor,float _fICRandomness = 0.0f,float _fFCRandomness = 0.0f)
		{
			m_oInitialColor = _oInitialColor;
			m_oFinalColor   = _oFinalColor;
			m_fICRandomness = _fICRandomness;
			m_fFCRandomness = _fFCRandomness;
		}

		/// Sets the size parameters for the generated particles
		void SetSizePars(float _fInitialSize,float _fFinalSize,float _fISRandomness = 0.0f,float _fFSRandomness = 0.0f)
		{
			m_fInitialSize	= _fInitialSize;
			m_fFinalSize	= _fFinalSize;
			m_fISRandomness = _fISRandomness;
			m_fFSRandomness = _fFSRandomness;
		}

		/// Sets the angle parameters for the generated particles.
		void SetAnglePars(float _fInitialAngle,float _fFinalAngle,float _fIARandomness= 0.0f,float _fFARandomness= 0.0f)
		{
			m_fInitialAngle = _fInitialAngle;
			m_fFinalAngle	= _fFinalAngle;
			m_fIARandomness = _fIARandomness;
			m_fFARandomness = _fFARandomness;
		}

		/// Sets the parameters for the spatial placement of the particles over a sphere centered on the instance
		void SetRadiusPars(float _fInnerRadius,float _fOuterRadius,float _fIRRandomness= 0.0f,float _fORRandomness= 0.0f)
		{
			m_fInnerRadius  = _fInnerRadius;
			m_fOuterRadius  = _fOuterRadius;
			m_fIRRandomness = _fIRRandomness;
			m_fORRandomness = _fORRandomness;
		}
		
		/// Retrieves the initial color of the particles
		const CGColor& oGetInitialColor() { return(m_oInitialColor); };
		
		/// Retrieves the final color of the particles
		const CGColor& oGetFinalColor() { return(m_oFinalColor); };
		
		/// Retrieves the initial color randomness of the particles
		float fGetInitialColorRnds() { return(m_fICRandomness); };
		
		/// Retrieves the final color randomness of the particles
		float fGetFinalColorRnds() { return(m_fFCRandomness); };
	
		/// Retrieves the initial size of the particles
		float fGetInitialSize() { return(m_fInitialSize); };
		
		/// Retrieves the final size of the particles
		float fGetFinalSize() { return(m_fFinalSize); };
		
		/// Retrieves the final size randomness of the particles
		float fGetInitialSizeRnds() { return(m_fISRandomness); };
		
		/// Retrieves the final size randomness of the particles
		float fGetFinalSizeRnds() { return(m_fFSRandomness); };
		
		/// Retrieves the initial angle of the particles
		float fGetInitialAngle() { return(m_fInitialAngle); };
		
		/// Retrieves the final angle of the particles
		float fGetFinalAngle() { return(m_fFinalAngle); };
		
		/// Retrieves the initial angle randomness of the particles
		float fGetInitialAngleRnds() { return(m_fIARandomness); };
		
		/// Retrieves the final angle randmness of the particles
		float fGetFinalAngleRnds() { return(m_fFARandomness); };
		
		/// Retrieves the inner radius of the particle system generator
		float fGetInnerRadius() { return(m_fInnerRadius); };
		
		/// Retrieves the outer radius of the particle system generator
		float fGetOuterRadius() { return(m_fOuterRadius); };
		
		/// Retrieves the inner radius randomness of the particle system generator
		float fGetInnerRadiusRnds() { return(m_fIRRandomness); };
		
		/// Retrieves the outer radius randomness of the particle system generator
		float fGetOuterRadiusRnds() { return(m_fORRandomness); };

	protected:
		
		CGColor 		m_oInitialColor;
		CGColor 		m_oFinalColor;
		float   		m_fICRandomness;
		float   		m_fFCRandomness;

		float 			m_fInitialSize;
		float 			m_fFinalSize;
		float 			m_fISRandomness;
		float 			m_fFSRandomness;

		float 			m_fInitialAngle;
		float 			m_fFinalAngle;
		float 			m_fIARandomness;
		float 			m_fFARandomness;

		float 			m_fInnerRadius;
		float 			m_fOuterRadius;
		float 			m_fIRRandomness;
		float 			m_fORRandomness;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------

