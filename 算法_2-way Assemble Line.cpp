#include "stdio.h"
int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        int a[3][t+1];
        int b[3][t+1];
        for(int i=1;i<3;i++)
        for(int j=1;j<=t;j++)
        scanf("%d",&a[i][j]);

        for(int i=1;i<3;i++)
        for(int j=1;j<=t;j++)
        scanf("%d",&b[i][j]);

        int l[2][t+1];
        int ll;
        int ff;

        int f[3][t+1];
        f[1][1]=a[1][1];
        f[2][1]=a[2][1];

        for(int j=2;j<=t;j++)
        {
            if(f[1][j-1]+a[1][j]+1<=f[2][j-1]+b[2][j-1]+a[1][j])
            {
                f[1][j]=f[1][j-1]+a[1][j]+1;
                l[1][j]=1;

            }
            else
            {
                f[1][j]=f[2][j-1]+b[2][j-1]+a[1][j];
                l[1][j]=2;
            }
            if(f[2][j-1]+a[2][j]+1<=f[1][j-1]+b[1][j-1]+a[2][j])
            {
                f[2][j]=f[2][j-1]+a[2][j]+1;
                l[2][j]=2;
            }
            else
            {
                f[2][j]=f[1][j-1]+b[1][j-1]+a[2][j];
                l[2][j]=1;
            }
        }
        if(f[1][t]<=f[2][t]){ff=f[1][t];ll=1;}
        else{ff=f[2][t];ll=2;}
        printf("%d\n",ff);

        int ans[t+1];
        int i=ll;
        ans[t]=ll;
        for(int j=t;j>=2;j--)
        {
            i=l[i][j];
            ans[j-1]=i;
        }
        for(int j=1;j<=t;j++)
        printf("%d",ans[j]);
        printf("\n");
    }
}

