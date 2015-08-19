#include <iostream>
using namespace std;
int main()
{
   int n,a,b,k;
   int f,g,i,h;
   cin >> n;

   while (n--)
   {
      f=0;
      g=0;
      cin>>k;
      cin>>a>>b;
      for(i=1;i<=k;i=i+1)
      {
         cin>>h;
         if(a>=h) f=f+1;
         else if((a+b)>=h)  
         {  
            g=g+1;
            f=f+1;
         }
      }cout<<f<<" "<<g<<endl;
   }cout<<endl;

}
