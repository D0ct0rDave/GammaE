//-----------------------------------------------------------------------------
#ifndef CE3D_ShIns_ZOp_h
#define CE3D_ShIns_ZOp_h 1
//-----------------------------------------------------------------------------
#include "Shaders\ShaderInstructions\CE3D_ShaderInstruction.h"
#include "E3D_Enums.h"
//-----------------------------------------------------------------------------
class CE3D_ShIns_ZOp : public CE3D_ShaderInstruction
{   
	public:
		CE3D_ShIns_ZOp() : CE3D_ShaderInstruction(E3D_SHI_ZOp), m_eZTF(E3D_ZTF_Current), m_eZW(E3D_ZW_Current){ };

		E3D_ZTestFunc eGetZTestFunc()
		{
			return(m_eZTF);
		}

		void SetZTestFunc(E3D_ZTestFunc value)
		{
			m_eZTF = value;
		}

		E3D_ZWrite eGetZWrite ()
		{
			return(m_eZW);
		}

		void SetZWrite(E3D_ZWrite value)
		{
			m_eZW = value;
		}

	protected:

		E3D_ZTestFunc	m_eZTF;
		E3D_ZWrite		m_eZW;
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
