#include <iostream>
using namespace std;
int main()
{
   int k,i;
   bool flag;
   flag=false;
   while(cin>>k)
   {
      if(flag)cout<<endl;
      flag=true;
      for(i=1;i<=k;i++)
      {
         switch(i%4)
         {
            case 1:
            case 2:
               cout<<"*";
               break;
            case 3:
            case 0:
               cout<<"#";
               break;
            default:break;
         }
         if(i%2==0)cout<<endl;
      }
      if(i%2==0)cout<<endl;
   }
}
