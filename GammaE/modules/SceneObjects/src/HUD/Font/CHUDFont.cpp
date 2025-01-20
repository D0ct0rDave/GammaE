//-----------------------------------------------------------------------------
#include "CHUDFont.h"
//-----------------------------------------------------------------------------
bool CHUDFont::bInit(const char* _szFontName)
{
	//
	return (bInit(_szFontName,_szFontName));
}
//-----------------------------------------------------------------------------
bool CHUDFont::bInit(const char* _szShapeShader,const char* _szDataFile)
{
	char szFilename[1024];
	m_poShader = CE3D_ShaderWH::I()->poCreateShader(_szShapeShader);
	if (! m_poShader) return(false);
	
	// Set default width and height
	m_fDefaultWidth = 1.0f / 16.0f;
	m_fDefaultHeight= 1.0f / 16.0f;

	// 	
	sprintf(szFilename,"%s.dat",_szDataFile);
	CFile oFile;
	if (oFile.bOpen(szFilename,"rb"))
	{		
		int i;
	
		// Find the first texture in the shader for max texture width
		CGMipMap* poMMO = NULL;	
		for (i=0;((i<m_poShader->iGetNumInstructions()) && (poMMO == NULL));i++)
		{
			CE3D_ShaderInstruction* poInst = m_poShader->pGetInstruction(i);
			if (poInst->eGetInstructionType() == E3D_SHI_Texture)
				poMMO = ((CE3D_ShIns_Texture*)poInst)->m_poTex->m_poMipMap;
		}

		if (poMMO == NULL)
			return(false);

		// Setup proper widths
		for (i=0;i<256;i++)
		{
			unsigned short usSize = oFile.sRead();
			m_fWidths[i] = (float)usSize / (float)poMMO->m_uiTX;
		}
	}
	else
	{
		// Set default values
		for (int i=0;i<256;i++)
			m_fWidths[i] = 1.0f / 16.0f;
	}

	// Set height
	m_fHeight = m_fDefaultHeight;

	return(true);
}
//-----------------------------------------------------------------------------
float CHUDFont::fGetTextWidth(char *Text)
{
	float fWidth = 0.0f;
	while (*Text)
		fWidth += m_fWidths[*Text];

	return(fWidth);
}
//-----------------------------------------------------------------------------
float CHUDFont::fCharHeight(char _cChar)
{
	return (m_fHeight);
}
//-----------------------------------------------------------------------------
float CHUDFont::fCharWidth(char _cChar)
{
	return( m_fWidths[_cChar] );
}
//-----------------------------------------------------------------------------
