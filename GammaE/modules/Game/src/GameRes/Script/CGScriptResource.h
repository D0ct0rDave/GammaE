// -----------------------------------------------------------------------------
#ifndef CGScriptResourceH
#define CGScriptResourceH
// -----------------------------------------------------------------------------
#include "GammaE_Misc.h"
// -----------------------------------------------------------------------------
class CGScriptResource : public CGTextResource
{
public:
	CGScriptResource();
	~CGScriptResource();

	void Init();
	void Finish();
	void Think(float _fDeltaT,void* _pParams);

protected:

	/// Last execution was succesful
	bool    m_bLESuccessful;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------