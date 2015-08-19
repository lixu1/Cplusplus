#include <iostream>
using namespace std;
int main()
{
   int counter=1;
   while (counter<=10)
    {
       cout<<"yes ";
       if(counter==6)
       continue;
       cout<<counter<<" ";
     counter++;
    }
   cout<<"\nUsed continue to skip printing 6 "<<endl;

}
