#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   const int arraySize=10;
   int data[arraySize];
   int a;
   for(int i=0;i<arraySize;i++)
      {
         cin>>a;
         data[i]=a;
      }
       int insert;
       cout<<"Unsorted array:\n";
       for(int i=0;i<arraySize;i++)
       cout<<setw(4)<<data[i];
       for(int next=1;next<arraySize;next++)
       {
      insert=data[next];
      int moveItem=next;
      while((moveItem>0)&&(data[moveItem-1]>insert))
      {
         data[moveItem]=data[moveItem-1];
         moveItem--;
      }
      data[moveItem]=insert;
   }
   cout<<"\nSort array:\n";
   for(int i=0;i<arraySize;i++)
      cout<<setw(4)<<data[i];
   cout<<endl;
}





