#include <iostream>
using namespace std;
class A{public:   void fun(){cout<<'A'<<endl;};};
class B1:public A{public:    void fun1(){cout<<"B1"<<endl;};
class B2:public A{public:   void fun1();};
class C1:public B1{};
class C2:public B2{};
class D: public C1, public C2{};
int main()
{
    D obj;   
    //obj.fun1();
    obj.B1::fun1();
    obj.B2::fun1();
    //obj.fun();
    //obj.A::fun(); 
    obj.B1::fun();
}
