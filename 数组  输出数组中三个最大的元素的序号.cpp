#include <iostream>
using namespace std;
int main()
{
   int n,b,c,d;
   int a[110];
   while(cin>>n)
   {
      int s=0;
      b=0;c=0;d=0;
      for(int i=0;i<n;i++)
         cin>>a[i];
      for(int i=0;i<n;i++)
      {
         
         if(a[i]>s){s=a[i];b=i;}
      }
      a[b]=0;
      s=0;
      for(int i=0;i<n;i++)
      {
         
         if(a[i]>s){s=a[i];c=i;}
      }
      a[c]=0;
      s=0;
      for(int i=0;i<n;i++)
      {
         
         if(a[i]>s){s=a[i];d=i;}
      }
      cout << (b+1) << " " << (c+1) << " " << (d+1) << endl;
   }
}
