//---------------------------------------------------------------------------
#ifndef CDummyListH
#define CDummyListH
#include <vcl.h>
#include <vector.h>
#include "CDummyInstance.h"

class CDummyList
{
public:
         CDummyList();
        ~CDummyList();

        AnsiString                  DummyModel;
        
        int                         iAlgType;
        float                       fProb;
        float                       fScale;
        int                         iIters;
        
        vector <CDummyInstance>     DInsts;
};
//---------------------------------------------------------------------------
#endif
 