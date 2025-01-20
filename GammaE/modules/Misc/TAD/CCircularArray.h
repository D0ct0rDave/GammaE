//## begin module%3D0A27300141.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3D0A27300141.cm

//## begin module%3D0A27300141.cp preserve=no
//## end module%3D0A27300141.cp

//## Module: CCircularArray%3D0A27300141; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Misc\TAD\CCircularArray.h

#ifndef CCircularArray_h
#define CCircularArray_h 1

//## begin module%3D0A27300141.additionalIncludes preserve=no
//## end module%3D0A27300141.additionalIncludes

//## begin module%3D0A27300141.includes preserve=yes
//## end module%3D0A27300141.includes

//## begin module%3D0A27300141.additionalDeclarations preserve=yes
//## end module%3D0A27300141.additionalDeclarations


//## begin CCircularArray%3D0A27300141.preface preserve=yes
//## end CCircularArray%3D0A27300141.preface

//## Class: CCircularArray%3D0A27300141; Parameterized Class
//## Category: Misc::TAD%3BD2D0650185
//## Persistence: Transient
//## Cardinality/Multiplicity: n
//## Space Complexity: T

template <class T>
class CCircularArray 
{
  //## begin CCircularArray%3D0A27300141.initialDeclarations preserve=yes
  //## end CCircularArray%3D0A27300141.initialDeclarations

  public:
    //## Constructors (generated)
      CCircularArray();

    //## Constructors (specified)
      //## Operation: CCircularArray%1024078843
      CCircularArray (int _iMaxElems);

    //## Destructor (generated)
      ~CCircularArray();


    //## Other Operations (specified)
      //## Operation: iAdd%1024078844
      int iAdd (const T& _roElem);

      //## Operation: Clear%1024078845
      void Clear ();

      //## Operation: Del%1024078846
      void Del (int _iElemIdx);

      //## Operation: iNumElems%1024078847
      int iNumElems ();

      //## Operation: Init%1024078848
      void Init (int _iMaxElems);

      //## Operation: iMaxElems%1024078850
      int iMaxElems ();

      //## Operation: poElem%1024097113
      T* poElem (int _iIdx);

    // Additional Public Declarations
      //## begin CCircularArray%3D0A27300141.public preserve=yes
      //## end CCircularArray%3D0A27300141.public

  protected:
    // Additional Protected Declarations
      //## begin CCircularArray%3D0A27300141.protected preserve=yes
      //## end CCircularArray%3D0A27300141.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: m_poElems%3D0A2743024C
      //## begin CCircularArray::m_poElems%3D0A2743024C.attr preserve=no  private: T* {UA} NULL
      T* m_poElems;
      //## end CCircularArray::m_poElems%3D0A2743024C.attr

      //## Attribute: m_bFree%3D0A274502C7
      //## begin CCircularArray::m_bFree%3D0A274502C7.attr preserve=no  private: bool * {UA} NULL
      bool *m_bFree;
      //## end CCircularArray::m_bFree%3D0A274502C7.attr

      //## Attribute: m_iHdrPos%3D0A27620139
      //## begin CCircularArray::m_iHdrPos%3D0A27620139.attr preserve=no  private: int {UA} -1
      int m_iHdrPos;
      //## end CCircularArray::m_iHdrPos%3D0A27620139.attr

      //## Attribute: m_iNumElems%3D0A27B40028
      //## begin CCircularArray::m_iNumElems%3D0A27B40028.attr preserve=no  private: int {UA} 0
      int m_iNumElems;
      //## end CCircularArray::m_iNumElems%3D0A27B40028.attr

      //## Attribute: m_iMaxElems%3D0A33F30275
      //## begin CCircularArray::m_iMaxElems%3D0A33F30275.attr preserve=no  private: int {UA} 0
      int m_iMaxElems;
      //## end CCircularArray::m_iMaxElems%3D0A33F30275.attr

    // Additional Private Declarations
      //## begin CCircularArray%3D0A27300141.private preserve=yes
      //## end CCircularArray%3D0A27300141.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCircularArray%3D0A27300141.implementation preserve=yes
      //## end CCircularArray%3D0A27300141.implementation

};

//## begin CCircularArray%3D0A27300141.postscript preserve=yes
//## end CCircularArray%3D0A27300141.postscript

// Parameterized Class CCircularArray 

template <class T>
inline CCircularArray<T>::CCircularArray()
  //## begin CCircularArray::CCircularArray%.hasinit preserve=no
      : m_poElems(NULL), m_bFree(NULL), m_iHdrPos(-1), m_iNumElems(0), m_iMaxElems(0)
  //## end CCircularArray::CCircularArray%.hasinit
  //## begin CCircularArray::CCircularArray%.initialization preserve=yes
  //## end CCircularArray::CCircularArray%.initialization
{
  //## begin CCircularArray::CCircularArray%.body preserve=yes
  //## end CCircularArray::CCircularArray%.body
}

template <class T>
inline CCircularArray<T>::CCircularArray (int _iMaxElems)
  //## begin CCircularArray::CCircularArray%1024078843.hasinit preserve=no
      : m_poElems(NULL), m_bFree(NULL), m_iHdrPos(-1), m_iNumElems(0), m_iMaxElems(0)
  //## end CCircularArray::CCircularArray%1024078843.hasinit
  //## begin CCircularArray::CCircularArray%1024078843.initialization preserve=yes
  //## end CCircularArray::CCircularArray%1024078843.initialization
{
  //## begin CCircularArray::CCircularArray%1024078843.body preserve=yes
	Init(_iMaxElems);
  //## end CCircularArray::CCircularArray%1024078843.body
}


template <class T>
inline CCircularArray<T>::~CCircularArray()
{
  //## begin CCircularArray::~CCircularArray%.body preserve=yes
	if (m_bFree)	mDel []m_bFree;
	if (m_poElems)	mDel []m_poElems;
  //## end CCircularArray::~CCircularArray%.body
}



//## Other Operations (inline)
template <class T>
inline int CCircularArray<T>::iAdd (const T& _roElem)
{
  //## begin CCircularArray::iAdd%1024078844.body preserve=yes
	assert ((m_iNumElems < m_iMaxElems) && "Static array overflow");
	
	int iPos;

	if (m_bFree[m_iHdrPos])	
		iPos = m_iHdrPos;
	else
	{
		int iOldHdrPos = m_iHdrPos;

		do{

			m_iHdrPos = (m_iHdrPos+1) % m_iMaxElems;

		}while ((m_iHdrPos != iOldHdrPos) && (! m_bFree[m_iHdrPos]));

		if (m_iHdrPos == iOldHdrPos) return(-1);

		iPos = m_iHdrPos;
	}

	m_iHdrPos = (m_iHdrPos+1) % m_iMaxElems;
	m_poElems[iPos] = _roElem;
	m_bFree  [iPos] = false;  
	m_iNumElems++;

	return(iPos);
  //## end CCircularArray::iAdd%1024078844.body
}

template <class T>
inline void CCircularArray<T>::Clear ()
{
  //## begin CCircularArray::Clear%1024078845.body preserve=yes
	for (int iElem=0;iElem<iMaxElems;iElem++) m_bFree[iElem] = true;
	m_iNumElems = 0;
	m_iHdrPos   = 0;
  //## end CCircularArray::Clear%1024078845.body
}

template <class T>
inline void CCircularArray<T>::Del (int _iElemIdx)
{
  //## begin CCircularArray::Del%1024078846.body preserve=yes
	assert(_iElemIdx < m_iMaxElems);
	assert(_iElemIdx >= 0);

	if (m_bFree[_iElemIdx]) return;

	m_bFree[_iElemIdx] = true;

	m_iNumElems--;
  //## end CCircularArray::Del%1024078846.body
}

template <class T>
inline int CCircularArray<T>::iNumElems ()
{
  //## begin CCircularArray::iNumElems%1024078847.body preserve=yes

/*
	// Count the number of elements:
	iNumElems = 0;
	for (int iElem=0;iElem<m_iMaxElems;iElem++)
		if (! m_bFree[iElem]) m_iNumElems++;
*/
	return(m_iNumElems);
  //## end CCircularArray::iNumElems%1024078847.body
}

template <class T>
inline void CCircularArray<T>::Init (int _iMaxElems)
{
  //## begin CCircularArray::Init%1024078848.body preserve=yes
  	m_iMaxElems = _iMaxElems;
	m_iNumElems = 0;
	m_iHdrPos   = 0;
		
	m_poElems   = mNew T[m_iMaxElems];
	m_bFree		= mNew bool[m_iMaxElems];
	
	// Initialize free element array
	for (int iElem=0;iElem<m_iMaxElems;iElem++)
		m_bFree[iElem] = true;

  //## end CCircularArray::Init%1024078848.body
}

template <class T>
inline int CCircularArray<T>::iMaxElems ()
{
  //## begin CCircularArray::iMaxElems%1024078850.body preserve=yes
	return(m_iMaxElems);
  //## end CCircularArray::iMaxElems%1024078850.body
}

template <class T>
inline T* CCircularArray<T>::poElem (int _iIdx)
{
  //## begin CCircularArray::poElem%1024097113.body preserve=yes
	assert(_iIdx< m_iMaxElems);
	assert(_iIdx>= 0);
	
	if (m_bFree[_iIdx]) 
		return(NULL);
	else
		return( &m_poElems[_iIdx] );
  //## end CCircularArray::poElem%1024097113.body
}

//## begin module%3D0A27300141.epilog preserve=yes
//## end module%3D0A27300141.epilog


#endif


// Detached code regions:
// WARNING: this code will be lost if code is regenerated.
#if 0
//## begin CCircularArray::operator[]%.body preserve=no
	assert(index< m_iMaxElems);
	assert(index>= 0);
	assert(m_bFree[index]);
	
	return (m_poElems[index]);
//## end CCircularArray::operator[]%.body

#endif
