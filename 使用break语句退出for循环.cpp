#include <iostream>
using namespace std;
int main()
{
   int counter;
   for(counter=1;counter<=10;counter++)
   {
      if(counter==4) break;
      cout<<counter<<" ";
   }
   cout<<"\nBroke out of loop at count = "<< counter <<endl;

}
