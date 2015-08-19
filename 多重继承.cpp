#include <iostream>
using namespace std;

class A{    int i;
public:
    A(int ii=0){    i=ii;
        cout<<"A... i="<<i<<endl;
    }
    void show()
    {cout<<"A::show() i="<<i<<endl;}
};
class B{    int i;
public:
    B(int ii=0){   i=ii;
        cout<<"B... i="<<i<<endl;
    }
    void show()
    {cout<<"B::show() i="<<i<<endl;}
};
class C:public A, public B{
    int i;
public:
    C(int i1=0, int i2=0, int i3=0)      :A(i1), B(i2){
        i=i3;
        cout<<"C... i="<<i<<endl;
     }
    void show()
    {cout<<"C::show()  i="<<i<<endl;}
};
int main(){
    C c(1,2,3);
    //C &c1;
    c.A::show();
    c.show();
    system("pause");
}
