#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
   double amount;
   double principal;
   double rate;
   int i_year;

   cout << "Year : ";
   cin >> i_year;
   cout << "Rate : ";
   cin >> rate;
   cout << "Principal : ";
   cin >> principal;

   // display headers
   cout << endl << "Year" << setw( 21 ) << "Amount on deposit" << endl;

   // set floating-point number format
   cout << fixed << setprecision( 2 );

   // calculate amount on deposit for each of ten years
   for ( int year = 1; year <= i_year; year++ )
   {
      // calculate new amount for specified year
      amount = principal * pow( 1.0 + rate, year ); // in fact, the efficiency can improved ...

      // display the year and the amount
      // cout << setw( 4 ) << year << setw( 21 ) << amount << endl;
	  cout << setw( 4 ) << left << year << setw( 21 ) << right << amount << endl;
   } // end for

   system("pause");

   return 0; // indicate successful termination
} // end main

