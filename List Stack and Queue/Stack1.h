#ifndef STACK1_H
#define STACK1_H
#include "List.h"

template<typename STACKTYPE>
class Stack1:private List<STACKTYPE>
{
   public:
      //Stack1();
      //virtual ~Stack1();
      void push(const STACKTYPE &data)
      {
         insertAtFront(data);
      }
      bool pop(STACKTYPE &data)
      {
         return(removeFromFront(data));
      }
      bool isStackEmpty()const
      {
         return this->isEmpty();
      }
      void printStack()const
      {
         this->print();
      }
   protected:
   private:
};

#endif // STACK1_H
