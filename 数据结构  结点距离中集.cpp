#include "stdio.h"
typedef struct node
{
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
		{pt[i].parent=-1;}
		scanf("%d%d",&m,&n);
		for(int i=0;i<m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			pt[b].parent=a;
		}
		for(int i=0;i<n;i++)
		{
			int ans=0;bool flag=false;
			int a,b;
			scanf("%d%d",&a,&b);
			int c[10000];int length1=0;
			for(int i=1;i<10000;i++)c[i]=-1;c[0]=a;length1++;
			int d[10000];int length2=0;
			for(int i=1;i<10000;i++)d[i]=-1;d[0]=b;length2++;
			int p=pt[a].parent;
			while(p>=0)
			{
				c[length1]=p;length1++;
				p=pt[p].parent;
			}
			//for(int i=0;i<length1;i++)
			//printf("%d ",c[i]);
			//printf("\n");
			int q=pt[b].parent;
			while(q>=0)
			{
				d[length2]=q;length2++;
				q=pt[q].parent;
			}
			//for(int i=0;i<length2;i++)
			//printf("%d ",d[i]);
			//printf("\n");
			for(int i=0;i<length1;i++)
			{
				for(int j=0;j<length2;j++)
				{
					if(c[i]==d[j])
					{ans=i+j;flag=true;break;}
				}
				if(flag) break;
			}
			printf("%d\n",ans); 
		}
	}
}
