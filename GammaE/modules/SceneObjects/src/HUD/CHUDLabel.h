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
#ifndef CHUDLabelH
#define CHUDLabelH
// -----------------------------------------------------------------------------
#include "CHUDObject.h"
#include "Font/CHUDFont.h"
// -----------------------------------------------------------------------------
class CHUDLabel : public CHUDObject
{
    public:     CHUDLabel();
        CHUDLabel(uint _uiMaxChars);
        virtual ~CHUDLabel();

        virtual CGBoundingVolume* poCreateBoundVol();

        void SetFont(CHUDFont* _poFont);
        void SetText(const CGString& _sText);
        void SetText(char* fmt,...);
        const CGString& sGetText();
        void SetColor(CGColor _oColor);

        void SetMaxChars(uint _uiMaxChars);

    protected:  void InternalInit(uint _uiMaxChars);
        void WriteChar(char _cA,float _fOfsX,float _fW);

        CHUDFont* poFont;
        CGSceneLeaf* poLeaf;
        CGString sText;
        CGColor oColor;
        uint uiMaxChars;
};
// -----------------------------------------------------------------------------
inline const CGString& CHUDLabel::sGetText()
{
    return (sText);
}
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
