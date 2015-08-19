#include <iostream>
#include "stdio.h"
#include "malloc.h"

using namespace std;

typedef struct Lnode
{
    int data;
    struct Lnode *next;
}LinkList;

void CreatList(LinkList *& l,int a[],int n)
{
    LinkList *s,*r;int i;
    l=(LinkList *)malloc(sizeof(LinkList ));
    r=l;
    for(i=0; i<n;i++)
    {
        s=(LinkList *)malloc(sizeof(LinkList));
        s->data=a[i];
        r->next=s;
        r=s;
    }
    r->next=NULL;
}
int SearchList(LinkList *l)
{
    LinkList *p,*q;
    p=l->next;
    q=l->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next->next;
    }
    return (p->data);
}
void DestoryList(LinkList *& l)
{
    LinkList *p=l,*q=p->next;
    while(q!=NULL)
    {
        free(p);
        p=q;
        q=q->next;
    }
    free(p);
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a[100];
        int b=1;
        int e;
        cin>>e;
        a[0]=e;
        if(cin.get()=='\n')
        {
            cout<<e<<endl;
            continue;
        }
        else
        {
            while(b<100)
            {
                cin>>e;
                a[b]=e;
                b++;
																if(cin.get()!=' ')
                break;
                
            }
												LinkList *l;
            CreatList(l,a,b);
            cout<<SearchList(l)<<endl;
            DestoryList(l);
        }
    }
    return 0;
}

