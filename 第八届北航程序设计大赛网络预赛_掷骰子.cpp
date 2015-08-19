#include"stdio.h"
void Quick(int a[],int s,int t)
{
   int i,j;
   i=s;j=t;
   if(i<j)
   {
      int temp=a[i];
      while(i<j)
      {
         while(a[j]>=temp&&j>i)j--;
         a[i]=a[j];
         while(a[i]<=temp&&i<j)i++;
         a[j]=a[i];
      }
      a[i]=temp;
      Quick(a,s,i-1);
      Quick(a,i+1,t);
   }
}
int main()
{
   int n;
   while(scanf("%d",&n)!=EOF)
   {
      int a[n];
      for(int i=0;i<n;i++)
      scanf("%d",&a[i]);
      Quick(a,0,n-1);
      double j=0;
      double ans=0;
      for(int i=0;i<n;i++)
      {
         ans=ans+(2*j-1+a[i])/2;
         j=j+a[i];
      }
      printf("%.2lf\n",ans);
   }
}
