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
#ifndef CGShInsGeoOpH
#define CGShInsGeoOpH
// ----------------------------------------------------------------------------
#include "Shaders\ShaderInstructions\eShInsGeoOp_TypeID.h"
#include "Shaders\ShaderInstructions\CGShaderInstruction.h"

#include "GammaE_Math.h"
// ----------------------------------------------------------------------------
class CGShInsGeoOp : public CGShaderInstruction
{
    public:
        CGShInsGeoOp() : CGShaderInstruction(E3D_SHI_GeoOp), m_poEval(NULL)
        {
        }
        virtual ~CGShInsGeoOp();

        eShInsGeoOp_TypeID eGetGOpType ()
        {
            return(m_eGOpType);
        }
        void SetGOpType(eShInsGeoOp_TypeID _eGOpType)
        {
            m_eGOpType = _eGOpType;
        }

        CGEvaluator* poGetEvaluator()
        {
            return(m_poEval);
        }
        void SetEvaluator(CGEvaluator* _poEval)
        {
            m_poEval = _poEval;
        }

    protected:
        CGEvaluator* m_poEval;
        eShInsGeoOp_TypeID m_eGOpType;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
