#include "stdio.h"
void Quick(int a[],int s,int t)
{
    int i=s,j=t;
    if(i<j)
    {
        int temp=a[i];
        while(i<j)
        {
            while(a[j]>=temp&&j>i)j--;
            a[i]=a[j];
            while(a[i]<=temp&&i<j)i++;
            a[j]=a[i];
        }
        a[i]=temp;
        Quick(a,s,i-1);
        Quick(a,i+1,t);
    }
}
int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        int a[t];
        for(int i=0;i<t;i++)
        scanf("%d",&a[i]);
        long long ans=0;
        Quick(a,0,t-1);
        for(int i=0;i<t;i++)
        {
            ans=ans+a[i]*(t-i);
        }
        printf("%lld\n",ans);
    }
}
