//-----------------------------------------------------------------------------
#ifndef CGResourceWHH
#define CGResourceWHH
//-----------------------------------------------------------------------------
#include "TAD\CGLookupArray.h"
#include "TAD\CGSingleton.h"
#include "MiscTypes.h"
//-----------------------------------------------------------------------------
// NOTE: Resource objects should derive from CGResource class or one of its derivates
//-----------------------------------------------------------------------------
#define DECLARE_WAREHOUSE(CLASSNAME, WAREHOUSETYPE, RESOURCETYPE )\
class CLASSNAME : public WAREHOUSETYPE<RESOURCETYPE,CLASSNAME>
/*
{\
	friend CSingleton<CLASSNAME>;\
\
	private:\
		CLASSNAME(){};\
		CLASSNAME(){};
*/

template <typename T, typename B> 
class CGResourceWH: public CGSingleton<B>
{

public:
		/// Initializes the warehouse to store a maximum of the given number of elements
		void Finish()
		{
		}
		
		/// Invalidates all the elements of the warehouse
        virtual void Invalidate(int _iIdx = -1)
        {
			if (_iIdx == -1)
			{
				for (uint i=0;i<m_oWH.uiNumElems();i++)
					m_oWH.oGetElem( i )->Invalidate();					// Should derive from resource
			}
			else
			{
				m_oWH.oGetElem( _iIdx )->Invalidate();
			}
		}

		/// Frees the warehouse of the resources stored
		void Reset()
		{
			m_oWH.Clear();
		}

		/// Deletes the resource and the association to a variable name associated to the given index
		void Del(uint _uiIdx)
		{
			m_oWH.Del(_uiIdx);
		}
		
		/// Adds a resources associated to a given variable name to the warehouse. Returns an already existent index
		//  if the object was already in the warehouse
        uint uiAdd(const T* _poResourceObject,const CGString& _sResourceName)
        {
			if (_poResourceObject == NULL) return(-1);

			int iIdx = m_oWH.iGetElemIdx((T*)_poResourceObject);
			if (iIdx != -1)
				return(iIdx);
			else
				return ( m_oWH.uiAddVar(_sResourceName, (T*)_poResourceObject) );
		}
	
		/// Finds and returns the resource associated to a given variable name
        T* poFind(const CGString& _sResourceName)
        {
			T* poVar = m_oWH.oGetVar( _sResourceName );
			return(poVar);
		}
		
		/// Checks whether a resource associated to a given variable name exists or not
        bool bExists(const CGString& _sResourceName)
        {
	        return( poFind(_sResourceName) != NULL );
		}
		
		/// Returns the resource associated to the given index
        T* poGet(uint _uiResourceIdx)
        {
			return( m_oWH.oGetElem(_uiResourceIdx) );
		}
		
		/// Returns the number of elements inside the warehouse
		uint uiNumElems()
		{
			return( m_oWH.uiNumElems() );
		}

		/// Returns the associated variable name of a given of a resource NULL if it doesn't exist
		const CGString& sGetName(const T* _poResource)
		{
			return ( m_oWH.sGetVarName((T*)_poResource) );
		}
		
		/// Returns the index of a resource -1 if it doesn't exist in the database
        int iGetIdx(const T* _poResource)
        {
			return( m_oWH.iGetElemIdx((T*)_poResource) );
		}

protected:
		CGLookupArray<T*>	m_oWH;
};


//-----------------------------------------------------------------------------
#endif // CGResourceWHH
//-----------------------------------------------------------------------------
