#include "stdio.h"
int main()
{
	char c;
	printf("请输入一个小写字母:\n");
	scanf("%c",&c);
	printf("%c--%c",c,(c-'a'+1)%26+'a');
} 
