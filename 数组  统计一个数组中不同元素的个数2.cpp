#include <iostream>
using namespace std;

int main()
{
   int  n;
   int a[110];
   int  ans,temp,i;
   while(cin>>n)
   {
      for(i=1;i<=100;i++)a[i]=0;
      ans=0;
      for(i=1;i<=n;i++)
      {
         cin>>temp;
         if(a[temp]==0)
         {
            a[temp]=1;
            ans++;
         }
      }
      cout<<ans<<endl;
   }
}
