#include <iostream>
using namespace std;
int main()
{
   int a;
   int *aPtr;
   a=7;
   aPtr=&a;
   cout<<"The address of a is "<<&a<<"\nThe value of aPtr is "<<aPtr;
   cout<<"\n\nThe value of a is "<<a<<"\n The value of *aPtr is "<<*aPtr;
   cout<<"\n\nShowing that * and & are inverses of "
      <<"each other.\n&*aPtr = "<<&*aPtr<<"\n*&aPtr = "<<*&aPtr<<endl;
}
