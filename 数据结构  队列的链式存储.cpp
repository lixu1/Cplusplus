#include <iostream> 
#include "malloc.h"
#include "stdio.h"

using namespace std;
typedef struct qnode
{
	int data;
	struct qnode *next;
}Qnode;

typedef struct 
{
	Qnode *front;
	Qnode *rear;
}LiQueue;

void InitQueue(LiQueue *&q)
{
	q=(LiQueue * )malloc(sizeof(LiQueue));
	q->front=q->rear=NULL;
}

void ClearQueue(LiQueue *&q)
{
	Qnode *p =q->front,*r;
	if(p!=NULL)
	{
		r=p->next;
		while(r!=NULL)
		{
			free(p);
			p=r;
			r=p->next;
		}
		free(p);
	}
	free(q); 
}

int QueueEmpty(LiQueue *q)
{
	if(q->rear==NULL)
	return 1;
	else return 0;
}

void enQueue(LiQueue *&q,int e)
{
	Qnode *s;
	s=(Qnode *)malloc(sizeof(Qnode));
	s->data=e;
	s->next=NULL;
	if(q->rear==NULL)
	q->front=q->rear=s;
	else
	{
		q->rear->next=s;
		q->rear=s;
	}
}
int deQueue(LiQueue *&q,int &e)
{
	Qnode *t;
	if(q->rear==NULL) return 0;
	t=q->front;
	if(q->front==q->rear)
	q->front=q->rear=NULL;
	else
	q->front=q->front->next;
	e=t->data;
	free(t);
	return 1;
} 
int main()
{
	LiQueue *q;
	InitQueue(q);
	for(int i=1;i<=10;i++)
	enQueue(q,i);
	cout<<QueueEmpty(q)<<endl;
	for(int i=1;i<=10;i++)
	{
		int a;
		deQueue(q,a);
		cout<<a<<endl;
	}
	ClearQueue(q);
	system("pause");
}
