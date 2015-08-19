#include <iostream>
using namespace std;
int main()
{
   int n;
   while( cin >> n)
   {
      while(n>0)
      {
         while(n>0)
         {
            cout<<"*";
            n=n-1;
            if(n==0)cout<<endl;
            break;
         }
      while(n>0)
      {
         cout<<"*";
         n=n-1;
         cout<<endl;
         break;
      }
      while(n>0)
      {
         cout<<"#";
         n=n-1;
         if(n==0)cout<<endl;
         break;
      }
      while(n>0)
      {
         cout<<"#";
         n=n-1;
         cout<<endl;
         break;
      }
      }
      cout << endl;
   }
}
