#include<iostream>
#include "malloc.h"
#include "stdio.h"


using namespace std;

typedef struct snode
{
    char data;
    struct snode * next;
}LiString;

void StrAssign(LiString *&s,char cstr[])
{
    int i;
    LiString *r,*p;
    s=(LiString *)malloc(sizeof (LiString));
    r=s;
    for(i=0;cstr[i]!='\0';i++)
    {
        p=(LiString *)malloc(sizeof (LiString));
        p->data=cstr[i];
        r->next=p;
        r=p;
    }
    r->next=NULL;
}


void StrCopy(LiString *&s,LiString *t)
{
	LiString *p=t->next,*q,*r;
	s=(LiString *)malloc(sizeof(LiString));
	r=s;
	while(p!=NULL)
	{
		q=(LiString *) malloc(sizeof(LiString));
		q->data=p->data;
		r->next=q;
		r=q;
		p=p->next;

	}
	r->next=NULL;
}

int StrEqual(LiString *s,LiString *t)
{
	LiString *p=s->next,*q=t->next;
	while(p!=NULL&&q!=NULL&&p->data==q->data)
	{
		p=p->next;
		q=q->next;
	}
	if(p==NULL&&q==NULL)
	return 1;
	else return 0;
}


int StrLength(LiString *s)
{
    int i=0;
    LiString *p=s->next;
    while(p!=NULL)
    {
        i++;
        p=p->next;
    }
    return i;
}

LiString *Concat(LiString *s,LiString *t)
{
	LiString *str,*p=s->next,*q,*r;
	str=(LiString *)malloc(sizeof(LiString));
	r=str;
	while(p!=NULL)
	{
		q=(LiString *)malloc(sizeof(LiString));
		q->data=p->data;
		r->next=q;
		r=q;
		p=p->next;
	}
	p=t->next;
	while(p!=NULL)
	{
		q=(LiString *)malloc(sizeof(LiString));
		q->data=p->data;
		r->next=q;
		r=q;
		p=p->next;
	}
	r->next=NULL;
	return str;
}

LiString *SubStr(LiString *s,int i,int j)
{
	int k;
	LiString *str,*p=s->next,*q,*r;
	str=(LiString *)malloc(sizeof(LiString));
	str->next=NULL;
	r=str;
	if(i<=0||i>StrLength(s)||j<0||i+j-1>StrLength(s))
	return str;
	for(k=0;k<i-1;k++)
	p=p->next;
	for(k=1;k<=j;k++)
	{
	   q=(LiString *)malloc(sizeof(LiString));
	   q->data=p->data;
	   r->next=q;
	   r=q;
	   p=p->next;
	}
	r->next=NULL;
	return str;
}
LiString *InsStr(LiString *s,int i,LiString *t)
{
    int k;
    LiString *str,*p=s->next,*pl=t->next,*q,*r;
    str=(LiString *)malloc(sizeof(LiString));
    str->next=NULL;
    r=str;
    if(i<=0||i>StrLength(s)+1)
    return str;
    for(k=1;k<i;k++)
    {
        q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    while(pl!=NULL)
    {
        q=(LiString *)malloc(sizeof(LiString));
        q->data=pl->data;
        r->next=q;
        r=q;
        pl=pl->next;
    }
    while(p!=NULL)
    {
        q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    r->next=NULL;
    return str;
}

LiString *DelStr(LiString *s,int i,int j)
{
   int k;
   LiString *str,*p=s->next,*q,*r;
   str=(LiString *)malloc(sizeof(LiString));
   r=str;
   if(i<=0||i>StrLength(s)||j<0||i+j-1>StrLength(s));
   return str;
   for(k=0;k<i-1;k++)
   {
      q=(LiString *)malloc(sizeof(LiString));
      q->data=p->data;
      r->next=q;
      r=q;
      p=p->next;
   }
   for(k=0;k<j;k++)
   p=p->next;
   while(p!=NULL)
   {
      q=(LiString *)malloc(sizeof(LiString));
      q->data=p->data;
      r->next=q;
      r=q;
      p=p->next;
   }
   r->next=NULL;
   return str;
}

LiString *RepStr(LiString *s,int i,int j,LiString *t)
{
   int k;
   LiString *str,*p=s->next,*pl=t->next,*q,*r;
   str=(LiString *)malloc(sizeof(LiString));
   r=str;
   if(i<=0||i>StrLength(s)||j<0||i+j-1>StrLength(s))
   return str;
   for(k=0;k<i-1;k++)
   {
        q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        q->next=NULL;
        r->next=q;
        r=q;
        p=p->next;
   }
   for(k=0;k<j;k++)
   p=p->next;
   while(pl!=NULL)
   {
        q=(LiString *)malloc(sizeof(LiString));
        q->data=pl->data;q->next=NULL;
        r->next=q;
        r=q;
        pl=pl->next;
   }
   while(p!=NULL)
   {
        q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;q->next=NULL;
        r->next=q;
        r=q;
        p=p->next;
   }
   r->next=NULL;
   return str;
}

void DispStr(LiString *s)
{
   LiString *p=s->next,*q=p;
   while(p!=NULL)
   {
      cout<<p->data;
      p=p->next;
      free(q);
      q=p;
   }
   cout<<endl;
   free(s);

}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        char a[3];
        cin>>a;
        if(a[0]=='I')
        {
            int m;
            cin>>m;
            char b[1000];
            cin>>b;
            char c[1000];
            cin>>c;
            LiString *s1;
            StrAssign(s1,b);
            LiString *s2;
            StrAssign(s2,c);

            DispStr(InsStr(s1,m,s2));

        }
        if(a[0]=='R')
        {
           int m;
           cin>>m;
           char b[1000];
           cin>>b;
           char c[1000];
           cin>>c;
           LiString *s1;
           StrAssign(s1,b);
           LiString *s2;
           StrAssign(s2,c);
           int t=StrLength(s2);
           DispStr(RepStr(s1,m,t,s2));
        }

    }
}
