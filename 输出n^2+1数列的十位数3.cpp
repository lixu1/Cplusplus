#include <iostream>
using namespace std;
int ans[102];
int main()
{
   ans[0]=1;
   int n;
   for(int i=1;i<=102;i++)
   {
      ans[i]=(ans[i-1]*ans[i-1]+1)%100;
   }
   while(cin>>n)
   {
      cout<<ans[n-1]/10<<endl;
   }
}
