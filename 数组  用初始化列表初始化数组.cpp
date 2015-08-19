#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
   int n[10]={32,23,234,345,56,43,64,75,756,6666};
   cout<<"Element"<<setw(13)<<"Value"<<endl;
   for(int i=0;i<10;i++)
      cout<<setw(7)<<i<<setw(13)<<n[i]<<endl;
}
