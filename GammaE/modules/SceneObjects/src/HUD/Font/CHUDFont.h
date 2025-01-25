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
#ifndef CHUDFontH
#define CHUDFontH
// -----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "GammaE_E3D.h"
// -----------------------------------------------------------------------------
class CHUDFont : public CGResource
{
    public:     CHUDFont() : m_fDefaultWidth(0),m_fHeight(0),m_fDefaultHeight(0)
    {
    }
        // virtual ~CHUDFont();
        bool bInit(const char* _szFontName);
        bool bInit(const char* _szShapeShader,const char* _szDataFile);

        CGShader* poGetShader()
        {
            return(m_poShader);
        }

        float fGetTextWidth(char* Text);
        float fCharHeight(char _cChar);
        float fCharWidth(char _cChar);
        float fDefaultCharWidth()
        {
            return (m_fDefaultWidth);
        }
        float fDefaultCharHeight()
        {
            return (m_fDefaultHeight);
        }

    private:
        CGShader* m_poShader;

        float m_fWidths[256];
        float m_fHeight;
        float m_fDefaultWidth;
        float m_fDefaultHeight;
};

// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
