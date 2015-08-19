#include "stdio.h"
typedef struct
{
	int weight;
	int parent;
	int lchild;
	int rchild; 
}HTNode;
void CreatHT(HTNode ht[],int n)
{
	int i,j,k,lnode,rnode;
	int min1,min2;
	for(i=0;i<2*n-1;i++) ht[i].lchild=ht[i].rchild=ht[i].parent=-1;
	for(i=n;i<n*2-1;i++)
	{
		min1=min2=2000;
		lnode=rnode=-1;
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
		ht[i].weight=ht[rnode].weight+ht[lnode].weight;
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
		char a[2000];int ans=0;
		scanf("%s",a);
		char b[2000];int length=0;
		int c[2000];
		for(int i=0;i<2000;i++) c[i]=0;
		for(int i=0;a[i]!='\0';i++)
		{
			bool flag=true;
			for(int j=0;j<length;j++)
			{
				if(a[i]==b[j]) {c[j]++;flag=false;}
			}
			if(flag) {b[length]=a[i];c[length]++;length++;}
		}
		//printf("%d\n",length);
		//for(int i=0;i<length;i++)
		//printf("%d ",c[i]);
		//printf("\n");
		HTNode ht[2*length-1];
		for(int i=0;i<length;i++)
		ht[i].weight=c[i];
		CreatHT(ht,length);
		int d[length];
		for(int i=0;i<length;i++) d[i]=0;
		for(int i=0;i<length;i++)
		{
			int l=0;int p=ht[i].parent;
			while(p!=-1)
			{
				l++;p=ht[p].parent;
			}
			d[i]=l;
		}
		//for(int i=0;i<length;i++)
		//printf("%d ",d[i]);
		//printf("\n");
		for(int i=0;i<length;i++)
		ans=ans+c[i]*d[i];
		printf("%d\n",ans);
	} 
}
