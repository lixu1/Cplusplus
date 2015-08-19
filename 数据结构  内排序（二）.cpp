#include "stdio.h"
void ShellSort(int a[],int n)
{
   int i,j,gap;
   int tmp;
   gap=n/2;
   while(gap>0)
   {
      for(i=gap;i<n;i++)
      {
         tmp=a[i];j=i-gap;
         while(j>=0&&tmp<a[j])
         {
            a[j+gap]=a[j];j=j-gap;
         }
         a[j+gap]=tmp;
      }
      gap=gap/2;
   }
}
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int a[10000];int length=0;
      /*char qq;
      scanf("%d",&a[length]);length++;
      while(scanf("%c",&qq)&&qq!='\n')
      {
         scanf("%d",&a[length]);length++;
      }*/
      int m ;char c[10];//int k = 0 ;
do
{
	scanf("%d%[^\\-0-9]", &m, c);
	a[length++]=m;
}while(c[0]!='\n' && c[1]!='\n' );

      ShellSort(a,length);
      for(int i=0;i<length-1;i++)
      printf("%d ",a[i]);
      printf("%d\n",a[length-1]);
   }
}
