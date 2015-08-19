#include "stdio.h"
int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
       int t1=t;
        long long a[4]= {1,1,1,0};
        long long ans[4]= {1,0,0,1};
        while(t>=1)
        {
            long long ans1[4];
            if(t%2==1)
            {
                for(int i=0; i<4; i++)
                    ans1[i]=ans[i];
                ans[0]=(ans1[0]*a[0]%100007+ans1[1]*a[2]%100007)%100007;
                ans[1]=(ans1[0]*a[1]%100007+ans1[1]*a[3]%100007)%100007;
                ans[2]=(ans1[2]*a[0]%100007+ans1[3]*a[2]%100007)%100007;
                ans[3]=(ans1[2]*a[1]%100007+ans1[3]*a[3]%100007)%100007;
            }
            for(int i=0; i<4; i++)
                ans1[i]=a[i];
            a[0]=(ans1[0]*ans1[0]%100007+ans1[1]*ans1[2]%100007)%100007;
            a[1]=(ans1[0]*ans1[1]%100007+ans1[1]*ans1[3]%100007)%100007;
            a[2]=(ans1[2]*ans1[0]%100007+ans1[3]*ans1[2]%100007)%100007;
            a[3]=(ans1[2]*ans1[1]%100007+ans1[3]*ans1[3]%100007)%100007;
            t=t/2;
        }
        printf("%lld\n",ans[0]%100007);

        /*int b[3];
        b[0]=1;b[1]=2;
        for(int i=0;i<t1-2;i++)
        {
           b[2]=(b[1]%100007+b[0]%100007)%100007;
           b[0]=b[1];
           b[1]=b[2];
        }
        printf("%d\n",b[2]);*/
    }
}
