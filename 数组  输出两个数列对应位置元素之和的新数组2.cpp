#include <iostream>
using namespace std;
int main()
{
   int n;
   while (cin>>n)
   {
      int a[n];
      int b[n];

      for(int i=0;i<n;i++)
         cin>>a[i];
      for(int i=0;i<n;i++)
         cin>>b[i];

      for(int i=0;i<n;i++)
      {
         cout<<(a[i]+b[i]);
         if(i<n-1)cout<<" ";
      }
   }
}
