//## begin module%3C6AD6B502E9.cm preserve=no
//## end module%3C6AD6B502E9.cm

//## begin module%3C6AD6B502E9.cp preserve=no
//## end module%3C6AD6B502E9.cp

//## Module: CE3D_ShaderWH%3C6AD6B502E9; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\Shaders\ShaderWarehouse\CE3D_ShaderWH.cpp

//## begin module%3C6AD6B502E9.additionalIncludes preserve=no
//## end module%3C6AD6B502E9.additionalIncludes

//## begin module%3C6AD6B502E9.includes preserve=yes
#include "Memory/GammaE_Mem.h"
#include <string.h>
//## end module%3C6AD6B502E9.includes

// CE3D_ShaderWH
#include "E3D\Shaders\ShaderWarehouse\CE3D_ShaderWH.h"
//## begin module%3C6AD6B502E9.additionalDeclarations preserve=yes
//## end module%3C6AD6B502E9.additionalDeclarations


// Class CE3D_ShaderWH 

//## begin CE3D_ShaderWH::iMaxShaders%3C6AD9220224.attr preserve=no  private: static int {UA} 0
int CE3D_ShaderWH::iMaxShaders = 0;
//## end CE3D_ShaderWH::iMaxShaders%3C6AD9220224.attr

//## begin CE3D_ShaderWH::oShaders%3C6AD82D0363.role preserve=no  public: static CE3D_ShWH_Entry { -> RHAN}
CE3D_ShWH_Entry *CE3D_ShaderWH::oShaders = NULL;
//## end CE3D_ShaderWH::oShaders%3C6AD82D0363.role

CE3D_ShaderWH::CE3D_ShaderWH()
  //## begin CE3D_ShaderWH::CE3D_ShaderWH%.hasinit preserve=no
  //## end CE3D_ShaderWH::CE3D_ShaderWH%.hasinit
  //## begin CE3D_ShaderWH::CE3D_ShaderWH%.initialization preserve=yes
  //## end CE3D_ShaderWH::CE3D_ShaderWH%.initialization
{
  //## begin CE3D_ShaderWH::CE3D_ShaderWH%.body preserve=yes
  //## end CE3D_ShaderWH::CE3D_ShaderWH%.body
}


CE3D_ShaderWH::~CE3D_ShaderWH()
{
  //## begin CE3D_ShaderWH::~CE3D_ShaderWH%.body preserve=yes
  //## end CE3D_ShaderWH::~CE3D_ShaderWH%.body
}



//## Other Operations (implementation)
void CE3D_ShaderWH::Init (int _iMaxShaderEntries)
{
  //## begin CE3D_ShaderWH::Init%1013633078.body preserve=yes
  	int cMatEntry;
	
	iMaxShaders = _iMaxShaderEntries;
	oShaders = mNew CE3D_ShWH_Entry[iMaxShaders];

    for (cMatEntry=0;cMatEntry<iMaxShaders;cMatEntry++)
    {
        strcpy(oShaders[cMatEntry].szName,"NULL");
        oShaders[cMatEntry].poShader = NULL;
        oShaders[cMatEntry].bValid   = false;
		oShaders[cMatEntry].iId      = cMatEntry;
    }
  //## end CE3D_ShaderWH::Init%1013633078.body
}

void CE3D_ShaderWH::Invalidate ()
{
  //## begin CE3D_ShaderWH::Invalidate%1013633069.body preserve=yes
    int cMatEntry;
    for (cMatEntry=0;cMatEntry<iMaxShaders;cMatEntry++)
    {
        strcpy(oShaders[cMatEntry].szName,"NULL");
		mDel (oShaders[cMatEntry].poShader);
		oShaders[cMatEntry].bValid = false;
    }	
  //## end CE3D_ShaderWH::Invalidate%1013633069.body
}

void CE3D_ShaderWH::FreeShader (CE3D_Shader &_roShader)
{
  //## begin CE3D_ShaderWH::FreeShader%1013633070.body preserve=yes
    CE3D_ShWH_Entry *poShEntry = poFindShader(_roShader);

	if (poShEntry)
    {
		strcpy(poShEntry->szName,"NULL");
        mDel(poShEntry->poShader);
        poShEntry->bValid = false;
    }
  //## end CE3D_ShaderWH::FreeShader%1013633070.body
}

bool CE3D_ShaderWH::bShaderExists (char *_szShaderName)
{
  //## begin CE3D_ShaderWH::bShaderExists%1013633071.body preserve=yes
    return( poFindShader(_szShaderName)!=NULL );
  //## end CE3D_ShaderWH::bShaderExists%1013633071.body
}

CE3D_ShWH_Entry * CE3D_ShaderWH::poFindShader (CE3D_Shader& _roShader)
{
  //## begin CE3D_ShaderWH::poFindShader%1013633075.body preserve=yes
    int cShEntry;
    
	for (cShEntry=0;cShEntry<iMaxShaders;cShEntry++)
        if (oShaders[cShEntry].poShader == &_roShader)
            return( &oShaders[cShEntry] );

    // Shader not found
    return(NULL);
  //## end CE3D_ShaderWH::poFindShader%1013633075.body
}

CE3D_ShWH_Entry * CE3D_ShaderWH::poFindShader (char *_szShaderName)
{
  //## begin CE3D_ShaderWH::poFindShader%1013633076.body preserve=yes
    int cShEntry;
    
	for (cShEntry=0;cShEntry<iMaxShaders;cShEntry++)
		if (! strcmp(oShaders[cShEntry].szName,_szShaderName))
            return(&oShaders[cShEntry] );

    // Shader not found
    return(NULL);
  //## end CE3D_ShaderWH::poFindShader%1013633076.body
}

CE3D_ShWH_Entry * CE3D_ShaderWH::poFindShader (int _iShaderIdx)
{
  //## begin CE3D_ShaderWH::poFindShader%1015675966.body preserve=yes
	if( _iShaderIdx < iMaxShaders)
		return ( &oShaders[_iShaderIdx] );
	else
		return(NULL);
  //## end CE3D_ShaderWH::poFindShader%1015675966.body
}

CE3D_ShWH_Entry * CE3D_ShaderWH::poFindFreeShaderEntry ()
{
  //## begin CE3D_ShaderWH::poFindFreeShaderEntry%1013633077.body preserve=yes
    int cShEntry;

	for (cShEntry=0;cShEntry<iMaxShaders;cShEntry++)
        if (! oShaders[cShEntry].bValid)
            return( &oShaders[cShEntry] );

	// there is no free shader entry
    return(NULL);
  //## end CE3D_ShaderWH::poFindFreeShaderEntry%1013633077.body
}

int CE3D_ShaderWH::iAddShader (char *_szShaderName, CE3D_Shader *_poShader)
{
  //## begin CE3D_ShaderWH::iAddShader%1013633087.body preserve=yes
	CE3D_ShWH_Entry *poShEntry;

    poShEntry = poFindShader(_szShaderName);
    if (poShEntry) return(-1);

    poShEntry = poFindFreeShaderEntry();
    if (! poShEntry) return(-1);		// There is no free shader entry

    strcpy(poShEntry->szName,_szShaderName);
    poShEntry->bValid	= true;
	poShEntry->poShader = _poShader;

	return(poShEntry->iId);
  //## end CE3D_ShaderWH::iAddShader%1013633087.body
}

int CE3D_ShaderWH::iAllocShader (char* _szShaderName)
{
  //## begin CE3D_ShaderWH::iAllocShader%1013633073.body preserve=yes
	int			iRes;
	CE3D_Shader *poShader = mNew CE3D_Shader;

	iRes = iAddShader(_szShaderName,poShader);

	if (iRes == -1) mDel poShader;
	return(iRes);
  //## end CE3D_ShaderWH::iAllocShader%1013633073.body
}

int CE3D_ShaderWH::iCreateShader (char* _szShaderName)
{
  //## begin CE3D_ShaderWH::iCreateShader%1013633072.body preserve=yes
	CE3D_ShWH_Entry *poShEntry;
    char            *szShaderDef;
    CE3D_Shader		*poShader;

	// Look if the material already exists in the warehouse
    poShEntry = poFindShader(_szShaderName);
    if (poShEntry) return(poShEntry->iId);

    // If it doesn't exist in the shader warehouse,
    // look if it's in the shader definition warehouse
    szShaderDef = CE3D_ShaderDefWH::szGetShader(_szShaderName);

    if (szShaderDef)
    	// Try loading shader from definition
		poShader = CE3D_ShaderParser::poParseShader(szShaderDef,_szShaderName);
	else
		// Try loading shader as a texture
		poShader = CE3D_ShaderParser::poCreateShaderFromTexture(_szShaderName);

	if (! poShader) return(-1);

	// Add shader to warehouse    
	int iId = iAddShader(_szShaderName,poShader);
	if (iId == -1) mDel poShader;

	return (iId);
  //## end CE3D_ShaderWH::iCreateShader%1013633072.body
}

CE3D_Shader* CE3D_ShaderWH::poCreateShader (char* _szShaderName)
{
  //## begin CE3D_ShaderWH::poCreateShader%1015675968.body preserve=yes
	int iId = iCreateShader(_szShaderName);
	if (iId != -1) return(oShaders[iId].poShader); else return(NULL);
  //## end CE3D_ShaderWH::poCreateShader%1015675968.body
}

CE3D_Shader* CE3D_ShaderWH::poGetShader (int _iShaderId)
{
  //## begin CE3D_ShaderWH::poGetShader%1015675967.body preserve=yes
	if (_iShaderId < iMaxShaders)
		return (oShaders[_iShaderId].poShader);
	else
		return (NULL);
  //## end CE3D_ShaderWH::poGetShader%1015675967.body
}

char * CE3D_ShaderWH::szGetShaderName (CE3D_Shader& _roShader)
{
  //## begin CE3D_ShaderWH::szGetShaderName%1013633074.body preserve=yes
    CE3D_ShWH_Entry *poShEntry = poFindShader(_roShader);

	if (poShEntry)
		return (poShEntry->szName);
	else
		return ( NULL );
  //## end CE3D_ShaderWH::szGetShaderName%1013633074.body
}

// Additional Declarations
  //## begin CE3D_ShaderWH%3C6AD6B502E9.declarations preserve=yes
  //## end CE3D_ShaderWH%3C6AD6B502E9.declarations

//## begin module%3C6AD6B502E9.epilog preserve=yes
//---------------------------------------------------------------------------
// epilog: singleton initializer through static instantiation
//---------------------------------------------------------------------------
static CE3D_ShaderWH oIntance;
//## end module%3C6AD6B502E9.epilog
