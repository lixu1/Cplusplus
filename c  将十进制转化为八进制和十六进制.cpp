#include "stdio.h"
int main()
{
	int n;
	while(scanf("%d",&n))
	{
		 printf("十进制%d的八进制是%o.\n",n,n);
			printf("十进制%d的十六进制是%x.\n",n,n);
	}
} 
