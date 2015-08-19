#define PI 3.1415926
#define AREA(r) ((r)*(r)*PI)
#include <iostream>
using namespace std;
int main()
{
	int c=1;
	cout<<AREA(c)<<endl;
	cout<<AREA(++c)<<endl;
	cout<<c<<endl;
 cout<<(++c)*(++c)<<endl;
 cout<<c<<endl;
 cout<<(c++)*(c++)<<endl;
	system("pause"); 

}
