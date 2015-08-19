#include <iostream>
using namespace std;
int main()
{
   int n;
   int ans;
   while(cin>>n)
   {
      ans=1;
      for(int i=2;i<=n;i++)
      ans=(ans*ans+1)%100;
      cout<<ans/10<<endl;
   }
   return 0;
}
