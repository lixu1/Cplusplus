#include <iostream>
#include "malloc.h"
#include "stdio.h"
#include <cstring>

using namespace std;

typedef struct Linknode
{
    int data;
    struct Linknode *next;
}LiStack;

void InitStack(LiStack *&s)
{
    s=(LiStack *)malloc(sizeof(LiStack));
    s->next=NULL;
}

void ClearStack(LiStack *&s)
{
    LiStack *p=s,*q=s->next;
    while(q!=NULL)
    {
        free(p);
        p=q;
        q=p->next;
    }
    free(p);

}
void Push(LiStack *&s,int e)
{
    LiStack *p;
    p=(LiStack * )malloc(sizeof(LiStack));
    p->data=e;
    p->next=s->next;
    s->next=p;
}
int Pop(LiStack *&s,char &e)
{
    LiStack *p;
    if(s->next==NULL) return 0;
    p=s->next;
    e=p->data;
    s->next=p->next;
    free(p);
    return 1;
}
int StackLength(LiStack *s)
{
    int n=0;
    LiStack *p;
    p=s->next;
    while(p!=NULL)
    {
        n++;
        p=p->next;
    }
    return n;
}
int StackEmpty(LiStack *s)
{
    return (s->next==NULL);
}
int GetTop(LiStack *s,char &e)
{
    if(s->next==NULL) return 0;
    e=s->next->data;
    return 1;
}
int Match(char exp[],int n)
{
    int i=0;
    char e;
    LiStack * st;
    InitStack(st);
    while(i<n)
    {
        switch ( exp[i] )
        {
            case '(':
            case '{':
            case '[':
            Push( st,exp[i] );
            break;
            case ')':

            if(GetTop(st,e)==1)
            {
                if(e!='(') return 0;
                else Pop(st,e);
            }
            else return 0;
            break;

            case ']':

            if(GetTop(st,e)==1)
            {
                if(e!='[') return 0;
                else Pop(st,e);
            }
            else return 0;
            break;

            case '}':

            if(GetTop(st,e)==1)
            {
                if(e!='{') return 0;
                else Pop(st,e);
            }
            else return 0;
            break;

            default:
																				break;
        }
        i++;
    }
    if(StackEmpty(st) ==1) return 1;
    else return 0;
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        char a[1000];
        cin>>a;
        int b=strlen(a);

        if(Match(a,b)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
    return 0;
}
