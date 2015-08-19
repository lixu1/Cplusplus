#include <iostream>
using namespace std;
int main()
{
   int n,t;
   cin>>n;
   while(n>0)
   {
      cin>>t;
      for(int i=1;i<=t;i++)
      cout<<"*";
      n=n-1;
      cout<<endl;
   }
}
