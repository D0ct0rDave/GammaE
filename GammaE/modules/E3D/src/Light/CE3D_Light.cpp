#include "CE3D_Light.h"

CE3D_Light::CE3D_Light()
{
	oLitAmb = CGColor(1,1,1,1);
	oLitDiff= CGColor(1,1,1,1);
	oLitSpec= CGColor(1,1,1,1);

	oPos.V3(0.0f,0.0f,0.0f);
	oDir.V3(0.0f,0.0f,1.0f);

	// For spot lights
	fSpCutOff = 180.0f;
	fSpExp= 0.0f;

	fCAtt = 1.0f;
	fLAtt = 0.0f;
	fQAtt = 0.0f;
	

	eType = LT_Point;
}

CE3D_Light::~CE3D_Light()
{
}