#include "stdio.h"
int s[200][200];
void Print(int i,int j)
{
    if(i==j)printf("A%d",i);
    else
    {
        printf("(");
        Print(i,s[i][j]);
        Print(s[i][j]+1,j);
        printf(")");
    }
}
int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        int p[t+1];
        scanf("%d",&p[0]);
        for(int i=1;i<t;i++)
        {
            scanf("%d%d",&p[i],&p[i]);
        }
        scanf("%d",&p[t]);
        int m[t+1][t+1];
        //int s[t+1][t+1];

        for(int i=1;i<=t;i++)
        m[i][i]=0;
        for(int l=2;l<=t;l++)
        {
            for(int i=1;i<=t-l+1;i++)
            {
                int j=i+l-1;
                m[i][j]=10000000;
                for(int k=i;k<=j-1;k++)
                {
                    int q=m[i][k]+m[k+1][j]+p[i-1]*p[j]*p[k];
                    if(q<m[i][j]) {m[i][j]=q;s[i][j]=k;}
                }
            }
        }
        printf("%d\n",m[1][t]);
        Print(1,t);
        printf("\n");

    }
}

