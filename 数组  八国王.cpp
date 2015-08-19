#include <iostream>
using namespace std;
int main()
{
   int n,b,c,ans;
   while(cin>>n)
   {
      b=0;
      ans=0;
      c=0;
      int a[n][n];
      for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
         cin>>a[i][j];
      for(int i=0;i<n;i++)
         {
            b=0;
            for(int j=0;j<n;j++)
            if(a[i][j]==1) {b++;c++;}
            if(b>1)ans++;
         }
      for(int i=0;i<n;i++)
         {
            b=0;
            for(int j=0;j<n;j++)
            if(a[j][i]==1) {b++;c++;}
            if(b>1)ans++;
         }
      if((ans==0)&&(c/2==n)) 
         cout<<"YES";
      else cout<<"NO";
      cout<<endl;
   }
}
