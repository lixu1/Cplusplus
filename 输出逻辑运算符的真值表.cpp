#include <iostream>
using namespace std;
int  main()
{
   cout<< boolalpha <<"Logical AND (&&)"
       <<"\nfalse && false: "<< ( false && false )
       <<"\nfalse && true: " << ( false && true )
       <<"\ntrue && false: " << (true && false )
       <<"\nture && true: " << (true && true )<<"\n\n";

   cout<<"Logical OR (||)"
       << "\nfalse || false: "<<( false || false )
       << "\nfalse || true: "<<( false || true )
       << "\nture || false: "<<( true || false )
       << "\ntrue || true: "<<( true || true ) <<"\n\n";

   cout<<"Logical NOT (!)"
       <<"\n!false: " << ( !false )
       <<"\n!true: " << ( !true ) <<endl;

}
