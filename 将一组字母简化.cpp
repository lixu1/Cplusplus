#include <iostream>
using namespace std;
int main()
{
   int n,ans,ti;
   char t,last;
   cin>>n;
   while (n--)
   {
      ans=1;
      cin>>ti;
      ti--;
      cin>>last;
      while (ti--);
      {
         cin>>t;
         if(t==last)ans=ans+1;
         else
         {cout<<ans<<last;
         ans=1;
         last=t;}

      }cout<<ans<<last<<endl;
   }
   return 0;
}
