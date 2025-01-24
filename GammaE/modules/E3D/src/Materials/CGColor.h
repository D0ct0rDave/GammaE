//-----------------------------------------------------------------------------
#ifndef CGColorH
#define CGColorH
//-----------------------------------------------------------------------------
#include "GammaE_Misc.h"
//-----------------------------------------------------------------------------
class CGColor
{
    public:
        CGColor() : r(0),g(0),b(0),a(0) {};
        CGColor(float _r,float _g,float _b,float _a) { Set(_r,_g,_b,_a); };

        /// Sets the color from its components
        void Set(float _r,float _g,float _b,float _a)
        {
			r = _r;
			g = _g;
			b = _b;
			a = _a;
        };

		CGColor(uint _uiColor)
		{
			Set(_uiColor);
		}
		
		/// Sets the color from its components
		void Set(uint _uiColor)
		{	
			const float _1_OVER_255 = 1.0f / 255.0f;

			r = (float)((_uiColor & 0x000000ff)    ) * _1_OVER_255;
			g = (float)((_uiColor & 0x0000ff00)>> 8) * _1_OVER_255;
			b = (float)((_uiColor & 0x00ff0000)>>16) * _1_OVER_255;
			a = (float)((_uiColor & 0xff000000)>>24) * _1_OVER_255;
		}

		/// Performs the linear interpolation of the given colors by a factor
		void Lerp(const CGColor& _oIni,const CGColor& _oEnd,float _fFact);

		/// Returns a pointer to the data
        float* v() const { return( (float*)&r ); };

		// Since changes to fields are doesn't have side effects,
		// no set/get functions are needed.
		float r;
		float g;
		float b;
		float a;
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------

 