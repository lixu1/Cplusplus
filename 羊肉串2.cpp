#include <iostream>
using namespace std;
int main()
{
   int n;
   bool flag;
   char a,b,c,t;
   while(cin>>n)
   {
      flag=false;
      cin>>a>>b>>c;
      if(((int)a+1==(int)b)&&((int)b+1==(int)c))
         flag=true;
      for(int i=4;i<=n;i++)
      {
         cin>>t;
         a=b;
         b=c;
         c=t;
         if(((int)a+1==(int)b)&&((int)b+1==(int)c))
            flag=true;
      }
      if(flag)cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
   }
}
