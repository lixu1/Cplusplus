#include <iostream>
#include "stdio.h"
#include "malloc.h"
using namespace std;

typedef struct LNode 
{
	char data;
	struct LNode *next;
	struct LNode *front;
} LinkList ;

void Createlist(LinkList *&l,char a[],int n)
{
	LinkList *s=NULL, *p=NULL;
	l=(LinkList *)malloc(sizeof(LinkList));
	l->data=a[0];
	s=l;
	p=s; 
	for(int i=1;i<n;i++)
	{
		s->next=(LinkList *)malloc(sizeof(LinkList));
		
		s=s->next;
		s->front =p;
		s->data=a[i];
		p=s;
	}
	s->next=l;
	l->front =s;
} 
void moveList(LinkList *&l,int n,int k)
{
	LinkList *p=NULL;
	for(int i=1;i<=k%n;i++)
	l=l->front;
	p=l;
	for(int i=1;i<n;i++)
	{
		cout<<l->data;
		l=l->next;
		free(p);
		p=l;
	}
	cout<<l->data;
	free(l);
	cout<<endl;
	 
}
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		char a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		LinkList * l;
		
		Createlist(l,a,n);
		moveList(l,n,k); 
	}
	return 0;
}
