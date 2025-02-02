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
#ifndef CGLoggerH
#define CGLoggerH
// ----------------------------------------------------------------------------
#include "GMiscTypes.h"
// ----------------------------------------------------------------------------
class CGLogger
{
    public:
        CGLogger(uint _uiBufferSize = 65536);
        void Write(char* fmt,...);
        char* szGetBuffer()
        {
            return(m_pucBuffer);
        }
        void Clear();

    private:
        bool m_bValid;
        // CGDynArray<char*> m_Lines;
        char* m_pucBuffer;
        uint m_uiBufferSize;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
