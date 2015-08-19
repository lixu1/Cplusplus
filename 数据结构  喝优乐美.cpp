#include <iostream>
#include "stdio.h"
#include "malloc.h"

using namespace std;

typedef struct LNode
{
	int data;
	struct LNode *next;
	struct LNode *front;
}LinkList;

void CreatList(LinkList *&l,int n)
{
	LinkList *p=NULL,*q=NULL;
	l=(LinkList *)malloc(sizeof(LinkList));
	l->data=1;
	l->front=NULL;
	q=l;
	for(int i=2;i<=n;i++)
	{
		p=(LinkList *)malloc(sizeof(LinkList));
		p->data=i;
		q->next=p;
		p->front=q;
		q=p;
	}
	q->next=NULL;
}

bool LengthList(LinkList *&l)
{
	return (l==NULL);
}


void ZuiqianList(LinkList *& l )
{
	while(l->front!=NULL)
	{
		l=l->front;
	}
}

void DisplayList(LinkList *&l)
{
	LinkList *p=l;
	if(LengthList(l)) cout<<endl;
	else
	{
		while(l->next!=NULL)
  {
  	cout<< l->data <<" ";
  	p=l;
  	l=l->next;
  	free(p);
  }
  cout<<l->data;
  free(l);
  cout<<endl;
 }
}

void CutfrontList(LinkList *&l,int c,int d)
{
	LinkList *r=NULL;
	for(int i=1;i<=c+d;i++)
	{
		if(l->front==NULL) break;
		l=l->front;
	}
	if(l->front==NULL)
	{
		for(int i=1;i<=d;i++)
		{
			r=l;
			l=l->next;
			l->front=NULL;
			free(r);
			if(LengthList(l)) break;
		}
	}

	else
	{
		for(int i=1;i<=d;i++)
		{
			r=l->front;
			r->next=l->next;
			l->next->front=r;
			r=l;
			l=l->next;
			free(r);
		}
		l=l->front;
	}
}

void CutnextList(LinkList *&l,int c,int d)
{
	LinkList *r=NULL;
	for(int i=1;i<=c+d;i++)
	{
		if(l->next==NULL) break;
		l=l->next;
	}
	if(l->next==NULL)
	{
		for(int i=1;i<=d;i++)
		{
			r=l;
			l=l->front;
			l->next=NULL;
			free(r);
			if(LengthList(l)) break;
		}
	}

	if(l->next!=NULL)
	{
		for(int i=1;i<=d;i++)
		{
			r=l->next;
			r->front=l->front;
			l->front->next=r;
			r=l;
			l=l->front;
			free(r);
		}
		l=l->next;
	}
}

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int num,a;
		cin>>num>>a;
		LinkList *l;
		CreatList ( l, num);
		while(a--)
		{
			int b;
			cin>>b;
			if(b== 0 )continue;
			if(b== 1 )
			{
				int c,d;
				cin>>c>>d;
				CutnextList (l,c,d);
			}
			if(b== -1 )
			{
				int c,d;
				cin>>c>>d;
				CutfrontList (l,c,d);
			}
		}
		ZuiqianList(l);
		DisplayList(l);
		
	}
	return 0;
}
