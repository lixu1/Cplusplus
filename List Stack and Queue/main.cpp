#include <iostream>
#include <string>
#include "List.h"
#include "Stack1.h"
#include "Queue.h"

using namespace std;

void instructions()
{
   cout<<"Enter one of the follwing:\n"
   <<"   1 to insert at beginning of list\n"
   <<"   2 to insert at end of list\n"
   <<"   3 to delete from beginning of list\n"
   <<"   4 to delete from end of list\n"
   <<"   5 to end list processing\n";
}

template<typename T>
void testList( List<T>& listObject,const string &typeName)
{
   cout<<"Testing a List of "<< typeName <<" values\n";
   instructions();
   int choice;
   T value;
   do
   {
      cout<<"?";
      cin>>choice;
      switch(choice)
      {
         case 1:
            cout<<"Enter "<<typeName<<": ";
            cin>>value;
            listObject.insertAtFront(value);
            listObject.print();
            break;
         case 2:
            cout<<"Enter "<<typeName<<": ";
            cin>>value;
            listObject.insertAtBack(value);
            listObject.print();
            break;
         case 3:
            if(listObject.removeFromFront(value))
            cout<<value<<" remove from list\n";
            listObject.print();
            break;
         case 4:
            if(listObject.removeFromBack(value))
            cout<<value<<" remove from list\n";
            listObject.print();
            break;
      }
   }while(choice<5);
   cout<<"End List test\n\n";
}

int main()
{
    List<int> integerList;
    testList(integerList,"integer");
    List<double> doubleList;
    testList(doubleList,"double");

    Stack1 <int>intStack;
    cout<<"processing an integer Stack"<<endl;
    for(int i=0;i<3;i++)
    {
       intStack.push(i);
       intStack.printStack();
    }
    int popInteger;
    while(!intStack.isStackEmpty())
    {
       intStack.pop(popInteger);
       cout<<popInteger<<" poped from stack"<<endl;
       intStack.printStack();
    }
    Stack1<double>doubleStack;
    double value=1.1;
    cout<<"processing a double Stack"<<endl;
    for(int j=0;j<3;j++)
    {
       doubleStack.push(value);
       doubleStack.printStack();
       value+=1.1;
    }
    double popDouble;
    while(!doubleStack.isStackEmpty())
    {
       doubleStack.pop(popDouble);
       cout<<popDouble<<" poped from stack"<<endl;
       doubleStack.printStack();
    }


    Queue<int>intQueue;
    cout<<"processing an integer Queue"<<endl;
    for(int i=0;i<3;i++)
    {
       intQueue.enQueue(i);
       intQueue.printQueue();
    }
    int dequeueInteger;
    while(!intQueue.isQueueEmpty())
    {
       intQueue.deQueue(dequeueInteger);
       cout<<dequeueInteger<<" dequeued"<<endl;
       intQueue.printQueue();
    }
    Queue<double>doubleQueue;
    value=1.1;
    cout<<"processing a double Queue"<<endl;
    for(int j=0;j<3;j++)
    {
       doubleQueue.enQueue(value);
       doubleQueue.printQueue();
       value+=1.1;
    }
    double dequeueDouble;
    while(!doubleQueue.isQueueEmpty())
    {
       doubleQueue.deQueue(dequeueDouble);
       cout<<dequeueDouble<<" dequeued"<<endl;
       doubleQueue.printQueue();
    }
    return 0;
}
