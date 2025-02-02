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
// ////////////////////////////////////////////////////////////////////////////////
// $Source: /usr/cvsroot/cdx/addons/CDXAStar/CDXASTARDEMO/CDXASTAR.H,v $
// $Author: mseibert $
//
// $Log: CDXASTAR.H,v $
// Revision 1.1  1999/05/30 02:32:44  mseibert
// A little demo to show how to use the CDXAStar class
//
// Revision 1.1.1.1  1999/05/04 23:59:23  bsimser
// Imported addons
//
// $Revision: 1.1 $
// ////////////////////////////////////////////////////////////////////////////////
#ifndef  CAI_CDXAStarH
#define CAI_CDXAStarH

#include "CGAIMap.h"

#define SHIFT 0         // change this to reflect the the size.
                        // Ex. 64x64 tile equals 2^6. or a shift of 6
#define TILESIZE 1      // change this also to reflect tile size. 64x64.

// ----------------------------------------------------------------------------
// ////////////////////////////////////////////////////////////////////////////////
// CDXAStar Class
// ////////////////////////////////////////////////////////////////////////////////
class CGAIDXAStar
{
    struct NODE                    // node structure
    {long f, h;
     int g, tmpg;
     int x, y;
     int NodeNum;
     NODE* Parent;
     NODE* Child[8];                     // a node may have upto 8+(NULL) children.
     NODE* NextNode;                     // for filing purposes
    };

    struct STACK                    // the stack structure
    {NODE* NodePtr;
     STACK* NextStackPtr;
    };

    public:

        // Modify only these 3 public member functions to support Your favorite Map
        CGAIDXAStar(CGAIMap* pMap, int forbiddenTiles);
        ~CGAIDXAStar();
        void InitAstarTileMap(CGAIMap* pMap, int forbiddenTiles);

        // Must be called and be true
        // before getting the node entries. It frees the lists,
        // calls ::Findpath() and returns true if path is accessible
        bool NewPath(int sx, int sy, int dx, int dy);

        bool ReachedGoal(void);                    // Call and check this function before using these 3 following
        void PathNextNode(void)
        {
            PATH = PATH->Parent;
        }
        int NodeGetX(void)
        {
            return(PATH->x);
        }
        int NodeGetY(void)
        {
            return(PATH->y);
        }

        // other usefull functions (do not change them they are used by the A* algorithm)
        int TileNum(int x, int y);                    // returns tilenum
        int FreeTile(int x, int y);                    // returns 1 = true if we can move on it

        bool is8Directions;
        long Width;
        long Height;

    private:
        void BoundaryTiles(void);                    // sets 1's around the map area. To be called before init the A* map
        void FreeNodes(void);                    // frees lists memory

        // The A* Algorithm
        void FindPath(int sx, int sy, int dx, int dy);
        NODE* ReturnBestNode(void);
        void GenerateSuccessors(NODE* BestNode, int dx, int dy);
        void GenerateSucc(NODE* BestNode,int x, int y, int dx, int dy);
        NODE* CheckOPEN(int tilenum);
        NODE* CheckCLOSED(int tilenum);
        void Insert(NODE* Successor);
        void PropagateDown(NODE* Old);
        void Push(NODE* Node);
        NODE* Pop(void);

        NODE* OPEN;                     // the node list pointers
        NODE* CLOSED;
        NODE* PATH;                     // pointer to the best path

        STACK* Stack;

        bool isPath;

        int ROWS,                    // tilemap data members, need to be initialisize
            COLS,                    // with current map's width and height
            TOTAL_TILES;                    // to allocate memory for the
        int* TileMap;                     // pointer to the A* own tilemap data array
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
