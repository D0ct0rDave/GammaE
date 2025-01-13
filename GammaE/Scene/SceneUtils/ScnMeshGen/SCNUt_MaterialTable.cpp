//## begin module%3BFEE7220290.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BFEE7220290.cm

//## begin module%3BFEE7220290.cp preserve=no
//## end module%3BFEE7220290.cp

//## Module: SCNUt_MaterialTable%3BFEE7220290; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnMeshGen\SCNUt_MaterialTable.cpp

//## begin module%3BFEE7220290.additionalIncludes preserve=no
//## end module%3BFEE7220290.additionalIncludes

//## begin module%3BFEE7220290.includes preserve=yes
#include <string.h>
#include "Memory/GammaE_mem.h"
//## end module%3BFEE7220290.includes

// SCNUt_MaterialTable
#include "Scene\SceneUtils\ScnMeshGen\SCNUt_MaterialTable.h"
//## begin module%3BFEE7220290.additionalDeclarations preserve=yes
//## end module%3BFEE7220290.additionalDeclarations


// Class SCNUt_MaterialTable 




SCNUt_MaterialTable::SCNUt_MaterialTable()
  //## begin SCNUt_MaterialTable::SCNUt_MaterialTable%.hasinit preserve=no
      : iMaxShaders(0), poShaders(NULL)
  //## end SCNUt_MaterialTable::SCNUt_MaterialTable%.hasinit
  //## begin SCNUt_MaterialTable::SCNUt_MaterialTable%.initialization preserve=yes
  //## end SCNUt_MaterialTable::SCNUt_MaterialTable%.initialization
{
  //## begin SCNUt_MaterialTable::SCNUt_MaterialTable%.body preserve=yes
  //## end SCNUt_MaterialTable::SCNUt_MaterialTable%.body
}

SCNUt_MaterialTable::SCNUt_MaterialTable(const SCNUt_MaterialTable &right)
  //## begin SCNUt_MaterialTable::SCNUt_MaterialTable%copy.hasinit preserve=no
      : iMaxShaders(0), poShaders(NULL)
  //## end SCNUt_MaterialTable::SCNUt_MaterialTable%copy.hasinit
  //## begin SCNUt_MaterialTable::SCNUt_MaterialTable%copy.initialization preserve=yes
  //## end SCNUt_MaterialTable::SCNUt_MaterialTable%copy.initialization
{
  //## begin SCNUt_MaterialTable::SCNUt_MaterialTable%copy.body preserve=yes
	int iShader;
	Init(right.iMaxShaders);
	
	for (iShader=0;iShader<iMaxShaders;iShader++)
		SetShader(iShader,right.poShaders[iShader]);

  //## end SCNUt_MaterialTable::SCNUt_MaterialTable%copy.body
}


SCNUt_MaterialTable::~SCNUt_MaterialTable()
{
  //## begin SCNUt_MaterialTable::~SCNUt_MaterialTable%.body preserve=yes
	if (poShaders)
		mDel []poShaders;
  //## end SCNUt_MaterialTable::~SCNUt_MaterialTable%.body
}


const SCNUt_MaterialTable & SCNUt_MaterialTable::operator=(const SCNUt_MaterialTable &right)
{
  //## begin SCNUt_MaterialTable::operator=%.body preserve=yes
	int iShader;
	Init(right.iMaxShaders);
	
	for (iShader=0;iShader<iMaxShaders;iShader++)
		SetShader(iShader,right.poShaders[iShader]);
	
	return(*this);
  //## end SCNUt_MaterialTable::operator=%.body
}



//## Other Operations (implementation)
void SCNUt_MaterialTable::Init (int _iMaxShaders)
{
  //## begin SCNUt_MaterialTable::Init%1006556681.body preserve=yes
	iMaxShaders = _iMaxShaders;
	poShaders   = mNew CE3D_Shader *[iMaxShaders];
	
	memset(poShaders,0,sizeof(CE3D_Shader*)*iMaxShaders);
  //## end SCNUt_MaterialTable::Init%1006556681.body
}

void SCNUt_MaterialTable::SetShader (int _iShIdx, CE3D_Shader *_poSh)
{
  //## begin SCNUt_MaterialTable::SetShader%1006556682.body preserve=yes
	assert( poShaders && "NULL Shader table");
	poShaders[_iShIdx] = _poSh;
  //## end SCNUt_MaterialTable::SetShader%1006556682.body
}

int SCNUt_MaterialTable::iAddShader (CE3D_Shader *_poSh)
{
  //## begin SCNUt_MaterialTable::iAddShader%1009552694.body preserve=yes
	assert( poShaders && "NULL Shader table");
	
	int iSh;

	// Look if we already have the material
  	for (iSh=0;iSh<iMaxShaders;iSh++)		
		if (poShaders[iSh] == _poSh)
			return(iSh);

	// Search for space in the table
	for (iSh=0;iSh<iMaxShaders;iSh++)
		if (! poShaders[iSh])
		{
			poShaders[iSh] = _poSh;
			return(iSh);
		}

	return(-1);	
  //## end SCNUt_MaterialTable::iAddShader%1009552694.body
}

CE3D_Shader * SCNUt_MaterialTable::poGetShader (int _iShIdx)
{
  //## begin SCNUt_MaterialTable::poGetShader%1006556683.body preserve=yes
	assert( poShaders && "NULL Shader table");
	return (poShaders[_iShIdx]);
  //## end SCNUt_MaterialTable::poGetShader%1006556683.body
}

// Additional Declarations
  //## begin SCNUt_MaterialTable%3BFEE7220290.declarations preserve=yes
  //## end SCNUt_MaterialTable%3BFEE7220290.declarations

//## begin module%3BFEE7220290.epilog preserve=yes
//## end module%3BFEE7220290.epilog
