#include "CNETTimeStampList.h"


CNETTimeStampList::CNETTimeStampList()
{
	m_oTSL.Init(16);
}

CNETTimeStampList::~CNETTimeStampList()
{
	m_oTSL.Clear();
}
			
bool CNETTimeStampList::bExists(unsigned int _uiTimeStamp)
{
	for (int i=0;i<m_oTSL.uiNumElems();i++)
	{
		if ( m_oTSL[i] == _uiTimeStamp)
			return(true);
	}

	return(false);
}

void CNETTimeStampList::Add(unsigned int _uiTimeStamp)
{
	if (m_oTSL.uiNumElems() == m_oTSL.uiMaxElems())
		m_oTSL.Del(0);
	
	m_oTSL.iAdd(_uiTimeStamp);
}



