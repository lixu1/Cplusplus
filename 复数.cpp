#include <iostream>
using namespace std;
struct complex
{
	double e1;
	double e2;
};
int AssignComplex(complex &z,double v1,double v2)
{
	z.e1=v1;
	z.e2=v2;
}
void DestroyComplex(complex &z)
{
	z.e1=0;
	z.e2=0;
}
int GetReal(complex &z,double &real)
{
	real=z.e1;

}
int GetImag(complex &z,double &Imag)
{
	Imag=z.e2;

}
int Add(complex z1,complex z2,complex &sum)
{
	double a,b;
	a=z1.e1+z2.e1;
	b=z1.e2+z2.e2;
 
		 sum.e1=a;
   sum.e2=b;
}
int main()
{
	double a,b,c,d;
	complex z,z1,z2,sum;
	cout<<"���븴��Z��ʵ�����鲿"<<endl;
	cin>>a>>b;
	AssignComplex(z,a,b);
	GetReal(z,c);
	cout<<"Z��ʵ����"<<c<<endl;
	GetImag(z,d);
	cout<<"Z���鲿��"<<d<<endl;
	double e,f,g,h;
	cout<<"���븴��Z1 Z2��ʵ�����鲿"<<endl;
	cin>>e>>f>>g>>h;
	AssignComplex(z1,e,f);
	AssignComplex(z2,g,h);
	Add(z1,z2,sum);
	cout<<"����Z1 Z2�ĺ��� "<<sum.e1<<"+"<<sum.e2<<"i"<<endl;

}
