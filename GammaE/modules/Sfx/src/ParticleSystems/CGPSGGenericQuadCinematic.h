// -----------------------------------------------------------------------------
#ifndef CGPSGGenericQuadCinematic_h
#define CGPSGGenericQuadCinematic_h 1
// -----------------------------------------------------------------------------
#include "CGParticle.h"
#include "CGPSGGeneric.h"
// -----------------------------------------------------------------------------
class CGPSGGenericQuadCinematicParticle : public CGParticle
{
    public:

        // Current values
        CGColor m_oColor;
        float m_fSize;
        float m_fAngle;
        float m_fRadius;

        // Delta vars
        CGColor m_oDColor;
        float m_fDSize;
        float m_fDAngle;
        float m_fDRadius;

        // Precomputed vars
        CGVect3 m_oPos;
        CGVect3 m_oDir;
        float m_fIEnergy;
};
// -----------------------------------------------------------------------------
class CGPSGGenericQuadCinematic : public CGParticleSystemGenerator
{
    public:
        // / Sets color values for the generated particles. Initial Color is modulated by IRandomness, Final Color, is modulated by FRandomness
        void SetColorsPars(CGColor _oInitialColor, CGColor _oFinalColor)
        {
            m_oInitialColor = _oInitialColor;
            m_oFinalColor = _oFinalColor;
        }

        // / Sets the size parameters for the generated particles
        void SetSizePars(float _fInitialSize,float _fRandomSize,float _fSizeSpeed = 0.0f,float _fRandomSizeSpeed = 0.0f,float _fAccelerationSize = 0.0f)
        {
            m_fInitialSize = _fInitialSize;
            m_fRandomSize = _fRandomSize;
            m_fSizeSpeed = _fSizeSpeed;
            m_fRandomSizeSpeed = _fRandomSizeSpeed;
            m_fAccelerationSize = _fAccelerationSize;
        }

        // / Sets the angle parameters for the generated particles.
        void SetAnglePars(float _fInitialAngle,float _fRandomAngle,float _fAngleSpeed = 0.0f,float _fRandomAngleSpeed = 0.0f)
        {
            m_fInitialAngle = _fInitialAngle;
            m_fRandomAngle = _fRandomAngle;
            m_fAngleSpeed = _fAngleSpeed;
            m_fRandomAngleSpeed = _fRandomAngleSpeed;
        }

        // / Sets the parameters for the spatial placement of the particles over a sphere centered on the instance
        void SetXPars(float _fXOfs,float _fXRandomOfs,float _fXSpeed = 0.0f,float _fRandomXSpeed = 0.0f,float _fXAcceleration = 0.0f)
        {
            m_fXOfs = _fXOfs;
            m_fXRandomOfs = _fXRandomOfs;
            m_fXSpeed = _fXSpeed;
            m_fRandomXSpeed = _fRandomXSpeed;
            m_fXAcceleration = _fXAcceleration;
        }

        // / Sets the parameters for the spatial placement of the particles over a sphere centered on the instance
        void SetYPars(float _fYOfs,float _fYRandomOfs,float _fYSpeed = 0.0f,float _fRandomYSpeed = 0.0f,float _fYAcceleration = 0.0f)
        {
            m_fYOfs = _fYOfs;
            m_fYRandomOfs = _fYRandomOfs;
            m_fYSpeed = _fYSpeed;
            m_fRandomYSpeed = _fRandomYSpeed;
            m_fYAcceleration = _fYAcceleration;
        }

        // / Sets the parameters for the spatial placement of the particles over a sphere centered on the instance
        void SetZPars(float _fZOfs,float _fZRandomOfs,float _fZSpeed = 0.0f,float _fRandomZSpeed = 0.0f,float _fZAcceleration = 0.0f)
        {
            m_fZOfs = _fZOfs;
            m_fZRandomOfs = _fZRandomOfs;
            m_fZSpeed = _fZSpeed;
            m_fRandomZSpeed = _fRandomZSpeed;
            m_fZAcceleration = _fZAcceleration;
        }

        // / Creates and initilaizes a pool of particles	specific to the generator.
        virtual CGParticle* poCreateParticlePool();

        // / Updates the particles of the particle system instance
        virtual void UpdateInstance(CGParticleSystemInstance& _oPSI,float _fDeltaT,const CGMatrix4x4& _oViewMatrix);

    protected:
        // / Initializes an independent particle of the particle system instance
        virtual void InitParticle(CGPSGGenericQuadCinematicParticle* _poPart);

        // / Updates an independent particle of the particle system instance
        virtual void UpdateParticle(CGPSGGenericQuadCinematicParticle* _poPart,float _fDeltaT);

        CGColor m_oInitialColor;
        CGColor m_oFinalColor;

        float m_fInitialSize;
        float m_fRandomSize;
        float m_fSizeSpeed;
        float m_fRandomSizeSpeed;
        float m_fAccelerationSize;

        float m_fFinalSize;
        float m_fISRandomness;
        float m_fFSRandomness;

        float m_fInitialAngle;
        float m_fRandomAngle;
        float m_fAngleSpeed;
        float m_fRandomAngleSpeed;

        float m_fFinalAngle;
        float m_fFARandomness;
        float m_fIARandomness;

        float m_fInnerRadius;
        float m_fIRRandomness;
        float m_fOuterRadius;
        float m_fORRandomness;

        float m_fXOfs;
        float m_fXRandomOfs;
        float m_fXSpeed;
        float m_fRandomXSpeed;
        float m_fXAcceleration;

        float m_fYOfs;
        float m_fYRandomOfs;
        float m_fYSpeed;
        float m_fRandomYSpeed;
        float m_fYAcceleration;

        float m_fZOfs;
        float m_fZRandomOfs;
        float m_fZSpeed;
        float m_fRandomZSpeed;
        float m_fZAcceleration;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
