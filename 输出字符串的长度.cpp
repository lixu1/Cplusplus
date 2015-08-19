#include <iostream>
using namespace std;
int Strlen(char *s)
{
   char *p=s;
   while (*p) p++;
   return (p-s);
}
int main()
{
   char ch[100];
   cout<<"Please input a string: ";
   while(cin>>ch)
   {cout<<"The result is "<<Strlen(ch)<<"."<<endl;}
}
