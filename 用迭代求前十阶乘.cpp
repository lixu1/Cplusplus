#include <iostream>
#include <iomanip>

using namespace std;
unsigned long factorial( unsigned long );
int main()
{
   for ( int counter = 0; counter <= 10; counter++)
      cout << setw( 2 ) << counter << "!= "<< factorial( counter )<<endl;
}
unsigned long factorial( unsigned long number )
{
   unsigned long result = 1;
   for( unsigned long i = number;i>=1; i--)
      result *=i;
      return result;
}
