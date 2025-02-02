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
#include "CHUDIcon.h"
// -----------------------------------------------------------------------------
CHUDIcon::CHUDIcon()
{
    EGBoundingVolumeType eOldType = CGGraphBVFactory::eGetBVMode();
    CGGraphBVFactory::SetBVMode(EGBoundingVolumeType::BVT_AABB);

    CGMeshRect* poMesh = mNew CGMeshRect;

    poLeaf = mNew CGSceneLeaf;
    poLeaf->SetMesh(poMesh);

    SetObject(poLeaf);

    CGSCNVBoundVolBuilder::I()->Visit(this);
    
    CGGraphBVFactory::SetBVMode(eOldType);
}
// -----------------------------------------------------------------------------
void CHUDIcon::SetIcon(CGShader* _poShader)
{
    poLeaf->SetShader(_poShader);
}
// -----------------------------------------------------------------------------
