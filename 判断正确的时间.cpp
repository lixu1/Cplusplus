#include <iostream>
using namespace std;
const int daymax[]={31,28,31,30,31,30,31,31,30,31,30,31};
bool lsleapyear(int x)
{
   bool ret=false;
   if(x%4==0)
   {
      if(x%100==0)
      {
         if(x%400==0) ret=true;
         else ret=false;
      }
      else ret=true;
   }
   return ret;
}
int main()
{
   int n,year,month,day,hour,minute,second;
   bool flag;

   cin>>n;
   while(n--)
   {
      flag=true;
      cin>>year>>month>>day>>hour>>minute>>second;
      if(month<1||month>12||day<1||hour<0||hour>23||minute<0
         ||minute>59||second<0||second>59)
         flag=false;
      else if(month!=2)
      {
         if(day>daymax[month-1])
         flag=false;
      }
      else if(lsleapyear(year))
      {
         if(day>29) flag=false;
      }
      else if(day>28)  flag=false;
      if(flag==true) cout<<"Good bye!"<<endl;
      else cout<<"Please wait for a moment!"<<endl;
   }
   return 0;
}
