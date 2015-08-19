#include "stdio.h"
#include "malloc.h"
#define MAXV 1005
#define INF 100000

typedef struct
{
   int edges[MAXV][MAXV];
   int n,e;
}MGraph;
int Prim(MGraph *g,int v)
{
   int ans=0;
   int lowcost[MAXV]; int min;
   int closest[MAXV],i,j,k;
   for(i=0;i<g->n;i++){lowcost[i]=g->edges[v][i];closest[i]=v;}
   for(i=1;i<g->n;i++)
   {
      min=INF;
      for(j=0;j<g->n;j++)
      if(lowcost[j]!=0&&lowcost[j]<min){min=lowcost[j];k=j;}
      ans=ans+lowcost[k];
      lowcost[k]=0;
      for(j=0;j<g->n;j++)
      if(g->edges[k][j]!=0&&g->edges[k][j]<lowcost[j])
      {
         lowcost[j]=g->edges[k][j];closest[j]=k;
      }
   }
   return ans;
}
//MGraph g;
int main()
{
   int t;
   scanf("%d",&t);
   MGraph *g;
   g=(MGraph *)malloc(sizeof(MGraph));
   while(t--)
   {
      int m,n;
      scanf("%d%d",&m,&n);
      //MGraph g;
      g->n=m; g->e=n;
      for(int i=0;i<m;i++)
      for(int j=0;j<m;j++)
      g->edges[i][j]=INF;
      for(int i=0;i<m;i++)
      g->edges[i][i]=0;
      for(int i=0;i<n;i++)
      {
         int o,d,l;
         scanf("%d%d%d",&o,&d,&l);
         g->edges[o][d]=l;
         g->edges[d][o]=l;
      }
      printf("%d %d\n",Prim(g,0),m-1);
   }
   free(g);
}
