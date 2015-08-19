#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    int a,b,c,n;
    cin>>n;
    while (n--)
    {
        cin >>a>>b>>c;
        if((b*b-4*a*c)<0)
           cout<<"No Answers"<<endl;
        else if((b*b-4*a*c)==0)
           cout<<fixed<<setprecision(2)<<(double)(-b)/(double)(a+a)<<endl;
        else
           cout<<fixed<<setprecision(2)<<fabs(sqrt(b*b-4*a*c)/(double)a)<<endl;
    }
    return 0;
}

