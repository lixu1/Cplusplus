#include "stdio.h"
int BinSearch(int a[],int n,int k)
{
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==k) return mid;
        if(a[mid]>k) high=mid-1;
        else low=mid+1;
    }
    return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int a[n];int b[m];
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(int i=0;i<m;i++)
        scanf("%d",&b[i]);
        for(int i=0;i<m;i++)
        {
            if(BinSearch(a,n,b[i])==-1) printf("-1\n");
            else
            printf("%d\n",BinSearch(a,n,b[i])+1);
        }
    }
}

