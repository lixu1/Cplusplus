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
    LiString *r=NULL,*p=NULL;
    s=(LiString *)malloc(sizeof (LiString));
    r=s;
    for(int i=0;cstr[i]!='\0';i++)
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
	LiString *p=t->next,*q=NULL,*r=NULL;
	r=s->next;
	while(r->next!=NULL)
	r=r->next;
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
void Copy(LiString *&s,LiString *t)
{
    s=(LiString *)malloc(sizeof(LiString));
    LiString *p=t->next,*r=NULL,*q=s;
    while(p!=NULL)
    {
        r=(LiString *) malloc(sizeof(LiString));
        r->data=p->data;
        q->next=r;
        q=r;
        p=p->next;
    }
    q->next=NULL;
}
void InsStr(LiString *&s,int i,char a[])
{
    LiString *p=s,*q=NULL;
    int j=0;
    for(int k=1;k<i;k++) p=p->next;
    while(a[j]!='\0')
    {
        q=(LiString *)malloc(sizeof(LiString));
        q->data=a[j];
        q->next=p->next;
        p->next=q;
        p=q;
        j++;
    }
}

void DelStr(LiString *&s,int i,int j)
{
   LiString *p=s,*q=NULL,*r=NULL;
   for(int k=1;k<i;k++) p=p->next;
   for(int k=0;k<j;k++)
   {
      q=p->next;
      p->next=p->next->next;
      free(q);
   }
}


void DispStr(LiString *s)
{
   LiString *p=s->next;
   if(s->next==NULL)printf("\n");
   else
   {
       while(p!=NULL)
   				{
      	printf("%c",p->data);
      	p=p->next;
   				}
							printf("\n");
   }
}
void DestroyStr(LiString *&s)
{
    LiString *p=NULL,*r=NULL;
    p=s->next;
    while(p!=NULL)
    {
        r=p;
        p=p->next;
        free(r);
    }
    free(s);
}
int main()
{
    char a[1500];
    scanf("%s",a);
    LiString *s;
    StrAssign(s,a);
    int n;
    scanf("%d",&n);
    while(n--)
    {
        char b[10];
        scanf("%s",b);
        if(b[0]=='I')
        {
           int c;
           scanf("%d",&c);
           char d[1500];
           scanf("%s",d);
           InsStr(s,c,d);DispStr(s);
        }
        if(b[0]=='D')
        {
            int c,d;
            scanf("%d%d",&c,&d);
            DelStr(s,c,d);DispStr(s);
        }
        if(b[0]=='C')
        {
            LiString *s1;
            Copy(s1,s);
            StrCopy(s,s1);
            DestroyStr(s1);DispStr(s);
        }
    }
    DispStr(s);
    DestroyStr(s);
system("pause"); 
}


