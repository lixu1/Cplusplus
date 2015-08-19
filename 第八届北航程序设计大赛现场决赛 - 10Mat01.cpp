#include "stdio.h"
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int n;
      scanf("%d",&n);
      char b[n][n+2];
      for(int i=0;i<n;i++)
      scanf("%s",b[i]);

      int a[n][n];
      for(int i=0;i<n;i++)
      {
         for(int j=0;j<n;j++)
         a[i][j]=b[i][j]-'0';
      }
      int ans=0;
      for(int i=0;i<n-1;i++)
      {
         for(int j=0;j<n-1;j++)
         {
            for(int k=i+1;k<n;k++)
            {
               if(a[i][j]==a[k][j])
               {
                  for(int s=j+1;s<n;s++)
                  {
                     if(a[i][s]==a[i][j])
                     {
                        if(a[k][s]==a[i][j])
                        ans++;
                     }
                  }
               }
            }
         }
      }
      printf("%d\n",ans);
   }
}
