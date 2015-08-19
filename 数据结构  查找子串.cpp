#include "stdio.h"
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		char a[150];
		scanf("%s",a);
		int ans=0;
		int i=0,j=0;
		int length=0;
		int k=0;
		while(a[k]!='\0')
		{
			length++;
			k++; 
		}
		//printf("%d",length);
		while(i<length&&j<length)
		{
			if(a[i]==a[j])
			{
				j++;
				int ans1=j-i;
				if(ans1>ans)ans=ans1;
			}
			else
			{
				i=j;
			}
		}
		printf("%d\n",ans);
}
}
 
