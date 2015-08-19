#include <iostream>
using std::cout;
using std::endl;
using namespace std;
int main()
{	
	int* p1;
	//int &p;
	const int abc=10;
	//p1=&abc; //A ±àÒë´íÎó
	p1=const_cast<int*> (&abc); //B
	*p1=5;
	cout<<"abc="<<abc
		<<"\n*p1="<<*p1<<endl;
	//return 0;
	
	system("pause");

}
