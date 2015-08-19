#include<iostream>
#include<string>
using namespace std;
int Fun(char *);

int main()
{
   int  c;
			char b[]={};
   while(cin >> b)
   {
      c = Fun(b);
      cout<<c<<endl;
			}
   return 0; 
}
int Fun(char *a)
{
   int num=0;
   int n=strlen(a);
   char *b=a;
   for(int i=0;i<n;i++)
   {
      if(*b>='A' && *b<='Z')
						{
						num++;}
						b++;
   }
   return num;
}
