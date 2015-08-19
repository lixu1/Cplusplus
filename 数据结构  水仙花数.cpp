#include <iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
	int a=n/100;
	int b=(n-a*100)/10;
	int c=n-a*100-b*10;
	if((a*a*a+b*b*b+c*c*c)==n)
	cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
} 
