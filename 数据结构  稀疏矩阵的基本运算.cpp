#include "stdio.h"
#define MaxSize 10000

typedef struct
{
	int r;
	int c;
	int d;
}TupNode;
typedef struct
{
	int rows;
	int cols;
	int nums;
	TupNode data[MaxSize];
}TSMatrix;

void DispMat(TSMatrix t)
{
	int i;
	if(t.nums<=0) return;
	printf("%d %d %d\n",t.rows,t.cols,t.nums);
	for(i=0;i<t.nums;i++)
	printf("%d %d %d\n",t.data[i].r , t.data[i].c , t.data[i].d);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int a[n][n];
		int b[n][n];
		int c[n][n];
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		scanf("%d",&a[i][j]);
		
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		scanf("%d",&b[i][j]);
		
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			int ans=0;
			for(int k=0;k<n;k++)
			ans=ans+a[i][k]*b[k][j];
			c[i][j]=ans;
		}
		TSMatrix t1;
		TSMatrix t2;
		TSMatrix t3;
		t1.rows=n;
	t1.cols=n;
	t1.nums=0;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		if(a[i][j]!=0)
		{
			t1.data[t1.nums].r=i;
			t1.data[t1.nums].c=j;
			t1.data[t1.nums].d=a[i][j];
			t1.nums++;
		}
	}
	
		t2.rows=n;
	t2.cols=n;
	t2.nums=0;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		if(b[i][j]!=0)
		{
			t2.data[t2.nums].r=i;
			t2.data[t2.nums].c=j;
			t2.data[t2.nums].d=b[i][j];
			t2.nums++;
		}
	}
	
	t3.rows=n;
	t3.cols=n;
	t3.nums=0;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		if(c[i][j]!=0)
		{
			t3.data[t3.nums].r=i;
			t3.data[t3.nums].c=j;
			t3.data[t3.nums].d=c[i][j];
			t3.nums++;
		}
	}
	
		DispMat(t1);
		DispMat(t2);
		DispMat(t3);
	}
	scanf("%d",&t);
}
