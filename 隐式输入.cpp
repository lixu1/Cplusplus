#include "stdio.h"
#include "conio.h"
int main()
{
	char ch,str[100];
	int i=0;
	while(1)
	{
		ch=getch();
		if(ch!=13)
		{
			str[i]=ch;
			i++;
			printf("*");
		}
		else
		{
			break;
		}
	}
	printf("\n");
	return 0;
}
