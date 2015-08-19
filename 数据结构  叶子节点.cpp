#include "stdio.h"
#include "malloc.h"
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
			case '(': top++;st[top]=p;k=1;break;
			case ')': top--;break;
			case ',': k=2;break;
			default: p=(BTNode *)malloc(sizeof(BTNode));
			p->data=ch;
			p->lchild=p->rchild=NULL;
			if(b==NULL)
			b=p;
			else
			{
				switch(k)
				{
					case 1: st[top]->lchild=p;break;
					case 2: st[top]->rchild=p;break;
				}
			} 
		}
		j++;
		ch=str[j];
	}
}
void DestroyBTNode(BTNode *&b)
{
	if(b!=NULL)
	{
		DestroyBTNode (b->lchild);
		DestroyBTNode (b->rchild);
		free(b);
	}
}
int Leaf(BTNode *b)
{
	if(b!=NULL)
	{
		if(b->lchild==NULL && b->rchild==NULL)
	 return 1;
		else
		return(Leaf(b->lchild)+Leaf(b->rchild)); 
	}
	return 0;
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
		printf("%d\n",Leaf(b)); 
		DestroyBTNode (b);
	} 
}
