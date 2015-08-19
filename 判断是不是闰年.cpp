#include <iostream>
using namespace std;

int leapyear(int year)
{
   if ((year%400==0) || (year%100!=0) && (year%4==0))
   return 1;
   else
   return 0;
}
int main()
{
   int n;
			while(cin>>n)
			{
			   if(leapyear(n) == 1)
      cout<<"Yes"<<endl;
      else cout<<"No"<<endl;
   }
   return 0;
}
