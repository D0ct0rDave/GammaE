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
#ifndef CGShInsTexOpH
#define CGShInsTexOpH
// ----------------------------------------------------------------------------
#include "Shaders\ShaderInstructions\eShInsTexOp_TypeID.h"
#include "Shaders\ShaderInstructions\CGShaderInstruction.h"
#include "GammaE_Math.h"
// ----------------------------------------------------------------------------
class CGShInsTexOp : public CGShaderInstruction
{
    public:
        CGShInsTexOp() : m_poEval(NULL), m_poMat(NULL), m_uiImgRows(0), m_uiImgCols(0), m_fFreq(0.0f)
        {
        }
        ~CGShInsTexOp();

        eShInsTexOp_TypeID eGetTOpType ()
        {
            return(m_eTOpType);
        }
        void SetTOpType(eShInsTexOp_TypeID _eTOpType)
        {
            m_eTOpType = _eTOpType;
        }

        CGEvaluator* poGetEvaluator()
        {
            return(m_poEval);
        }
        void SetEvaluator(CGEvaluator* _poEval)
        {
            m_poEval = _poEval;
        }

        CGMatrix4x4* m_poMat;
        uint m_uiImgRows;
        uint m_uiImgCols;
        float m_fFreq;

    protected:
        CGEvaluator* m_poEval;
        eShInsTexOp_TypeID m_eTOpType;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------