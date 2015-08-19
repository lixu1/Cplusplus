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
												p->data=-p->data;
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
		int c[1000];int length=0;
		for(int i=0;i<1000;i++) c[i]=0;
		BTNode *st[2000],*p;
		int top=-1;
		if(b!=NULL)
		{
			p=b;
			while(top>-1||p!=NULL)
			{
				while(p!=NULL)
				{
				top++;
				st[top]=p;
				p=p->lchild;
				}
			if(top>-1)
			{
				p=st[top];
				top--;
				c[length]=p->data;length++;
				p=p->rchild;
			}
		}
	}
	//for(int i=0;i<length;i++)
	//printf("%d ",c[i]);
	//printf("\n");
	bool flag1=true;
	bool flag2=true;
	for(int i=0;i<length-1;i++)
	{
		if(c[i]>c[i+1]){flag1=false;break;}
	}
	for(int i=0;i<length-1;i++)
	{
		if(c[i]<c[i+1]){flag2=false;break;}
	}
	if(flag1||flag2)printf("Yes.\n");
	else printf("No.\n");
	}
}
