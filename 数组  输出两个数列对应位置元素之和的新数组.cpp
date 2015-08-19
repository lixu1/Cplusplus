#include <iostream>
using namespace std;
int main()
{
   int n;
   while (cin>>n)
   {
      int a[n];
      int b[n];
      int c[n];
      for(int i=0;i<n;i++)
         cin>>a[i];
      for(int i=0;i<n;i++)
         cin>>b[i];
      for(int i=0;i<n;i++)
         c[i]=a[i]+b[i];
      for(int i=0;i<n;i++)
      {
         cout<<c[i];
         if(i<n-1)cout<<" ";
      }
      cout<<endl; 
   }
}
