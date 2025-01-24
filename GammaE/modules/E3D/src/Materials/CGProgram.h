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
#ifndef CGProgramH
#define CGProgramH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------
class CGProgram : public CGResource
{
    public:
        CGProgram() : m_hProgram(0), m_hVS(0), m_hPS(0), m_pucVSData(NULL), m_pucPSData(NULL)
        {
        }

        // / Vertex Shader handler
        handler m_hVS;

        // / Pixel Shader handler
        handler m_hPS;

        // / Program handler
        handler m_hProgram;

        // / Vertex shader definition data
        char* m_pucVSData;

        // / Pixel shader definition data
        char* m_pucPSData;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
