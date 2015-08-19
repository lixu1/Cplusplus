/*测试数据
1
6
7 9 3 4 8 4
8 5 6 4 5 7
2 4
2 3 1 3 4
2 1 2 2 1
3 2

*/
#include "stdio.h"
int main()
{
   int q;
   scanf("%d",&q);
   while(q--)
   {
      int n;
      scanf("%d",&n);
      int a[3][n+1];
      for(int i=1;i<3;i++)
      for(int j=1;j<n+1;j++)
      scanf("%d",&a[i][j]);

      int e1,e2;
      scanf("%d%d",&e1,&e2);

      int t[3][n];
      for(int i=1;i<3;i++)
      for(int j=1;j<n;j++)
      scanf("%d",&t[i][j]);

      int x1,x2;
      scanf("%d%d",&x1,&x2);
      int ff;
      int ll;

      int f[2][n+1];
      int l[2][n+1];

      f[1][1]=e1+a[1][1];
      f[2][1]=e2+a[2][1];
      for(int j=2;j<=n;j++)
      {
         if(f[1][j-1]+a[1][j]<=f[2][j-1]+t[2][j-1]+a[1][j])
         {
            f[1][j]=f[1][j-1]+a[1][j];
            l[1][j]=1;
         }
         else
         {
            f[1][j]=f[2][j-1]+t[2][j-1]+a[1][j];
            l[1][j]=2;
         }
         if(f[2][j-1]+a[2][j]<=f[1][j-1]+t[1][j-1]+a[2][j])
         {
            f[2][j]=f[2][j-1]+a[2][j];
            l[2][j]=2;
         }
         else
         {
            f[2][j]=f[1][j-1]+t[1][j-1]+a[2][j];
            l[2][j]=1;
         }
      }
      if(f[1][n]+x1<=f[2][n]+x2){ff=f[1][n]+x1;ll=1;}
      else {ff=f[2][n]+x2;ll=2;}

      printf("最小时间为：%d\n过程为：\n",ff);

      int i=ll;
      printf("line %d,station %d\n",i,n);
      for(int j=n;j>=2;j--)
      {
         i=l[i][j];
         printf("line %d,station %d\n",i,j-1);
      }



   }
}
