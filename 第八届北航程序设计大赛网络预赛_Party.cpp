#include "stdio.h"
const int MAXN = 550;
int uN, vN;  				    // u,ｖ数目
bool g[MAXN][MAXN];			    // g[i][j] 表示 xi与yj相连
int xM[MAXN], yM[MAXN];		    //  输出量
bool chk[MAXN];  				// 辅助量 检查某轮 y[v]是否被check
bool SearchPath(int u)
{
   int v;
   for(v = 0; v < vN; v++)
   {
      if(g[u][v] && !chk[v])
      {
         chk[v] = true;
         if(yM[v] == -1 || SearchPath(yM[v]))
         {
            yM[v] = u;
            xM[u] = v;
             return true ;
         }
      }
   }
   return false ;
}

int MaxMatch()
{
   int u;
   int ret = 0 ;
   for(int i=0;i<MAXN;i++)
   {
      xM[i]=-1;
      yM[i]=-1;
   }
   for(u = 0; u < uN; u++)
   {
      if(xM[u] == -1)
      {
         for(int i=0;i<MAXN;i++)
   {
      chk[i]=false;
   }
         if(SearchPath(u)) ret++;
      }
   }
   return ret;
}
int main()
{
   int n,m;
   while(scanf("%d%d",&n,&m)!=EOF)
   {
      uN=n;
      vN=m;
      for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
      g[i][j]=false;
      for(int i=0;i<n;i++)
      {
         int k;
         scanf("%d",&k);
         for(int j=0;j<k;j++)
         {
            int p;
            scanf("%d",&p);
            g[i][p-1]=true;
         }
      }
      printf("%d\n",MaxMatch());
   }
}
