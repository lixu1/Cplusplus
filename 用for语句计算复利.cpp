#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
   double amount;
   double principle = 1000;
   double rate = 0.05;

   cout<<"Year"<<setw(21)<<"Amount on deposit"<<endl;
   cout<<fixed<<setprecision(2);
   for(int year=1;year<=10;year++)
   {
      amount=principle*pow(1.0+rate,year);
      cout<<left<<setw(4)<<year<<right<<setw(21)<<amount<<endl;
   }
}
