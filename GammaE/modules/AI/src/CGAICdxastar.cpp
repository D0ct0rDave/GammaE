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
// $Source: /usr/cvsroot/cdx/addons/CDXAStar/CDXASTARDEMO/Cdxastar.cpp,v $
// $Author: mseibert $
//
// $Log: Cdxastar.cpp,v $
// Revision 1.1  1999/05/30 02:32:44  mseibert
// A little demo to show how to use the CDXAStar class
//
// Revision 1.2  1999/05/29 16:17:07  mseibert
// Corrected a bug and enhanced the diagonal pathfinding routine
//
// Revision 1.1.1.1  1999/05/04 23:59:23  bsimser
// Imported addons
//
// $Revision: 1.1 $
// ////////////////////////////////////////////////////////////////////////////////
#include "CGCDXAStar.h"
#include <stdlib.h>
// ----------------------------------------------------------------------------
// //////////////////////////////////////////////////////////////////////////////
// Constructor Destructor                           //
// //////////////////////////////////////////////////////////////////////////////
CGDXAStar::CGDXAStar(CGMap* pMap, int forbiddenTiles)
{
    Stack = ( STACK* )calloc( 1,sizeof(STACK) );
    is8Directions = true;
    Width = 1;
    Height = 1;
    isPath = false;
    OPEN = NULL;
    CLOSED = NULL;
    PATH = NULL;

    // Sets the A* Tilemap append on CDXMap
    InitAstarTileMap(pMap, forbiddenTiles);
}

// //////////////////////////////////////////////////////////////////////////////
CGDXAStar::~CGDXAStar()
{
    FreeNodes();
    free(Stack);
    if ( TileMap )
        delete [] TileMap;
}

// //////////////////////////////////////////////////////////////////////////////
// Public Member Functions                        //
// //////////////////////////////////////////////////////////////////////////////
void CGDXAStar::InitAstarTileMap(CGMap* pMap, int forbiddenTiles)
{
    COLS = pMap->m_Width + 2;                    // note the cols should be 2 more than the map size
    ROWS = pMap->m_Height + 2;                    // because if we have a point at the extremes and we check
    TOTAL_TILES = ROWS * COLS;                    // to see if we can go in all directions, we don't need a
                                                  // special case to check these. (same for rows)
    TileMap = new int[TOTAL_TILES];
    int index = COLS + 1;                    // A* map index
    int CDXMapIndex = 0;
    int tile = 0;

    BoundaryTiles();                    // sets 1's arround the map area

    for ( int i = 0; i < ROWS - 2; i++ )                    // fill up the area with current map data
    {                                    // 1 = obstacle
        for ( int j = 0; j < COLS - 2; j++ )                    // 0 = free
        {
            tile = pMap->GetTile(j, i);

            if ( tile >= forbiddenTiles )                    // the first "forbidden" tiles
            {
                TileMap[index] = 1;                    // in the CDX-tiles-bitmap are not reachable
            }
            else
            {
                TileMap[index] = 0;                    // free
            }
            index++;
        }
        index += 2;                    // jump boundary
    }
}

// //////////////////////////////////////////////////////////////////////////////

bool CGDXAStar::NewPath(int sx,int sy, int dx,int dy)
{
    if ( FreeTile(dx,dy) && FreeTile(sx,sy) && ( TileNum(sx,sy) != TileNum(dx,dy) ) )
    {
        FreeNodes();                    // clear node lists
        FindPath(sx,sy,dx,dy);
        if ( PATH == NULL ) return(false);
        return (isPath = true);
    }
    else
        return (isPath = false);
}

// //////////////////////////////////////////////////////////////////////////////

bool CGDXAStar::ReachedGoal(void)                    // check it's return value before getting
{                                      // the node entries
    if ( !isPath ) return(true);                    // this looks a little bit strange
    if ( &PATH == NULL ) return(true);
    if ( PATH->Parent != NULL )                    // but prevents illegal calls of ::PathNextNode()
        return(false);                    // or ::PathGet*()
    else
        return(true);
}

// //////////////////////////////////////////////////////////////////////////////

int CGDXAStar::TileNum(int x, int y)
{
    return( (y) * COLS + (x) + COLS + 1 );                        // The reason I add COLS+1 to
    // tile number is because I want the tile number to start at the 2nd
    // the column and the 2nd row. Because if we do this we don't have to have
    // a special case to test if at a boundary. In the function BoundaryTiles
    // I place 1's around the boundary, in this way when I call the function
    // FreeTile() it returns false because we can't go there.
}

// //////////////////////////////////////////////////////////////////////////////

int CGDXAStar::FreeTile(int x, int y)                    // returns 1 if tile is free(nothing on it).
{                    // Note: if TileMap[equation]==0 it means free so just !(not) it.
    long i = 0;
    long j = 0;
    bool isFree = true;

    for ( i = 0; i <= Height - 1; i++ )
    {
        for ( j = 0; j <= Width - 1; j++ )
        {
            if ( TileMap[(y + i) * COLS + (x + j) + COLS + 1] )
            {
                isFree = false;
                break;
            }
            if ( !isFree )
            {
                break;
            }
        }
    }

    if ( isFree )
    {
        return(1);
    }
    else
    {
        return(0);
    }
    // return(!TileMap[(y)*COLS + (x)+COLS+1]);
}

// //////////////////////////////////////////////////////////////////////////////
// Private Member Functions                        //
// //////////////////////////////////////////////////////////////////////////////

void CGDXAStar::FreeNodes(void)
{
    NODE* Node, * OldNode;

    if ( OPEN != NULL )
    {
        Node = OPEN->NextNode;
        while ( Node != NULL )
        {
            OldNode = Node;
            Node = Node->NextNode;
            free(OldNode);
        }
    }

    if ( CLOSED != NULL )
    {
        Node = CLOSED->NextNode;
        while ( Node != NULL )
        {
            OldNode = Node;
            Node = Node->NextNode;
            free(OldNode);
        }
    }
}

// //////////////////////////////////////////////////////////////////////////////

void CGDXAStar::BoundaryTiles(void)                    // This function places 1 around the boundary
{                             // so that we don't go there. Also we don't
    int c, index = 0;                    // have to treat the boundaries as a special case

    for ( c = 0; c < TOTAL_TILES; c++ )                    // zero out tiles.
        TileMap[c] = 0;

    for ( c = 0; c < COLS; c++ )                    // place 1's at boundaries.
        TileMap[c] = 1;

    for ( c = 1; c < ROWS - 1; c++ )
    {
        index += COLS;
        TileMap[index] = 1;
        TileMap[index + COLS - 1] = 1;
    }
    index += COLS;

    for ( c = index; c < TOTAL_TILES; c++ )
        TileMap[c] = 1;
}

// //////////////////////////////////////////////////////////////////////////////
// A* Algorithm                                 //
// //////////////////////////////////////////////////////////////////////////////

void CGDXAStar::FindPath(int sx, int sy, int dx, int dy)
{
    NODE* Node, * BestNode;
    int TileNumDest;

    TileNumDest = TileNum(sx, sy);

    OPEN = ( NODE* )calloc( 1,sizeof(NODE) );
    CLOSED = ( NODE* )calloc( 1,sizeof(NODE) );

    Node = ( NODE* )calloc( 1,sizeof(NODE) );
    Node->g = 0;
    Node->h = (dx - sx) * (dx - sx) + (dy - sy) * (dy - sy);                            // should really use sqrt().
    Node->f = Node->g + Node->h;
    Node->NodeNum = TileNum(dx, dy);
    Node->x = dx;
    Node->y = dy;

    OPEN->NextNode = Node;                    // make Open List point to first node
    for (;; )
    {
        BestNode = ReturnBestNode();
        if ( BestNode == NULL )
        {
            break;
        }
        if ( BestNode->NodeNum == TileNumDest )                    // if we've found the end, break and finish
            break;
        GenerateSuccessors(BestNode,sx,sy);
    }
    PATH = BestNode;
}

// //////////////////////////////////////////////////////////////////////////////

CGDXAStar::NODE
* CGDXAStar::ReturnBestNode(void)
{
    NODE* tmp;

    if ( OPEN->NextNode == NULL )
    {
        return(NULL);

// sprintf(message,"No more nodes on OPEN: Perhaps tilenum destination not reachable!");
// MessageBox(0, message, "Error A* Pathfinder", MB_OK | MB_ICONERROR);
// PostQuitMessage(0);
    }

// Pick Node with lowest f, in this case it's the first node in list
// because we sort the OPEN list wrt lowest f. Call it BESTNODE.

    tmp = OPEN->NextNode;                    // point to first node on OPEN
    OPEN->NextNode = tmp->NextNode;                    // Make OPEN point to nextnode or NULL.

// Next take BESTNODE (or temp in this case) and put it on CLOSED

    tmp->NextNode = CLOSED->NextNode;
    CLOSED->NextNode = tmp;

    return(tmp);
}

// //////////////////////////////////////////////////////////////////////////////

void CGDXAStar::GenerateSuccessors(NODE* BestNode, int dx, int dy)
{
    int x, y;
    // If diagonal movements are not allowed, remove the "if" cases for diagonal pathfinding
    // That means that the pathfinding routine only allows left/right/up/down movements

    //
    // Case study by Martin Seibert:
    //
    // If your sprite cannot reach a diagonal Tile because it's size, you must find
    // out, if there is at least one other Tile passable to reach to diagonal Tile
    // Example:
    //
    // # = Not passable
    // . = passable
    // X = Destination
    // * = Player
    //
    // This example won't work!
    //
    // ....#.....  This would cause the Player stuck at the shown position when using the
    // ....###*..  original version of the GenerateSuccessor code.
    // ......X#.#  I've added some additional code to find out if at least one other Tile
    // ..........  is passable to move directly (diagonal) to the destination point.
    // ..........  PS: This example assumes that the Player doesn't fit between two diagonal Tiles
    //
    // This example works!
    //
    // ....#.....  Here the player can move one Tile left, and then one Tile down to reach
    // ....##.*..  the destination Tile!
    // ......X#.#
    // ..........
    // ..........
    //
    //

    if ( is8Directions == true )
    {
        // Upper-Left
        if ( FreeTile(x = BestNode->x - TILESIZE, y = BestNode->y - TILESIZE) && ( FreeTile(x + TILESIZE,y) || FreeTile(x,y + TILESIZE) ) )
            GenerateSucc(BestNode,x,y,dx,dy);
    }

    // Upper
    if ( FreeTile(x = BestNode->x, y = BestNode->y - TILESIZE) )
        GenerateSucc(BestNode,x,y,dx,dy);

    if ( is8Directions == true )
    {
        // Upper-Right
        if ( FreeTile(x = BestNode->x + TILESIZE, y = BestNode->y - TILESIZE) && ( FreeTile(x - TILESIZE,y) || FreeTile(x,y + TILESIZE) ) )
            GenerateSucc(BestNode,x,y,dx,dy);
    }
    // Right
    if ( FreeTile(x = BestNode->x + TILESIZE, y = BestNode->y) )
        GenerateSucc(BestNode,x,y,dx,dy);

    if ( is8Directions == true )
    {
        // Lower-Right
        if ( FreeTile(x = BestNode->x + TILESIZE, y = BestNode->y + TILESIZE) && ( FreeTile(x - TILESIZE,y) || FreeTile(x,y - TILESIZE) ) )
            GenerateSucc(BestNode,x,y,dx,dy);
    }

    // Lower
    if ( FreeTile(x = BestNode->x, y = BestNode->y + TILESIZE) )
        GenerateSucc(BestNode,x,y,dx,dy);

    if ( is8Directions == true )
    {
        // Lower-Left
        if ( FreeTile(x = BestNode->x - TILESIZE, y = BestNode->y + TILESIZE) && ( FreeTile(x + TILESIZE,y) || FreeTile(x,y - TILESIZE) ) )
            GenerateSucc(BestNode,x,y,dx,dy);
    }
    // Left
    if ( FreeTile(x = BestNode->x - TILESIZE, y = BestNode->y) )
        GenerateSucc(BestNode,x,y,dx,dy);

/*
    // Upper-Left
    if ( FreeTile(x=BestNode->x-TILESIZE, y=BestNode->y-TILESIZE) && FreeTile(x-1,y-1))
        GenerateSucc(BestNode,x,y,dx,dy);
    // Upper
    if ( FreeTile(x=BestNode->x, y=BestNode->y-TILESIZE) && FreeTile(x,y-1))
        GenerateSucc(BestNode,x,y,dx,dy);
    // Upper-Right
    if ( FreeTile(x=BestNode->x+TILESIZE, y=BestNode->y-TILESIZE) && FreeTile(x+1,y-1))
        GenerateSucc(BestNode,x,y,dx,dy);
    // Right
    if ( FreeTile(x=BestNode->x+TILESIZE, y=BestNode->y) && FreeTile(x+1,y))
        GenerateSucc(BestNode,x,y,dx,dy);
    // Lower-Right
    if ( FreeTile(x=BestNode->x+TILESIZE, y=BestNode->y+TILESIZE) && FreeTile(x+1,y+1))
        GenerateSucc(BestNode,x,y,dx,dy);
    // Lower
    if ( FreeTile(x=BestNode->x, y=BestNode->y+TILESIZE) && FreeTile(x,y+1))
        GenerateSucc(BestNode,x,y,dx,dy);
    // Lower-Left
    if ( FreeTile(x=BestNode->x-TILESIZE, y=BestNode->y+TILESIZE) && FreeTile(x-1,y+1))
        GenerateSucc(BestNode,x,y,dx,dy);
    // Left
    if ( FreeTile(x=BestNode->x-TILESIZE, y=BestNode->y) && FreeTile(x-1,y))
        GenerateSucc(BestNode,x,y,dx,dy);
 */
}

// //////////////////////////////////////////////////////////////////////////////

void CGDXAStar::GenerateSucc(NODE* BestNode,int x, int y, int dx, int dy)
{
    int g, TileNumS, c = 0;
    NODE* Old, * Successor;

    g = BestNode->g + 1;                    // g(Successor)=g(BestNode)+cost of getting from BestNode to Successor
    TileNumS = TileNum(x,y);                    // identification purposes

    if ( ( Old = CheckOPEN(TileNumS) ) != NULL )                    // if equal to NULL then not in OPEN list, else it returns the Node in Old
    {
        for ( c = 0; c < 8; c++ )
            if ( BestNode->Child[c] == NULL )                    // Add Old to the list of BestNode's Children (or Successors).
                break;
        BestNode->Child[c] = Old;

        if ( g < Old->g )                    // if our new g value is < Old's then reset Old's parent to point to BestNode
        {
            Old->Parent = BestNode;
            Old->g = g;
            Old->f = g + Old->h;
        }
    }
    else
    if ( ( Old = CheckCLOSED(TileNumS) ) != NULL )                    // if equal to NULL then not in OPEN list, else it returns the Node in Old
    {
        for ( c = 0; c < 8; c++ )
            if ( BestNode->Child[c] == NULL )                    // Add Old to the list of BestNode's Children (or Successors).
                break;
        BestNode->Child[c] = Old;

        if ( g < Old->g )                    // if our new g value is < Old's then reset Old's parent to point to BestNode
        {
            Old->Parent = BestNode;
            Old->g = g;
            Old->f = g + Old->h;
            PropagateDown(Old);                    // Since we changed the g value of Old, we need
                                                   // to propagate this new value downwards, i.e.
                                                   // do a Depth-First traversal of the tree!
        }
    }
    else
    {
        Successor = ( NODE* )calloc( 1,sizeof(NODE) );
        Successor->Parent = BestNode;
        Successor->g = g;
        Successor->h = (x - dx) * (x - dx) + (y - dy) * (y - dy);                            // should do sqrt(), but since we don't really
        Successor->f = g + Successor->h;                    // care about the distance but just which branch looks
        Successor->x = x;                    // better this should suffice. Anyayz it's faster.
        Successor->y = y;
        Successor->NodeNum = TileNumS;
        Insert(Successor);                    // Insert Successor on OPEN list wrt f
        for ( c = 0; c < 8; c++ )
            if ( BestNode->Child[c] == NULL )                    // Add Old to the list of BestNode's Children (or Successors).
                break;
        BestNode->Child[c] = Successor;
    }
}

// //////////////////////////////////////////////////////////////////////////////

CGDXAStar::NODE
* CGDXAStar::CheckOPEN(int tilenum)
{
    NODE* tmp;

    tmp = OPEN->NextNode;
    while ( tmp != NULL )
    {
        if ( tmp->NodeNum == tilenum )
            return (tmp);
        else
            tmp = tmp->NextNode;
    }
    return(NULL);
}

// //////////////////////////////////////////////////////////////////////////////

CGDXAStar::NODE
* CGDXAStar::CheckCLOSED(int tilenum)
{
    NODE* tmp;

    tmp = CLOSED->NextNode;

    while ( tmp != NULL )
    {
        if ( tmp->NodeNum == tilenum )
            return(tmp);
        else
            tmp = tmp->NextNode;
    }
    return(NULL);
}

// //////////////////////////////////////////////////////////////////////////////

void CGDXAStar::Insert(NODE* Successor)
{
    NODE* tmp1, * tmp2;
    int f;

    if ( OPEN->NextNode == NULL )
    {
        OPEN->NextNode = Successor;
        return;
    }

    // insert into OPEN successor wrt f
    f = Successor->f;
    tmp1 = OPEN;
    tmp2 = OPEN->NextNode;

    while ( (tmp2 != NULL) && (tmp2->f < f) )
    {
        tmp1 = tmp2;
        tmp2 = tmp2->NextNode;
    }

    Successor->NextNode = tmp2;
    tmp1->NextNode = Successor;
}

// //////////////////////////////////////////////////////////////////////////////

void CGDXAStar::PropagateDown(NODE* Old)
{
    int c, g;
    NODE* Child, * Father;

    g = Old->g;                    // alias.
    for ( c = 0; c < 8; c++ )
    {
        if ( (Child = Old->Child[c]) == NULL )                      // create alias for faster access.
            break;
        if ( g + 1 < Child->g )
        {
            Child->g = g + 1;
            Child->f = Child->g + Child->h;
            Child->Parent = Old;                    // reset parent to new path.
            Push(Child);                    // Now the Child's branch need to be
        }                    // checked out. Remember the new cost must be propagated down.
    }

    while ( Stack->NextStackPtr != NULL )
    {
        Father = Pop();
        for ( c = 0; c < 8; c++ )
        {
            if ( (Child = Father->Child[c]) == NULL )                      // we may stop the propagation 2 ways: either
                break;
            if ( Father->g + 1 < Child->g )                    // there are no children, or that the g value of
            {                          // the child is equal or better than the cost we're propagating
                Child->g = Father->g + 1;
                Child->f = Child->g + Child->h;
                Child->Parent = Father;
                Push(Child);
            }
        }
    }
}

// //////////////////////////////////////////////////////////////////////////////
// STACK FUNCTIONS                               //
// //////////////////////////////////////////////////////////////////////////////

void CGDXAStar::Push(NODE* Node)
{
    STACK* tmp;

    tmp = ( STACK* )calloc( 1,sizeof(STACK) );
    tmp->NodePtr = Node;
    tmp->NextStackPtr = Stack->NextStackPtr;
    Stack->NextStackPtr = tmp;
}

// //////////////////////////////////////////////////////////////////////////////

CGDXAStar::NODE
* CGDXAStar::Pop(void)
{
    NODE* tmp;
    STACK* tmpSTK;

    tmpSTK = Stack->NextStackPtr;
    tmp = tmpSTK->NodePtr;

    Stack->NextStackPtr = tmpSTK->NextStackPtr;
    free(tmpSTK);
    return(tmp);
}
// ----------------------------------------------------------------------------
