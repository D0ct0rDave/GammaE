//---------------------------------------------------------------------------
#ifndef ColorObjH
#define ColorObjH
//---------------------------------------------------------------------------
#include <tex.h>
//---------------------------------------------------------------------------
class TColorObj{
    public:
                TColorObj();
                ~TColorObj();

                void Think();
                TFColor Color();
                void SetColor(float r,float g,float b,float a);
    private:
                TFColor ResColor;

};
//---------------------------------------------------------------------------
#endif
 