#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
   double n,a,b,c,d;
   cin>>n;
   cout << left << "Car" << right<<setw( 18 ) << "Hours" << setw( 20 ) << "Charge" <<endl;

   for(int i=1;i<=n;i++)
   {
      cin >> a;
      if((0<a)&&(a<=3))
         b = 2;
      else if ((a>3)&&(a<17))
         b = ceil( a-3 )*0.5+2;
      else if((a>=17)||(a<=24))
         b = 10;
      c = c+a;
      d = d+b;
      cout << left << i << right << setw( 20 ) << a << fixed << setprecision( 2 ) << setw( 20 ) << b << endl;
   }
    cout << left << "TOTAL" << right << setw( 16 ) << c << fixed << setprecision( 2 )<< setw( 20 )<< d << endl;
}
