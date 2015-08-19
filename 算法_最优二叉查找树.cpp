#include "stdio.h"
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        double p[n+1];
        double q[n+1];
        for(int i=1; i<=n; i++)
            scanf("%lf",&p[i]);
        for(int j=0; j<=n; j++)
            scanf("%lf",&q[j]);
        double e[n+2][n+2];
        double w[n+2][n+2];
        int root[n+2][n+2];
        for(int i=1; i<=n+1; i++)
        {
            e[i][i-1]=q[i-1];
            w[i][i-1]=q[i-1];
        }
        for(int l=1; l<=n; l++)
        {
            for(int i=1; i<=n-l+1; i++)
            {
                int j=i+l-1;
                e[i][j]=1000000;
                w[i][j]=w[i][j-1]+p[j]+q[j];
                for(int r=i; r<=j; r++)
                {
                    double t=e[i][r-1]+e[r+1][j]+w[i][j];
                    if(t<e[i][j])
                    {
                        e[i][j]=t;
                        root[i][j]=r;
                    }
                }
            }
        }
        printf("%.3lf\n",e[1][n]);
    }
}

