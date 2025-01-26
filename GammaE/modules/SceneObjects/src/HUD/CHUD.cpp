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
// ----------------------------------------------------------------------------
#include "CHUD.h"
// ----------------------------------------------------------------------------
CHUDElem::CHUDElem(CGSceneNode* _poObj, float _x, float _y, float _tx, float _ty)
{
    Setup(_poObj,_x,_y,_tx,_ty);
}

CHUDElem::~CHUDElem()
{
    if ( poObj )
        poObj->Deref();
}

void CHUDElem::Setup(CGSceneNode* _poObj, float _x, float _y, float _tx, float _ty)
{
    x = _x;
    y = _y;
    tx = _tx;
    ty = _ty;

    poObj = _poObj;

    if ( poObj )
        poObj->Ref();
}
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// HeadUpDisplay
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
CHUD::CHUD()
{
    bFrustumTest = false;
}
CHUD::CHUD(uint _uiMaxElems)
{
    Init(_uiMaxElems);
}

CHUD::~CHUD()
{
}

void CHUD::Init(uint _uiMaxElems)
{
}
// ----------------------------------------------------------------------------
uint CHUD::uiAddObject(CGSceneNode* _poObj, float _x, float _y, float _tx, float _ty,const CGString& _sName)
{
    // modify previously existent entry
    for ( uint i = 0; i < m_oHUDObjs.uiNumElems(); i++ )
        if ( m_oHUDObjs[i]->poObj == _poObj )
        {
            m_oHUDObjs[i]->Setup(_poObj,_x,_y,_tx,_ty);
            return(i);
        }

    // Add new entry
    CHUDElem* poHO = mNew CHUDElem(_poObj,_x,_y,_tx,_ty);
    uint uiObj = m_oHUDObjs.uiAddVar(_sName, poHO );

    return(uiObj);
}
// ----------------------------------------------------------------------------
void CHUD::Invalidate ()
{
    m_oHUDObjs.Clear();
}
// ----------------------------------------------------------------------------
void CHUD::Render ()
{
    float fRatio = CGRenderer::I()->fGetAspectRatio();

    float TX,TY,TZ;
    float XTrans,YTrans,ZTrans;

    CGBoundingVolume* BVol;

    bool bDefMode;

    // Save Render State
    bDefMode = CGRenderer::I()->UsingDefferredMode();

    // Setup our Render State
    CGRenderer::I()->DisableDefferredMode();

    CGRenderer::I()->PushCameraMatrix();
    CGRenderer::I()->ClearCameraMatrix();
    CGRenderer::I()->PushProjectorMatrix();
    CGRenderer::I()->ClearProjectorMatrix();
    CGRenderer::I()->PushWorldMatrix();
    CGRenderer::I()->ClearWorldMatrix();

    // glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

    // A partir de ahora trabajamos con coordenadas de pantalla normalizadas

    // Render all the objects
    for ( uint i = 0; i < m_oHUDObjs.uiNumElems(); i++ )
    {
        if ( m_oHUDObjs[i]->poObj )
        {
            CGRenderer::I()->PushWorldMatrix();
            // CGRenderer::I()->PushCameraMatrix();

            BVol = m_oHUDObjs[i]->poObj->poGetBV();

            TX = BVol->GetRange(0);
            if ( !TX ) TX = 1.0f;
            TY = BVol->GetRange(1);
            if ( !TY ) TY = 1.0f;
            TZ = BVol->GetRange(2);
            if ( !TZ ) TZ = 1.0f;

            XTrans = -BVol->oGetCenter().x;
            YTrans = -BVol->oGetCenter().y;
            ZTrans = -BVol->oGetCenter().z;

            // Los objetos están definidos en un rango (0..1)(0..1), tanto en el tamaño como en la posición.

            // Move the object to the left/top corner: screen oringin (<> world origin !)		(-1.0f, 1.0f)
            // Rescale to the desired object size.	(-1.0f, 1.0f)
            // CGRenderer::I()->Scale    (2.0f,2.0f,1);

            // Translate to to range (0.0f,1.0f)
            // CGRenderer::I()->Translate(-1.0f*fRatio,1.0f-m_oHUDObjs[cObj].ty,0.0f);

            CGMatrix4x4 oM;
            oM.LoadIdentity();

            // Translate to final position	(-1.0f, 1.0f)
            // CGRenderer::I()->Translate(fX,,0.0f);
            oM.Translate(-1.0f,1.0f,0.0f);

            // Translate to the desired position
            oM.Translate(m_oHUDObjs[i]->x / 0.5f,-m_oHUDObjs[i]->y / 0.5f,0.0f);

            // Scale to the desired size
            oM.Scale    (m_oHUDObjs[i]->tx,m_oHUDObjs[i]->ty,1);

            // Translate to to range (0.0f,2.0f)
            oM.Translate(1.0f,-1.0f,0.0f);

            // Translate to to range (-1.0f,1.0f)
            oM.Scale    (2.0f,2.0f,1);

            // Rescale to the range. Object range: (-0.5..0.5)
            oM.Scale    (1.0f / TX,-1.0f / TY,1.0f / TZ);

            // Center object at origin
            oM.Translate(XTrans,YTrans,ZTrans);

            // Multiply the world matrix by the computed one
            CGRenderer::I()->MultiplyMatrix(&oM);

            // Render the object
            m_oHUDObjs[i]->poObj->Render();

            // CGRenderer::I()->PopCameraMatrix();
            CGRenderer::I()->PopWorldMatrix();
        }
    }

    // glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    CGRenderer::I()->PopWorldMatrix();
    CGRenderer::I()->PopCameraMatrix();
    CGRenderer::I()->PopProjectorMatrix();

    // Restore previous render state
    if ( bDefMode ) CGRenderer::I()->EnableDefferredMode();
}
// ----------------------------------------------------------------------------
int CHUD::iCulled ()
{
    return(0);
}
// ----------------------------------------------------------------------------
CGBoundingVolume* CHUD::poGetBV ()
{
    return (NULL);
}
// ----------------------------------------------------------------------------
void CHUD::ComputeBoundVol ()
{
}
// ----------------------------------------------------------------------------
