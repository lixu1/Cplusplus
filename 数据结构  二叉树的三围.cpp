#include "stdio.h"
#include "malloc.h"
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
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char a[1000];
		scanf("%s",a);
		BTNode *b;
		CreatBTNode(b,a);
		//preorder(b,0);
		
		int d[1000];int length=0;
		d[0]=1;length++;
		for(int i=1;i<1000;i++) d[i]=0;
		BTNode *p;
		BTNode *qu[1000];
		int front=-1,rear=-1;
		rear++;
		qu[rear]=b;
		int r=0;
		while(front!=rear)
		{
			front=(front+1)%1000;
			p=qu[front];
			
			if(p->lchild!=NULL&&p->rchild!=NULL)
			{
				rear=(rear+1)%1000;
				qu[rear]=p->lchild;
				rear=(rear+1)%1000;
				qu[rear]=p->rchild;
				d[length]=d[length]+2;
			}
			else if(p->lchild!=NULL&&p->rchild==NULL)
			{
				rear=(rear+1)%1000;
				qu[rear]=p->lchild;
				d[length]++;
			}
			else if(p->lchild==NULL&&p->rchild!=NULL)
			{
				rear=(rear+1)%1000;
				qu[rear]=p->rchild;
				d[length]++;
			}
			r++;
			if(r==d[length-1]){r=0;length++;}
		}
		//for(int i=0;i<length;i++)
		//printf("%d ",d[i]);
		//printf("\n");
		int ans=0;
		if(length<=3)printf("Invalid tree!\n");
		else
		{
			for(int i=1;i<length-1;i++)
			if( d[ans]<d[i] ) ans=i;
			if(ans>=(length-2)||ans==0)printf("Invalid tree!\n");
			else printf("%d %d %d\n",d[ans-1],d[ans],d[ans+1]);
		}
		DestroyBT(b);
	}
}
