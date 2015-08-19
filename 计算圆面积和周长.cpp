#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
   int n,r;
   double l,s;
   cin>> n;

   while (n--)
   {
      cin>>r;
      if (r<0) cout<<"Impossible";
      else
      {l=2*r*3.1415926;
       s=r*r*3.1415926;
       cout<<fixed<<setprecision(2)<<l<<" "<<s<<endl;
      }
   }
   return 0;
}
