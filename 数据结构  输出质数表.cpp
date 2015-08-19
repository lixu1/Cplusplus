#include <iostream>
using namespace std;
int main()
{
	int a[1000];
	for(int k=0;k<1000;k++)
	a[k]=0; 
	int b=0;
	for(int i=2; i<=1000; i++)
	{
		bool flag=false;
		for(int j=2;j<=i/2;j++)
		{
			if(i%j==0) {flag=true;break;}
		}
		if( !flag) 
		{ a[ b ] = i; b++; }
	}
	int n;
	cin>>n;
	while(n--)
	{
		int x;
		cin>>x;
		if(x==2) cout<<2<<endl;
		else
		{
		int p=0;
		for( p;p<b-2;p++)
		{
			if(a[p+2]>x) break;
			cout<<a[p]<<" ";
		}
		cout<<a[p]<<" "<<a[p+1]<<endl;
		}
	}
	return 0;
}
