#include <iostream>
using namespace std;
int main()
{
   int n,a,b,i,s,ans,c;
   cin>>n;
   ans=0;
   while(n--)
   {
      cin>>a>>b;
      s=1;
      while(s!=0)
      {
         i=10;
         s=a/i;
         if(s=0) c=i;
         i=i*10;
      };
      for(c/10;c!=1;c=c/10)
      {
         ans=ans+a/c;
         a=a-a/c*c;
      };
      s=1;
      while(s!=0)
      {
         i=10;
         s=b/i;
         if(s=0) c=i;
         i=i*10;
      };
      for(c/10;c!=1;c=c/10)
      {
         ans=ans+b/c;
         b=b-b/c*c;
      };
      cout<<ans;
   }
}
