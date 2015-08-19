#include <iostream>
using namespace std;
int main()
{
   int n;
   cin>>n;
   while(n--)
   {
      int a,b;
      cin>>a>>b;
      long long c=1,d=1,e=1;
      for(int i=1;i<=b;i++)
      c=c*i;
      for(int i=1;i<=a;i++)
      d=d*i;
      for(int i=1;i<=(b-a);i++)
      e=e*i;
      cout<<c/d/e<<endl;
   }
}
