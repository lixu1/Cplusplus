#include <iostream>
#include "Time2.h"
using namespace std;
int main()
{
   Time2 t;
   cout<<"The initial universal time is ";
   t.printUniversal();
   cout<<"\nThe initial standard time is ";
   t.printStandard();

   t.setTime( 13, 27, 6);
   cout<<"\n\nUniversal time after setTime is ";
   t.printUniversal();
   cout<<"\nStandard time after setTime is ";
   t.printStandard();

   t.setTime( 99, 99, 99);
   cout<<"\n\nAfter attempting invalid setting:"<<"\nUniversal time: ";
   t.printUniversal();
   cout<<"\nStandard time: ";
   t.printStandard();
   cout<<1<< endl;
   system("pause");
}

