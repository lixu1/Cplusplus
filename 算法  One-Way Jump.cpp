/*2
5
2
1
30
Case No.1:
1 0 2 0 3 2 4 3 5 4 3 5 4 6 5 4 6 5 7 6 5 7 6 8 7 6 8 7 9 8 7
*/
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

      int c[m];
      for(int i=0;i<m;i++)
      scanf("%d",&c[i]);

      printf("Case No.%d:\n",k);
      int s=c[0];
      for(int i=0;i<m;i++)
      if(s<c[i])s=c[i];

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
      for(int i=0;i<s+1;i++)
      printf("%d ",b[i]);
      printf("\n");
      for(int k=0;k<m;k++)
      {
         int ans=0;
         if(b[c[k]]==0)printf("Impossible\n");
         else printf("%d\n",b[c[k]]-1);
      }
   }
}
