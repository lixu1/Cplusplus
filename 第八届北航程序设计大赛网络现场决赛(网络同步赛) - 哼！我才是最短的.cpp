#include"stdio.h"
int main()
{
   int k;
   scanf("%d",&k);
   while(k--)
   {
      int n;
      scanf("%d",&n);
      if(n==1)
      printf("1\n");
      else if(n%2==0)
      {
         int t=n/2;
         printf("%d ",t);
         for(int i=1;i<=t-1;i++)
         {
            printf("%d ",t+i);
            printf("%d ",t-i);
         }
         printf("%d\n",n);
      }
      else
      {
         int t=n/2+1;
         printf("%d ",t);
         for(int i=1;i<=t-1;i++)
         {
            printf("%d ",t+i);
            printf("%d ",t-i);
         }
         printf("\n");
      }
   }
}
