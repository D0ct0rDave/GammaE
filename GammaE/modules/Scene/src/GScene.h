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
#ifndef GScene_h
#define GScene_h 1
// ----------------------------------------------------------------------------
#include "GSceneEnums.h"

#include "CGSceneNode.h"
#include "CGSceneGroup.h"
#include "CGSceneTransf.h"
#include "CGSceneInstance.h"
#include "CGSceneCamera.h"
#include "CGSceneLeaf.h"
#include "CGSceneScreenRect.h"
#include "CGSceneSwitch.h"

#include "Animation/CGSceneAnimCfg.h"
#include "Animation/CGSceneAnimNode.h"
#include "Animation/CGSceneAnimTransf.h"
#include "Animation/CGSceneAnimMesh.h"
#include "Animation/CGSceneAnimGroup.h"

#include "3D_Loaders/3DSLoader/CLoader3DS.h"
#include "3D_Loaders/MD2Loader/CLoaderMD2.h"
#include "3D_Loaders/MD3Loader/CLoaderMD3.h"
#include "3D_Loaders/BSP2Loader/CLoaderBSP2.h"

#include "3D_Loaders/GEMLoader/GEMFile.h"
#include "3D_Loaders/GEMLoader/CLoaderGEM.h"
#include "3D_Savers/GEMSaver/CSaverGEM.h"

#include "Visitors/CGSCNVBoundVolBuilder.h"
#include "Visitors/CGSCNVRenderer.h"
#include "Visitors/CGSCNVVisibilityChecker.h"
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
