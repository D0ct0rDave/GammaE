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
#ifndef CHUDIconH
#define CHUDIconH
// -----------------------------------------------------------------------------
#include "GammaE_E3D.h"
#include "GammaE_Scene.h"
#include "CHUDObject.h"
// -----------------------------------------------------------------------------
class CHUDIcon : public CHUDObject
{
    public:     
        CHUDIcon();
        virtual ~CHUDIcon();
        void SetIcon(CGShader* _poShader);

private:
        CGSceneLeaf* poLeaf;
};

// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
