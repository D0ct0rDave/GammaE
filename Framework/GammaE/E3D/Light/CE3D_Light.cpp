#include "CE3D_Light.h"

CE3D_Light::CE3D_Light()
{
	oLitAmb.r  = 1.0f;
	oLitAmb.g  = 1.0f;
	oLitAmb.b  = 1.0f;
	oLitAmb.a  = 1.0f;

	oLitDiff.r = 1.0f;
	oLitDiff.g = 1.0f;
	oLitDiff.b = 1.0f;
	oLitDiff.a = 1.0f;

	oLitSpec.r = 1.0f;
	oLitSpec.g = 1.0f;
	oLitSpec.b = 1.0f;
	oLitSpec.a = 1.0f;

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