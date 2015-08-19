#include "stdio.h"
#include "malloc.h"
#define MaxSize 20
typedef struct node
{
	char data[20];
	int length;
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
											p->length=0;
											p->data[p->length]=ch;p->length++;
											while(str[j+1]!='('&&str[j+1]!=')'&&str[j+1]!=','&&str[j+1]!='\0')
											{
												j++;
												p->data[p->length]=str[j];p->length++;
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
void preorder(BTNode *b,int n)
{
    if(b!=NULL)
    {
        for(int i=0;i<n;i++) printf(" ");
    				for(int i=0;i<b->length;i++)
    				printf("%c",b->data[i]);
    				printf("\n");
    				preorder(b->lchild,n+2);
    				preorder(b->rchild,n+2);
    }
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
	int n;
	scanf("%d",&n);
	while(n--)
	{
		char a[10000];
		scanf("%s",a);
		BTNode *b;
		CreatBTNode (b,a);
		preorder(b,0);
		DestroyBT(b);
	}
}


