// -----------------------------------------------------------------------------
#ifndef CFollowerGroupEntityH
#define CFollowerGroupEntityH

// -----------------------------------------------------------------------------
#include "antares.h"
#include "Game/Ents/Enemies/CFollowerEntity.h"
#include "Game/Ents/Enemies/CGroupManager.h"

class CFollowerGroupEntity : public CFollowerEntity, public CGroupManager
{
public:	
		 CFollowerGroupEntity();
		~CFollowerGroupEntity();
		
		void Init(char* _szGraphicRes,unsigned int _uiNum,char*_szFilename);
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
