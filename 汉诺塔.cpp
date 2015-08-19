#include <iostream>
using namespace std;

void hanoi(int number,char x,char y,char z)
{	if(number==1)
        cout << x << "-->" << z << endl;
	else {
		    hanoi(number-1,x,z,y);
		    cout << x << "-->" << z << endl;
		    hanoi(number-1,y,x,z);
	     }
}
int main()
{
   char a,b,c;
   int num;
   cin>>num>>a>>b>>c;
   hanoi(num,a,b,c);
}
