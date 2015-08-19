#include <iostream>
using namespace std;
int main()
{
   int m,n;
   int a[m][n];

   while(cin >> m >> n)
   {

      for( int i = 0;i < m;i++)
         for(int j = 0;j < n;j++)
            cin >> a[ i ][ j ];
      for(int pass=1;pass<m*n;pass++)
      {
         for(int i=0;i<m*n-1;i++)
         {
            if(a[i/n][i%n]>a[(i+1)/n][(i+1)%n])
            {
                  int hold;
                  hold=a[i/n][i%n];
                  a[i/n][i%n]=a[(i+1)/n][(i+1)%n];
                  a[(i+1)/n][(i+1)%n]=hold;
            }
         }
      }
       for( int i = 0;i < m;i++)
         {for(int j = 0;j < n;j++)
           cout<< a[ i ][ j ]<<" ";cout<<endl;}
       cout<<endl;
    }
}
