//-----------------------------------------------------------------------------
#ifndef CHUDLabelH
#define CHUDLabelH
//-----------------------------------------------------------------------------
#include "CHUDObject.h"
#include "Font/CHUDFont.h"
//-----------------------------------------------------------------------------
class CHUDLabel : public CHUDObject
{
	public:		CHUDLabel();
				CHUDLabel(uint _uiMaxChars);
				virtual ~CHUDLabel();

				virtual CGraphBV* poCreateBoundVol();

				void SetFont(CHUDFont* _poFont);
				void SetText(const CGString& _sText);
				void SetText(char *fmt,...);
				const CGString& sGetText();
				void SetColor(CGColor _oColor);

				void SetMaxChars(uint _uiMaxChars);

	protected:	void InternalInit(uint _uiMaxChars);
				void WriteChar(char _cA,float _fOfsX,float _fW);	
				
				CHUDFont		*poFont;
				CObject3D_Leaf	*poLeaf;
				CGString		sText;
				CGColor		oColor;
				uint			uiMaxChars;
};
//-----------------------------------------------------------------------------
inline const CGString& CHUDLabel::sGetText()
{
	return ( sText );
}
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------