// -----------------------------------------------------------------------------
#ifndef CBVTypeH
#define CBVTypeH
// -----------------------------------------------------------------------------
#include "antares.h"
// -----------------------------------------------------------------------------
typedef enum TBVType{

	BVT_None,

	BVT_Sphere,			// Sphere
	BVT_AABB,			// AABB
	BVT_Cyl,			// Cylinder
	BVT_CCyl,			// Capped cylinder
	BVT_AABBCC,			// AABB cylinder container

	BVT_NumBVTs
};
// -----------------------------------------------------------------------------
class CBVType
{
	public:
		virtual TBVType eType() = 0;
};
// -----------------------------------------------------------------------------
class CBVSphere : public CBVType
{
	public:
			virtual TBVType eType(){ return(BVT_Sphere); };
			float		m_fRadius;
};
// -----------------------------------------------------------------------------
class CBVAABB: public CBVType
{
	public:
			virtual TBVType eType(){ return(BVT_AABB); };

			MTH_CPoint3 m_oExt;			// Extents
};
// -----------------------------------------------------------------------------
class CBVCylinder : public CBVType
{
	public:
			virtual TBVType eType(){ return(BVT_Cyl); };

			MTH_CMat4x4 m_oRS;			// Reference system
			float		m_fRadius;
			float		m_fHeight;
};
// -----------------------------------------------------------------------------
class CBVCappedCylinder : public CBVCylinder
{
	public:
			virtual TBVType eType(){ return(BVT_CCyl); };
};
// -----------------------------------------------------------------------------
class CBVAABBCylinderContainer : public CBVType
{
	public:
			virtual TBVType eType(){ return(BVT_AABBCC); };
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------