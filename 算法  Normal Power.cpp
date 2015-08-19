#include "stdio.h"
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      int er1[1000];
      for(int i=0;i<1000;i++)
      er1[i]=0;
      int length=0;
      while(b>1)
      {
         er1[length]=b%2;
         length++;
         b=b/2;
      }
      //if(b==1)
      er1[length]=1;
      length++;
      //for(int i=length-1;i>=0;i--)
      //printf("%d",er1[i]);
      //printf("\n");

      int ans=1;
      if(er1[0]==1) ans= a%c;
      for(int i=1;i<length;i++)
      {
         if(er1[i]==1)
         {
            int ans1=a%c;
            for(int j=i;j>0;j--)
            {
               ans1=(ans1*ans1)%c;
            }
            ans=(ans1*ans)%c;
         }
      }
      printf("%d\n",ans);
   }
}
