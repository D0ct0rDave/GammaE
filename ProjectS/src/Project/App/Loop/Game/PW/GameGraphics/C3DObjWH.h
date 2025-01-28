// -----------------------------------------------------------------------------
#ifndef C3DObjWHH
#define C3DObjWHH
// -----------------------------------------------------------------------------
#include "antares.h"

#define MAX_OBJECTS 256

class GEOM_CompositeGeometry;

typedef struct{
	GEOM_CompositeGeometry* m_poObj;
	char		m_szFilename[MAX_CHARS];
}TWHObj;

class C3DObjWH
{
public:
	static GEOM_CompositeGeometry* poGetObj(char* _szObjFilename,char* _szTexPath = NULL);
	static void Invalidate();

	static TWHObj m_ao3DOWH[MAX_OBJECTS];
	static int    m_iNumObjs;
};

// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------