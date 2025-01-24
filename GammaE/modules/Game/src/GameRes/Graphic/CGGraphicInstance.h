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
// -----------------------------------------------------------------------------
/*! \class CGGraphicInstance
 *  \brief A component that stores visible information of the instance of a resource
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
#ifndef CGGraphicInstanceH
#define CGGraphicInstanceH
// -----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "GammaE_Math.h"
#include "CGGraphicResource.h"
// -----------------------------------------------------------------------------
class CGGraphicInstance
{
    public:
        CGGraphicInstance();

        CGGraphicInstance(CGGraphicResource* _poResource);
        CGGraphicInstance(const CGString& _sResource);
        ~CGGraphicInstance();

        // / Initializes a the graphic instance of a given resource
        virtual void Init(const CGString& _sResource);

        // / Performs a engine step to update graphics
        virtual void Update(float _fDeltaT);

        // / Renders the instance
        virtual void Render();

        // / Set's the intance to be visible or not
        void Visible(bool _bEnable);

        // / Tells whether the instance is currently visible or not
        bool bVisible()
        {
            return(m_bVisible);
        }

        // / Set's up the position of the instance
        void Pos(const CVect3& _oPos)
        {
            m_oPos = _oPos;
            m_bDirty = true;
        }

        // / Retrieves the position of the instance
        CVect3& oPos()
        {
            return (m_oPos);
        }

        // / Sets'up the scale of the instance
        void Scale(float _fScale)
        {
            m_fScale = _fScale;
            m_bDirty = true;
        }

        // / Returns the scale of the instance
        float fScale()
        {
            return (m_fScale);
        }

        // / Sets the pitch angle for the instance
        void Pitch(float _fPitch)
        {
            m_fPitch = _fPitch;
            m_bDirty = true;
        }

        // / Retrieves the pitch angle of the instance
        float fPitch()
        {
            return(m_fPitch);
        }

        // / Sets the yaw angle for the current instance
        void Yaw(float _fYaw)
        {
            m_fYaw = _fYaw;
            m_bDirty = true;
        }

        // / Retrieves the yaw angle of the current instance
        float fYaw()
        {
            return(m_fYaw);
        }

        // / Sets the roll angle for the current instance
        void Roll(float _fRoll)
        {
            m_fRoll = _fRoll;
            m_bDirty = true;
        }

        // / Retrieves the roll angle of the current instance
        float fRoll()
        {
            return(m_fRoll);
        }

        // / Retrieves a reference of the instance's graphic object resource
        CGGraphicResource* poGraphicResource()
        {
            return (m_poResource);
        }

        // / Retrieves the transformation matrix of the instance
        const CMatrix4x4& oTransform()
        {
            if ( m_bDirty )
                UpdateTransform();

            return (m_oMat);
        }

        // / Sets the constant color for this entity
        void SetColor(const CGColor& _oColor)
        {
            m_oColor = _oColor;
        }

        // / Retrieves the constant color for this entity
        const CGColor& SetColor(const CGColor& _oColor) const
        {
            return(m_oColor);
        }

    protected:

        bool m_bVisible;

        // Transformation properties
        float m_fScale;

        float m_fPitch;
        float m_fYaw;
        float m_fRoll;

        CVect3 m_oPos;
        bool m_bDirty;
        CMatrix4x4 m_oMat;

        CGColor m_oColor;

        void UpdateTransform();
    private:
        // This part depends on the kind of representation we choose for this game: we can choose sprites or 3D objects, etc

        // Representation Dependent Part
        CGGraphicResource* m_poResource;

        // MEM_DynamicArray<CSFXObject*>	m_oFX;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
