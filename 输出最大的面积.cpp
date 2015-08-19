#include <iostream>
using namespace std;
int main()
{
   int n,k,i;
   int a,b,s,ans;
   cin>>n;
   while (n--)
   {
      cin>>k;
      ans=0;
      for(i=1;i<=k;i++)
      {
         cin>>a>>b;
         s=a*b;
         if(ans<s)ans=s;
      }
      cout<<ans<<endl;
   }return 0;
}
