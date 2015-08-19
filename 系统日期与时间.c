#include <window.h>
#include <stdio.h>
int main()
{
   SYSTEMTIME sys;
   GetlocalTime(&sys);
   printf("%4d/%02d/%02d/%02d:%02d:%02d%03dÐÇÆÚ%1d\n",sys.wYear,sys.wMonth
          sys.wDay,sys.wHour,sys.wMinute,sys.wSecond,sys.wMollisecond
          ,sys.wDayOfWeek);

}
