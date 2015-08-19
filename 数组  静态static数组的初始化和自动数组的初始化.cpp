#include <iostream>
using namespace std;

void staticArrayInit(void);
void automaticArrayInit(void);
const int arraySize=3;
int main()
{
   cout<<"First call to each function:\n";
   staticArrayInit();
   automticArrayInit();
   cout<<"\n\nSecond call to each function:\n";
   staticArrayInit();
   automticArrayInit();
   cout<<endl;
}
void staticArrayInit(void)
{
  static int array1[arraySize];
  cout<<"\nValue on entering staticArrayInit:\n";

}




