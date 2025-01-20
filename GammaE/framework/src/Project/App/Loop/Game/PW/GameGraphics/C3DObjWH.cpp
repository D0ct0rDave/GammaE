// -----------------------------------------------------------------------------
#include "C3DObjWH.h"
#include "cephei.h"

TWHObj C3DObjWH::m_ao3DOWH[MAX_OBJECTS];
int    C3DObjWH::m_iNumObjs = 0;
// -----------------------------------------------------------------------------
static char* szGetShaderDefFilename(char* _szObjFilename)
{
	static char szStr[1024];
	char szAuxStr[1024];

	strcpy(szAuxStr,_szObjFilename);
	int iLen = strlen(szAuxStr);
	char *szExt = szAuxStr + (iLen - 4);

	// Look for file extension
	while ((*szExt != '.') && (*szExt)) szExt++;
	if (*szExt == '.') *szExt = 0;

	sprintf(szStr,"%s.def",szAuxStr);	
	return(szStr);
}
// -----------------------------------------------------------------------------
static char* szGetPath(char* _szObjFilename)
{
	static char szAuxStr[1024];

	strcpy(szAuxStr,_szObjFilename);
	ExtractPath(szAuxStr);
	
	return(szAuxStr);
}
// -----------------------------------------------------------------------------
GEOM_CompositeGeometry* C3DObjWH::poGetObj(char* _szObjFilename,char* _szTexPath)
{
	for (int i=0;i<m_iNumObjs;i++)
	{
		if (! stricmp(_szObjFilename,m_ao3DOWH[i].m_szFilename))
			return (m_ao3DOWH[i].m_poObj);
	}

	// Add the shader definition file of the object (if it has one)
	// char *szShaderDefFile = szGetShaderDefFilename(_szObjFilename);
	// if (szShaderDefFile) GEOM_ShaderDef::iAdd(szShaderDefFile);
	GEOM_CompositeGeometry* poLoader= pNew GEOM_CompositeGeometry;

	// if (! poLoader->iLoad(_szObjFilename,_szTexPath))
	if (! poLoader->ImportGFile(_szObjFilename,_szTexPath))
		return (NULL);

	/// m_ao3DOWH[m_iNumObjs].m_poObj->Compile();
	strcpy(m_ao3DOWH[m_iNumObjs].m_szFilename,_szObjFilename);

	m_ao3DOWH[m_iNumObjs].m_poObj	= poLoader;
	m_iNumObjs++;

	return( poLoader );
}
// -----------------------------------------------------------------------------
void C3DObjWH::Invalidate()
{
	for(int i=0;i<m_iNumObjs;i++)
	{
		vDelete m_ao3DOWH[i].m_poObj;
		m_ao3DOWH[i].m_poObj = NULL;
	}

	m_iNumObjs = 0;
}
// -----------------------------------------------------------------------------