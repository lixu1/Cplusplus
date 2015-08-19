#include <iostream>

#include "malloc.h"
#include "stdio.h"
using namespace std;

typedef struct Dnode
{
	int data;
	struct Dnode *next;
}DLinkList;

void InitList(DLinkList *&l)
{
	l=( DLinkList *)malloc(sizeof( DLinkList ));
	l->data=0;
	l->next=NULL;
}

void CreatList( DLinkList *&l,int a[],int n)
{
	DLinkList *p;
	for(int i=0;i<n;i++)
	{
		p=(DLinkList *)malloc(sizeof( DLinkList ));
		p->data=a[i];
		p->next=l->next;
		l->next=p;
	}
}
void DisplayList(DLinkList *&l)
{
	DLinkList *p=l->next;
	while(p->next!=NULL)
	{
		l->next=p->next;
		cout<<p->data<<" ";
		free(p);
		p=l->next;
	}
	cout<<p->data<<endl;
	free(p);
	free(l);
}

int main()
{
	int n;
	int a[1000];
	
	cin>>n;
	while(n--)
	{
		int b;
		cin>>b;
		a[0]=b;
		int length=1;
		while(1)
		{
			if(cin.get()!=' ')
			break; 
			cin>>b;
			a[length]=b;
			length++;
		}
		DLinkList *l;
		InitList(l);
		CreatList(l,a,length);
		DisplayList(l);
	}
	return 0;
}
