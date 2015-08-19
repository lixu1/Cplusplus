#include "stdio.h"
int main()
{
    int t;
    scanf("%d",&t);
    for(int k=0; k<t; k++)
    {
        int n;
        scanf("%d",&n);
        int a[n];
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        int m;
        scanf("%d",&m);
        int b[m];
        for(int i=0; i<m; i++)
            scanf("%d",&b[i]);
        int bmax=b[0];
        for(int i=1; i<m; i++)
            if(bmax<b[i]) bmax=b[i];
        int amax=a[0];
        for(int i=1; i<n; i++)
            if(amax<a[i]) amax=a[i];

        int c[bmax+amax+1];
        for(int i=0; i<amax+bmax+1; i++)
            c[i]=0;
        c[0]=1;
        int d[bmax+amax+1];
        int p1=0,p2=1;
        d[p1]=0;
        while(p1!=p2)
        {
            for(int i=0; i<n; i++)
            {
                if(d[p1]+a[i]<bmax+amax+1&&c[d[p1]+a[i]]==0)
                {
                    c[d[p1]+a[i]]=c[d[p1]]+1;
                    d[p2]=d[p1]+a[i];
                    p2++;
                }
            }
            for(int i=0; i<n; i++)
            {
                if(d[p1]-a[i]>0&&c[d[p1]-a[i]]==0)
                {
                    c[d[p1]-a[i]]=c[d[p1]]+1;
                    d[p2]=d[p1]-a[i];
                    p2++;
                }
            }
            p1++;
        }
        //for(int i=0;i<amax+bmax+1;i++)
        //printf("%d ",c[i]);
        //printf("\n");



        printf("Case No.%d:\n",k+1);
        for(int i=0; i<m; i++)
        {
            if(c[b[i]]==0) printf("Impossible\n");
            else printf("%d\n",c[b[i]]-1);
        }
    }
}
