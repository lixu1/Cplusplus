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
	BTNode *st[200],*p=NULL;
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
bool PostOrder1(BTNode *b,int n,char q)
{
	bool flag1=false;
	BTNode *st[200];
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
				if(b->data==q)
					{
					    if(top*2<=n) {flag1=true;return flag1;}
					    else return flag1;
					}
				b=b->lchild;
			}
			p=NULL;
			flag=1;
			while(top!=-1&&flag)
			{
				b=st[top];
				if(b->rchild==p)
				{
					if(b->data==q)
					{
					    if((top-1)*2<=n) {flag1=true;return flag1;}
					    else return flag1;
					}
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
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int m;
		char p;
		char q;
		scanf("%d",&m);
		scanf("%c",&q);
		scanf("%c",&p);
		scanf("%c",&q);

		char a[1500];
		scanf("%s",a);
		BTNode *b;
		CreatBTNode (b,a);
		if(PostOrder1(b,m,p)) printf("Yes\n");
		else printf("No\n");
	}
}


