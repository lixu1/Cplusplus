#include "stdio.h"
#include "malloc.h" 
typedef struct node
{
	char data;
	struct node *lchild;
	struct node *rchild;
}BTNode;
BTNode * CreatBT1(char *pre,char *in,int n)
{
	BTNode *s;
	char *p;
	int k;
	if(n<=0)return NULL;
	s=(BTNode *)malloc(sizeof(BTNode ));
	s->data=*pre;
	for(p=in;p<in+n;p++)
	if(*p==*pre) break;
	k=p-in;
	s->lchild=CreatBT1(pre+1,in,k);
	s->rchild=CreatBT1(pre+k+1,p+1,n-k-1);
	return s;
}
void DispBTNode(BTNode *b)
{
	if(b!=NULL)
	{
		printf("%c",b->data);
		if(b->lchild!=NULL||b->rchild!=NULL)
		{
			printf("(");
			DispBTNode(b->lchild);
			printf(",");
			DispBTNode(b->rchild);
			printf(")");
		}
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
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char a[100];
		char b[100];
		scanf("%s",a);
		scanf("%s",b);
		int length=0;
		for(int i=0;a[i]!='\0';i++)
		length++;
		BTNode *c=CreatBT1(a,b,length);
		DispBTNode(c);
		printf("\n");
		DestroyBT(c); 
	}
}
