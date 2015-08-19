#include <iostream>
using namespace std;
int main()
{
    int a,b,c,d,e,f;
    cout<<"enter a five degree integer";
    cin>>a;

    b=(a/10000);
    c=(a%10000/1000);
    d=(a%10000%1000/100);
    e=(a%10000%1000%100/10);
    f=(a%10000%1000%100%10);
    cout<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<endl;
    return 0;

}
