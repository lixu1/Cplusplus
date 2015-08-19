#include"stdio.h"
int f[1001][1001];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int a[n+1];
        int b[n+1];
        for(int i=1; i<=n; i++)
            scanf("%d %d",&a[i],&b[i]);
        int max=n;
        if(max<m)max=m;

        for(int i=0; i<=max; i++)
        {
            f[i][0]=0;
            f[0][i]=0;
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=m; j++)
            {
                int ans1=f[i-1][j];
                if(j<a[i])
                {f[i][j]=ans1;continue;}
                int ans2=f[i-1][j-a[i]]+b[i];
                if(ans2>ans1) f[i][j]=ans2;
                else f[i][j]=ans1;
            }
        }
        /*for(int i=0; i<=max; i++)
        {
            for(int j=0; j<=max; j++)
                printf("%d ",f[i][j]);
            printf("\n");
        }*/
        printf("%d\n",f[n][m]);
    }
}

