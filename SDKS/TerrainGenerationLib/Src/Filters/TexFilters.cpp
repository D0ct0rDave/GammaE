//---------------------------------------------------------------------------
#include <math.h>
//---------------------------------------------------------------------------
#include "TexFilters.h"
#include "tex.h"
//---------------------------------------------------------------------------
#ifndef PI
#define PI 3.1415926535897932384626433832795
#endif
//---------------------------------------------------------------------------
void TexFilter_ComputeDFT(Texture* Tex, TComplex* DFTMatrix)
{
	unsigned int cI,cJ,cK,cL,cC;
    TComplex Sum[4];
    float frec,cs,sn;
    unsigned int Color;
    unsigned char *pcColor = (unsigned char *)&Color;
    unsigned int Size = Tex->width * Tex->height;

    for (cL=0;cL<Tex->height;cL++)
    	for (cK=0;cK<Tex->width;cK++)
        {
        	// (a)
        	// for (cC=0;cC<4;cC++) { Sum[cC].Real = Sum[cC].Img = 0;cC++;};
            // Sum[0].Img = 0;

            Sum[0].Real = 0;
            for (cJ=0;cJ<Tex->height;cJ++)
    			for (cI=0;cI<Tex->width;cI++)
                {
                	frec  = (2.0f*PI*(cK*cI + cJ*cL)) / (float)Tex->width;
                    cs    = cos(frec);
                    // sn    = sin(frec);

                	// Color = TEX_fn_GetARGBColor(Tex,cI,cJ);
                    unsigned char* texColorPtr = Tex->data + (((cJ * Tex->width) + cI) * Tex->channels);

                    // Get grayscale pixel
                    unsigned char texColor;
                    {
                        int numChannels = (Tex->channels > 3) ? 3 : Tex->channels;
                        int colorAccum = 0;
                        for (int c = 0; c < numChannels; c++)
                        {
                            colorAccum += texColorPtr[c];
                        }
                        texColor = colorAccum / numChannels;
                    }

                    *pcColor = texColor;
                    Sum[0].Real += *pcColor * cs;

                    // Sum[0].Img  += pcColor[0] * sn;
                	// (b)
                    /*
                    for (cC=0;cC<4;cC++)
                    {
                    	Sum[cC].Real += pcColor[cC] * cs;
                        Sum[cC].Img  += pcColor[cC] * sn;
                    }
                    */
               	}

            DFTMatrix[cL*Tex->width + cK].Real = Sum[0].Real / (Tex->height*Tex->width);
			// DFTMatrix[cL*Tex->width + cK].Img  = Sum[0].Img  / Tex->height;

			// (c)
            /*
            for (cC=0;cC<4;cC++)
            {
            	DFTMatrix[cC*Size + cL*Tex->width + cK].Real =    Sum[cC].Real/Tex->height;
	            DFTMatrix[cC*Size + cL*Tex->width + cK].Img  = -1*Sum[cC].Img /Tex->height;
            }
            */
        }
}

/* (a)
            Sum[0].Real = 0;
            Sum[0].Img  = 0;
        	Sum[1].Real = 0;
            Sum[1].Img  = 0;
        	Sum[2].Real = 0;
            Sum[2].Img  = 0;
        	Sum[3].Real = 0;
            Sum[3].Img  = 0;
*/
/*
(b)
                    Sum[0].Real += Color.r*cs;
                    Sum[0].Img  += Color.r*sn;
                    Sum[1].Real += Color.g*cs;
                    Sum[1].Img  += Color.g*sn;
                    Sum[2].Real += Color.b*cs;
                    Sum[2].Img  += Color.b*sn;
                    Sum[3].Real += Color.a*cs;
                    Sum[3].Img  += Color.a*sn;
*/
/*
	(c)
            	DFTMatrix[0*Size + cL*Tex->width + cI].Real =    Sum[0].Real/Tex->height;
	            DFTMatrix[0*Size + cL*Tex->width + cI].Img  = -1*Sum[0].Img /Tex->height;
    	        DFTMatrix[1*Size + cL*Tex->width + cI].Real =    Sum[1].Real/Tex->height;
        	    DFTMatrix[1*Size + cL*Tex->width + cI].Real = -1*Sum[1].Img /Tex->height;
            	DFTMatrix[2*Size + cL*Tex->width + cI].Real =    Sum[2].Real/Tex->height;
	            DFTMatrix[2*Size + cL*Tex->width + cI].Real = -1*Sum[2].Img /Tex->height;
    	        DFTMatrix[3*Size + cL*Tex->width + cI].Real =    Sum[3].Real/Tex->height;
        	    DFTMatrix[3*Size + cL*Tex->width + cI].Real = -1*Sum[3].Img /Tex->height;
*/
//---------------------------------------------------------------------------

