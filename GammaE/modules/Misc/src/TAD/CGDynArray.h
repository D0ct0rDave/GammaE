//-----------------------------------------------------------------------------
#ifndef CGDynArray_h
#define CGDynArray_h 1
//-----------------------------------------------------------------------------
#include "GammaE_Mem.h"
#include "MiscTypes.h"
#include <assert.h>
//-----------------------------------------------------------------------------
template <class T>
class CGDynArray 
{
	public:

		CGDynArray();
		~CGDynArray();

		T& operator[](const uint index) const;

		uint uiAdd (const T& _oElem);
		
		/// Retrieves a free element of the array
		T& oGet();

		void Clear ();
		void Del (uint _uiElemIdx);
		uint uiNumElems () const;
		void SetReallocFactor (uint _uiRealloc);
		T * poBuff ();

		T &operator[](const uint index);


	protected:
		T* m_poElems;
		uint m_uiNumElems;
		uint m_uiMaxElems;
		uint m_uiRealloc;
};
//-----------------------------------------------------------------------------
template <class T>
inline CGDynArray<T>::CGDynArray() : m_poElems(NULL), m_uiNumElems(0), m_uiMaxElems(0), m_uiRealloc(10)
{
  
}
//-----------------------------------------------------------------------------
template <class T>
inline CGDynArray<T>::~CGDynArray()
{
	Clear();
}
//-----------------------------------------------------------------------------
template <class T>
inline T& CGDynArray<T>::operator[](const uint index) const
{
  	assert(index< m_uiNumElems);
	return (m_poElems[index]);
}
//-----------------------------------------------------------------------------
template <class T>
inline uint CGDynArray<T>::uiAdd(const T& _oElem)
{
	if (m_uiNumElems == m_uiMaxElems)
	{
		T*	poNewElems;

		m_uiMaxElems += m_uiRealloc;
		poNewElems   = (T*)mAlloc(sizeof(T)*m_uiMaxElems);
		memset(poNewElems,0,sizeof(T)*m_uiMaxElems);

		if (m_poElems)
		{
			memcpy(poNewElems,m_poElems,m_uiNumElems*sizeof(T));
			mFree(m_poElems);
		}

		m_poElems = poNewElems;		
	}
	m_poElems[m_uiNumElems] = _oElem;
	m_uiNumElems++;

	return(m_uiNumElems-1);  
}
//-----------------------------------------------------------------------------
template <class T>
inline T& CGDynArray<T>::oGet()
{
	T oVar;
	uint uiIdx = uiAdd(oVar);
	return( m_poElems[uiIdx] );
}
//-----------------------------------------------------------------------------
template <class T>
inline void CGDynArray<T>::Clear ()
{
	if (m_poElems)
	{
		mFree(m_poElems);
		m_poElems = NULL;
	}

	m_uiNumElems = 0;
	m_uiMaxElems = 0;
}
//-----------------------------------------------------------------------------
template <class T>
inline void CGDynArray<T>::Del (uint _uiElemIdx)
{
	assert(_uiElemIdx < m_uiNumElems);

	if (_uiElemIdx<m_uiNumElems-1)
	{
		T* poNewElems;
		poNewElems   = (T*)mAlloc(sizeof(T)*(m_uiNumElems-1));
		
		memcpy(poNewElems            ,m_poElems              ,_uiElemIdx*sizeof(T));
		memcpy(poNewElems+(_uiElemIdx),m_poElems+(_uiElemIdx+1),(m_uiNumElems-_uiElemIdx-1)*sizeof(T));
		
		mFree(m_poElems);
		m_poElems = poNewElems;
		
		m_uiMaxElems = m_uiNumElems-1;
	}

	m_uiNumElems--;
}
//-----------------------------------------------------------------------------
template <class T>
inline uint CGDynArray<T>::uiNumElems() const
{
	return (m_uiNumElems);
}
//-----------------------------------------------------------------------------
template <class T>
inline void CGDynArray<T>::SetReallocFactor (uint _uiRealloc)
{
	if (_uiRealloc>0) m_uiRealloc = _uiRealloc;
}
//-----------------------------------------------------------------------------
template <class T>
inline T * CGDynArray<T>::poBuff ()
{
	return(m_poElems);
}
//-----------------------------------------------------------------------------
template <class T>
inline T& CGDynArray<T>::operator[](const uint index)
{
  	assert(index< m_uiNumElems);
	return (m_poElems[index]);
}
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------

