#include "stdio.h"
int find(int i,int k,int q[])
{
	int j=1;
	while(j<k)
	{
		if((q[j]==i)||(q[j]-i==j-k)||(q[j]-i==k-j))return 0;
		j++;
	}
	return 1;
}
void place(int k,int n,int &ans,int q[])
{
	if(k>n) ans++;
	else
	{
		for(int i=1;i<=n;i++)
		if(find(i,k,q))
		{
			q[k]=i;place(k+1,n,ans,q);
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	int q[t];
	int ans=0;
	place(1,t,ans,q);
	printf("%d\n",ans);
	scanf("%d",&t);
}
