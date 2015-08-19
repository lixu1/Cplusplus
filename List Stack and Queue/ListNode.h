#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
using namespace std;

template <typename NODETYPE> class List;

template <typename NODETYPE>
class ListNode
{
   friend class List<NODETYPE>;
   public:
      ListNode(const NODETYPE &);
      //virtual ~ListNode();
      NODETYPE getData()const;
   protected:
   private:
      NODETYPE data;
      ListNode<NODETYPE> *nextPtr;
};
template <typename NODETYPE>
ListNode<NODETYPE>::ListNode(const NODETYPE &info)
:data(info),nextPtr(0)
{
   //ctor
}
/*template <typename NODETYPE>
ListNode<NODETYPE>::~ListNode()
{
   //dtor
}*/

template <typename NODETYPE>
NODETYPE ListNode<NODETYPE>::getData()const
{
   return data;
}

#endif // LISTNODE_H
