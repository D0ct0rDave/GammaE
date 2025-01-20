//-----------------------------------------------------------------------------
#ifndef CHUDProgressBarH
#define CHUDProgressBarH
//-----------------------------------------------------------------------------
#include "GammaE_E3D.h"
#include "GammaE_Scene.h"

#include "CHUDObject.h"
//-----------------------------------------------------------------------------
class CHUDProgressBar : public CHUDObject
{
	public:		CHUDProgressBar();
				virtual ~CHUDProgressBar();

				void SetFrameShader(CE3D_Shader *_poShader);
				void SetBarShader  (CE3D_Shader *_poShader);

				void SetIniColor(CGColor _oColor);
				void SetEndColor(CGColor _oColor);

				void Value(float _fValue);
				float fValue();
				
	protected:	
				void WriteChar(char _cA);	

				CGColor			oIniColor;
				CGColor			oEndColor;
				float			m_fValue;
				
				CE3D_Shader*	poFShader;
				CE3D_Shader*	poBShader;				
				CE3D_Shader*	poDefBarSh;
				
				CMesh*			m_poBarMesh;
				CObject3D_Leaf*	m_poBarLeaf;
				CObject3D_Leaf*	m_poFrameLeaf;
};
//-----------------------------------------------------------------------------
inline float CHUDProgressBar::fValue()
{
	return (m_fValue);
}
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------