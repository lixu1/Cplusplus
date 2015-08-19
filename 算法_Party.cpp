#include "stdio.h"
long long zheng[100001];
long long fan[100001];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            printf("0\n");
        else
        {
            int l[n];
            int a[n+1];
            for(int i=1; i<n; i++)
                scanf("%d",&l[i]);
            for(int i=1; i<n+1; i++)
                scanf("%d",&a[i]);


            long long zhengnum;

            long long fannum;
            for(int i=0;i<n+1;i++)
            {
               zheng[i]=0;
               fan[i]=0;
            }

            zheng[1]=0;
            zhengnum=a[1];
            for(int i=2; i<n+1; i++)
            {
                zheng[i]=zheng[i-1]+zhengnum*l[i-1];
                zhengnum=zhengnum+a[i];
            }
            fan[n]=0;
            fannum=a[n];
            for(int i=n-1; i>=1; i--)
            {
                fan[i]=fan[i+1]+fannum*l[i];
                fannum=fannum+a[i];
            }
            /*for(int i=1;i<=n;i++)
            printf("%lld ",zhengnum[i]);
            printf("\n");
            for(int i=1;i<=n;i++)
            printf("%lld ",zheng[i]);
            printf("\n");
            for(int i=1;i<=n;i++)
            printf("%lld ",fannum[i]);
            printf("\n");
            for(int i=1;i<=n;i++)
            printf("%lld ",fan[i]);
            printf("\n");
            */
            long long ans=1000000000000;
            for(int i=1; i<=n; i++)
            {
                if(zheng[i]+fan[i]<ans)
                    ans=zheng[i]+fan[i];
            }
            printf("%lld\n",ans);
        }
    }
}
