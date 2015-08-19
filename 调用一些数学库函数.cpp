#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
   double a;
   cout << "Enter a number";
   cin >> a;
   cout << "不小于它的最小整数是 " << ceil( a ) << endl;
   cout << "它的余弦是 " << cos( a ) << endl;
   cout << "它的e次方是 "<< exp( a ) << endl;
   cout << "它的绝对值是 " << fabs( a ) <<endl;
   cout << "不大于它的最大整数是 "<< floor( a ) << endl;
   cout << "它的自然对数是 " << log( a ) << endl;
   cout << "它的以10为底的对数是 " << log10( a ) << endl;
   cout << "它的正弦是 "<< sin( a ) << endl;
   cout << "它的平方根是 "<< sqrt( a ) << endl;
   cout << "它的正切是 "<< tan( a )<<endl;
}
