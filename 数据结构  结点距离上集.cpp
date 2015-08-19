#include "stdio.h"
typedef struct node
{
	int data;
	int parent;
}PTree;
int main()
{
	int t;
	scanf("%d",&t);
	PTree pt[10000];
	while(t--)
	{
		int m,n;
		for(int i=0;i<10000;i++)
		{pt[i].data=-1;pt[i].parent=-1;}
		scanf("%d%d",&m,&n);
		for(int i=0;i<m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			pt[b].parent=a;
		}
		for(int i=0;i<n;i++)
		{
			int a;
			scanf("%d",&a);
			int p=pt[a].parent;
			int ans=0;
			while(p>=0)
			{
				ans++;
				p=pt[p].parent;
			}
			printf("%d\n",ans);
		}
	}
}
