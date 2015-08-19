#include <iostream>
using namespace std;
int  main()
{
   int a,n;
   double b;
   char c;
   while ( cin >>n)
   {
      switch( n )
      {
         case 0:
            cin>>a;
            cout <<(char)a<<endl;
            break;
         case 1:
            cin>>a;
            cout<<(double)a<<endl;
            break;
         case 2:
            cin>>c;
            cout<<(int)c<<endl;
            break;
         case 3:
            cin>>b;
            cout<<(int)b<<endl;
            break;
      }

   }
}
