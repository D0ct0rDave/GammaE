// -----------------------------------------------------------------------------
#ifndef CE3D_ShIns_TexOp_h
#define CE3D_ShIns_TexOp_h 1
// -----------------------------------------------------------------------------
#include "Shaders\ShaderInstructions\eShInsTexOp_TypeID.h"
#include "Shaders\ShaderInstructions\CE3D_ShaderInstruction.h"
#include "GammaE_Math.h"
// -----------------------------------------------------------------------------
class CE3D_ShIns_TexOp : public CE3D_ShaderInstruction
{
	public:
		CE3D_ShIns_TexOp() : m_poEval(NULL), m_poMat(NULL), m_uiImgRows(0), m_uiImgCols(0), m_fFreq(0.0f) {};
		~CE3D_ShIns_TexOp();

		eShInsTexOp_TypeID eGetTOpType () { return(m_eTOpType); };
		void SetTOpType(eShInsTexOp_TypeID _eTOpType) { m_eTOpType = _eTOpType; }

		CEvaluator* poGetEvaluator(){ return(m_poEval); };
		void SetEvaluator(CEvaluator* _poEval) { m_poEval = _poEval; };

		CMatrix4x4*			m_poMat;
		uint				m_uiImgRows;
		uint				m_uiImgCols;
		float				m_fFreq;

	protected:
		CEvaluator*			m_poEval;
		eShInsTexOp_TypeID	m_eTOpType;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
