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
        for(int i=0; i<n; i++)
            b[i]=1;
        for(int i=1; i<n; i++)
        {
            int j=i-1;
            while(j>=0)
            {
               if(a[i]>a[j])
               {
                  if(b[j]+1>b[i])
                  b[i]=b[j]+1;
               }
               j--;
            }
        }
        //for(int i=0;i<n;i++)
        //printf("%d ",b[i]);
        //printf("\n");
        int ans=0;
        for(int i=0; i<n; i++)
        {
            if(b[i]>ans)ans=b[i];
        }
        //ans++;
        printf("Case %d: %d\n",no,ans);
    }
}

