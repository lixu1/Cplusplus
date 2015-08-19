#include <iostream>
#include <iomanip>
using namespace std;
int main()
{

    char chr='p',str='k';
    cout<<chr<<"\n";
    cout<<setw(5)<<chr<<'\n';//设置输出宽度为5
    cout<<setw(5)<<setfill('T')<<chr<<'\n';//设置输出宽度为5，填充字符'T'
    //----------------------------------------
}


