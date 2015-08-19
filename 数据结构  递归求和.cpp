#include "stdio.h"
int shuzihe(char a[],int n)
{
	if(n==1)
	{
		return (a[0]-'0'); 
	}
	else
	{
		return ( a[n-1]-'0'+shuzihe(a,n-1) );
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		char a[150];
		scanf("%s",a);
		int length=0;
		for(int i=0;a[i]!='\0';i++)
		length++;
		printf("%d\n",shuzihe(a,length));
	}
}
