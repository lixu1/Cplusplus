#include <iostream>
using namespace std;
int answer(int x)
{
   if(x==1) return 1;
   int ret=ans(x-1);
   return (ret*ret+1)%100;
}
int main()
{
   int n;
   while(cin>>n)
   {
      cout<<answer(n)/10<<endl;
   }
   return 0;
}
