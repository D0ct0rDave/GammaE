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
#ifndef CGCircularArrayH
#define CGCircularArrayH
// ----------------------------------------------------------------------------
#include "GMiscTypes.h"
// ----------------------------------------------------------------------------
template <class T>
class CGCircularArray
{
    public:

        CGCircularArray();
        CGCircularArray (uint _uiMaxElems);
        ~CGCircularArray();

        // / Initializes the static array with a specific capacity to store a maximum number of elements
        void Init(uint _uiMaxElems);

        // / Sets all the elements of the array as free
        void FreeAll();

        // / Retrieves a free element of the array
        T* poGet();

        // / Releases a used element of the array and sets it as free
        void Release(T* _poElem);

        // / Retrieves a determinate element of the array, NULL if it's free or not exists
        T* poElem(uint _uiIdx);

        // / Retrieves the maximum number of elements that could be stored
        uint uiMaxElems() const;

    protected:

        T* m_poElems;
        bool* m_bFree;
        int m_iHdrPos;
        uint m_uiMaxElems;
};
// ----------------------------------------------------------------------------
template <class T>
inline CGCircularArray <T>::CGCircularArray() : m_poElems(NULL), m_bFree(NULL), m_iHdrPos(-1), m_uiMaxElems(0)
{
}
// ----------------------------------------------------------------------------
template <class T>
inline CGCircularArray <T>::CGCircularArray (uint _uiMaxElems) : m_poElems(NULL), m_bFree(NULL), m_iHdrPos(-1), m_uiMaxElems(0)
{
    Init(_uiMaxElems);
}
// ----------------------------------------------------------------------------
template <class T>
inline CGCircularArray <T>::~CGCircularArray()
{
    if ( m_bFree ) mDel [] m_bFree;
    if ( m_poElems ) mDel [] m_poElems;
}
// ----------------------------------------------------------------------------
template <class T>
inline void CGCircularArray <T>::Init(uint _uiMaxElems)
{
    m_uiMaxElems = _uiMaxElems;
    m_iHdrPos = 0;

    m_poElems = mNew T[m_uiMaxElems];
    m_bFree = mNew bool[m_uiMaxElems];

    for ( uint uiElem = 0; uiElem < m_uiMaxElems; uiElem++ )
        m_bFree[uiElem] = true;
}
// ----------------------------------------------------------------------------
template <class T>
inline void CGCircularArray <T>::FreeAll()
{
    for ( uint uiElem = 0; uiElem < m_uiMaxElems; uiElem++ )
        m_bFree[uiElem] = true;

    m_iHdrPos = 0;
}
// ----------------------------------------------------------------------------
template <class T>
inline uint CGCircularArray <T>::uiMaxElems() const
{
    return(m_uiMaxElems);
}
// ----------------------------------------------------------------------------
template <class T>
inline T* CGCircularArray <T>::poGet()
{
    int iPos;

    if ( m_bFree[m_iHdrPos] )
        iPos = m_iHdrPos;
    else
    {
        int iOldHdrPos = m_iHdrPos;

        do {
            m_iHdrPos = (m_iHdrPos + 1) % m_uiMaxElems;
        } while ( (m_iHdrPos != iOldHdrPos) && (!m_bFree[m_iHdrPos]) );

        if ( m_iHdrPos == iOldHdrPos )
        {
            assert(1);
            return(NULL);
        }

        iPos = m_iHdrPos;
    }

    // Update Header
    m_iHdrPos = (m_iHdrPos + 1) % m_uiMaxElems;

    // Set as used element
    m_bFree  [iPos] = false;

    return(&m_poElems[iPos]);
}
// ----------------------------------------------------------------------------
template <class T>
inline void CGCircularArray <T>::Release(T* _poElem)
{
    size_t uiIdx = _poElem - m_poElems;
    m_bFree[uiIdx] = true;
}
// ----------------------------------------------------------------------------
template <class T>
inline T* CGCircularArray <T>::poElem(uint _uiIdx)
{
    if ( _uiIdx >= m_uiMaxElems ) return (NULL);

    if ( m_bFree[_uiIdx] )
        return(NULL);
    else
        return(&m_poElems[_uiIdx]);
}
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
