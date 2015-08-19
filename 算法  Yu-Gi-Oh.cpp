#include"stdio.h"
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        int a[n];
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

        int b[2*k];
        for(int i=0;i<2*k;i++)
        scanf("%d",&b[i]);
        long long c[n+1];
        c[0]=0;
        for(int i=1;i<n+1;i++)
        {
            c[i]=c[i-1]+a[i-1];
        }
        for(int i=0;i<k;i++)
        {
            printf("%d\n",(c[b[2*i+1]]-c[b[2*i]-1])%20121024);
        }
    }
}

