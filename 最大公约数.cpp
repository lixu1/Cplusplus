#include <iostream>
using namespace std;
int main()
{
	  int a,b,c,d;
	  while(cin>>a>>b)
	  {
				  c=a+b;
				  d=0;
						for(int i=0;i<c;i++)
						if(a%i==0&&b%i==0) {d=i;break;}
						if(d!=0) cout<<d<<endl;
						else cout<<"无最大公约数"<<endl;
   }
			return 0;
} 
