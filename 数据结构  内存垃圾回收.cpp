#include "stdio.h"
#include "malloc.h"
#include <iostream>

using namespace std;

typedef struct qnode
{
	int data;
	struct qnode *next;
}QNode;

typedef struct
{
	struct qnode *front;
	struct qnode *rear;
}LiQueue;

void InitQueue(LiQueue *&q)
{
	q=(LiQueue *)malloc(sizeof(LiQueue));
	q->front=q->rear=NULL;
}

void enQueue(LiQueue *&q,int e)
{
	QNode *p;
	p=(QNode *)malloc(sizeof(QNode));
	p->data=e;
	p->next=NULL;
	if(q->front==NULL)
	{
		q->front=q->rear=p;
	}
	else
	{
		q->rear->next=p;
		q->rear=p;
	}
}

int deQueue(LiQueue *&q,int &e)
{
	if(q->front==NULL)
	return 0;
	QNode *p=q->front;
	if(q->front==q->rear)
	{
		q->front=q->rear=NULL;
	}
	else
	{
		q->front=q->front->next;
	}
	e=p->data; 
	free(p);
	return 1;
}

int ClearQueue(LiQueue *&q)
{
	if(q->front==NULL)
	{free(q);return 1;}
	QNode *p=q->front,*r;
	while(p!=q->rear)
	{
		r=p;
		p=p->next;
		free(r); 
	}
	free(p);
	free(q);
	return 1;
}
int DisplayQueue(LiQueue *&q)
{
	if(q->front==NULL) {cout<<endl;return 1;}
	QNode *p=q->front;
	while(p!=q->rear)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<p->data<<endl;
	return 1;
}

int QueueLength(LiQueue *&q)
{
	if(q->front==NULL) return 0;
	QNode *p=q->front;
	int n=0;
	while(p!=q->rear)
	{
		n++;
		p=p->next;
	}
	n++;
	return n;
}

void ReduceQueue(LiQueue *&q,int b,int c)
{
	while(QueueLength(q)>b/2)
		{
			int e;
			deQueue(q,e);
			if(e>c){e=e-c;enQueue(q,e);}
		}
}

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		LiQueue *q;
		InitQueue(q);
		for(int i=0;i<a;i++)
		{
			int e;
			cin>>e;
			enQueue(q,e);
			if(QueueLength(q)==b)
			ReduceQueue(q,b,c);
	 }
		DisplayQueue(q);
		ClearQueue(q); 
		
	}
	return 0;
} 
