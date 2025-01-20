// -----------------------------------------------------------------------------
#ifndef CE3D_OGL_MatrixStack_h
#define CE3D_OGL_MatrixStack_h 1
// -----------------------------------------------------------------------------
#include "GammaE_Math.h"
#include "GammaE_Misc.h"
// -----------------------------------------------------------------------------
class CE3D_OGL_MatrixStack
{	
	public:
		/// Creates a matrix stack with a maximum depth
		CE3D_OGL_MatrixStack(uint _uiMaxStackDepth = 32)
		{
			m_oStack.Init(_uiMaxStackDepth);

			CMatrix4x4 oM;
			oM.LoadIdentity();

			// Adds the first element to the stack
			m_oStack.iAdd(oM);
		};
		
 		/// Pushes the top element of the stack into the stack
 		void Push()
 		{
 			m_oStack.iAdd( m_oStack[ m_oStack.uiNumElems()-1 ] );
 		}
		
 		/// Pops the top element of the stack
 		void Pop()
 		{
 			m_oStack.Del( m_oStack.uiNumElems()-1 );
 		}
		
		/// Sets the identity matrix for the top of the stack
 		void LoadIdentity()
 		{
 			m_oStack[m_oStack.uiNumElems()-1].LoadIdentity();
 		}
 		
		/// Loads the top element with the given matrix
		void Load(const CMatrix4x4& _oMatrix)
		{
			m_oStack[m_oStack.uiNumElems()-1] = _oMatrix;
		}

		/// Retrieves the top element of the stack
		const CMatrix4x4& oGetTop()
		{
			return( m_oStack[m_oStack.uiNumElems()-1] );
		}

		/// Multiplies the top element by the given matrix
		void Multiply(const CMatrix4x4& _oMatrix)
		{
			m_oStack[m_oStack.uiNumElems()-1].MultiplyBy(_oMatrix);
		}

	protected:
		/// The matrix stack
		CGStArray<CMatrix4x4> m_oStack;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
