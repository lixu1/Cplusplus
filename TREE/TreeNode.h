#ifndef TREENODE_H
#define TREENODE_H
template<typename NODETYPE> class Tree;

template<typename NODETYPE>

class TreeNode
{
   friend class Tree<NODETYPE>;
   public:
      TreeNode(const NODETYPE &d)
      :leftPtr(0),rightPtr(0),data(d)
      {

      }
      NODETYPE getData()const
      {
         return data;
      }
      //virtual ~TreeNode();
   protected:
   private:
   TreeNode<NODETYPE>*leftPtr;
   NODETYPE data;
   TreeNode<NODETYPE>*rightPtr;
};

#endif // TREENODE_H
