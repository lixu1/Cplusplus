#include <iostream>
using namespace std;
int main()
{
   int x= 3;
   int &y=x;

   cout<<"x= "<<x<<endl<<"y= "<<y<<endl;
   y=7;
   cout<<"x= "<<x<<endl<<"y= "<<y<<endl;

}
