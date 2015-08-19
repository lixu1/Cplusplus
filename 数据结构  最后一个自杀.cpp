#include <iostream>
#include <stdio.h>
#include <malloc.h>

using namespace std;

typedef struct zhisha
{
	int data;
	int length;
	zhisha *next;
	zhisha *dangqian;
};


void CreatList(zhisha *&l,int n)
{
	zhisha *r,*s;
	l=(zhisha * )malloc(sizeof(zhisha));
	l->data=0;
	l->length=0;
	r=l;
 for (int i=0;i<n;i++)
	{
		s=(zhisha * )malloc(sizeof(zhisha));
		s->data=i+1;
		s->length=0;
		s->dangqian=NULL;
		r->next= s;
		r=s;
		l->length++;
 }
 r->next=l->next;
 l->dangqian=l;
}
void Destroy(zhisha *&l)
{
	free(l);
}
void ListLength(zhisha *l,int &c)
{
	c = (l->length);
}
void DestoryList(zhisha *&l,int m)
{
	
	for(int i=0;i<m-1;i++)
	{
		l->dangqian=l->dangqian->next;
	}
	zhisha *p=l->dangqian->next;
	l->dangqian->next=l->dangqian->next->next;
	free(p);
	l->length--;
	//l->dangqian=l->dangqian->next;
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int a,b,c;
		cin>>a>>b;
		zhisha *l;
		CreatList(l,a);
		ListLength(l,c);
		while( c!= 1)
		{
			DestoryList(l,b);
			ListLength(l,c);
		}
		cout<<l->dangqian->data<<endl;
		
		}
		return 0;
}
		
