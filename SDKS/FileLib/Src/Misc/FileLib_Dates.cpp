//---------------------------------------------------------------------------
#ifdef BCB
#include <vcl.h>
#endif

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "FileLib_dates.h"

#define         MAX_CARS_DATE           128

//---------------------------------------------------------------------------
void GetDate(TDate*Date)
{
    // Changed to make compatible with MS Visual C++
	
	struct tm *TheTime;
	time_t tNow;

	time(&tNow);

	TheTime = localtime(&tNow);

    //GetLocalTime((LPSYSTEMTIME) &TheTime);

    Date->Year  = TheTime->tm_year;  /* years since 1900 */
    Date->Month = TheTime->tm_mon;   /* months since January - [0,11] */
    Date->Day   = TheTime->tm_mday;  /* day of the month - [1,31] */
    Date->Hour  = TheTime->tm_hour;  /* hours since midnight - [0,23] */
    Date->Min   = TheTime->tm_min;	/* minutes after the hour - [0,59] */
    Date->Sec   = TheTime->tm_sec;	/* seconds after the minute - [0,59] */
}
//---------------------------------------------------------------------------
void GetDateString(char *StrDate)
{
    TDate Date;

    GetDate(&Date);
    ConvertDateToString(&Date,StrDate);
}
//---------------------------------------------------------------------------
void ConvertDateToString(TDate*Date, char *StrDate)
{
    sprintf(StrDate,
            "%d/%d/%d (%d:%d:%d)",
            Date->Day,
            Date->Month,
            Date->Year,
            Date->Hour,
            Date->Min,
            Date->Sec);
}
//-------------------------------------------------------------------------





