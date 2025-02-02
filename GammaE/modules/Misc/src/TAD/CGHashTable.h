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
#ifndef CGHashTableH
#define CGHashTableH
// ----------------------------------------------------------------------------
#include "utils/CRC.h"
#include "CGLookupArray.h"
#include "GMiscTypes.h"
// ----------------------------------------------------------------------------
template <class T>
class CGHashTable
{
    public:

        CGHashTable() : m_uiNumCols(0), m_poElems(NULL)
        {
        }
        CGHashTable(uint _uiNumCols)
        {
            Init(_uiNumCols);
        }

        ~CGHashTable()
        {
            Finish();
        }

        void Init (uint _uiNumCols)
        {
            Finish();

            m_uiNumCols = _uiNumCols;
            m_poElems = mNew CGLookupArray <T>[_uiNumCols];
        }

        void AddVar (const CGString& _sString, T _oValue)
        {
            int iIndex = uiGetIndex(_sString);
            m_poElems[iIndex].uiAddVar(_sString,_oValue);
        }

        T poGetVar (const CGString& _sString)
        {
            int iIndex = uiGetIndex(_sString);
            return ( m_poElems[iIndex].oGetVar(_sString) );
        }

        void Finish ()
        {
            if ( m_poElems )
            {
                m_poElems = NULL;
            }
        }

        void Invalidate ()
        {
            Finish();
            Init(m_uiNumCols);
        }

        uint uiNumCols()
        {
            return(m_uiNumCols);
        }

        CGLookupArray <T>* poGetList(uint _uiCol)
        {
            return(&m_poElems[_uiCol]);
        }

    protected:

        CGLookupArray <T>* m_poElems;

    private:

        uint uiGetIndex (const CGString& _sString)
        {
            return(Utils::uiCRCGenerate( _sString.szString(),_sString.uiLen() ) % m_uiNumCols);
        }

        uint m_uiNumCols;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
