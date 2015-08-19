#include <iostream>
using namespace std;
int boxVolume(int length = 1,int width = 1,int heigh = 1);

int main()
{
   cout<<"The default box volume is: "<<boxVolume();
   cout<<"\n\nThe volume of a box with length 10\n"<<"width 1 and heigh 1 is:"<<boxVolume(10);
   cout<<"\n\nThe volume of a box with length 10\n"<<"width 5 and heigh 1 is:"<<boxVolume(10,5);
   cout<<"\n\nThe volume of a box with length 10\n"<<"width 5 and heigh 2 is:"<<boxVolume(10,5,2)<<endl;

}
int boxVolume(int length,int width,int height)
{
   return length*width*height;
}
