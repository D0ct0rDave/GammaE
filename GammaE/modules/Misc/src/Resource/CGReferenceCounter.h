//-----------------------------------------------------------------------------
#ifndef CGReferenceCounterH
#define CGReferenceCounterH
//-----------------------------------------------------------------------------
#include "Logging/CGWarningLC.h"
//-----------------------------------------------------------------------------
class CGReferenceCounter
{
public:
	CGReferenceCounter() : m_uiNumRefs(0) { };
	~CGReferenceCounter()
	{
		if (m_uiNumRefs>0)
			CGWarningLC::I()->Write("object referenced deleted");
	};

	void Ref() { m_uiNumRefs ++; };
	virtual void Deref() { m_uiNumRefs--; };
	uint uiNumRefs() { return(m_uiNumRefs); };
	
protected:
	uint m_uiNumRefs;
};

//-----------------------------------------------------------------------------
#endif //  CGReferenceCounterH
//-----------------------------------------------------------------------------