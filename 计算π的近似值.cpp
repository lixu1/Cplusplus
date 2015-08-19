#include <iostream>
#include <iomanip>
#include  <cmath>
using namespace std;
int main()
{
   double n,s,t;
   cin>>t;
   while(t>0)
   {
      cin>>n;
      s=1;
      for(int i=1;i<=n;i++)
      {
         s=s+pow((-1),i&)*(1/(2i+1));
      }
      s=s*4;
      cout<<s<<endl;
      t=t-1;
   }
}
