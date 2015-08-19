#include"stdio.h"
int main()
{
    int m,n;
    int no=0;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        no++;
        int a[m+1];
        int b[n+1];
        int c[m+1][n+1];
        for(int i=1; i<=m; i++)
            scanf("%d",&a[i]);
        for(int j=1; j<=n; j++)
            scanf("%d",&b[j]);
        for(int i=0; i<=m; i++)
            c[i][0]=0;
        for(int i=0; i<=n; i++)
            c[0][i]=0;
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(a[i]==b[j])c[i][j]=c[i-1][j-1]+1;
                else
                {
                    if(c[i-1][j]>=c[i][j-1])
                        c[i][j]=c[i-1][j];
                    else c[i][j]=c[i][j-1];
                }
            }
        }
        printf("Case #%d: %d\n",no,c[m][n]);
    }
}

