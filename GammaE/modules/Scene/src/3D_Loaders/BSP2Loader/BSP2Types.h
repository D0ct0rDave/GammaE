// ------------------------------------------------------------
#ifndef BSP2TypesH
#define BSP2TypesH
// ------------------------------------------------------------

#define BSP_ENTITITES_LUMP  0
#define BSP_PLANES_LUMP     1
#define BSP_VERTEXS_LUMP    2
#define BSP_VIS_LUMP        3
#define BSP_NODES_LUMP      4
#define BSP_TEXINFO_LUMP    5
#define BSP_FACES_LUMP      6
#define BSP_LMAPS_LUMP      7
#define BSP_LEAVES_LUMP     8
#define BSP_LFT_LUMP        9
#define BSP_LBT_LUMP        10
#define BSP_EDGES_LUMP      11
#define BSP_FET_LUMP        12
#define BSP_MODELS_LUMP     13
#define BSP_BRUSHES_LUMP    14
#define BSP_BSIDES_LUMP     15
#define BSP_POP_LUMP        16
#define BSP_AREAS_LUMP      17
#define BSP_APORTALS_LUMP   18

// ------------------------------------------------------------

#ifdef _MSC_
#pragma pack(push,bsp2File);
#pragma pack(1)
#endif

// ------------------------------------------------------------

struct bsp_point3f
{
   float x;
   float y;
   float z;
};

struct bsp_point3s
{
   short x;
   short y;
   short z;
};

struct bsp_lump
{
   unsigned int offset;
   unsigned int lenght;
};

struct bsp_header
{
   unsigned int magic;
   unsigned int version;
   bsp_lump lump[19];
};

struct bsp_edge
{
   unsigned short start;
   unsigned short end;
};

struct bsp_face
{
   unsigned short plane;
   unsigned short plane_side;

   unsigned int first_edge;
   unsigned short num_edges;

   unsigned short texture_info;

   unsigned char lightmap_styles[4];
   unsigned int lightmap_offset;
};

struct bsp_face_edge
{
   unsigned int index;
};

struct bsp_plane
{
   bsp_point3f normal;
   float distance;
   unsigned int type;          // 0:X ,1:Y ,2:Z, 3:any
};

struct bsp_node
{
   unsigned int plane;
   int front_child;            // negative idxs are leafs: leaf = -(idx+1)
   int back_child;

   bsp_point3s bbox_min;
   bsp_point3s bbox_max;

   unsigned short first_face;
   unsigned short num_faces;
};

struct bsp_leaf
{
   unsigned int brush_or;
   unsigned short cluster;
   unsigned short area;

   bsp_point3s bbox_min;
   bsp_point3s bbox_max;

   unsigned short first_leaf_face;
   unsigned short num_leaf_faces;

   unsigned short first_leaf_brush;
   unsigned short num_leaf_brushes;
};

struct bsp_leaf_face
{
   unsigned short index;
};

struct bsp_texinfo
{
   bsp_point3f u_axis;
   float u_offset;
   bsp_point3f v_axis;
   float v_offset;

   unsigned int flags;
   unsigned int value;

   char texture_name[32];
   unsigned int next_texinfo;
};

struct bsp_vis_offset
{
   unsigned int pvs;
   unsigned int phs;
};

struct bsp_vis
{
   unsigned int iNumVisOfs;
   bsp_vis_offset *pVisOfs;
};

#ifdef _MSC_
#pragma pack(pop,bsp2File);
#endif

// ------------------------------------------------------------
#endif // ifndef BSP2TypesH
// ------------------------------------------------------------
