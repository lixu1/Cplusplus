#include "stdio.h"
int fu(int n)
{
    if(n==0) return 1;
    else if(n==1) return 1;
    else if(n==2) return 0;
    else return (fu(n/2)+fu(n/3));
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a;
        scanf("%d",&a);
        printf("%d\n",fu(a));
    }
}

