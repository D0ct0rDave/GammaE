#ifndef CNETTimeStampListH
#define CNETTimeStampListH

#include "GammaE_Misc.h"

class CNETTimeStampList
{
	public:	 CNETTimeStampList();
			~CNETTimeStampList();
			
			bool bExists(unsigned int _uiTimeStamp);
			void Add(unsigned int _uiTimeStamp);

	protected:
			CGStArray<unsigned int> m_oTSL;
};

#endif