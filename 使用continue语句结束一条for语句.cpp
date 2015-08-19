#include <iostream>
using namespace std;
int main()
{
   for(int counter=1;counter<=10;counter++)
   {
      if(counter==6)
      continue;
      cout<<counter<<" ";
   }
   cout<<"\nUsed continue to skip printing 6 "<<endl;

}
