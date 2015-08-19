#include <iostream>
using namespace std;
int main()
{
   const int arraySize = 10;
   int total=0;
   int a[arraySize]={87,68,94,100,83,78,85,91,76,87};
   for(int i=0;i<arraySize;i++)
      total+=a[i];
   cout<<"Total of array elements: "<<total<<endl;
}
