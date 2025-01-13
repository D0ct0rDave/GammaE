//## begin module%3CE3D89303B7.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CE3D89303B7.cm

//## begin module%3CE3D89303B7.cp preserve=no
//## end module%3CE3D89303B7.cp

//## Module: CStArray%3CE3D89303B7; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Misc\TAD\CStArray.h

#ifndef CStArray_h
#define CStArray_h 1

//## begin module%3CE3D89303B7.additionalIncludes preserve=no
//## end module%3CE3D89303B7.additionalIncludes

//## begin module%3CE3D89303B7.includes preserve=yes
#include "Memory/GammaE_Mem.h"
//## end module%3CE3D89303B7.includes

//## begin module%3CE3D89303B7.additionalDeclarations preserve=yes
//## end module%3CE3D89303B7.additionalDeclarations


//## begin CStArray%3CE3D89303B7.preface preserve=yes
//## end CStArray%3CE3D89303B7.preface

//## Class: CStArray%3CE3D89303B7; Parameterized Class
//## Category: Misc::TAD%3BD2D0650185
//## Persistence: Transient
//## Cardinality/Multiplicity: n
//## Space Complexity: T

template <class T>
class CStArray 
{
  //## begin CStArray%3CE3D89303B7.initialDeclarations preserve=yes
  //## end CStArray%3CE3D89303B7.initialDeclarations

  public:
    //## Constructors (generated)
      CStArray();

    //## Constructors (specified)
      //## Operation: CStArray%1021565341
      CStArray (int _iMaxElems);

    //## Destructor (generated)
      ~CStArray();

    //## Subscription Operation (generated)
      T& operator[](const int index) const;


    //## Other Operations (specified)
      //## Operation: iAdd%1021565335
      int iAdd (const T& _roElem);

      //## Operation: Clear%1021565336
      void Clear ();

      //## Operation: Del%1021565337
      void Del (int _iElemIdx);

      //## Operation: iNumElems%1021565338
      int iNumElems ();

      //## Operation: iMaxElems%1021565342
      int iMaxElems ();

      //## Operation: poBuff%1021565339
      T * poBuff ();

      //## Operation: Init%1021565340
      void Init (int _iMaxElems);

    // Additional Public Declarations
      //## begin CStArray%3CE3D89303B7.public preserve=yes
      //## end CStArray%3CE3D89303B7.public

  protected:
    // Additional Protected Declarations
      //## begin CStArray%3CE3D89303B7.protected preserve=yes
      //## end CStArray%3CE3D89303B7.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: m_poElems%3CE3D8C303DE
      //## begin CStArray::m_poElems%3CE3D8C303DE.attr preserve=no  private: T* {UA} NULL
      T* m_poElems;
      //## end CStArray::m_poElems%3CE3D8C303DE.attr

      //## Attribute: m_iNumElems%3CE3D8CD0374
      //## begin CStArray::m_iNumElems%3CE3D8CD0374.attr preserve=no  private: int {UA} 0
      int m_iNumElems;
      //## end CStArray::m_iNumElems%3CE3D8CD0374.attr

      //## Attribute: m_iMaxElems%3CE3D8D20032
      //## begin CStArray::m_iMaxElems%3CE3D8D20032.attr preserve=no  private: int {UA} 0
      int m_iMaxElems;
      //## end CStArray::m_iMaxElems%3CE3D8D20032.attr

    // Additional Private Declarations
      //## begin CStArray%3CE3D89303B7.private preserve=yes
      //## end CStArray%3CE3D89303B7.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CStArray%3CE3D89303B7.implementation preserve=yes
      //## end CStArray%3CE3D89303B7.implementation

};

//## begin CStArray%3CE3D89303B7.postscript preserve=yes
//## end CStArray%3CE3D89303B7.postscript

// Parameterized Class CStArray 

template <class T>
inline CStArray<T>::CStArray()
  //## begin CStArray::CStArray%.hasinit preserve=no
      : m_poElems(NULL), m_iNumElems(0), m_iMaxElems(0)
  //## end CStArray::CStArray%.hasinit
  //## begin CStArray::CStArray%.initialization preserve=yes
  //## end CStArray::CStArray%.initialization
{
  //## begin CStArray::CStArray%.body preserve=yes
  //## end CStArray::CStArray%.body
}

template <class T>
inline CStArray<T>::CStArray (int _iMaxElems)
  //## begin CStArray::CStArray%1021565341.hasinit preserve=no
      : m_poElems(NULL), m_iNumElems(0), m_iMaxElems(0)
  //## end CStArray::CStArray%1021565341.hasinit
  //## begin CStArray::CStArray%1021565341.initialization preserve=yes
  //## end CStArray::CStArray%1021565341.initialization
{
  //## begin CStArray::CStArray%1021565341.body preserve=yes
	Init(_iNumElems);
  //## end CStArray::CStArray%1021565341.body
}


template <class T>
inline CStArray<T>::~CStArray()
{
  //## begin CStArray::~CStArray%.body preserve=yes
	mDel []m_poElems;
  //## end CStArray::~CStArray%.body
}


template <class T>
inline T& CStArray<T>::operator[](const int index) const
{
  //## begin CStArray::operator[]%.body preserve=yes
  	assert(index< m_iNumElems);
	assert(index>= 0);

	return (m_poElems[index]);
  //## end CStArray::operator[]%.body
}



//## Other Operations (inline)
template <class T>
inline int CStArray<T>::iAdd (const T& _roElem)
{
  //## begin CStArray::iAdd%1021565335.body preserve=yes
	assert ((m_iNumElems < m_iMaxElems) && "Static array overflow");
	m_poElems[m_iNumElems++] = _roElem;
	return(m_iNumElems-1);
  //## end CStArray::iAdd%1021565335.body
}

template <class T>
inline void CStArray<T>::Clear ()
{
  //## begin CStArray::Clear%1021565336.body preserve=yes
	m_iNumElems = 0;	
  //## end CStArray::Clear%1021565336.body
}

template <class T>
inline void CStArray<T>::Del (int _iElemIdx)
{
  //## begin CStArray::Del%1021565337.body preserve=yes
	assert(_iElemIdx < m_iNumElems);
	assert(_iElemIdx >= 0);

	if (_iElemIdx<m_iNumElems-1)
		memcpy(m_poElems+_iElemIdx,m_poElems+(_iElemIdx+1),(m_iNumElems-_iElemIdx-1)*sizeof(T));

	m_iNumElems--;
  //## end CStArray::Del%1021565337.body
}

template <class T>
inline int CStArray<T>::iNumElems ()
{
  //## begin CStArray::iNumElems%1021565338.body preserve=yes
	return(m_iNumElems);
  //## end CStArray::iNumElems%1021565338.body
}

template <class T>
inline int CStArray<T>::iMaxElems ()
{
  //## begin CStArray::iMaxElems%1021565342.body preserve=yes
	return(m_iMaxElems);
  //## end CStArray::iMaxElems%1021565342.body
}

template <class T>
inline T * CStArray<T>::poBuff ()
{
  //## begin CStArray::poBuff%1021565339.body preserve=yes
	return(m_poElems);
  //## end CStArray::poBuff%1021565339.body
}

template <class T>
inline void CStArray<T>::Init (int _iMaxElems)
{
  //## begin CStArray::Init%1021565340.body preserve=yes
	m_poElems   = mNew T[_iMaxElems];
	m_iNumElems = 0;
	m_iMaxElems = _iMaxElems;
  //## end CStArray::Init%1021565340.body
}

//## begin module%3CE3D89303B7.epilog preserve=yes
//## end module%3CE3D89303B7.epilog


#endif
