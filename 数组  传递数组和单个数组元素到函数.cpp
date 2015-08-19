#include <iostream>
#include <iomanip>
using namespace std;

void modifyArray( int [],int );
void modifyElement( int );

int main()
{
   const int arraySize=5;
   int a[arraySize ]={0,1,2,3,4};

   cout<<"Effect of passing entire array by reference:"
   <<"\n\nThe value of the original array are:\n";
   for(int i=0;i<arraySize ;i++)
      cout<<setw(3)<<a[i];
   cout<<endl;
   modifyArray(a,arraySize);
   cout<<"The values of the modified array are:\n";
   for(int j=0;j<arraySize ;j++)
      cout<<setw(3)<<a[j];
   cout<<"\n\nEffects of passing array element by value:"
   <<"\n\na[3]before modifyElement: "<<a[3]<<endl;
   modifyElement (a[3]);
   cout<<"a[3]after modifyElement: "<<a[3]<<endl;
}
void modifyArray(int b[],int sizeOfArray)
{
   for(int k=0; k < sizeOfArray;k++)
   b[k]*=2;
}
void modifyElement(int e)
{
   cout << "Value of element in modifyElement: "<<( e*=2) << endl;

}









