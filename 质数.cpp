#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
   int n,ans;
   while(scanf("%d",&n)!=EOF)
   {
      ans=2;
      for(int i=2;(i*i)<=n;i++)
      {
         if(n%i==0)
         break;
         ans++;
      }
      if(ans*ans <= n) printf("NO\n");
      else printf("YES\n");
   }
   return 0;
}
