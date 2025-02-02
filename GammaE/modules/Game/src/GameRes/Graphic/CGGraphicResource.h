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
#ifndef CGGraphicResourceH
#define CGGraphicResourceH
// -----------------------------------------------------------------------------
class CGVect3;
class CGSceneNode;
// -----------------------------------------------------------
#include "GammaE_Math.h"
#include "GammaE_Misc.h"
#include "GammaE_Scene.h"
// -----------------------------------------------------------
class CGControlPoint
{
    public:
        CGString m_sName;
        CGVect3 m_oPos;

        unsigned char m_ucCPType;
        unsigned char m_ucSubType;
        unsigned char m_ucDir;
        unsigned char m_ucPad;
};
// -----------------------------------------------------------------------------
class CGGraphicResource : public CGResource
{
    public:
        CGGraphicResource(CGSceneNode* _poModel = NULL)
        {
            m_poModel = _poModel;
        }

        // / Retrieves a named control point
        CGControlPoint* poGetCP(const CGString& _sCPName);

        // / Gets the model associated with the graphic resource
        CGSceneNode* poGetModel()
        {
            return (m_poModel);
        }

        // / Sets the model associated with the graphic resource
        void SetModel(CGSceneNode* _poModel)
        {
            m_poModel = _poModel;
        }

    private:
        CGSceneNode* m_poModel;
    public:
        CGDynArray <CGControlPoint> m_oCPs;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
