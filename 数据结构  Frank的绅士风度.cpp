#include <iostream>
#include "stdio.h"
#include "malloc.h"

using namespace std;

typedef struct qnode
{
   long data;
   struct qnode *next;
}QNode;

typedef struct
{
   QNode *front;
   QNode *rear;
}LiQueue;

void InitQueue(LiQueue *&q)
{
   q=(LiQueue *)malloc(sizeof (LiQueue));
   q->front=q->rear=NULL;
}

void ClearQueue(LiQueue *&q)
{
   QNode *p=q->front,*r;
   if(p!=NULL)
   {
      r=p;
      p=p->next;
      free(r);
   }
   free(q);
}

int QueueEmpty(LiQueue *q)
{
   if(q->front==NULL)
   return 1;
   else return 0;
}

void enQueue(LiQueue *&q,long e)
{
   QNode *s;
   s=(QNode *)malloc(sizeof(QNode));
   s->data=e;
   s->next=NULL;
   if(q->rear==NULL)
   {
      q->front=q->rear=s;
   }
   else
   {
      q->rear->next=s;
      q->rear=s;
   }
}

int deQueue(LiQueue *&q,long  &e)
{
   if(q->rear==NULL)
   return 0;
   QNode *t;
   t=q->front;
   if(t==q->rear)
   {
      q->front=q->rear=NULL;
   }
   else q->front=q->front->next;
   e=t->data;
   free(t);
   return 1;
}

void DisplayQueue(LiQueue *q)
{
   QNode *t=q->front;
   while(t->next!=NULL)
   {
      cout<<t->data<<" ";
      t=t->next;
   }
   cout<<t->data<<endl;

}

int main()
{
   long n;
   cin>>n;
   while(n--)
   {
      long m;
						long no;
      LiQueue *q;
      InitQueue(q);
      cin>>m>>no;
      for(long i=0;i<m;i++)
      {
         long a;
         cin>>a;
         enQueue(q,a);
      }
      long b;
      cin>>b;
      while(b--)
      {
         long c;
         cin>>c;
         if(c%2!=0)
         {
            long e;
            deQueue(q,e);
            enQueue(q,c);
         }
         else
         {
            if(q->front->data!=no)
            {
               QNode *p=q->front,*r;
               if(p->next->data==no)
               {p->data=c;}
               else
               {
               	while(p->next->data!=no)
               	{p=p->next;}
               	long e;
               	deQueue(q,e);
               	r=(QNode *)malloc(sizeof(QNode));
               	r->data=c;
               	r->next=p->next;
               	p->next=r;
															}
            }
         }
         
      }
      DisplayQueue(q);
      ClearQueue(q);
   }
   return 0;
}
