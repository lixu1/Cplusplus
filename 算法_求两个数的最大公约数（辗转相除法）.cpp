#include "stdio.h"
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a<b)
		{int temp=a;a=b;b=temp;}
		int r=a%b;
		while(r!=0)
		{
			a=b;b=r;r=a%b;
		}
		printf("%d\n",b);
	}
}
