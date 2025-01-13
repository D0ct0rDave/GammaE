//## begin module%3CB48FE80075.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CB48FE80075.cm

//## begin module%3CB48FE80075.cp preserve=no
//## end module%3CB48FE80075.cp

//## Module: CDynArray%3CB48FE80075; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Misc\TAD\CDynArray.h

#ifndef CDynArray_h
#define CDynArray_h 1

//## begin module%3CB48FE80075.additionalIncludes preserve=no
//## end module%3CB48FE80075.additionalIncludes

//## begin module%3CB48FE80075.includes preserve=yes
#include "memory/gammae_mem.h"
#include <assert.h>
//## end module%3CB48FE80075.includes

//## begin module%3CB48FE80075.additionalDeclarations preserve=yes
//## end module%3CB48FE80075.additionalDeclarations


//## begin CDynArray%3CB48FE80075.preface preserve=yes
//## end CDynArray%3CB48FE80075.preface

//## Class: CDynArray%3CB48FE80075; Parameterized Class
//## Category: Misc::TAD%3BD2D0650185
//## Persistence: Transient
//## Cardinality/Multiplicity: n
//## Space Complexity: T

template <class T>
class CDynArray 
{
  //## begin CDynArray%3CB48FE80075.initialDeclarations preserve=yes
  //## end CDynArray%3CB48FE80075.initialDeclarations

  public:
    //## Constructors (generated)
      CDynArray();

    //## Destructor (generated)
      ~CDynArray();

    //## Subscription Operation (generated)
      T& operator[](const int index) const;


    //## Other Operations (specified)
      //## Operation: iAdd%1018461824
      int iAdd (const T& _roElem);

      //## Operation: Clear%1018461825
      void Clear ();

      //## Operation: Del%1018461826
      void Del (int _iElemIdx);

      //## Operation: iNumElems%1018461827
      int iNumElems ();

      //## Operation: SetReallocFactor%1018461828
      void SetReallocFactor (int _iRealloc);

      //## Operation: poBuff%1018461829
      T * poBuff ();

    // Additional Public Declarations
      //## begin CDynArray%3CB48FE80075.public preserve=yes
	  T &operator[](const int index);
      //## end CDynArray%3CB48FE80075.public
  protected:
    // Additional Protected Declarations
      //## begin CDynArray%3CB48FE80075.protected preserve=yes
      //## end CDynArray%3CB48FE80075.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: m_poElems%3CB48FF103AD
      //## begin CDynArray::m_poElems%3CB48FF103AD.attr preserve=no  private: T* {UA} NULL
      T* m_poElems;
      //## end CDynArray::m_poElems%3CB48FF103AD.attr

      //## Attribute: m_iNumElems%3CB48FF8033F
      //## begin CDynArray::m_iNumElems%3CB48FF8033F.attr preserve=no  private: int {UA} 0
      int m_iNumElems;
      //## end CDynArray::m_iNumElems%3CB48FF8033F.attr

      //## Attribute: m_iMaxElems%3CB48FFE01D5
      //## begin CDynArray::m_iMaxElems%3CB48FFE01D5.attr preserve=no  private: int {UA} 0
      int m_iMaxElems;
      //## end CDynArray::m_iMaxElems%3CB48FFE01D5.attr

      //## Attribute: m_iRealloc%3CB49005012B
      //## begin CDynArray::m_iRealloc%3CB49005012B.attr preserve=no  private: int {UA} 10
      int m_iRealloc;
      //## end CDynArray::m_iRealloc%3CB49005012B.attr

    // Additional Private Declarations
      //## begin CDynArray%3CB48FE80075.private preserve=yes
      //## end CDynArray%3CB48FE80075.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CDynArray%3CB48FE80075.implementation preserve=yes
      //## end CDynArray%3CB48FE80075.implementation

};

//## begin CDynArray%3CB48FE80075.postscript preserve=yes
//## end CDynArray%3CB48FE80075.postscript

// Parameterized Class CDynArray 

template <class T>
inline CDynArray<T>::CDynArray()
  //## begin CDynArray::CDynArray%.hasinit preserve=no
      : m_poElems(NULL), m_iNumElems(0), m_iMaxElems(0), m_iRealloc(10)
  //## end CDynArray::CDynArray%.hasinit
  //## begin CDynArray::CDynArray%.initialization preserve=yes
  //## end CDynArray::CDynArray%.initialization
{
  //## begin CDynArray::CDynArray%.body preserve=yes
  //## end CDynArray::CDynArray%.body
}


template <class T>
inline CDynArray<T>::~CDynArray()
{
  //## begin CDynArray::~CDynArray%.body preserve=yes
	Clear();
  //## end CDynArray::~CDynArray%.body
}


template <class T>
inline T& CDynArray<T>::operator[](const int index) const
{
  //## begin CDynArray::operator[]%.body preserve=yes
  	assert(index< m_iNumElems);
	assert(index>= 0);

	return (m_poElems[index]);
  //## end CDynArray::operator[]%.body
}



//## Other Operations (inline)
template <class T>
inline int CDynArray<T>::iAdd (const T& _roElem)
{
  //## begin CDynArray::iAdd%1018461824.body preserve=yes
	if (m_iNumElems == m_iMaxElems)
	{
		// Reallocate
		T*	poNewElems;

		// Allocate space for old + new elems
		m_iMaxElems += m_iRealloc;
		poNewElems   = mNew T[m_iMaxElems];

		// Copy old data
		if (m_poElems)
		{
			// delete old data
			memcpy(poNewElems,m_poElems,m_iNumElems*sizeof(T));
			mDel []m_poElems;
		}

		// Rearrange
		m_poElems = poNewElems;		
	}
	
	// Add new element	
	m_poElems[m_iNumElems] = _roElem;
	m_iNumElems++;

	return(m_iNumElems-1);
  //## end CDynArray::iAdd%1018461824.body
}

template <class T>
inline void CDynArray<T>::Clear ()
{
  //## begin CDynArray::Clear%1018461825.body preserve=yes
	if (m_poElems)
	{
		mDel []m_poElems;
		m_poElems = NULL;
	}

	m_iNumElems = 0;
	m_iMaxElems = 0;
  //## end CDynArray::Clear%1018461825.body
}

template <class T>
inline void CDynArray<T>::Del (int _iElemIdx)
{
  //## begin CDynArray::Del%1018461826.body preserve=yes
	assert(_iElemIdx < m_iNumElems);
	assert(_iElemIdx >= 0);

	if (_iElemIdx<m_iNumElems-1)
	{
		// reordering
		T* poNewElems;
		poNewElems = mNew T[m_iNumElems-1];
		
		memcpy(poNewElems            ,m_poElems              ,_iElemIdx*sizeof(T));
		memcpy(poNewElems+(_iElemIdx),m_poElems+(_iElemIdx+1),(m_iNumElems-_iElemIdx-1)*sizeof(T));
		
		mDel []m_poElems;
		m_poElems = poNewElems;
		
		m_iMaxElems = m_iNumElems-1;
	}

	m_iNumElems--;
  //## end CDynArray::Del%1018461826.body
}

template <class T>
inline int CDynArray<T>::iNumElems ()
{
  //## begin CDynArray::iNumElems%1018461827.body preserve=yes
	return (m_iNumElems);
  //## end CDynArray::iNumElems%1018461827.body
}

template <class T>
inline void CDynArray<T>::SetReallocFactor (int _iRealloc)
{
  //## begin CDynArray::SetReallocFactor%1018461828.body preserve=yes
	if (_iRealloc) m_iRealloc = _iRealloc;
  //## end CDynArray::SetReallocFactor%1018461828.body
}

template <class T>
inline T * CDynArray<T>::poBuff ()
{
  //## begin CDynArray::poBuff%1018461829.body preserve=yes
	return(m_poElems);
  //## end CDynArray::poBuff%1018461829.body
}

//## begin module%3CB48FE80075.epilog preserve=yes

template <class T>
inline T& CDynArray<T>::operator[](const int index)
{
  	assert(index< m_iNumElems);
	assert(index>= 0);

	return (m_poElems[index]);
}
//## end module%3CB48FE80075.epilog


#endif
