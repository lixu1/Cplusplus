#include <iostream>
using namespace std;
int square(int);
int main()
{
   int a;
   cin>>a;
   cout<< a <<" square: "<< square(a)<<endl;
}
int square( int x )
{
   return x*x;
}
