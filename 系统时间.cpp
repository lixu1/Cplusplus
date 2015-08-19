#include <windows.h>
#include <stdio.h>
int main( void )
{
SYSTEMTIME sys;
GetLocalTime( &sys );
printf( "%4d/%02d/%02d--%02d:%02d:%02d.%03d--ÐÇÆÚ%1d "
       ,sys.wYear,sys.wMonth,sys.wDay
       ,sys.wHour,sys.wMinute, sys.wSecond
       ,sys.wMilliseconds,sys.wDayOfWeek);
return 0;
}
