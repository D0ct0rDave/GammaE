//---------------------------------------------------------------------------
#include "ASE_Tokens.h"

//---------------------------------------------------------------------------
// Tokens de caracter general
//---------------------------------------------------------------------------
char *TokenTable[] ={
    "*3DSMAX_ASCIIEXPORT",
    "*COMMENT",
    "*SCENE",
    "*MATERIAL_LIST",
    "*GEOMOBJECT"
};
//---------------------------------------------------------------------------
// Tokens del bloque SCENE
//---------------------------------------------------------------------------
 char * Scene_TokenTable[] = {
    "*SCENE_FILENAME",
    "*SCENE_FIRSTFRAME",
    "*SCENE_LASTFRAME",
    "*SCENE_FRAMESPEED",
    "*SCENE_TICKSPERFRAME",
    "*SCENE_BACKGROUND_STATIC",
    "*SCENE_AMBIENT_STATIC"
};

//---------------------------------------------------------------------------
// Tokens del bloque material list
//---------------------------------------------------------------------------
 char * MaterialList_TokenTable[] = {
    "*MATERIAL_COUNT",
    "*MATERIAL"
};
//---------------------------------------------------------------------------
// Tokens del bloque material
// ... a completar
//---------------------------------------------------------------------------
 char * SceneTokenTable[] = {
    "*MATERIAL_NAME",
    "**MATERIAL_CLASS"
};

//---------------------------------------------------------------------------
// Tokens del bloque GEOMOBJECT
//---------------------------------------------------------------------------
 char *Mesh_TokenTable[] = {
    "*TIMEVALUE",
    "*MESH_NUMVERTEX",
    "*MESH_NUMFACES",
    "*MESH_VERTEX_LIST",
    "*MESH_FACE_LIST",
    "*MESH_NUMTVERTE",
    "*MESH_TVERTLIST",
    "*MESH_NUMTVFACES",
    "*MESH_TFACELIS"
};
//---------------------------------------------------------------------------
