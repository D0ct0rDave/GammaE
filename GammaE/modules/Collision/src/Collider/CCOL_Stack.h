// -----------------------------------------------------------------------------
#ifndef CCOL_Stack_h
#define CCOL_Stack_h 1
// -----------------------------------------------------------------------------
#include "GammaE_Math.h"
// -----------------------------------------------------------------------------
class CCOL_StackCollisionElem
{
	public:
		float m_fFrameFact;
        void* m_poCObj;      
};
// -----------------------------------------------------------------------------
class CCOL_Stack 
{
	public:
		/// Initializes the collision stack
		void Init(uint _uiMaxColisions);
		
		/// Resets the stack
		void Reset();
		
		/// Adds a collision with a given object in a given frame factor
		void AddCollision (void *_poCObj, float _fFrameFact);

		/// Retrieves the number of collisions in the stack
		uint uiGetNumCollisions ();

		/// Retrieves the elements of the stack
		CCOL_StackCollisionElem* poGetCollided();

	protected:

		/// The stack structure
		CGStArray<CCOL_StackCollisionElem> m_oCollided;
};
// -----------------------------------------------------------------------------
inline uint CCOL_Stack::uiGetNumCollisions()
{
	return ( m_oCollided.uiNumElems() );
}
// -----------------------------------------------------------------------------
inline CCOL_StackCollisionElem* CCOL_Stack::poGetCollided()
{
    return ( m_oCollided.poBuff() );
}
// -----------------------------------------------------------------------------
inline void CCOL_Stack::Init (uint _uiMaxColisions)
{
	m_oCollided.Init(_uiMaxColisions);
}
// -----------------------------------------------------------------------------
inline void CCOL_Stack::Reset ()
{
	m_oCollided.Clear();
}
// -----------------------------------------------------------------------------
inline void CCOL_Stack::AddCollision (void *_poCObj, float _fFrameFact)
{
	CCOL_StackCollisionElem oSCE;
	oSCE.m_poCObj     = _poCObj;
	oSCE.m_fFrameFact = _fFrameFact;

	m_oCollided.iAdd(oSCE);
}
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
