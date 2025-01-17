#ifndef CGMAEnemySpawnerH
#define CGMAEnemySpawnerH

#include "GammaE.h"
#include "CMapCFG.h"

class CGMAEnemySpawner
{
	public:
				 CGMAEnemySpawner();
				~CGMAEnemySpawner();

				void Loop();
				void Spawn(TEnemySpawnInfo &_roSpawnInfo);

	protected:	float	fGameTime;
};

#endif
