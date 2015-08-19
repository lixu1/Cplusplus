#include "stdio.h"
#define MAXV 1000
#include "malloc.h"
typedef struct ANode
{
    int adjvex;
    struct ANode *nextarc;
}ArcNode;
typedef struct
{
    ArcNode *firstarc;
}VNode;
typedef VNode AdjList[MAXV];
typedef struct
{
    AdjList adjlist;
    int n,e;
}ALGraph;

void DFS(ALGraph *G,int v,int visited[])
{
    ArcNode *p;
    visited[v]=1;
    printf("%d ",v);
    p=G->adjlist[v].firstarc;
    while(p!=NULL)
    {
        if(visited[p->adjvex]==0)
        DFS(G,p->adjvex,visited);
        p=p->nextarc;
    }
}
void DFS1(ALGraph *G)
{
    int i;
    int visited[G->n];
    for(int i=0;i<G->n;i++) visited[i]=0;
    for(int i=0;i<G->n;i++)
    {if(visited[i]==0)DFS(G,i,visited);}
}

void DestroyALGraph(ALGraph *&G)
{
	ArcNode *p,*q;
	for(int i=0;i<G->n;i++)
	{
		p=G->adjlist[i].firstarc->nextarc;
		while(p!=NULL)
		{
			q=p;
			p=p->nextarc;
			free(q);
		}
	}
	free(G);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m,k;
        scanf("%d %d",&k,&m);
        ALGraph *G;
        G=(ALGraph *)malloc(sizeof(ALGraph));
        G->n=k;G->e=m;
        for(int i=0;i<k;i++)
        G->adjlist[i].firstarc=NULL;
        ArcNode *p,*q,*s;
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            p=(ArcNode *)malloc(sizeof(ArcNode));
            p->adjvex=b;p->nextarc=NULL;
            s=G->adjlist[a].firstarc;
            if(s==NULL) G->adjlist[a].firstarc=p;
            else
            {
               while(s->nextarc!=NULL) s=s->nextarc;
               s->nextarc=p;
            }
            q=(ArcNode *)malloc(sizeof(ArcNode));
            q->adjvex=a;q->nextarc=NULL;
            s=G->adjlist[b].firstarc;
            if(s==NULL) G->adjlist[b].firstarc=q;
            else
            {
               while(s->nextarc!=NULL)  s=s->nextarc;
               s->nextarc=q;
            }
        }

        //MatToList(g,G);
        DFS1(G);
        printf("\n");
        DestroyALGraph(G);
    }
}

