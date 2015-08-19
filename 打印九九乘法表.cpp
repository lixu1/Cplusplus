#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
   int i;
   for(i=1;i<=9;i++)
   cout<<setw(4)<<i;
   cout<<endl;
   for(i=1;i<=9;i++)
   cout<<"----";
   cout<<endl;
   for(i=1;i<=9;i++)
   {
      cout<<i;
      //cout<<setw((i-1)*4)<<' ';
      for(int j=1;j<=9;j++)
      {
         cout<<setw(4)<<i*j;
      }
      cout<<endl;
   }
   cin.get();
}
