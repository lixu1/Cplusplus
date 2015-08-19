#include <iostream>
using namespace std;
int main()
{
   int n,a,ans;
   cin>>n;
   ans=0;
   while(n--)
   {
      cin>>a;
      if(ans<=a) ans=a;
   }cout<<"Answer = "<<ans<<endl;
}
