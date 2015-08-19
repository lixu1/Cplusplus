#include <iostream>
using namespace std;
int main()
{
   int n;
   int a[110];
   int b[110];
   int c[110];

   while (cin>>n)
   {
      for(int i=0;i<n;i++)
         cin>>a[i];
      for(int i=0;i<n;i++)
         cin>>b[i];
      for(int i=0;i<n;i++)
         c[i]=a[i]+b[i];
      for(int i=0;i<n-1;i++)
         cout<<c[i]<<" ";
      cout<<c[n-1]<<endl;
   }
}
