#include <iostream>
using namespace std;

int main()
{
   int n,a[101],max,maxt,i,j;
   while(cin>>n)
   {
      for(i=1;i<=n;i++)cin>>a[i];
      for(j=1;j<=3;j++)
      {
         if(j!=1)cout<<" ";
         max=-1;
         for(i=1;i<=n;i++)
            if(a[i]>max)
            {
               max=a[i];
               maxt=i;
            }
         cout<<maxt;
         a[maxt]=-1;

      }
      cout<<endl;
   }
}
