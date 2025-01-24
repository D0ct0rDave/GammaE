// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGOGLMatrixStackH
#define CGOGLMatrixStackH
// ----------------------------------------------------------------------------
#include "GammaE_Math.h"
#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------
class CGOGLMatrixStack
{
    public:
        // / Creates a matrix stack with a maximum depth
        CGOGLMatrixStack(uint _uiMaxStackDepth = 32)
        {
            m_oStack.Init(_uiMaxStackDepth);

            CGMatrix4x4 oM;
            oM.LoadIdentity();

            // Adds the first element to the stack
            m_oStack.iAdd(oM);
        }

        // / Pushes the top element of the stack into the stack
        void Push()
        {
            m_oStack.iAdd( m_oStack[ m_oStack.uiNumElems() - 1 ] );
        }

        // / Pops the top element of the stack
        void Pop()
        {
            m_oStack.Del( m_oStack.uiNumElems() - 1 );
        }

        // / Sets the identity matrix for the top of the stack
        void LoadIdentity()
        {
            m_oStack[m_oStack.uiNumElems() - 1].LoadIdentity();
        }

        // / Loads the top element with the given matrix
        void Load(const CGMatrix4x4& _oMatrix)
        {
            m_oStack[m_oStack.uiNumElems() - 1] = _oMatrix;
        }

        // / Retrieves the top element of the stack
        const CGMatrix4x4& oGetTop()
        {
            return(m_oStack[m_oStack.uiNumElems() - 1]);
        }

        // / Multiplies the top element by the given matrix
        void Multiply(const CGMatrix4x4& _oMatrix)
        {
            m_oStack[m_oStack.uiNumElems() - 1].MultiplyBy(_oMatrix);
        }

    protected:
        // / The matrix stack
        CGStArray <CGMatrix4x4> m_oStack;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
