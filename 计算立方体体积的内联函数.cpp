#include <iostream>
using namespace std;

inline double cube (const double side )
{
   return side * side * side;
}
int main()
{
   double side;
   cout<<"Enter the side lengh of your cube: ";
   cin>>side;
   cout<<"Volume of cube with side "
   <<side <<" is "<< cube(side)<<endl;


}
