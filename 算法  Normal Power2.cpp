#include "stdio.h"
int PowerMod(int a, int b, int c)
{
   int ans = 1;
   a = a % c;
   while(b>0)
   {
      if(b % 2 == 1) ans = (ans * a) % c;
      b = b/2;
      a = (a * a) % c;
   }
   return ans;
}
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      printf("%d\n",PowerMod(a,b,c));
   }
}
