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
#ifndef CAI_MapH
#define CAI_MapH
// ----------------------------------------------------------------------------
class CGMap
{
    public:

        void NewMap(long width, long height);
        void SetTile(long x, long y, long t);
        long GetTile(long x, long y);
        long m_Height;
        long m_Width;
        CGMap();
        virtual ~CGMap();

        long* lTiles;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
