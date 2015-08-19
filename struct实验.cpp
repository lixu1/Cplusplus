#include <iostream>
using namespace std;
struct student
{
	int no;
	char sex;
};
int main()
{
	student xue[3];
	for(int i=1;i<=3;i++)
	{
		xue[i].no=i;
		xue[i].sex='f';
 }
	for(int i=1;i<=3;i++)
	cout<<xue[i].no<<xue[i].sex<<endl;
	cin.get();
}
