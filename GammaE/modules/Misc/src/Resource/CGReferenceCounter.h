// ----------------------------------------------------------------------------
/*! \class CGReferenceCounter
 *  \brief Basic reference counting functionality.
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGReferenceCounterH
#define CGReferenceCounterH
// ----------------------------------------------------------------------------
#include "Logging/CGWarningLC.h"
// ----------------------------------------------------------------------------
class CGReferenceCounter
{
    public:

        // / Constructor and initializer for the reference counted object.
        CGReferenceCounter() : m_uiNumRefs(0)
        {
        }

        // / Destructor of the reference counted object.
        ~CGReferenceCounter()
        {
            if ( m_uiNumRefs > 0 )
                CGWarningLC::I()->Write("referenced object deleted");
        }

        // / Increases the reference counter of this object.
        void Ref()
        {
            m_uiNumRefs++;
        }

        // / Decreases the reference counter of this object.
        virtual void Deref()
        {
            m_uiNumRefs--;
        }

        // / Retrieves the number of times this object is referenced.
        uint uiNumRefs()
        {
            return(m_uiNumRefs);
        }

    protected:

        // Holds the number of references of this object.
        uint m_uiNumRefs;
};
// ----------------------------------------------------------------------------
#endif // CGReferenceCounterH
// ----------------------------------------------------------------------------
