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
#ifndef CHUDProgressBarH
#define CHUDProgressBarH
// -----------------------------------------------------------------------------
#include "GammaE_E3D.h"
#include "GammaE_Scene.h"

#include "CHUDObject.h"
// -----------------------------------------------------------------------------
class CHUDProgressBar : public CHUDObject
{
    public:     CHUDProgressBar();
        virtual ~CHUDProgressBar();

        void SetFrameShader(CGShader* _poShader);
        void SetBarShader(CGShader* _poShader);

        void SetIniColor(CGColor _oColor);
        void SetEndColor(CGColor _oColor);

        void Value(float _fValue);
        float fValue();

    protected:
        void WriteChar(char _cA);

        CGColor oIniColor;
        CGColor oEndColor;
        float m_fValue;

        CGShader* poFShader;
        CGShader* poBShader;
        CGShader* poDefBarSh;

        CGMesh* m_poBarMesh;
        CGSceneLeaf* m_poBarLeaf;
        CGSceneLeaf* m_poFrameLeaf;
};
// -----------------------------------------------------------------------------
inline float CHUDProgressBar::fValue()
{
    return (m_fValue);
}
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
