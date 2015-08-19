#include "stdio.h"
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int n;
      scanf("%d",&n);
      int a[n];
      for(int i=0;i<n;i++)
      scanf("%d",&a[i]);

      int b[n];
      for(int i=0;i<n;i++)
      b[i]=0;

      int c[n];
      for(int i=0;i<n;i++)
      c[i]=i;

      for(int i=0;i<n;i++)
      {
         bool change=false;
         for(int j=0;j<n-1;j++)
         {
            if(a[j]<a[j+1])
            {
               change=true;
               b[j]++;
               int temp=b[j];b[j]=b[j+1];b[j+1]=temp;
               temp=a[j];a[j]=a[j+1];a[j+1]=temp;
               temp=c[j];c[j]=c[j+1];c[j+1]=temp;
            }
         }
         if(change==false) break;
      }

      for(int i=0;i<n;i++)
      {
         if(b[i]!=0)printf("%d %d\n",c[i]+1,b[i]);
      }

   }
}
