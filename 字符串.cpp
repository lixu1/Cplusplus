#include <iostream>
#include <cstring>
using namespace std;
char a[10000];
int main()
{
   int n;
   while(cin>>a>>n)
   {

      while(n--)
      {
         int x=strlen(a);
         char b;cin>>b;
         if(b=='#')
         {
            int c,d;
            char e[100];
            cin>>c>>d>>e;
            int p=strlen(e);
            if(c-1+d>x) cout<<"Sorry,request denied."<<endl;
            else
            {
               int f=x-c+1-d;
               for(int i=f;i>0;i--) a[c-2+p+i]=a[c+d+i-2];
               for(int i=0;i<p;i++) a[c-1+i]=e[i];
               for(int i=0;i<x-d+p;i++) cout<<a[i];
               cout<<endl;
            }
         }
         if(b=='@')
         {
            int g;
            char h[100];
            cin>>g>>h;
            int j=strlen(h);
            if(g>x) cout<<"Sorry,request denied."<<endl;
            else
            {
               int k=x-g;
               for(int i=k;i>0;i--) a[g-2+j+i]=a[g+i-1];
               for(int i=0;i<j;i++) a[g-1+i]=h[i];
               for(int i=0;i<x-1+j;i++) cout<<a[i];
               cout<<endl;
            }
         }
      }
   }
   return 0;
}
