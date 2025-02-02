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
#ifndef GEMFileH
#define GEMFileH
// ----------------------------------------------------------------------------
#include "GSceneEnums.h"
#include "GammaE_Misc.h"
#include "GammaE_FileSys.h"
// ----------------------------------------------------------------------------
const uint GEM_FILE_IDENTIFIER = MAKE_RIFF_ID('G','E','M','D');

#define             GEM_MAJOR_VERSION           1
#define             GEM_MINOR_VERSION           1

const uint GEM_NULL_IDENTIFIER = MAKE_RIFF_ID('N','U','L','L');
const uint GEM_LEAF_IDENTIFIER = MAKE_RIFF_ID('L','E','A','F');
const uint GEM_NODE_IDENTIFIER = MAKE_RIFF_ID('N','O','D','E');
const uint GEM_GROUP_IDENTIFIER = MAKE_RIFF_ID('G','R','U','P');
const uint GEM_TRANSF_IDENTIFIER = MAKE_RIFF_ID('X','F','R','M');
const uint GEM_ANIMNODE_IDENTIFIER = MAKE_RIFF_ID('A','O','B','J');
const uint GEM_ANIMGROUP_IDENTIFIER = MAKE_RIFF_ID('A','N','O','D');
const uint GEM_ANIMMESH_IDENTIFIER = MAKE_RIFF_ID('A','M','S','H');
const uint GEM_ANIMTRANSF_IDENTIFIER = MAKE_RIFF_ID('A','T','R','A');
const uint GEM_ANIMACTIONSET_IDENTIFIER = MAKE_RIFF_ID('A','C','F','G');
const uint GEM_CAMERA_IDENTIFIER = MAKE_RIFF_ID('C','A','M',' ');
const uint GEM_BSPNODE_IDENTIFIER = MAKE_RIFF_ID('B','S','P','N');
const uint GEM_MUX_IDENTIFIER = MAKE_RIFF_ID('M','U','X',' ');
const uint GEM_MESH_IDENTIFIER = MAKE_RIFF_ID('M','E','S','H');
// ----------------------------------------------------------------------------
inline uint GEMFile_Translate_TypeID2FileID(ESceneNodeType _eType)
{
    switch ( _eType )
    {
        case SNT_NULL:           return (GEM_NULL_IDENTIFIER);

        case SNT_Node:           return (GEM_NODE_IDENTIFIER);

        case SNT_Leaf:           return (GEM_LEAF_IDENTIFIER);

        case SNT_Group:          return (GEM_GROUP_IDENTIFIER);

        case SNT_Camera:         return (GEM_CAMERA_IDENTIFIER);

        case SNT_BSPNode:        return (GEM_BSPNODE_IDENTIFIER);

        case SNT_Mux:            return (GEM_MUX_IDENTIFIER);

        // Animation nodes
        case SNT_AnimNode:       return (GEM_ANIMNODE_IDENTIFIER);

        case SNT_AnimGroup:      return (GEM_ANIMGROUP_IDENTIFIER);

        case SNT_AnimMesh:       return (GEM_ANIMMESH_IDENTIFIER);

        case SNT_AnimTransf:     return (GEM_ANIMTRANSF_IDENTIFIER);

        case SNT_AnimActionSet:  return (GEM_ANIMACTIONSET_IDENTIFIER);

        default:    return (0);
    }
}
// ----------------------------------------------------------------------------
inline ESceneNodeType GEMFile_Translate_FileID2TypeID2(uint uiFileID)
{
    switch ( uiFileID )
    {
        case MAKE_RIFF_ID('N','U','L','L'): return (SNT_NULL);

        case MAKE_RIFF_ID('N','O','D','E'): return (SNT_Node);

        case MAKE_RIFF_ID('L','E','A','F'): return (SNT_Leaf);

        case MAKE_RIFF_ID('G','R','U','P'): return (SNT_Group);

        // Animation nodes
        case MAKE_RIFF_ID('A','O','B','J'): return (SNT_AnimNode);

        case MAKE_RIFF_ID('A','N','O','D'): return (SNT_AnimGroup);

        case MAKE_RIFF_ID('A','M','S','H'): return (SNT_AnimMesh);

        case MAKE_RIFF_ID('A','T','R','A'): return (SNT_AnimTransf);

        case MAKE_RIFF_ID('A','C','F','G'): return (SNT_AnimActionSet);

        case MAKE_RIFF_ID('C','A','M',' '): return (SNT_Camera);

        case MAKE_RIFF_ID('B','S','P','N'): return (SNT_BSPNode);

        case MAKE_RIFF_ID('M','U','X',' '): return (SNT_Mux);

        default:    return (SNT_NULL);
    }
}
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
