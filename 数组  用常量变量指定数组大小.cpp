#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
   const int arraySize=10;
   int s[arraySize];
   for(int i=0;i<arraySize;i++);
      s[i]=2+2*i;
   cout<<"Element"<<setw(13)<<"Value"<<endl;
   for(int j=0;j<arraySize;j++)
      cout<<setw(7)<<j<<setw(13)<<s[j]<<endl;
}
