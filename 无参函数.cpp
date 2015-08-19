#include <iostream>
using namespace std;

void function1();
void function2( void );

int main()
{
   function1();
   function2();
   function2();
}
void function1()
{
   cout << "function1 takes no arguements"<<endl;

}

void function2( void )
{
   cout<<"function2 also takes no arguements "<<endl;
}


