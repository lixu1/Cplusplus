#include <iostream>
using namespace std;
int main()
{
   int map[50][50];
   int n;
   int i,j,x;
   int number;
   bool flag=false;
   while(cin>>n)
   {
      if(flag)cout<<endl;
      flag=true;
      number=0;
      for(x=1;x<=n;x++)
      {
         i=x;j=x;
         while(j<=n) {number++;map[i][j]=number;j++;}
         i=x+1;j=x;
         while(i<=n) {number++;map[i][j]=number;i++;}
      }
      for(i=1;i<=n;i++)
      {
         for(j=1;j<n;j++) cout<<map[i][j]<<" ";
         cout<<map[i][n]<<endl;
      }
   }return 0;
}
