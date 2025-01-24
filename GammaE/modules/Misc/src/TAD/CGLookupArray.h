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
#ifndef CGLookupArrayH
#define CGLookupArrayH
// ----------------------------------------------------------------------------
#include "CGDynArray.h"
#include "Types/CGString.h"
// ----------------------------------------------------------------------------
template <class T>
class CGLookupArray
{
    protected:

        class CLookupEntry
        {
            public:
                CLookupEntry()
                {
                }

                CLookupEntry(const CGString& _sVarName,const T& _oValue)
                {
                    m_sName = _sVarName;
                    m_oData = _oValue;
                }

                CGString m_sName;
                T m_oData;
        };

    public:

        ~CGLookupArray()
        {
        }

        uint uiAddVar (const CGString& _sVarName,const T& _oValue)
        {
            // If the var exists just replace it
            int iIdx = iGetIdx(_sVarName);

            if ( iIdx == -1 )
            {
                CLookupEntry oEntry(_sVarName,_oValue);
                return( m_oVars.uiAdd(oEntry) );
            }
            else
            {
                SetElem(iIdx,_oValue);
                return(iIdx);
            }
        }

        T oGetVar(const CGString& _sVarName) const
        {
            for ( uint i = 0; i < uiNumElems(); i++ )
            {
                if ( m_oVars[i].m_sName == _sVarName )
                    return (m_oVars[i].m_oData);
            }

            return ( (T)0 );
        }

        void SetVar(const CGString& _sVarName,const T& _oValue)
        {
            for ( uint i = 0; i < uiNumElems(); i++ )
            {
                if ( m_oVars[i].m_sName == _sVarName )
                {
                    m_oVars[i].m_oData = _oValue;
                    return;
                }
            }
        }

        T& oGetElem(uint _uiIdx)
        {
            return(m_oVars[_uiIdx].m_oData);
        }

        T& operator[](const uint _uiIdx)
        {
            return (m_oVars[_uiIdx].m_oData);
        }

        int iGetElemIdx(const T& _oData)
        {
            for ( uint i = 0; i < uiNumElems(); i++ )
                if ( m_oVars[i].m_oData == _oData )
                    return (i);

            return(-1);
        }

        int iGetIdx(const CGString& _sVarName)
        {
            for ( uint i = 0; i < uiNumElems(); i++ )
            {
                if ( m_oVars[i].m_sName == _sVarName )
                    return (i);
            }

            return(-1);
        }

        void SetElem(uint _uiIdx,const T& _oData)
        {
            m_oVars[_uiIdx].m_oData = _oData;
        }

        const CGString& sGetVarName(const T& _oObj)
        {
            for ( uint i = 0; i < uiNumElems(); i++ )
            {
                if ( _oObj == m_oVars[i].m_oData )
                    return (m_oVars[i].m_sName);
            }

            static CGString sNULLString = "NULL";
            return (sNULLString);
        }

        const CGString& sGetElemName(uint _uiElem)
        {
            return (m_oVars[_uiElem].m_sName);
        }

        void Del(uint _uiElemIdx)
        {
            m_oVars.Del(_uiElemIdx);
        }

        uint uiMaxElems() const
        {
            return ( m_oVars.uiMaxElems() );
        }

        uint uiNumElems() const
        {
            return ( m_oVars.uiNumElems() );
        }

        void Clear ()
        {
            m_oVars.Clear();
        }

    protected:

        CGDynArray <CLookupEntry> m_oVars;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
