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
}TDate;

void GetDate            (TDate*Date);
void GetDateString      (char *StrDate);
void ConvertDateToString(TDate*Date, char *StrDate);
//---------------------------------------------------------------------------
#endif
 