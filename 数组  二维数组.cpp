#include <iostream>
using namespace std;
void printArray(const int [][ 3 ]);
const int rows = 2;
const int columns = 3;

int main()
{
   int array1[ rows ][ columns ] = {{1,2,3},{4,5,6}};
   int array2[ rows ][ columns ] = {1,2,3,4,5};
   int array3[ rows ][ columns ]={{1,2},{4}};

   cout<<"Values in array1 by row are:"<<endl;
   printArray( array1 );

   cout<<"\nvalues in array2 by row are:"<<endl;
   printArray( array2 );

   cout<<"\nValues in array3 by rwo are:"<<endl;

   printArray( array3 );
}
void printArray(const int a[][columns])
{
   for( int i=0;i < rows;i++)
   {
      for(int j = 0;j < columns;j++)
         cout<<a[ i ][ j ] << " ";
      cout << endl;
   }
}


