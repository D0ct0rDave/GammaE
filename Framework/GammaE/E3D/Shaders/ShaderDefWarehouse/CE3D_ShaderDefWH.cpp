//## begin module%3C6AE35502DD.cm preserve=no
//## end module%3C6AE35502DD.cm

//## begin module%3C6AE35502DD.cp preserve=no
//## end module%3C6AE35502DD.cp

//## Module: CE3D_ShaderDefWH%3C6AE35502DD; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\Shaders\ShaderDefWarehouse\CE3D_ShaderDefWH.cpp

//## begin module%3C6AE35502DD.additionalIncludes preserve=no
//## end module%3C6AE35502DD.additionalIncludes

//## begin module%3C6AE35502DD.includes preserve=yes
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#include "Memory/GammaE_Mem.h"
#include "Misc/GammaE_Misc.h"
//## end module%3C6AE35502DD.includes

// CE3D_ShaderDefWH
#include "E3D\Shaders\ShaderDefWarehouse\CE3D_ShaderDefWH.h"
//## begin module%3C6AE35502DD.additionalDeclarations preserve=yes

//---------------------------------------------------------------------------
bool ControlBracketPairs(char *ShaderString)
{
	int NumBrackets = 0;

    while (*ShaderString)
    {
    	 if (*ShaderString == '{') NumBrackets++;
    else if (*ShaderString == '}') NumBrackets--;

		if (NumBrackets<0) return(false);

        ShaderString ++;
    }

    return(NumBrackets==0);
}
//---------------------------------------------------------------------------
char *FindNextShader(char *ShaderString)
{
	if (! ShaderString)  return(NULL);
	if (! *ShaderString) return(NULL);

	while ( strnicmp(ShaderString,"Material ",9) )
    {
        ShaderString++;
        if (! *ShaderString) return(NULL);
    }

	return(ShaderString);
}
//---------------------------------------------------------------------------
bool GetShaderDefinition(char *_szShaderString,CE3D_ShDefWH_Entry *_poShEntry)
{
	char *szShaderName;
	char *szShaderDefinition;

	// skip "material" token
    szShaderName       = ParseUtils_ParseToken(_szShaderString);
	// Get material name
	szShaderName       = ParseUtils_ParseToken(_szShaderString);
	// Get material definition
    szShaderDefinition = _szShaderString;

    if (! ControlBracketPairs(szShaderDefinition)) return(false);

    _poShEntry->szName = ParseUtils_CreateString(szShaderName      );
    _poShEntry->szDef  = ParseUtils_CreateString(szShaderDefinition);

	return(true);
}
//---------------------------------------------------------------------------


//## end module%3C6AE35502DD.additionalDeclarations


// Class CE3D_ShaderDefWH 

//## begin CE3D_ShaderDefWH::iMaxShDefs%3C6AE417028B.attr preserve=no  private: static int {UA} 0
int CE3D_ShaderDefWH::iMaxShDefs = 0;
//## end CE3D_ShaderDefWH::iMaxShDefs%3C6AE417028B.attr

//## begin CE3D_ShaderDefWH::iNumShDefs%3C6AE86C00A5.attr preserve=no  private: static int {UA} 0
int CE3D_ShaderDefWH::iNumShDefs = 0;
//## end CE3D_ShaderDefWH::iNumShDefs%3C6AE86C00A5.attr

//## begin CE3D_ShaderDefWH::oShDefs%3C6AE406033C.role preserve=no  public: static CE3D_ShDefWH_Entry { -> RHAN}
CE3D_ShDefWH_Entry *CE3D_ShaderDefWH::oShDefs = NULL;
//## end CE3D_ShaderDefWH::oShDefs%3C6AE406033C.role

CE3D_ShaderDefWH::CE3D_ShaderDefWH()
  //## begin CE3D_ShaderDefWH::CE3D_ShaderDefWH%.hasinit preserve=no
  //## end CE3D_ShaderDefWH::CE3D_ShaderDefWH%.hasinit
  //## begin CE3D_ShaderDefWH::CE3D_ShaderDefWH%.initialization preserve=yes
  //## end CE3D_ShaderDefWH::CE3D_ShaderDefWH%.initialization
{
  //## begin CE3D_ShaderDefWH::CE3D_ShaderDefWH%.body preserve=yes
  //## end CE3D_ShaderDefWH::CE3D_ShaderDefWH%.body
}


CE3D_ShaderDefWH::~CE3D_ShaderDefWH()
{
  //## begin CE3D_ShaderDefWH::~CE3D_ShaderDefWH%.body preserve=yes
  //## end CE3D_ShaderDefWH::~CE3D_ShaderDefWH%.body
}



//## Other Operations (implementation)
void CE3D_ShaderDefWH::Init (int _iMaxShDefs)
{
  //## begin CE3D_ShaderDefWH::Init%1013633086.body preserve=yes
	assert ((!oShDefs) && "Shader definition warehouse already initialized");

	iMaxShDefs = _iMaxShDefs;
	iNumShDefs = 0;
	oShDefs = mNew CE3D_ShDefWH_Entry[iMaxShDefs];
  //## end CE3D_ShaderDefWH::Init%1013633086.body
}

int CE3D_ShaderDefWH::iAddShaderFile (char* _szFilename)
{
  //## begin CE3D_ShaderDefWH::iAddShaderFile%1013633081.body preserve=yes
  	char			*szShaderFile   = ParseUtils_ReadFile(_szFilename);
    char			*szShaderStream = szShaderFile;
    char			*szShaderDef;
    unsigned int	uiNumReadShaders = 0;

    while (szShaderFile)
    {
    	szShaderDef  = FindNextShader(szShaderFile);
        szShaderFile = szShaderDef;

        if (szShaderDef)
       	{
			szShaderFile = FindNextShader(szShaderDef+1);

    	    if (szShaderFile) 
				*(szShaderFile-1) = 0;	// Mark the previous shader

            if (iAddShader(szShaderDef) < 0)
            	break;
            else
            	uiNumReadShaders++;
        }
    }

    if (szShaderStream)
		free(szShaderStream);

    return(uiNumReadShaders);
  //## end CE3D_ShaderDefWH::iAddShaderFile%1013633081.body
}

int CE3D_ShaderDefWH::iAddShader (char* _szShaderString)
{
  //## begin CE3D_ShaderDefWH::iAddShader%1013633082.body preserve=yes
	CE3D_ShDefWH_Entry	oAuxShaderEntry;
    int 				iShaderEntry;

    // Get the shader definition
    if (! GetShaderDefinition(_szShaderString,&oAuxShaderEntry)) return(-1);

    // Look if the shader was previously defined
    iShaderEntry = iFindShader(oAuxShaderEntry.szName);
    if (iShaderEntry!=-1)
       	return(iShaderEntry);

    // Look if we can store a new shader definition
	if (iNumShDefs>=iMaxShDefs)
    	return(-1);

	// Set the new shader
    oShDefs[iNumShDefs].szName = oAuxShaderEntry.szName;
    oShDefs[iNumShDefs].szDef  = oAuxShaderEntry.szDef;
	
	oAuxShaderEntry.szName = NULL;
	oAuxShaderEntry.szDef  = NULL;

    return(iNumShDefs++);
  //## end CE3D_ShaderDefWH::iAddShader%1013633082.body
}

void CE3D_ShaderDefWH::Invalidate ()
{
  //## begin CE3D_ShaderDefWH::Invalidate%1013633083.body preserve=yes
	int cSh;

	for(cSh=0;cSh<iNumShDefs;cSh++)
    {
    	free(oShDefs[cSh].szDef);
		free(oShDefs[cSh].szName);
    }

    iNumShDefs = 0;
  //## end CE3D_ShaderDefWH::Invalidate%1013633083.body
}

char * CE3D_ShaderDefWH::szGetShader (char *_szShaderName)
{
  //## begin CE3D_ShaderDefWH::szGetShader%1013633084.body preserve=yes
  	int iShaderEntry = iFindShader(_szShaderName);

    if (iShaderEntry != -1)
    	return(oShDefs[iShaderEntry].szDef);
    else
    	return(NULL);
  //## end CE3D_ShaderDefWH::szGetShader%1013633084.body
}

int CE3D_ShaderDefWH::iFindShader (char *_szShaderName)
{
  //## begin CE3D_ShaderDefWH::iFindShader%1013633085.body preserve=yes
	int cSh;

	for(cSh=0;cSh<iMaxShDefs;cSh++)
    {
		if ( oShDefs[cSh].szName )
		{
    		if (! stricmp(_szShaderName,oShDefs[cSh].szName))
        		return(cSh);
		}
    }

    // Shader not found
    return(-1);
  //## end CE3D_ShaderDefWH::iFindShader%1013633085.body
}

// Additional Declarations
  //## begin CE3D_ShaderDefWH%3C6AE35502DD.declarations preserve=yes
  //## end CE3D_ShaderDefWH%3C6AE35502DD.declarations

//## begin module%3C6AE35502DD.epilog preserve=yes
//---------------------------------------------------------------------------
// epilog: singleton initializer through static instantiation
//---------------------------------------------------------------------------
static CE3D_ShaderDefWH oInstance;

//## end module%3C6AE35502DD.epilog
