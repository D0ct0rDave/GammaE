// -----------------------------------------------------------------------------
#include "CGColliderInstance.h"
#include "CGColliderResourceWH.h"

CGColliderInstance::CGColliderInstance(const CGString& _sResource)
{
	Init(_sResource);
}	
// -----------------------------------------------------------------------------
void CGColliderInstance::Init(const CGString& _sResource)
{
	m_poResource = CGColliderResourceWH::I()->poFind(_sResource);
}
// -----------------------------------------------------------------------------

