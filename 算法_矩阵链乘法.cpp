/*≤‚ ‘ ˝æ›
1
6
30 35 15 5 10 20 25
*/
#include "stdio.h"
#define MAX 10000000
int s[10000][10000];
void Print(int i,int j)
{
   if(i==j)printf("A%d",i);
   else
   {
      printf("(");
      Print(i,s[i][j]);
      Print(s[i][j]+1,j);
      printf(")");
   }
}
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int n;
      scanf("%d",&n);
      int a[n+1];
      for(int i=0;i<n+1;i++)
      scanf("%d",&a[i]);
      int m[n+1][n+1];

      for(int i=1;i<=n;i++)
      m[i][i]=0;
      for(int l=2;l<=n;l++)
      {
         for(int i=1;i<=n-l+1;i++)
         {
            int j=i+l-1;
            m[i][j]=MAX;
            for(int k=i;k<=j-1;k++)
            {
               int q=m[i][k]+m[k+1][j]+a[i-1]*a[k]*a[j];
               if(q<m[i][j]){m[i][j]=q;s[i][j]=k;}
            }
         }
      }
      Print(1,n);

   }
}
