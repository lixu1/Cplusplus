#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
   double a;
   cout << "Enter a number";
   cin >> a;
   cout << "��С��������С������ " << ceil( a ) << endl;
   cout << "���������� " << cos( a ) << endl;
   cout << "����e�η��� "<< exp( a ) << endl;
   cout << "���ľ���ֵ�� " << fabs( a ) <<endl;
   cout << "������������������� "<< floor( a ) << endl;
   cout << "������Ȼ������ " << log( a ) << endl;
   cout << "������10Ϊ�׵Ķ����� " << log10( a ) << endl;
   cout << "���������� "<< sin( a ) << endl;
   cout << "����ƽ������ "<< sqrt( a ) << endl;
   cout << "���������� "<< tan( a )<<endl;
}
