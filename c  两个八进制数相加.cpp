#include "stdio.h"
#include <iostream>
using namespace std;
int main()
{
	int x,y,sum;
	printf("\n�����������˽�������:\n");
	scanf("%o%o",&x,&y);
	sum=x+y;
	printf("0%o+0%o=0%o\n",x,y,sum);
	printf("%d+%d=%d\n",x,y,sum);
	system("pause");
} 
