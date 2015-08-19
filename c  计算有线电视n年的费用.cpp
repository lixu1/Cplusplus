#include "stdio.h"
void show(int year)
{
	int a,b,total;
	a=18;
	b=12;
	total=a*b*year;
	printf("%d年的费用是%d元.\n",year,total);
}
void main()
{
	show(3);
	printf("See you!\n");
}