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
#ifndef CGStArrayH
#define CGStArrayH
// ----------------------------------------------------------------------------
#include "GammaE_Mem.h"
#include "GMiscTypes.h"
#include <assert.h>
// ----------------------------------------------------------------------------
template <class T>
class CGStArray
{
    public:

        // / Default constructor
        CGStArray();

        // / Destructor
        ~CGStArray();

        // / Creates the static array with a specific capacity to store a maximum number of elements
        CGStArray(uint _uiMaxElems);

        // / Initializes the static array with a specific capacity to store a maximum number of elements
        void Init(uint _uiMaxElems);

        // / Inserts an element into the array
        int iAdd(const T& _oElem);

        // / Retrieves a free element of the array
        T& oGet();

        // / Deletes the given index element and displaces the rest to the left
        void Del(uint _uiIdx);

        // / Clears all the elements of the array
        void Clear();

        // / Retrieves the current number of stored elements
        uint uiNumElems() const;

        // / Retrieves the maximum number of elements that could be stored
        uint uiMaxElems() const;

        // / Operator to access to the given index element
        T& operator[](const uint _uiIdx) const;

        // / Retrieves a pointer to the buffer of elements
        T* poBuff() const;

    protected:

        // / The buffer of elements
        T* m_poElems;

        // / Current number of stored elements
        uint m_uiNumElems;

        // / The maximum number of elements
        uint m_uiMaxElems;
};
// ----------------------------------------------------------------------------
template <class T>
inline CGStArray <T>::CGStArray() : m_poElems(NULL), m_uiNumElems(0), m_uiMaxElems(0)
{
}
// ----------------------------------------------------------------------------
template <class T>
inline CGStArray <T>::CGStArray (uint _uiMaxElems) : m_poElems(NULL), m_uiNumElems(0), m_uiMaxElems(0)
{
    Init(_uiMaxElems);
}
// ----------------------------------------------------------------------------
template <class T>
inline CGStArray <T>::~CGStArray()
{
    if ( m_poElems )
        mDel [] m_poElems;
}
// ----------------------------------------------------------------------------
template <class T>
inline void CGStArray <T>::Init (uint _uiMaxElems)
{
    m_poElems = mNew T[_uiMaxElems];
    m_uiNumElems = 0;
    m_uiMaxElems = _uiMaxElems;
}
// ----------------------------------------------------------------------------
template <class T>
inline T &CGStArray <T>::operator[](const uint _uiIdx) const
{
    assert(_uiIdx < m_uiNumElems);
    return (m_poElems[_uiIdx]);
}
// ----------------------------------------------------------------------------
template <class T>
inline int CGStArray <T>::iAdd(const T& _oElem)
{
    if ( m_uiNumElems < m_uiMaxElems )
    {
        m_poElems[m_uiNumElems++] = _oElem;
        return(m_uiNumElems - 1);
    }
    else
        return(-1);
}
// ----------------------------------------------------------------------------
template <class T>
inline T& CGStArray <T>::oGet()
{
    if ( m_uiNumElems < m_uiMaxElems )
    {
        m_uiNumElems++;
        return(m_poElems[m_uiNumElems - 1]);
    }
    else
    {
        assert(0);
        return( *( (T*)0 ) );
    }
}
// ----------------------------------------------------------------------------
template <class T>
inline void CGStArray <T>::Clear()
{
    m_uiNumElems = 0;
}
// ----------------------------------------------------------------------------
template <class T>
inline void CGStArray <T>::Del(uint _uiIdx)
{
    assert(_uiIdx < m_uiNumElems);

    // Displace contents
    if ( _uiIdx < m_uiNumElems - 1 )
        memcpy( m_poElems + _uiIdx,m_poElems + (_uiIdx + 1),(m_uiNumElems - _uiIdx - 1) * sizeof(T) );

    m_uiNumElems--;
}
// ----------------------------------------------------------------------------
template <class T>
inline uint CGStArray <T>::uiNumElems() const
{
    return(m_uiNumElems);
}
// ----------------------------------------------------------------------------
template <class T>
inline uint CGStArray <T>::uiMaxElems() const
{
    return(m_uiMaxElems);
}
// ----------------------------------------------------------------------------
template <class T>
inline T* CGStArray <T>::poBuff() const
{
    return(m_poElems);
}
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
