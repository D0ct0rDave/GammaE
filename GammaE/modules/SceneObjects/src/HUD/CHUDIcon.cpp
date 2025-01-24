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
// -----------------------------------------------------------------------------
#include "CHUDIcon.h"
// -----------------------------------------------------------------------------
CHUDIcon::CHUDIcon()
{
    eGraphBV_TypeID eOldType = CGraphBV_Manager::eGetBVMode();
    CGraphBV_Manager::SetBVMode(eGraphBV_Box);

    CGMeshRect* poMesh;
    poMesh = mNew CGMeshRect;

    poLeaf = mNew CGSceneLeaf;
    poLeaf->SetMesh(poMesh);

    SetObject(poLeaf);

    CGraphBV_Manager::SetBVMode(eOldType);
    ComputeBoundVol();
}
// -----------------------------------------------------------------------------
CGraphBV* CHUDIcon::poCreateBoundVol ()
{
    eGraphBV_TypeID eOldType = CGraphBV_Manager::eGetBVMode();
    CGraphBV_Manager::SetBVMode(eGraphBV_Box);

    CGraphBV* poBVol = CGraphBV_Manager::poCreate();

    CGraphBV_Manager::SetBVMode(eOldType);

    return(poBVol);
}
// -----------------------------------------------------------------------------
CHUDIcon::~CHUDIcon()
{
    // CGSceneMux::~CGSceneMux();
}
// -----------------------------------------------------------------------------
void CHUDIcon::SetIcon(CE3D_Shader* _poShader)
{
    poLeaf->SetShader(_poShader);
}
// -----------------------------------------------------------------------------
