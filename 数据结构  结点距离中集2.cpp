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
			int a,b; int ans1=0;int ans2=0;bool flag=false;
			scanf("%d%d",&a,&b);
			int p=a;
			while(p>=0)
			{
				int q=b;
				if(q==p){flag=true;break;}
				else
				{
					while(q>=0&&q!=p)
					{
						q=pt[q].parent;
						ans2++;
					}
					if(q==p){flag=true;break;}
					else{ans2=0;}
				}
				if(flag)break;
				p=pt[p].parent;
				ans1++;
			}
			printf("%d\n",ans1+ans2);
		}
	}
}
