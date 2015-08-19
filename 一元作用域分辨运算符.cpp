#include <iostream>
using namespace std;

int number = 7;
int main()
{
   int number = 10;
   cout << "Local double value of number = "<<number<<"\nGlobal int value of number = "<<::number<<endl;
}
