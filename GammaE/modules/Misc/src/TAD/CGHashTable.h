//-----------------------------------------------------------------------------
#ifndef CGHashTable_h
#define CGHashTable_h 1
//-----------------------------------------------------------------------------
#include "utils/CRC.h"
#include "TAD\CGLookupArray.h"
#include "MiscTypes.h"
//-----------------------------------------------------------------------------
template <class T>
class CGHashTable 
{
  public:

		CGHashTable() : m_uiNumCols(0), m_poElems(NULL) {};
		CGHashTable(uint _uiNumCols) { Init(_uiNumCols); };

		~CGHashTable() { Finish();	};

		void Init (uint _uiNumCols)
		{
			Finish();

			m_uiNumCols = _uiNumCols;
			m_poElems = mNew CGLookupArray<T>[_uiNumCols];
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
			if (m_poElems)
			{
				m_poElems = NULL;
			}	
		}
	     
		void Invalidate ()
		{
			Finish();
			Init(m_uiNumCols);
		}

		uint uiNumCols() { return(m_uiNumCols); };

		CGLookupArray<T>* poGetList(uint _uiCol) { return( &m_poElems[_uiCol] ); };

	protected:

		CGLookupArray<T> *m_poElems;

	private:
      
		uint uiGetIndex (const CGString& _sString)
		{
			return( uiCRCGenerate(_sString.szString(),_sString.uiLen()) % m_uiNumCols );
		}
      
		uint m_uiNumCols;
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------

