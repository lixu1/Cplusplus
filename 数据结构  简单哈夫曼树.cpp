#include "stdio.h"

typedef struct 
{
	int weight;
	int parent;
	int lchild;
	int rchild;
}HTNode;
void CreateHT(HTNode ht[],int n)
{
	int i,j,k,lnode,rnode;
	int min1,min2;
	for(i=0;i<2*n-1;i++)
	ht[i].parent=-1;
	ht[i].lchild=-1;
	ht[i].rchild=-1;
	for(i=n;i<2*n-1;i++)
	{
		min1=32767;min2=32767;
		lnode=-1;rnode=-1;
		for(k=0;k<=i-1;k++)
		if(ht[k].parent==-1)
		{
			if(ht[k].weight<min1)
			{
				min2=min1;rnode=lnode;
				min1=ht[k].weight;lnode=k;
			}
			else if(ht[k].weight<min2)
			{min2=ht[k].weight;rnode=k;}
		}
		ht[i].weight=ht[lnode].weight+ht[rnode].weight;
		//printf("%d\n",ht[i].weight);
		ht[i].lchild=lnode;ht[i].rchild=rnode;
		ht[lnode].parent=i;ht[rnode].parent=i;
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
		int a[n];
		for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		//for(int i=0;i<n;i++)
		//printf("%d",a[i]);
		HTNode h[2*n-1];
		for(int i=0;i<n;i++)
		h[i].weight=a[i];
		CreateHT(h,n);
		int b[n];
		for(int i=0;i<n;i++)
		{
			b[i]=0;
			int f=h[i].parent;
		
			while(f!=-1)
			{
				b[i]++;
				f=h[f].parent;
			}
		}
		int ans=0;
		for(int i=0;i<n;i++)
		{
			ans=ans+a[i]*b[i];
		}
		printf("%d\n",ans);
	}
}
