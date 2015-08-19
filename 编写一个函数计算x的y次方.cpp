#include <iostream>
using namespace std;
int intergerPower(int);
int main()
{
   int a,b;

   cout<<"Enter two interger ";
   cin>>a>>b;
   cout <<"Ans is: "<< intergerPower(a,b) <<endl;
}
int intergerPower(int a,int b)
{
    int c=1;
   for(int i=1;i<=b;i++)
      c=c*b;
   cout<<c;
}
