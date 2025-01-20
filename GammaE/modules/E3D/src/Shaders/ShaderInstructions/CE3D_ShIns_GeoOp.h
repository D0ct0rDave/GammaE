//-----------------------------------------------------------------------------
#ifndef CE3D_ShIns_GeoOp_h
#define CE3D_ShIns_GeoOp_h 1
//-----------------------------------------------------------------------------
#include "Shaders\ShaderInstructions\eShInsGeoOp_TypeID.h"
#include "Shaders\ShaderInstructions\CE3D_ShaderInstruction.h"

#include "GammaE_Math.h"
//-----------------------------------------------------------------------------
class CE3D_ShIns_GeoOp : public CE3D_ShaderInstruction
{
	public:
		CE3D_ShIns_GeoOp() : CE3D_ShaderInstruction(E3D_SHI_GeoOp), m_poEval(NULL){};
		virtual ~CE3D_ShIns_GeoOp();

		eShInsGeoOp_TypeID eGetGOpType () { return(m_eGOpType); };
		void SetGOpType(eShInsGeoOp_TypeID _eGOpType) { m_eGOpType = _eGOpType; }

		CEvaluator* poGetEvaluator(){ return(m_poEval); };
		void SetEvaluator(CEvaluator* _poEval) { m_poEval = _poEval; };

	protected:
		CEvaluator*			m_poEval;
		eShInsGeoOp_TypeID	m_eGOpType;
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
