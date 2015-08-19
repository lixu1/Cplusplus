//1-1,2-2,3-2,4-3,5-4,6-
#include "stdio.h"

int main()
{
	int t;
	scanf("%d",&t);
	int a[101],b[101],c[101];
	a[0]=0;b[0]=0;c[0]=0;
	for(int i=1;i<101;i++)a[i]=a[i-1]+1;
	for(int i=1;i<101;i++)b[i]=b[i-1]+2;
	for(int i=1;i<101;i++)c[i]=c[i-1]+5;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int ans=0;
		if(n!=0)
		{for(int i=0;i<101;i++)
		{
			for(int j=0;j<101;j++)
			{
			for(int k=0;k<101;k++)
			{if(a[i]+b[j]+c[k]==n){ans++;break;}}
			}
		}
		}
		printf("%d\n",ans);
	}
}
