#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
   long int n,t,s;
   cin>>n;
   cout<<"n!  "<<setw(20)<<"Answer"<<endl;
   while (n>0)
   {
      cout<<n<<"!";
      s=1;
      for(int i=n;i>0;i--)
      {
         s=s*i;

      }
      cout<<setw(20)<<s<<endl;
      n=n-1;
   }

}
