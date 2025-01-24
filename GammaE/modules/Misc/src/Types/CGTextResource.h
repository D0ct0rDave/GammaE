//-----------------------------------------------------------------------------
#ifndef CGTextResource_h
#define CGTextResource_h 1
//-----------------------------------------------------------------------------
#include "Resource/CGResource.h"
#include "Types/CGString.h"
//-----------------------------------------------------------------------------
class CGTextResource : public CGResource
{
	public:
		CGTextResource() : m_sText(""){ };
		CGTextResource(const CGString& _sText) { m_sText = _sText; };

		const CGString& sGetData() { return (m_sText); }
		void SetData(const CGString& _sText) { m_sText = _sText; }

	protected:
		CGString m_sText;
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
