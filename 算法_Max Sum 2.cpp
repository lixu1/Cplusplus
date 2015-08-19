#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    int i,j,k,elem[201][201],sub[201][201],sum[201],tmp[201],max;
    while (t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= m; j++)
            {
                scanf("%d", &elem[i][j]);
            }
        }
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= m; j++)
            {
                sub[i][j] = 0;
            }
        }
        for (k = 1; k <= m; k++)
        {
            sub[0][k] = 0;
            for (i = 1; i <= n; i++)
            {
                sub[i][k] += sub[i-1][k] + elem[i][k];
            }
        }
        int max = -1000;
        for (i = 1; i <= n; i++)
        {
            for (j = i; j <= n; j++)
            {
                for (k = 1; k <= m; k++)
                {
                    sum[k] = sub[j][k] - sub[i-1][k];
                }
                for (k = 0; k <= m ; k++)
                {
                    tmp[k] = 0;
                }
                for (k = 1; k <= m; k++)
                {
                    if (sum[k] + tmp[k-1] > sum[k])
                    {
                        tmp[k] = tmp[k-1] + sum[k];
                    }
                    else tmp[k] = sum[k];
                    if (tmp[k] > max) max=tmp[k];
                }
            }
        }
        printf("%d\n", max);
    }
    return 0;
}
