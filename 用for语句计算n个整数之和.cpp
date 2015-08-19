#include <iostream>
using namespace std;
int main()
{
   int n,a,ans;
   cin>>n;
   ans=0;
   for(int i=1;i<=n;i++)
   {cin>>a;
   ans+=a;
   }
   cout<<"Answer = "<<ans<<endl;
   return 0;
}
