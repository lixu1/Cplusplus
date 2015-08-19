#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
   const int n=10;
   int a[ n ];
   for( int i = 0;i < n;i++ )
      cin >> a[i];
   int c;
   for( int i = 0;i < n-1;i++ )
   {
      for(int i = 0;i < n-1;i++)
      {
         int next = i;
         while((next<n-1)&&(a[next]>a[next+1]))
         {
            c = a[next+1];
            a[next+1] = a[next];
            a[next] = c;
            next++;
         }
      }
   }
   for( int i = 0;i < n;i++)
   cout << setw(5) << a[ i ];
   cout << endl;
}
