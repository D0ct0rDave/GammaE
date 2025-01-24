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
#ifndef CGResourceH
#define CGResourceH
// ----------------------------------------------------------------------------
#include "CGReferenceCounter.h"
// ----------------------------------------------------------------------------
class CGResource : public CGReferenceCounter
{
    public:
        CGResource() : m_bValid(false)
        {
        }

        virtual void Invalidate()
        {
            m_bValid = false;
        }
        virtual void Validate()
        {
            m_bValid = true;
        }
        virtual bool bValid()
        {
            return(m_bValid);
        }

    private:
        bool m_bValid;
};
// ----------------------------------------------------------------------------
#endif // CGResourceH
// ----------------------------------------------------------------------------
