#include"stdio.h"
#include "stdlib.h"

void merge(int r[],int low,int mid,int high,int b[],int c[])
{
   int r1[high-low+1];int b1[high-low+1];int c1[high-low+1];
   int i=low,j=mid+1,k=0;
   while(i<=mid&&j<=high)
   {
      if(r[i]>=r[j])
      {
         //for(int p=j;p<=high;p++)c[p]++;
         r1[k]=r[i];b1[k]=b[i];c1[k]=c[i];i++;k++;
      }
      else
      {
         for(int p=i;p<=mid;p++)c[p]++;
         r1[k]=r[j];b1[k]=b[j];c1[k]=c[j];j++;k++;
      }
   }
   while(i<=mid){r1[k]=r[i];b1[k]=b[i];c1[k]=c[i];i++;k++;}
   while(j<=high){r1[k]=r[j];b1[k]=b[j];c1[k]=c[j];j++;k++;}
   //for(i=low;i<=high;i++)
   //printf("%d %d %d\n",r[i],b[i],c[i]);
   for(k=0,i=low;i<=high;k++,i++){r[i]=r1[k];b[i]=b1[k];c[i]=c1[k];}
   //for(i=low;i<=high;i++)
   //printf("%d %d %d\n",r[i],b[i],c[i]);
}

void mergeSort(int r[],int low,int high,int b[],int c[])
{
   int mid;
   if(low<high)
   {
      mid=(low+high)/2;
      mergeSort(r,low,mid,b,c);
      mergeSort(r,mid+1,high,b,c);
      merge(r,low,mid,high,b,c);
   }
}
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
      b[i]=i;

      int c[n];
      for(int i=0;i<n;i++)
      c[i]=0;


      mergeSort(a,0,n-1,b,c);

      for(int i=0;i<n;i++)
      {
         if(c[i]!=0)printf("%d %d\n",b[i]+1,c[i]);
      }



   }
}
