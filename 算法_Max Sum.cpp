#include "stdio.h"
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a[n+1];
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        int ans=0;
        int b=0;
        for(int i=1;i<=n;i++)
        {
            if (b>0)
            {
                b+=a[i];
            }
            else
            {
                b=a[i];
            }
            if (b>ans)
            {
                ans=b;
            }
        }
        printf("%d\n",ans);
    }
}

