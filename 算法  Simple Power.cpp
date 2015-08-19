#include "stdio.h"
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      int ans=a%c;
      while(b>1)
      {
         ans=((ans%c)*(ans%c))%c;
         b=b/2;
      }
      printf("%d\n",ans);
   }
}
