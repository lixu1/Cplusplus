#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int m;
    while(cin >> m)
    {
       cout<<"please input a number:\n";
       double sqrtm=sqrt(m*1.0);
       for(int i=2;i<=sqrtm;++i)
       if(m%i==0)
       {
          cout<<m<<"��������\n";
          return 1;
       }
        cout<<m<<"������\n";

    }
   return 0;
}
