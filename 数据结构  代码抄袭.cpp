#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n1,n2;
		double ans=0,num=0;
		cin>>n1;
		char a[n1];cin>>a;
		cin>>n2;
		char b[n2];cin>>b;
		if(n1==n2)
		{
			for(int i=0;i<n1;i++)
			if(a[i]==b[i]) num++;
			ans=num/n1;
			if(ans>=0.7) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		else
		cout<<"No"<<endl;
	}
}
