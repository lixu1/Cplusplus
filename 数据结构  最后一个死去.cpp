//4-3,5-5,6-5,7-5,8-5,9-5,10-5,11-5,20-17,25-17,30-17

#include <iostream>
#include "malloc.h"
#include "stdio.h"

using namespace std;

typedef struct LNode
{
	int data;
	struct LNode *next;
	struct LNode *front;
} LinkList;

void CreatList(LinkList *&l,int n)
{
	LinkList *p=NULL,*r=NULL;
	l=(LinkList *)malloc(sizeof(LinkList));
	l->next=NULL;
	l->data=1; 
	r=l;
	for(int i=2;i<=n;i++)
	{
		p=(LinkList *) malloc (sizeof(LinkList));
		p->data=i;
		p->front=r;
		r->next=p;
		r=p;
	}
	r->next=l;
	l->front=r;
}

bool ListLength(LinkList *&l)
{
	return (l->next==l);
}
void DestroyList(LinkList *&l)
{
	free(l);
}
void CutList(LinkList *&l,int k)
{
	LinkList *p=l,*q=NULL,*s=l;
	l=l->next;
	while( (!ListLength(l)) &&(s!=l))
	{
		for(int i=1;i<k;i++)
		{
			p->next=l->next;
			l->next->front=p;
			q=l;
			l=l->next;
			free(q);
			if( ListLength( l )|| (l==s) ) break;
		}
		if( ListLength( l )|| (l==s) ) break;
		p=l;
		l=l->next;
		if( ListLength( l ) ||(l==s) ) break;
	}
	if(s==l) l=l->front;
}

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int a;
		cin>>a;
		LinkList *l;
		CreatList(l,a);
		for(int i=2;;i++) 
		{
			CutList(l,i);
			if(ListLength(l)) break;
		}
		cout<<l->data<<endl;
		DestroyList(l);
	}
	return 0;
}
