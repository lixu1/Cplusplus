#include<iostream>
using namespace std;
int main()
{
   int n;
   int a[100][100];
   while( cin >> n )
   {
      if(n==1) a[0][0]=1;
      else
      {
         for(int i=0;i<n-1;i++)
         {
            for(int j=i;j<n;j++)
               a[i][j]=n*n-(n-i)*(n-i)+j+1-i;
            for(int j=i+1;j<n;j++)
               a[j][i]=n*n-(n-i)*(n-i)+j+n-i-i;
            a[n-1][n-1]=n*n;
         }
      }
      if(n==1) cout<<1<<endl;
      else
      {
         for(int i=0;i<n;i++)
         {
            for(int j=0;j<n-1;j++)
            cout<<a[i][j]<<" ";
            cout<<a[i][n-1]<<endl;
         }
      }
      cout<<endl;
   }
   return 0;
}
