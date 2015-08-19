#include "stdio.h"
int main()
{
   int t;
   scanf("%d",&t);
   for(int k=0;k<t;k++)
   {
      int n;
      scanf("%d",&n);
      int a[n];
      for(int i=0;i<n;i++)
      scanf("%d",&a[i]);
      int m;
      scanf("%d",&m);
      int b[m];
      for(int i=0;i<m;i++)
      scanf("%d",&b[i]);
      int max_b=b[0];
      for(int i=0;i<m;i++)
      if(max_b<b[i])max_b=b[i];

      printf("Case No.%d:\n",k+1);
      int c[max_b+1];
      for(int i=0;i<=max_b;i++)
      c[i]=0;
      c[0]=1;

      int d[max_b+2];
      int p1=0,p2=1;
      d[0]=0;
      //printf("%d\n",max_b);
      while(p2!=p1)
      {
         for(int q=0;q<n;q++)
         {
            if(c[d[p1]+a[q]] < max_b+1&&c[d[p1]+a[q]]==0)
            {
               c[d[p1]+a[q]]=c[d[p1]]+1;
                  d[p2]=d[p1]+a[q];
                  p2=(p2+1)%(max_b+2);
            }
         }

         p1=(p1+1)%(max_b+2);
         //printf("p1 %d %d\n",p1,d[p1]);
      }

      //for(int i=0;i<max_b+1;i++)
      //printf("%d ",c[i]);
      //printf("\n");

      for(int i=0;i<m;i++)
      {
         if(c[b[i]]==0)printf("Impossible\n");
         else printf("%d\n",c[b[i]]-1);
      }
   }
}
