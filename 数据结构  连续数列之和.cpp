#include "stdio.h"
int main()
{
   int t;
   while(scanf("%d",&t)!=EOF)
   {
      int i=1;bool flag=false;
      while(i<t)
      {
         int j=i+1;
         while(((j-i+1)*(i+j))/2<=t)
         {
            if(((j-i+1)*(i+j))/2==t)
            {
               for(int k=i;k<j;k++)printf("%d ",k);
               printf("%d\n",j);
               flag=true;
            }
            j++;
         }
         i++;
      }
      if(!flag)printf("No Exist.\n");

   }
}
