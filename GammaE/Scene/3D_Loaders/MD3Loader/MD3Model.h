#ifndef MD3ModelH
#define MD3ModelH

typedef struct
{ 
	char	id[4];				// id = IDP3
	int		version;			// version = 15
	char	filename[68];
	int		numBoneFrames;
	int		numTags;
	int		numMeshes;
	int		numMaxSkins;
	int		headerlength;
	int		tag_start;
	int		tag_end;
	int		filesize;
} md3_header_t;
	
typedef struct
{
	float	mins[3];
	float	maxs[3];
	float	position[3];
	float	scale;
	char		creator[16];
} boneframe_t;

typedef struct
{
	char		name[64];
	float	position[3];
	float	rotation[3][3];
} tag_t;

typedef struct
{
	char		id[4];
	char		name[68];
	int		numMeshFrames;
	int		numSkins;
	int      numVertexs;
	int		numTriangles;
	int		tri_start;
	int		headersize;
	int      texvec_start;
	int		vertex_start;
	int		meshsize;
} mesh_header_t;

typedef struct
{
	char		name[68];
	
} skin_t;

typedef struct{
	char name[68];
}skin_tag_entry_t;

typedef struct{
	char name[68];
	char texture[68];
} skin_mesh_entry_t;

typedef struct{
	skin_mesh_entry_t *skinmeshes;
	int				iNumSkinMeshes;	
	skin_tag_entry_t  *skintags;
	int				iNumSkinTags;


} skin_file_t;

typedef struct
{
	int		vertex[3];
} Q3triangle_t;

typedef struct
{
	float	texvec[2];
} tex_coord_t;

typedef struct
{
	signed		short	Vec[3];
	unsigned	char	Normal[2];
} vertice_t;

typedef struct
{
	mesh_header_t	mesh_h;
	skin_t			*skins;
	Q3triangle_t		*triangles;
	tex_coord_t		*tex_coords;
	vertice_t		*vertices;

	//CTexture		texture;
	unsigned char	settexture; // 1 - On 0 - Off
} mesh_t;

typedef struct
{
	int		first_frame, num_frames, looping_frames, frames_per_second;
} anim_t;

typedef enum {
	BOTH_DEATH1,
	BOTH_DEAD1,
	BOTH_DEATH2,
	BOTH_DEAD2,
	BOTH_DEATH3,
	BOTH_DEAD3,

	TORSO_GESTURE,

	TORSO_ATTACK,
	TORSO_ATTACK2,

	TORSO_DROP,
	TORSO_RAISE,

	TORSO_STAND,
	TORSO_STAND2,

	LEGS_WALKCR,
	LEGS_WALK,
	LEGS_RUN,
	LEGS_BACK,
	LEGS_SWIM,

	LEGS_JUMP,
	LEGS_LAND,

	LEGS_JUMPB,
	LEGS_LANDB,

	LEGS_IDLE,
	LEGS_IDLECR,

	LEGS_TURN,

	MAX_ANIMATIONS
} animNumber_t;


#endif