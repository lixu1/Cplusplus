#include"stdio.h"
int main()
{
    long long  a[1001];
    a[0]=0;
    a[1]=1;
    for(int i=2;i<=1000;i++)
    a[i]=(a[i-1]+a[i-2])%10007;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",(a[n]));
    }
}

