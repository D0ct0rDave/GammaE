#include "CSFXObject.h"
#include <stdlib.h>

CSFXObject::CSFXObject()
{
	m_bDirectional	= false;
	m_bEnabled		= true;
}

CSFXObject::~CSFXObject()
{
}

void CSFXObject::Init(MTH_CPoint3 &_oPos)
{
	m_oIPos = _oPos;
	m_oPos  = _oPos;
}

void CSFXObject::Init(MTH_CPoint3 &_oPos,MTH_CPoint3 &_oDir)
{
	m_oIPos  = _oPos;
	m_oIDir  = _oDir;
	m_oPos   = _oPos;
	m_oDir   = _oDir;
	m_bDirectional = true;
}

void CSFXObject::Dir(MTH_CPoint3 &_oDir)
{
	m_oDir = _oDir;
	m_bDirectional = true;
}

void CSFXObject::Pos(MTH_CPoint3 &_oPos)
{
	m_oPos = _oPos;
}

void CSFXObject::Enable()
{
	m_bEnabled = true;
}

void CSFXObject::Disable()
{
	m_bEnabled = false;
}

void CSFXObject::Update(float _fDeltaT)
{
}

void CSFXObject::Render()
{
}
