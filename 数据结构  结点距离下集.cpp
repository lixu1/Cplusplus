#include "stdio.h"
#include "malloc.h" 
#define MAXV 100
#include <iostream>
using namespace std;
typedef struct
{
	int edges[MAXV][MAXV];
	int n,e;
}MGraph;


typedef struct ANode
{
	int adjvex;
	struct ANode *nextarc;
}ArcNode;
typedef struct Vnode
{
	int data;
	ArcNode *firstarc;
}VNode;
typedef VNode AdjList[MAXV];
typedef struct
{
	AdjList adjlist;
	int n,e;
}ALGraph;
void MatToList(MGraph g,ALGraph *&G)
{
	int i,j,n=g.n;
	ArcNode *p;
	G=(ALGraph *)malloc(sizeof(ALGraph));
	for(i=0;i<n;i++)
	G->adjlist[i].firstarc=NULL;
	for(i=0;i<n;i++)
	for(j=n-1;j>=0;j--)
	if(g.edges[i][j]!=0)
	{
		p=(ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex=j;
		p->nextarc=G->adjlist[i].firstarc;
		G->adjlist[i].firstarc=p;
	}
	G->n=n;G->e=g.e;
}
void DFS(ALGraph *G,int v,int visited[])
{
	ArcNode *p;
	visited[v]=1;
	printf("%d ",v);
	p=G->adjlist[v].firstarc;
	while(p!=NULL)
	{
		if(visited[p->adjvex]==0) DFS(G,p->adjvex,visited);
		p=p->nextarc;
	}
} 
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m,n;
		scanf("%d%d",&m,&n);
		MGraph g;
		for(int i=0;i<MAXV;i++)
		for(int j=0;j<MAXV;j++)
		g.edges[i][j]=0;
		g.e=m;
		int gn[MAXV];int length=0;
		int visited[MAXV];
		for(int i=0;i<MAXV;i++) visited[i]=0;
		for(int i=0;i<m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			bool flag=false;
			for(int i=0;i<length;i++)
			{
				if(gn[i]==a){flag=true;break;}
			}
			if(!flag)c[length]=a;length++;}
			flag=false;
			for(int i=0;i<length;i++)
			{
				if(gn[i]==b){flag=true;break;}
			}
			if(!flag)c[length]=b;length++;}
			g.edges[a][b]=1;g.edges[b][a]=1;
		}
		g.n=length;
		
	}
}
