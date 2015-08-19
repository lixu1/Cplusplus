#include <iostream>
using namespace std;
int main()
{
   int n;
   char c;
   int a[110];
   int i,j,total,temp;
   while(cin>>n>>c)
   {
      total=0;
      if(c=='a')
      {
         for(i=1;i<=n;i++)
         {
            cin>>temp;
            if(temp%2==1)
            {total++;a[total]=temp;}
         }
      }
      else
      {
         for(i=1;i<=n;i++)
         {
            cin>>temp;
            if(temp%2==0)
            {
               total++;a[total]=temp;
            }
         }
      }
      for(j=1;j<=total;j++)
         for(i=1;i<=total;i++)
         if(a[i]>a[i+1])
         {
            temp=a[i];a[i]=a[i+1];
            a[i+1]=temp;
         }
      for(i=1;i<total;i++)cout<<a[i]<<" ";
      cout<<a[total]<<endl;
   }
}
