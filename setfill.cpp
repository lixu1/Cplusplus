#include <iostream>
#include <iomanip>
using namespace std;
int main()
{

    char chr='p',str='k';
    cout<<chr<<"\n";
    cout<<setw(5)<<chr<<'\n';//����������Ϊ5
    cout<<setw(5)<<setfill('T')<<chr<<'\n';//����������Ϊ5������ַ�'T'
    //----------------------------------------
}


