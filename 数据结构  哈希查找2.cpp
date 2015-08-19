#include "stdio.h"
#include <memory.h>
int h[1000000];
int main()
{
   int t;int p;
   scanf("%d",&t);
   while(t--)
   {
      memset(h, 0, sizeof(h));
      //for(int i=0;i<1000000;i++)
      //h[i]=0;
      int m ;char c[10];//int k = 0 ;
      do
      {
         scanf("%d%[^\\-0-9]", &m, c);
         h[m]=1;
      }while(c[0]!='\n' && c[1]!='\n' );
      scanf("%d",&m);
      for(int i=0;i<m;i++)
      {
         scanf("%d",&p);
         if(h[p]==1) printf("Yes.\n");
         else printf("No.\n");
      }
   }
}
