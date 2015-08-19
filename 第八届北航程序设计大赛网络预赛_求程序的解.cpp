#include "stdio.h"

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
