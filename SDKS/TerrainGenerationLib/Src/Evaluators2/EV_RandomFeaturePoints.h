//---------------------------------------------------------------------------
#ifndef EV_RandomFeaturePointsH
#define EV_RandomFeaturePointsH
//---------------------------------------------------------------------------
#include "Math/Vect2.h"
#include "Evaluator2D.h"

//---------------------------------------------------------------------------
// Random Feature Points
//---------------------------------------------------------------------------
class TEv2D_RandomFeaturePoints : TEvaluator2D
{
	public:

	virtual float GetValue(float x,float y) = 0;
};
//---------------------------------------------------------------------------
// Points are stored in a list
//---------------------------------------------------------------------------
class TEv2D_RFP_List : public TEv2D_RandomFeaturePoints
{
	public:
	TEv2D_RFP_List();
    ~TEv2D_RFP_List();
    virtual float GetValue(float x,float y) = 0;

    virtual void  GenerateRFPList(unsigned int uiMaxPoints,float fRadius);
    virtual void  AttachRFPList  (TVect2 *RFPList,unsigned int uiMaxPoints);

protected:
    TVect2   	 *Points;
    unsigned int uiNumPoints;
    float        fRFPRadius;
    
    bool		 bAttachedList;
};
//---------------------------------------------------------------------------
// Fast versions
//---------------------------------------------------------------------------
class TEv2D_RFP_1stDistF : public TEv2D_RFP_List
{
	public:
    TEv2D_RFP_1stDistF();
	virtual float GetValue(float x,float y);
};

class TEv2D_RFP_2ndDistF : public TEv2D_RFP_List
{
	public:
    TEv2D_RFP_2ndDistF();
	virtual float GetValue(float x,float y);
};

class TEv2D_RFP_3rdDistF : public TEv2D_RFP_List
{
	public:
    TEv2D_RFP_3rdDistF();
	virtual float GetValue(float x,float y);
};
//---------------------------------------------------------------------------
// Real versions
//---------------------------------------------------------------------------
class TEv2D_RFP_1stDist : public TEv2D_RFP_1stDistF
{
	public:
	virtual float GetValue(float x,float y);
};

class TEv2D_RFP_2ndDist : public TEv2D_RFP_2ndDistF
{
	public:
	virtual float GetValue(float x,float y);
};

class TEv2D_RFP_3rdDist : public TEv2D_RFP_3rdDistF
{
	public:
	virtual float GetValue(float x,float y);
};
//---------------------------------------------------------------------------
#endif
