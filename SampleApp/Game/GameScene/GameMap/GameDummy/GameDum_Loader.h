//## begin module%3C2B3AF301FA.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C2B3AF301FA.cm

//## begin module%3C2B3AF301FA.cp preserve=no
//## end module%3C2B3AF301FA.cp

//## Module: GameDum_Loader%3C2B3AF301FA; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\GameScene\GameMap\GameDummy\GameDum_Loader.h

#ifndef GameDum_Loader_h
#define GameDum_Loader_h 1

//## begin module%3C2B3AF301FA.additionalIncludes preserve=no
//## end module%3C2B3AF301FA.additionalIncludes

//## begin module%3C2B3AF301FA.includes preserve=yes
//## end module%3C2B3AF301FA.includes

// GammaE_E3D
#include "E3D\GammaE_E3D.h"
// GammaE_Math
#include "Math\GammaE_Math.h"
// GammaE_Scene
#include "Scene\GammaE_Scene.h"
//## begin module%3C2B3AF301FA.additionalDeclarations preserve=yes
#include "File.h"
#define DIF_FILEIDENTIFIER  MAKE_RIFF_ID('D','I','N','F')

#define DIF_MAJORVERSION    1
#define DIF_MINORVERSION    0

#define DINFO_MAXCARS	128

typedef struct{

	char		szModelName[DINFO_MAXCARS];
	int			iAlgType;
	float		fProb;
	float		fScale;
	int			iIters;
	
	unsigned int uiNumDInsts;
	CVect3		*pDInsts;

}TDummyList;

typedef struct{

	char			szTerrainScene[DINFO_MAXCARS];
	
	unsigned int	uiNumDTs;
	
	TDummyList		*pDT;

}TDummyInfo;
//## end module%3C2B3AF301FA.additionalDeclarations


//## begin GameDum_Loader%3C2B3AF301FA.preface preserve=yes
//## end GameDum_Loader%3C2B3AF301FA.preface

//## Class: GameDum_Loader%3C2B3AF301FA
//## Category: Game::GameScene::GameMap::GameDummy%3C2B3AE8026D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C2BB90A03D0;GammaE_E3D { -> }
//## Uses: <unnamed>%3C2BB9540051;GammaE_Scene { -> }
//## Uses: <unnamed>%3C2BBB4E0031;GammaE_Math { -> }

class GameDum_Loader 
{
  //## begin GameDum_Loader%3C2B3AF301FA.initialDeclarations preserve=yes
  //## end GameDum_Loader%3C2B3AF301FA.initialDeclarations

  public:
    //## Constructors (generated)
      GameDum_Loader();

    //## Destructor (generated)
      ~GameDum_Loader();


    //## Other Operations (specified)
      //## Operation: pLoad%1009496916
      CObject3D* pLoad (char* _szFilename);

      //## Operation: pCreateDummyScene%1009496917
      CObject3D* pCreateDummyScene (TDummyInfo& _DInfo);

      //## Operation: DestroyDummyInfo%1009496918
      void DestroyDummyInfo (TDummyInfo& _DInfo);

    // Additional Public Declarations
      //## begin GameDum_Loader%3C2B3AF301FA.public preserve=yes
      //## end GameDum_Loader%3C2B3AF301FA.public

  protected:
    // Additional Protected Declarations
      //## begin GameDum_Loader%3C2B3AF301FA.protected preserve=yes
      //## end GameDum_Loader%3C2B3AF301FA.protected

  private:
    // Additional Private Declarations
      //## begin GameDum_Loader%3C2B3AF301FA.private preserve=yes
      //## end GameDum_Loader%3C2B3AF301FA.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin GameDum_Loader%3C2B3AF301FA.implementation preserve=yes
      //## end GameDum_Loader%3C2B3AF301FA.implementation

};

//## begin GameDum_Loader%3C2B3AF301FA.postscript preserve=yes
//## end GameDum_Loader%3C2B3AF301FA.postscript

// Class GameDum_Loader 

//## begin module%3C2B3AF301FA.epilog preserve=yes
//## end module%3C2B3AF301FA.epilog


#endif
