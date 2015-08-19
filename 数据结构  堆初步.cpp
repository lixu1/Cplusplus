#include "stdio.h"
#include "malloc.h"
typedef struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
}BTNode;
void CreatBTNode(BTNode *&b,char str[])
{
	BTNode *st[2000],*p=NULL;
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
											if(ch!='-')
											{
												p->data=ch-'0';
												while(str[j+1]!='('&&str[j+1]!=')'&&str[j+1]!=','&&str[j+1]!='\0')
												{j++;p->data=p->data*10+str[j]-'0';}
											}
											else
											{
												j++;p->data=str[j]-'0';
												while(str[j+1]!='('&&str[j+1]!=')'&&str[j+1]!=','&&str[j+1]!='\0')
												{j++;p->data=p->data*10+str[j]-'0';}
												p->data=- p->data;
											}
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
bool HaveBTNode(BTNode *b)//ÍêÈ«¶þ²æÊ÷ 
{
	if(b!=NULL)
	{
		if(b->lchild!=NULL&&b->rchild!=NULL)
		return (HaveBTNode(b->lchild)&&HaveBTNode(b->rchild));
		else if(b->lchild==NULL&&b->rchild==NULL)
		return true;
		else return false;
	}
	else return true;
}
bool MinBTNode(BTNode *b)
{
	if(b!=NULL)
	{
		if(b->lchild!=NULL&&b->rchild!=NULL)
		{
			if(b->data<=b->lchild->data &&b->data<=b->rchild->data) 
			return(MinBTNode(b->lchild)&&MinBTNode(b->rchild));
			else return false;
		}
		else if(b->lchild==NULL&&b->rchild==NULL)
		return true;
		else return false;
	}
	//else return true;
}
bool MaxBTNode(BTNode *b)
{
	if(b!=NULL)
	{
		if(b->lchild!=NULL&&b->rchild!=NULL)
		{
			if(b->data>=b->lchild->data &&b->data>=b->rchild->data) 
			return(MaxBTNode(b->lchild)&&MaxBTNode(b->rchild));
			else return false;
		}
		else if(b->lchild==NULL&&b->rchild==NULL)
		return true;
		else return false;
	}
	//else return true;
}
void DestroyBT(BTNode *b)
{
	if(b!=NULL)
	{
		DestroyBT(b->lchild);
		DestroyBT(b->rchild);
		free(b);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char a[1000];
		scanf("%s",a);
		BTNode *b;
		CreatBTNode(b,a);
		if(MinBTNode(b)&&HaveBTNode(b)&&b->lchild!=NULL&&b->rchild!=NULL) 
		printf("Min-heap.\n");
		else if(MaxBTNode(b)&&HaveBTNode(b)&&b->lchild!=NULL&&b->rchild!=NULL) 
		printf("Max-heap.\n");
		else printf("No.\n");
		DestroyBT(b);
	}
}
