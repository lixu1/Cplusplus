#include <iostream>
using namespace std;
int main()
{
   int n;
   while(cin>>n)
   {
      char x[n];
      char a;
      int ans=0;
      for(int i=0;i<n;i++)
      {
         cin>>a;
         x[i]=a;
      }
      for(int i=0;i<n-2;i++)
      {
         if (((int)(x[i+1])-(int)(x[i])==1)&&((int)(x[i+2])-(int)(x[i+1])==1))
            ans=ans+1;
      }
      if(ans>0)cout<<"YES";
      else cout<<"NO";
   }
}
