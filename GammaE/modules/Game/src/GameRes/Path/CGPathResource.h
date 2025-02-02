// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#ifndef CGPathResourceH
#define CGPathResourceH
// -----------------------------------------------------------------------------
#include "CGPath.h"
// -----------------------------------------------------------------------------
class CGPathResource : public CGResource
{
    public:

        void SetPath(CGPath* _poPath)
        {
            m_poPath = _poPath;
        }
        CGPath* poGetPath()
        {
            return(m_poPath);
        }

    protected:

        // / Stores the path resource
        CGPath* m_poPath;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
