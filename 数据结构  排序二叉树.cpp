#include "stdio.h"
#include "malloc.h"
typedef struct node
{
    int key;
    struct node *lchild,*rchild;
}BSTNode;
int InsertBST(BSTNode *&p,int k)
{
    if(p==NULL)
    {
        p=(BSTNode *)malloc(sizeof(BSTNode));
        p->key=k;
        p->lchild=p->rchild=NULL;
        return 1;
    }
    //else if(k==p->key) return 0;
    else if(k<=p->key) return InsertBST(p->lchild,k);
    else return InsertBST(p->rchild,k);
}
BSTNode *searchBST(BSTNode *bt,int k)
{
    if(bt==NULL||bt->key==k) return bt;
    else if(k<=bt->key) return searchBST(bt->lchild,k);
    else return searchBST(bt->rchild,k);
}
BSTNode *CreatBST(int a[],int n)
{
    BSTNode *bt=NULL;
    int i=0;
    while(i<n)
    {
        InsertBST(bt,a[i]);
        i++;
    }
    return bt;
}
void Delete1(BSTNode *p,BSTNode *&r)
{
    BSTNode *q;
    if(r->rchild!=NULL)
    Delete1(p,r->rchild);
    else
    {
        p->key=r->key;
        q=r;
        r=r->lchild;
        free(q);
    }
}
void Delete(BSTNode *&p)
{
    BSTNode *q;
    if(p->rchild==NULL)
    {
        q=p;
        p=p->lchild;
        free(q);
    }
    else if(p->lchild==NULL)
    {
        q=p;
        p=p->rchild;
        free(q);
    }
    else Delete1(p,p->lchild);
}
int DeleteBST(BSTNode *&bt,int k)
{
    if(bt==NULL)return 0;
    else
    {
        if(k<bt->key) return DeleteBST(bt->lchild,k);
        else if(k>bt->key) return DeleteBST(bt->rchild,k);
        else
        {Delete(bt);return 1;}
    }
}

void Inorder1(BSTNode *bt)
{
	BSTNode *st[1000],*p;
	int top=-1;
	if(bt!=NULL)
	{
		p=bt;
		while(top>-1||p!=NULL)
		{
			while(p!=NULL)
			{
				top++;st[top]=p;p=p->lchild;
			}
			if(top>-1)
			{
				p=st[top];top--;
				printf("%d ",p->key);
				p=p->rchild;
			}
		}
		printf("\n");
	}
}
void Inorder(BSTNode *bt)
{
    if(bt!=NULL)
    {
        Inorder(bt->lchild);
        printf("%d ",bt->key);
        Inorder(bt->rchild);
    }
}
void DestroyBST(BSTNode *bt)
{
	if(bt!=NULL)
	{
		DestroyBST(bt->lchild);
		DestroyBST(bt->rchild);
		free(bt);
	}
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a[1000];int length=0;
        scanf("%d",&a[length]); length++;
        char qqq;
        while(scanf("%c",&qqq)&&qqq!='\n')
        {
            scanf("%d",&a[length]);length++;
        }
        BSTNode *bt;
        bt=CreatBST(a,length);
        int m;
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            char b[10];
            scanf("%s",b);
            if(b[0]=='I')
            {
                int k;
                scanf("%d",&k);
                InsertBST(bt,k);
            }
            if(b[0]=='D')
            {
                int k;
                scanf("%d",&k);
                BSTNode *ww;
                ww=searchBST(bt,k);
                if(ww!=NULL) DeleteBST(bt,k);
            }
            //Inorder1(bt);//printf("\n");
        }
        Inorder1(bt);//printf("\n");
        DestroyBST(bt);
    }
}

