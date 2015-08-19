#ifndef QUEUE_H
#define QUEUE_H
#include "List.h"

template<typename QUEUETYPE>

class Queue:private List<QUEUETYPE>
{
   public:
      //Queue();
      //virtual ~Queue();
      void enQueue(const QUEUETYPE &data)
      {
         insertAtBack(data);
      }
      bool deQueue(QUEUETYPE &data)
      {
         return removeFromFront(data);
      }
      bool isQueueEmpty()const
      {
         return this->isEmpty();
      }
      void printQueue()const
      {
         this->print();
      }
   protected:
   private:
};

#endif // QUEUE_H
