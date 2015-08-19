#include"stdio.h"
int main()
{
   int m;
   while(scanf("%d",&m)!=EOF)
   {
      int n,k;
      scanf("%d%d",&n,&k);
      int a[k];
      for(int i=0;i<k;i++)
      scanf("%d",&a[i]);
      int b[k+1];
      b[0]=a[0];
      for(int i=1;i<k;i++)
      b[i]=a[i]-a[i-1];
      b[k]=m-a[k-1];

      //for(int i=0;i<k+1;i++)
      //printf("%d ",b[i]);
      //printf("\n");

      bool flag=true;
      for(int i=0;i<k+1;i++)
      if(b[i]>n)flag=false;
      if(flag==false)
      printf("-1\n");
      else
      {
         int ans=0;
         int sum=0;
         for(int i=0;i<k+1;i++)
         {
            sum=sum+b[i];
            if(sum>n)
            {
               i--;
               sum=0;
               ans++;
            }
         }
         /*int ans=0;
         int p=0;
         while(p<k+1)
         {
            int sum=0;
            while(sum<n&&p<k+1)
            {
               sum=sum+b[p];
               p++;
            }
            if(sum==n)
            {
               if(p==k+1) break;
               else ans++;
            }
            else
            {
               p--;
               ans++;
            }
         }*/
         printf("%d\n",ans);
      }
   }
}
