// ----------------------------------------------------------------------------
/*! \class CGSceneGroup
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#include <assert.h>
#include "GammaE_Mem.h"
#include "CGSceneGroup.h"
// ----------------------------------------------------------------------------
CGSceneGroup::CGSceneGroup()
{
    m_eNodeType = SNT_Group;
    m_poBV = CGGraphBVFactory::poCreate();
}
// ----------------------------------------------------------------------------
CGSceneGroup::CGSceneGroup(uint _uiMaxSubObjs)
{
    Init(_uiMaxSubObjs);
}
// ----------------------------------------------------------------------------
CGSceneGroup::~CGSceneGroup()
{
    Clear();

    if ( m_poBV )
        mDel m_poBV;
}
// ----------------------------------------------------------------------------
void CGSceneGroup::Init(uint _uiMaxSubObjs)
{
    m_poSubObj.Init(_uiMaxSubObjs);

    // Adds null objects to initialize the array
    for ( uint i = 0; i < _uiMaxSubObjs; i++ )
        m_poSubObj.iAdd(NULL);
}
// ----------------------------------------------------------------------------
void CGSceneGroup::Clear()
{
    // Free SubObj
    for ( uint cObj = 0; cObj < m_poSubObj.uiNumElems(); cObj++ )
    {
        if ( m_poSubObj[cObj] )
            m_poSubObj[cObj]->Deref();
    }
    m_poSubObj.Clear();
}
// ----------------------------------------------------------------------------
void CGSceneGroup::DelObject(uint _uiPos)
{
    assert( ( _uiPos < m_poSubObj.uiNumElems() ) && "Object out of bounds" );

    if ( m_poSubObj[_uiPos] )
    {
        m_poSubObj[_uiPos]->Deref();
        m_poSubObj[_uiPos] = NULL;
    }
}
// ----------------------------------------------------------------------------
int CGSceneGroup::iAddObject(CGSceneNode* _poObj)
{
    if (_poObj == NULL)
    {
        return(-1);
    }

    for ( uint i = 0; i < m_poSubObj.uiMaxElems(); i++ )
    {
        if ( m_poSubObj[i] == NULL )
        {
            m_poSubObj[i] = _poObj;
            m_poSubObj[i]->Ref();

            return(i);
        }
    }

    // Cannot add object to the node
    return(-1);
}
// ----------------------------------------------------------------------------
void CGSceneGroup::SetObject(CGSceneNode* _poObj, uint _uiPos)
{
    assert( ( _uiPos < m_poSubObj.uiNumElems() ) && "Object out of bounds" );
    assert( _poObj && "Setting a NULL Subobject");

    if (m_poSubObj[_uiPos] != NULL)
    {
        m_poSubObj[_uiPos]->Deref();
    }

    m_poSubObj[_uiPos] = _poObj;
    _poObj->Ref();
}
// ----------------------------------------------------------------------------
CGSceneNode* CGSceneGroup::poGetObject(uint _uiPos)
{
    assert( ( _uiPos < m_poSubObj.uiNumElems() ) && "Object out of bounds" );
    return(m_poSubObj[_uiPos]);
}
// ----------------------------------------------------------------------------
uint CGSceneGroup::uiNumSubObjs()
{
    return(m_poSubObj.uiNumElems());
}
// ----------------------------------------------------------------------------
void CGSceneGroup::SetBV(CGGraphBV* _poBV)
{
    if (m_poBV)
        mDel m_poBV;

    m_poBV = _poBV;
}
// ----------------------------------------------------------------------------
CGGraphBV* CGSceneGroup::poGetBV()
{
    return m_poBV;
}
// ----------------------------------------------------------------------------
