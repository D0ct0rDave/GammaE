//---------------------------------------------------------------------------
#include "EV_RandomFeaturePoints.h"
#include <stdlib.h>
#include <math.h>
#include "math/MMath.h"
//---------------------------------------------------------------------------
float GetRange(TVect2 *VXs,unsigned int uiNumVXs)
{
    unsigned int cI;
    float fMinX,fMinY,fMaxX,fMaxY;

    fMinX = fMinY =  10000000;
    fMaxX = fMaxY = -10000000;
    for (cI=0;cI<uiNumVXs;cI++)
    {
		if (VXs[cI].v[0] < fMinX) fMinX = VXs[cI].v[0];
		if (VXs[cI].v[1] < fMinY) fMinY = VXs[cI].v[1];
		if (VXs[cI].v[0] > fMaxX) fMaxX = VXs[cI].v[0];
		if (VXs[cI].v[1] > fMaxY) fMaxY = VXs[cI].v[1];
    }

    return ( sqrt((fMaxX-fMinX)*(fMaxX-fMinX) + (fMaxY-fMinY)*(fMaxY-fMinY)) ); 
}
//---------------------------------------------------------------------------
TEv2D_RFP_List::TEv2D_RFP_List()
{
	uiNumPoints   = 0;
    Points        = NULL;
    bAttachedList = false;
}

TEv2D_RFP_List::~TEv2D_RFP_List()
{
	if (Points && ! bAttachedList)
    	delete Points;
}

void TEv2D_RFP_List::GenerateRFPList(unsigned int uiMaxPoints,float fRadius)
{
    unsigned int cP;

	if (Points && ! bAttachedList) delete Points;

    // Allocate space to store points
    Points = new TVect2[uiMaxPoints];

    fRFPRadius    = fRadius;
    uiNumPoints   = uiMaxPoints;
    bAttachedList = false;

    // Generate randomly distributed points
    for (cP=0;cP<uiMaxPoints;cP++)
    {
		Points[cP].v[0] = fRFPRadius*(1.0f - (float)rand()/(float)RAND_MAX);
		Points[cP].v[1] = fRFPRadius*(1.0f - (float)rand()/(float)RAND_MAX);
    }
}

void TEv2D_RFP_List::AttachRFPList(TVect2 *RFPList,unsigned int uiMaxPoints)
{
	if (Points && ! bAttachedList) delete Points;

	Points        = RFPList;
    uiNumPoints   = uiMaxPoints;
    bAttachedList = true;
}
//---------------------------------------------------------------------------
// 1st distance
//---------------------------------------------------------------------------
TEv2D_RFP_1stDistF::TEv2D_RFP_1stDistF() : TEv2D_RFP_List(){};
float TEv2D_RFP_1stDistF::GetValue(float x,float y)
{
	if (! Points) return(0);

    unsigned int	 cI;
	TVect2 			*CurrentPoint;
    float 			 x2,y2,Distance;
    float 			 MinDistance=1000000000;

    CurrentPoint = Points;
    for (cI=0;cI<uiNumPoints;cI++)
    {
    	x2= x - CurrentPoint->v[0];
    	y2= y - CurrentPoint->v[1];

        Distance = x2*x2 + y2*y2;
        if (Distance<MinDistance) MinDistance = Distance;

        CurrentPoint++;
    }

    return(MinDistance);
    // return(sqrt(MinDistance));
}
//---------------------------------------------------------------------------
// 2on distance
//---------------------------------------------------------------------------
TEv2D_RFP_2ndDistF::TEv2D_RFP_2ndDistF() : TEv2D_RFP_List(){};
float TEv2D_RFP_2ndDistF::GetValue(float x,float y)
{
	if (! Points) return(0);

    unsigned int	 cI;
	TVect2 			*CurrentPoint;
    float 			 x2,y2,Distance;
    float 			 Distances[2];

    Distances[0] =  999999999;
    Distances[1] = 1000000000;
    CurrentPoint = Points;

	for (cI=0;cI<uiNumPoints;cI++)
    {
    	x2= x - CurrentPoint->v[0];
    	y2= y - CurrentPoint->v[1];

        Distance = x2*x2 + y2*y2;
        if (Distance < Distances[0])
        {
        	Distances[1] = Distances[0];
            Distances[0] = Distance;
        }
        else
        {
        	if (Distance < Distances[1])
            	Distances[1] = Distance;
        }

        CurrentPoint++;
    }
    return(Distances[1]);
    // return(sqrt(Distances[1]));
}
//---------------------------------------------------------------------------
// 3rd distance
//---------------------------------------------------------------------------
TEv2D_RFP_3rdDistF::TEv2D_RFP_3rdDistF() : TEv2D_RFP_List(){};
float TEv2D_RFP_3rdDistF::GetValue(float x,float y)
{
    unsigned int	 cI;
	TVect2 			*CurrentPoint;
    float 			 x2,y2,Distance;
    float 			 Distances[3];

    Distances[0] =  999999998;
    Distances[1] =  999999999;
    Distances[2] = 1000000000;

	for (cI=0;cI<uiNumPoints;cI++)
    {
    	x2= x - CurrentPoint->v[0];
    	y2= y - CurrentPoint->v[1];

        Distance = (x2*x2 + y2*y2);
        if (Distance < Distances[0])
        {
			Distances[2] = Distances[1];
            Distances[1] = Distances[0];
            Distances[0] = Distance;
        }
        else
        {
        	if (Distance < Distances[1])
            {
            	Distances[2] = Distances[1];
                Distances[1] = Distance;
            }

    	    else
        	{
            	if (Distance<Distances[2])
                	Distances[2] = Distance;
	        }
        }

        CurrentPoint++;
    }

    return(Distances[2]);
    // return(sqrt(Distances[2]));
};
//---------------------------------------------------------------------------
// Real versions:
//---------------------------------------------------------------------------
// Estas versiones con correctas, y más optimas que las iniciales
// en las que se hacia una raiz cuadrada para cada uno de los
// valores. El valor importante es el de distancia mínima.
// Ese valor se puede obtener con la distancia cuadrada (versiones rápidas)
// Tras obtener el valor, se puede realizar el cuadrado y obtener la distancia
// real
//---------------------------------------------------------------------------
float TEv2D_RFP_1stDist::GetValue(float x,float y)
{
	return ( MMath_Sqrt(TEv2D_RFP_1stDistF::GetValue(x,y)) );
}

float TEv2D_RFP_2ndDist::GetValue(float x,float y)
{
	return ( MMath_Sqrt(TEv2D_RFP_2ndDistF::GetValue(x,y)) );
}

float TEv2D_RFP_3rdDist::GetValue(float x,float y)
{
	return ( MMath_Sqrt(TEv2D_RFP_3rdDistF::GetValue(x,y)) );
}
//---------------------------------------------------------------------------
