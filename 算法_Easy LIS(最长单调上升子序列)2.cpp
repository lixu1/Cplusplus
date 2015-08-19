#include "stdio.h"
int main()
{
    int n;
    int no=0;
    while(scanf("%d",&n)!=EOF)
    {
        no++;
        int a[n];
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        int b[n];
        int length=0;
        b[length]=a[0];
        length++;
        for(int i=1;i<n;i++)
        {
           if(a[i]>b[length-1])
           {
              b[length]=a[i];
               length++;
           }
           else
           {
              int low=0;
              int high=length-1;
              int mid;
              while(low<high)
              {
                 mid=(low+high)/2;
                 if(a[i]==b[mid])
                 {
                    low=mid;break;
                 }
                 else if(a[i]>b[mid])
                 low=mid+1;
                 else
                 high=mid;
              }
              b[low]=a[i];
           }
           //for(int j=0;j<length;j++)
           //printf("%d ",b[j]);
           //printf("\n");
        }
        printf("Case %d: %d\n",no,length);
    }
}
