#include "stdio.h"
#include "malloc.h"
typedef struct node
{
   int no;//第k件物品
   int w;//有w个比它大的物品放在它上面
   int v;//物品i的体积
   struct node *lchild;
   struct node *rchild;
}BSTNode;

void counter(BSTNode *&p)
{
   if(p!=NULL)
   {
      p->w++;
      counter(p->lchild);
      counter(p->rchild);
   }
}

int InsertBST(BSTNode *&p,int k,int i)
{
   if(p==NULL)
   {
      p=(BSTNode *)malloc(sizeof(BSTNode));
      p->v=k;
      p->no=i;
      p->w=0;
      p->lchild=p->rchild=NULL;
   }
   else if(k<=p->v)return InsertBST(p->lchild,k,i);
   else
   {
      p->w++;
      counter(p->lchild);
      return InsertBST(p->rchild,k,i);
   }
}
BSTNode * CreatBST(int a[],int n)
{
   BSTNode *bt=NULL;
   int i=0;
   while(i<n)
   {
      InsertBST(bt,a[i],i);
      i++;
   }
   return bt;
}
void Travel(BSTNode *&p,int b[])
{
   if(p!=NULL)
   {
      b[p->no]=p->w;
      Travel(p->lchild,b);
      Travel(p->rchild,b);
      free(p);
   }
}
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int n;
      scanf("%d",&n);
      int a[n];
      for(int i=0;i<n;i++)
      scanf("%d",&a[i]);
      BSTNode *b=CreatBST(a,n);
      int c[n];
      Travel(b,c);
      for(int i=0;i<n;i++)
      if(c[i]!=0)printf("%d %d\n",i+1,c[i]);
   }
}
