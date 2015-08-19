#include <iostream>
#include <iomanip>

using namespace std;

#ifndef TIME2_H
#define TIME2_H
class Time2
{
public:
   Time2()
   {
   hour=minute=second=0;
   }
   void setTime(int h,int m,int s)
   {
   hour = ( h>=0 && h<24 ) ? h : 0 ;
   minute = (m>=0 && m<=60) ? m : 0;
   second = ( s>=0 && s<=60) ? s : 0;
   }
   void printUniversal()
   {
   cout<<setfill('0')<<setw(2)<<hour<<":"<<setw(2)<<minute<<":"
   <<setw(2)<<second;
   }
   void printStandard()
   {
   cout<<((hour==0||hour==12) ? 12 : hour % 12 )<<":"
   <<setfill('0')<<setw(2)<<minute<<":"<<setw(2)<<second
   <<(hour<12 ? "AM" :"PM");
   }
private:
   int hour;
   int minute;
   int second;
};


#endif // TIMEÀà¶¨Òå_H_INCLUDED
