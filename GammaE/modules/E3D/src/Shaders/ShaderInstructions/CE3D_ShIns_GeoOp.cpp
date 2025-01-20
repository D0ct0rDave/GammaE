#include "GammaE_Mem.h"
#include "Shaders\ShaderInstructions\CE3D_ShIns_GeoOp.h"
//-----------------------------------------------------------------------------
CE3D_ShIns_GeoOp::~CE3D_ShIns_GeoOp()
{
  	if (m_poEval) mDel m_poEval;
}
//-----------------------------------------------------------------------------
