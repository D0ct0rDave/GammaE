// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGProgramWHH
#define CGProgramWHH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "CGProgram.h"
// -----------------------------------------------------------------------------
DECLARE_WAREHOUSE(CGProgramWH,CGDiskResourceWH,CGProgram)
{
    public:
        CGProgramWH();

        virtual CGProgram* poLoadResource(const CGString& _sFilename);
        void AlternatePath(const CGString& _sAternatePath)
        {
            m_sAlternatePath = _sAternatePath;
        }

    protected:
        CGString m_sAlternatePath;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
