#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int x;
		cin>>x;
		int a[5000];
		int b[5000];
		for(int i=0;i<5000;i++)
		{
			a[i]=0;
			b[i]=0;
		}
		int p=0;
		for(int i=2;i<=x;i++)
		{
			int k=i; int j=2;
			while(j<=k)
			{
				if(k%j==0)
				{
					bool flag=false;
					for(int w=0;w<p;w++)
					{
						if(a[w]==j)  {flag=true;b[w]++;k=k/j;j=j-1;}
					}
					if(!flag)  {a[p]=j;b[p]++;p++;k=k/j;j=j-1;}
				}
				if(k==1) break;
				j++;
			}
		}
		if(b[0]==1)
			cout<<a[0];
			else
			cout<<a[0]<<"^"<<b[0];
		for(int i=1;i<p;i++)
		{
			if(b[i]==1)
			cout<<"*"<<a[i];
			else
			cout<<"*"<<a[i]<<"^"<<b[i];
		}
		cout<<endl;
	}
	system("pause");
}
