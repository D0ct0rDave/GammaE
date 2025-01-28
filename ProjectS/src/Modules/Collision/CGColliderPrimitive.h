// -----------------------------------------------------------------------------
#ifndef CGColliderPrimitiveH
#define CGColliderPrimitiveH
// -----------------------------------------------------------------------------
#include "GammaE.h"
// -----------------------------------------------------------------------------
typedef enum EGColliderPrimitiveType{

	CPT_None,

	CPT_Sphere,			// Sphere
	CPT_AABB,			// AABB
	CPT_Composite,		// Composite of colliders

	CPT_NumBVTs
};
// -----------------------------------------------------------------------------
class CGColliderPrimitive
{
	public:
		
		/// Creates the object assigning a specific text ID
		CGColliderPrimitive() : m_sID ("none") {};

		CGColliderPrimitive(const CGString& _sID) { m_sID = _sID; };
			
		/// Retrieves the kind of collidable object.
		virtual EGColliderPrimitiveType eType() = 0;
		
		/// Retrieves the text ID for this collidable object
		const CGString& sID(){ return(m_sID); };

	protected:

		/// Stores the text identifier
		CGString m_sID;
};
// -----------------------------------------------------------------------------
class CGCPTSphere : public CGColliderPrimitive
{
	public:
		
		/// Creates a sphere collidable object
		CGCPTSphere(const CGString& _sID, const CGVect3& _oCenter, float _fRadius)
		{
			m_sID     = _sID;
			m_oCenter = _oCenter;
			m_fRadius = _fRadius;
		};
		
		/// Creates a sphere collidable objet without text ID
		CGCPTSphere(const CGVect3& _oCenter, float _fRadius)
		{
			m_oCenter = _oCenter;
			m_fRadius = _fRadius;
		};

		/// Retrieves the type of this collider
		virtual EGColliderPrimitiveType eType(){ return(CPT_Sphere); };

		/// Stores the center of the collidable
		CGVect3		m_oCenter;

		/// Stores the collision radius
		float		m_fRadius;
};
// -----------------------------------------------------------------------------
class CGCPTAABB: public CGColliderPrimitive
{
	public:

		/// Creates a axis aligned bounding box collidable object
		CGCPTAABB(const CGString& _sID,const CGVect3& _oCenter,const CGVect3& _oExtents)
		{
			m_sID		= _sID;
			m_oCenter	= _oCenter;
			m_oExtents	= _oExtents;
		};
		
		/// Creates a axis aligned bounding box collidable objet without text ID
		CGCPTAABB(const CGVect3& _oCenter,const CGVect3& _oExtents)
		{
			m_oCenter	= _oCenter;
			m_oExtents	= _oExtents;
		};
		
		/// Retrieves the type of this collider
		virtual EGColliderPrimitiveType eType(){ return(CPT_AABB); };

		/// Stores the collision center
		CGVect3 m_oCenter;
		CGVect3 m_oExtents;
};
// -----------------------------------------------------------------------------
class CGCPTComposite : public CGColliderPrimitive
{
	public:

		///
		CGCPTComposite(uint _uiNumElems) : m_poCT(NULL) { m_oElems.Init(_uiNumElems); };

		///
		CGCPTComposite(const CGString& _sID,uint _uiNumElems)
		{
			m_sID = _sID;
			m_oElems.Init(_uiNumElems);
		};
		
		virtual EGColliderPrimitiveType eType(){ return(CPT_Composite); };

		CGColliderPrimitive* poElem(uint _uiElem)
		{			
			return ( m_oElems[_uiElem] );
		};
		
		void AddElem(CGColliderPrimitive*_poCT)
		{			
			m_oElems.iAdd( _poCT );
			
			// Rebuild internal collider
		};

		uint uiNumElems() { return (m_oElems.uiNumElems()); };
		
		/// Retrieves the collider that bounds all the composited elements of the collider
		CGColliderPrimitive* poGlobalCollider()
		{
			return(m_poCT);
		}

	protected:

		/// The collider object that bounds the entire composite object: for broad collision approach.
		// It should be forbidden to be another composite.
		CGColliderPrimitive*				m_poCT;

		/// The elements that make the composition
		CGStArray<CGColliderPrimitive*>	m_oElems;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
