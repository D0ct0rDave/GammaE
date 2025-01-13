//---------------------------------------------------------------------------
#ifndef datesH
#define datesH

//---------------------------------------------------------------------------

typedef struct{
    unsigned short  Year;
    unsigned char   Month;
    unsigned char   Day;
    unsigned char   Hour;
    unsigned char   Min;
    unsigned short  Sec;
}tdstDate;

void GetDate            (tdstDate *Date);
void GetDateString      (char *StrDate);
void ConvertDateToString(tdstDate *Date, char *StrDate);
//---------------------------------------------------------------------------
#endif
 