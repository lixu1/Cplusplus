#include "stdio.h"
#include "stdlib.h"
void Quick(int a[],int m,int n)
{
    int i=m,j=n;
    if(m<n)
    {
        int temp=a[i];

        while(i!=j)
        {

            while(a[j]>=temp&&j>i)j--;
            a[i]=a[j];
            while(a[i]<=temp&&i<j)i++;
            a[j]=a[i];

        }
        a[i]=temp;
        Quick(a,m,i-1);
        Quick(a,i+1,n);
    }
    return;
}
int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        int a[t];
        for(int i=0; i<t; i++)
            scanf("%d",&a[i]);

        for(int i=0;i<t;i++)
        {
            int s=rand()%t;
            int p=a[i];
            a[i]=a[s];
            a[s]=p;
        }

        Quick(a,0,t-1);
        for(int i=0; i<t-1; i++)
            printf("%d ",a[i]);
        printf("%d\n",a[t-1]);
    }
}

