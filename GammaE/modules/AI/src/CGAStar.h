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
#ifndef CGAStarH
#define CGAStarH
// ----------------------------------------------------------------------------
#include "CGCDXAStar.h"
// ----------------------------------------------------------------------------
#ifndef NULL
    #define NULL 0
#endif
// ----------------------------------------------------------------------------

class CGAStar
{
    public:

        CGAStar()
        {
            pAStar = NULL;
            bAllow8Directions = true;
            Width = 1;
            Height = 1;
        }

        ~CGAStar()
        {
            if ( pAStar != NULL )
            {
                delete pAStar;
            }
        }

        // IAStar
    public:
        long Height;
        long Width;
        void SetHeight(long lHeight);
        void SetWidth(long lWidth);
        void NewMap(long width, long height);
        void SetTile(long x, long y, long t);
        long lGetTile(long x, long y);
        bool bFindAPath(long x1, long y1, long x2, long y2);
        bool bGoalReached();
        void NextPathNode();
        long lNodeGetX();
        long lNodeGetY();
        void Allow8Directions(bool bAllowed);

        CGMap map;
        CGDXAStar* pAStar;
        bool bAllow8Directions;
};

// ----------------------------------------------------------------------------
#endif // GameAI_AStar
// ----------------------------------------------------------------------------
