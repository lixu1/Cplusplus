#include "stdio.h"
int main()
{
	char c;
	printf("������һ��Сд��ĸ:\n");
	scanf("%c",&c);
	printf("%c--%c",c,(c-'a'+1)%26+'a');
} 
