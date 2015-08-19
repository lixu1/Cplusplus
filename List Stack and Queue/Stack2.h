#ifndef STACK2_H
#define STACK2_H
#include "List.h"

template <typename STACKTYPE>
class Stack2
{
   public:
      //Stack2();
      //virtual ~Stack2();
      void push(const STACKTYPE &data)
      {
         stackList.insertAtFront(data);
      }
      bool pop(STACKTYPE &data)
      {
         return (stackList.removeFromFront(data));
      }
      bool isStackEmpty()const
      {
         return stackList.isEmpty();
      }
      void printStack()const
      {
         stackList.print();
      }
   protected:
   private:
      List<STACKTYPE>stackList;
};

#endif // STACK2_H
