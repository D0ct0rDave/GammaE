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
#ifndef CHUD_h
#define CHUD_h 1
// -----------------------------------------------------------------------------
#include "GammaE_Scene.h"
// -----------------------------------------------------------------------------
class CHUDElem
{
    public:
        CHUDElem() : x(0),y(0),tx(0),ty(0),poObj(NULL)
        {
        }
        CHUDElem(CGSceneNode* _poObj, float _x, float _y, float _tx, float _ty);
        ~CHUDElem();

        float x;
        float y;
        float tx;
        float ty;
        CGSceneNode* poObj;

        void Setup(CGSceneNode* _poObj, float _x, float _y, float _tx, float _ty);
};
// -----------------------------------------------------------------------------
class CHUD : public CGSceneNode
{
    public:
        CHUD();
        CHUD(uint _uiMaxElems);
        void Init(uint _uiMaxElems);
        virtual ~CHUD();

        uint uiAddObject(CGSceneNode* _poObj, float _x, float _y, float _tx, float _ty,const CGString& _sName = "");
        CHUDElem* poGetElem(const CGString& _sName)
        {
            return( m_oHUDObjs.oGetVar(_sName) );
        }
        CHUDElem* poGetElem(uint _uiElem)
        {
            return ( m_oHUDObjs.oGetElem(_uiElem) );
        }

        CGraphBV* poCreateBoundVol ()
        {
            return(NULL);
        }

        void Invalidate();

        virtual void Render();
        virtual int iCulled();
        virtual CGraphBV* poGetBV();
        virtual void ComputeBoundVol();

        virtual void Accept(CGSceneVisitor* _poObj)
        {
        }

    protected:
        CGLookupArray <CHUDElem*> m_oHUDObjs;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
