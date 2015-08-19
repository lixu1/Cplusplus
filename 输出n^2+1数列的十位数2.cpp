#include <iostream>
using namespace std;
int ans (int x)
{
   if(x==1)
      return 1;
   int a=ans(x-1);
   return (a*a+1)%100;
}
int main()
{
   int n;
   while(cin>>n)
   {
      cout<<ans(n)/10<<endl;
   }
}
