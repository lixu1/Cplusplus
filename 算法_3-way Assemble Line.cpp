#include "stdio.h"
int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        int a[4][t+1];
        int b[7][t+1];

        for(int i=1;i<4;i++)
        for(int j=1;j<=t;j++)
        scanf("%d",&a[i][j]);

        for(int i=1;i<7;i++)
        for(int j=1;j<=t;j++)
        scanf("%d",&b[i][j]);

        int l[4][t+1];
        int ll;
        int ff;

        int f[4][t+1];
        f[1][1]=a[1][1];
        f[2][1]=a[2][1];
        f[3][1]=a[3][1];

        for(int j=2;j<=t;j++)
        {
            int q1=f[1][j-1]+a[1][j]+1;
            int q2=f[2][j-1]+b[3][j-1]+a[1][j];
            int q3=f[3][j-1]+b[5][j-1]+a[1][j];
            f[1][j]=q1;l[1][j]=1;
            if(f[1][j]>=q2){f[1][j]=q2;l[1][j]=2;}
            if(f[1][j]>=q3){f[1][j]=q3;l[1][j]=3;}

            q1=f[1][j-1]+b[1][j-1]+a[2][j];
            q2=f[2][j-1]+a[2][j]+1;
            q3=f[3][j-1]+b[6][j-1]+a[2][j];
            f[2][j]=q1;l[2][j]=1;
            if(f[2][j]>=q2){f[2][j]=q2;l[2][j]=2;}
            if(f[2][j]>=q3){f[2][j]=q3;l[2][j]=3;}


            q1=f[1][j-1]+b[2][j-1]+a[3][j];
            q2=f[2][j-1]+b[4][j-1]+a[3][j];
            q3=f[3][j-1]+a[3][j]+1;
            f[3][j]=q1;l[3][j]=1;
            if(f[3][j]>=q2){f[3][j]=q2;l[3][j]=2;}
            if(f[3][j]>=q3){f[3][j]=q3;l[3][j]=3;}
        }
        ff=f[1][t];ll=1;
        if(ff>f[2][t]){ff=f[2][t];ll=2;}
        if(ff>f[3][t]){ff=f[3][t];ll=3;}

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

