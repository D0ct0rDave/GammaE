//-----------------------------------------------------------------------------
#ifndef CGProgramWHH
#define CGProgramWHH
//-----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "CGProgram.h"
//-----------------------------------------------------------------------------
DECLARE_WAREHOUSE(CGProgramWH,CGDiskResourceWH,CGProgram)
{
    public:
		CGProgramWH();

		virtual CGProgram* poLoadResource(const CGString& _sFilename);
		void AlternatePath(const CGString& _sAternatePath) { m_sAlternatePath = _sAternatePath; }

    protected:
		CGString m_sAlternatePath;
};
//-----------------------------------------------------------------------------
#endif
