#include <iostream>
using namespace std;
int main()
{
	int n,t;
	cin>>n;
	while(n--)
	{
		cin>>t;
		if(t<0||t>100)
		   cout<<"score is error";
		else if(t>=90)
           cout<<"A"<<endl;
        else if(t>=80)
           cout<<"B"<<endl;
        else if(t>=70)
           cout<<"C"<<endl;
        else if(t>=60)
           cout<<"D"<<endl;
        else 
           cout<<"E"<<endl;
	}
	return 0;
}
