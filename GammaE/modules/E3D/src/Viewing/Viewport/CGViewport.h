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
#ifndef CGViewportH
#define CGViewportH
// ----------------------------------------------------------------------------
class CGViewport
{
    public:
        CGViewport();

        ~CGViewport();

        void SetViewport(float cX, float cY, float TX, float TY);

        float ScrCX;

        float ScrCY;

        float ScrTX;

        float ScrTY;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
