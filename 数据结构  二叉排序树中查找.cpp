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
bool PreOrder1(BTNode *b,char a)
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
			if(p->data==a) return true;
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
		
	}
	return false;
}
int main()
{
	int n;
	scanf("%d",&n);
	char a[1000];
	scanf("%s",a); 
	BTNode *b;
	CreatBTNode (b,a);
	for(int i=0;i<n;i++)
	{
		char c;
		scanf("%c",&c);
		if(PreOrder1(b,c)) printf("Yes.\n");
		else printf("No.\n");
	}
	  scanf("%d",&n);
}
