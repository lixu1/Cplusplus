#include <stdio.h>

int n;

int rabbit(int year,int now,int last)
{
    if (year == n) return now + last; else
    return rabbit(year+1,last+now,now);
}

int main()
{
    while (scanf("%d\n",&n) != EOF)
    {
          printf("%d\n",rabbit(1,0,1));
    }
    return 0 ;
}
