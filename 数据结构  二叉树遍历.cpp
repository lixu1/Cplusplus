#include "stdio.h"
#include "malloc.h"
#define MaxSize 20
typedef struct node
{
	char data;
	struct node *lchild;
	struct node *rchild;
}BTNode;
void CreatBTNode(BTNode *&b,char str[])
{
	BTNode *st[20],*p=NULL;
	int top=-1,k,j=0;
	char ch;
	b=NULL;
	ch=str[j];
	while(ch!='\0')
	{
		switch(ch)
		{
			case '(':top++;st[top]=p;k=1; break;
			case ')':top--;break;
			case ',':k=2;break;
			default:
											p=(BTNode *)malloc(sizeof(BTNode));
											p->data=ch;
											p->lchild=p->rchild=NULL;
											if(b==NULL) b=p;
											else
											{
												switch(k)
												{
													case 1:st[top]->lchild=p;break;
													case 2:st[top]->rchild=p;break;
												}
											} 
		}
		j++;
		ch=str[j];
	}
}
void PreOrder1(BTNode *b)
{
	BTNode *st[20],*p=NULL;
	int top=-1;
	if(b!=NULL)
	{
		top++;
		st[top]=b;
		while(top>-1)
		{
			p=st[top];
			top--;
			printf("%c",p->data);
			if(p->rchild!=NULL)
			{
				top++;
				st[top]=p->rchild;
			}
			if(p->lchild!=NULL)
			{
				top++;
				st[top]=p->lchild;
			}
			
		}
		printf("\n");
	}
}
void PostOrder1(BTNode *b)
{
	BTNode *st[20];
	BTNode *p=NULL;
	int flag,top=-1;
	if(b!=NULL)
	{
		do
		{
			while(b!=NULL)
			{
				top++;
				st[top]=b;
				b=b->lchild;
			}
			p=NULL;
			flag=1;
			while(top!=-1&&flag)
			{
				b=st[top];
				if(b->rchild==p)
				{
					printf("%c",b->data);
					top--;
					p=b;
				}
				else
				{
					b=b->rchild;
					flag=0;
				}
			}
		}while(top!=-1);
		printf("\n");
	}
}

void LevelOrder(BTNode *b)
{
	BTNode *p;
	BTNode *qu[MaxSize];
	int front,rear;
	front=rear=-1;
	rear++;
	qu[rear]=b;
	while(front!=rear)
	{
		front=(front+1)%MaxSize;
		p=qu[front];
		printf("%c",p->data);
		if(p->lchild!=NULL)
		{
			rear=(rear+1)%MaxSize;
			qu[rear]=p->lchild;
		}
		if(p->rchild!=NULL)
		{
			rear=(rear+1)%MaxSize;
			qu[rear]=p->rchild;
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		char a[1000];
		scanf("%s",a);
		BTNode *b;
		CreatBTNode (b,a);
		PreOrder1(b);
		
	 PostOrder1(b);
		
		LevelOrder(b);
		printf("\n");
	}  
}
