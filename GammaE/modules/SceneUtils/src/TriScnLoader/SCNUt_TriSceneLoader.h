//	  %X% %Q% %Z% %W%
#ifndef SCNUt_TriSceneLoader_h
#define SCNUt_TriSceneLoader_h 1

// SCNUt_TriScene
#include "SCNUt_TriScene.h"

// SCNUt_MaterialTable
#include "SCNUt_MaterialTable.h"

class SCNUt_TriSceneLoader 
{   
	public:
		SCNUt_TriSceneLoader();

		~SCNUt_TriSceneLoader();


		SCNUt_TriScene * poLoad (char* _szFilename, SCNUt_MaterialTable& _oMTable);
            
	protected:
		// Additional Protected Declarations
            
	private:
		// Additional Private Declarations

	private:     
		// Additional Implementation Declarations
};
// Class SCNUt_TriSceneLoader 
#endif
