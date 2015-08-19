#include "stdio.h"
int main()
{
   int t;
   scanf("%d",&t);
   for(int k=1;k<=t;k++)
   {
      int n;
      scanf("%d",&n);
      int a[n];
      for(int i=0;i<n;i++)
      scanf("%d",&a[i]);

      int m;
      scanf("%d",&m);

      int s;

      printf("Case No.%d:\n",k);

      for(int k=0;k<m;k++)
      {

         scanf("%d",&s);
         int b[s+1];
      for(int i=0;i<s+1;i++) b[i]=0;
      b[0]=1;
      for(int i=0;i<s+1;i++)
      {
         if(b[i]==0) continue;
         for(int j=0;j<n;j++)
         {
            if(a[j]+i<=s)
            {
               if(b[a[j]+i]==0) b[a[j]+i]=b[i]+1;
               else if(b[a[j]+i]>b[i]+1) b[a[j]+i]=b[i]+1;
            }
         }
      }
         int ans=0;
         if(b[s]==0)printf("Impossible\n");
         else printf("%d\n",b[s]-1);
      }
   }
}
