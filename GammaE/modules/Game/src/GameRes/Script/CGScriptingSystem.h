// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#ifndef CGScriptingSystem_h
#define CGScriptingSystem_h 1
// -----------------------------------------------------------------------------
#include "GammaE_Misc.h"
DECLARE_SINGLETON(CGScriptingSystem)
{
    public:
        void Init();
        void Finish();

        handler hHandler()
        {
            return (m_hHnd);
        }
        void RegisterExtension(const CGString &_sFunctionName,void* _pFunctionCallback,const CGString& _sParameters = "",const CGString& _sResults = "");

        void* pCallExtension(const CGString& _sFunctionName,const CGString& _sFunctionParameters = "");

    protected:

        typedef struct TExtension
        {
            public:
                CGString m_sFunctionName;
                CGString m_sParameters;
                CGString m_sResults;
                const void* m_pFunctionCallback;
        };

        handler m_hHnd;
        CGDynArray <TExtension> m_oExtensionTable;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
