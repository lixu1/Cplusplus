#include"stdio.h"
long long a[1000000];
void QuickSort(int p,int q)
{
    int i=p,j=q;
    if(p<q)
    {
        long long t=a[p];
        while(i!=j)
        {
            while(j>i&&a[j]>=t)j--;
            a[i]=a[j];
            while(i<j&&a[i]<=t)i++;
            a[j]=a[i];
        }
        a[i]=t;
        QuickSort(p,i-1);
        QuickSort(i+1,q);
    }
    return;
}
int BinSearch(int n,long long k)
{
   int low=0,high=n-1,mid;
   while(low<=high)
   {
      mid=(low+high)/2;
      if(a[mid]==k)return mid;
      if(a[mid]>k)high=mid-1;
      else low=mid+1;
   }
   return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int k=0; k<t; k++)
    {
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%lld",&a[i]);

        int m;
        scanf("%d",&m);
        int b[m];
        for(int i=0; i<m; i++)
            scanf("%d",&b[i]);

        printf("Case No.%d:\n",k+1);
        QuickSort(0,n-1);

        //for(int i=0;i<n;i++)
        //printf("%lld\n",a[i]);

        for(int i=0; i<m; i++)
        {
           int ans=BinSearch(n,b[i]);
           if(ans==-1)printf("Not Found!\n");
           else
           {
              while(a[ans+1]==a[ans]&&ans<n-1)ans++;
              printf("%d\n",n-ans);
           }
        }
    }
}
