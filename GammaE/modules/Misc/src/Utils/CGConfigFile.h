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
#ifndef CGConfigFileH
#define CGConfigFileH
// ----------------------------------------------------------------------------
#include "GMiscTypes.h"
#include "Types/CGString.h"
// ----------------------------------------------------------------------------
class CGConfigFile
{
    public:

        // / Creates the object and opens the configuration file ready for reading
        CGConfigFile(const CGString& _sConfigFile);
        ~CGConfigFile();

        // / Retrieves whether the configuration file was correctly opened or not
        bool bInitialized() const;

        // / Retrieves a string variable value from the configuration file
        CGString sGetString(const CGString& _sVar,const CGString& _sDefaultValue) const;

        // / Retrieves a float variable value from the configuration file
        float fGetFloat(const CGString& _sVar,float _fDefaultValue) const;

        // / Retrieves a integer variable value from the configuration file
        int iGetInteger(const CGString& _sVar,uint _uiDefaultValue) const;

        // / Retrieves a bool variable value from the configuration file
        bool bGetBool(const CGString& _sVar,bool _bDefaultValue) const;

    protected:
        // /
        handler m_hConfigObj;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
