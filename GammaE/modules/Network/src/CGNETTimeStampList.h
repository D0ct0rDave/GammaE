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
#ifndef CGNETTimeStampListH
#define CGNETTimeStampListH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------

class CGNETTimeStampList
{
    public:  CGNETTimeStampList();
        ~CGNETTimeStampList();

        bool bExists(uint _uiTimeStamp);
        void Add(uint _uiTimeStamp);

    protected:
        CGStArray <unsigned int> m_oTSL;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
