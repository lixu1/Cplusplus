#include <iostream>
using namespace std;
int main()
{
	int a[1000];
	for(int k=0;k<1000;k++)
	{a[k]=0;} 
	a[0]=2;
	int b=1;
	int j,i;
	for(i=3; i<=1000; i++)
	{
		for(j=2;j<=i;j++)
		{
			if(i%j==0) break;
		}
		if(j==i ) 
		{ a[ b ] = i;cout<<a[b]<<endl; b++; }
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
