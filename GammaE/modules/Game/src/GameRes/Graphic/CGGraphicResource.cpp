// -----------------------------------------------------------------------------
#include "CGGraphicResource.h"
// -----------------------------------------------------------------------------
CGControlPoint* CGGraphicResource::poGetCP(const CGString& _sCPName)
{
	for (int i=0;i<m_oCPs.uiNumElems();i++)
		if (m_oCPs[i].m_sName == _sCPName)
			return (&m_oCPs[i]);

	return (NULL);
}
// -----------------------------------------------------------------------------