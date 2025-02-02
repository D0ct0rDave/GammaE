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
#ifndef CGTextResourceH
#define CGTextResourceH
// ----------------------------------------------------------------------------
#include "Resource/CGResource.h"
#include "Types/CGString.h"
// ----------------------------------------------------------------------------
class CGTextResource : public CGResource
{
    public:
        CGTextResource() : m_sText("")
        {
        }
        CGTextResource(const CGString& _sText)
        {
            m_sText = _sText;
        }

        const CGString& sGetData()
        {
            return (m_sText);
        }
        void SetData(const CGString& _sText)
        {
            m_sText = _sText;
        }

    protected:
        CGString m_sText;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
