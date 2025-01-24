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
#ifndef GCollision_h
#define GCollision_h 1
// -----------------------------------------------------------------------------

#include "CollisionSystem/CCOL_CollisionSystem.h"
#include "CollisionUtils/CCOL_TriList_BVRayTest.h"
#include "COL_TriList/CCOL_TriListGen.h"
#include "COL_TriList/CCOL_Scn_TriListGen.h"
#include "COL_TriList/CCOL_TRN_TriListGen.h"
#include "COL_Testers/COL_SceneTest/COL_MeshTest/CCOL_MT_CommonMesh.h"
#include "COL_Testers/COL_SceneTest/COL_MeshTest/CCOL_MT_TerrainMesh.h"
#include "COL_Testers/COL_SceneTest/CCOL_Scn_ColTester.h"

#include "COL_Testers/COL_StaticTest/CCOL_ST_Box.h"
#include "COL_Testers/COL_StaticTest/CCOL_ST_Sphere.h"
#include "COL_Testers/COL_StaticTest/CCOL_ST_ColTester.h"
#include "COL_Testers/COL_StaticTest/CCOL_ST_Point.h"
#include "COL_Testers/COL_StaticTest/CCOL_ST_Sphere.h"
#include "COL_Testers/COL_StaticTest/CCOL_ST_Tris.h"

#include "COL_Testers/COL_DynamicTest/CCOL_DT_Box.h"
#include "COL_Testers/COL_DynamicTest/CCOL_DT_Sphere.h"
#include "COL_Testers/COL_DynamicTest/CCOL_DT_ColTester.h"
#include "COL_Testers/COL_DynamicTest/CCOL_DT_Point.h"
#include "COL_Testers/COL_DynamicTest/CCOL_DT_Sphere.h"
#include "COL_Testers/COL_DynamicTest/CCOL_DT_Tri.h"
// -----------------------------------------------------------------------------
// Allow GammaE libs to access without scope the declarations in the module
#ifdef GAMMAE_LIB
using namespace GammaE::Collision;
#endif
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
