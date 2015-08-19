#include "stdio.h"
#include "malloc.h"
#define MaxSize 100 
//#include <iomanip>

using namespace std;
typedef struct node
{
	char data;
	double a;
	struct node *lchild;
	struct node *rchild;
}BTNode;
void CreatBTNode (BTNode *&b,char *str)
{
	BTNode *st[MaxSize],*p=NULL;
	int top=-1,k,j=0;
	char ch;
	b=NULL;
	ch=str[j];
	while(ch!='\0')
	{
		switch(ch)
		{
			case '(':top++;st[top]=p;k=1;break;
			case ')':top--;break;
			case ',':k=2;break;
			default:
											p=(BTNode *)malloc(sizeof(BTNode));
											switch(ch)
											{
												case '+':p->data=ch;p->a=0;p->lchild=NULL;p->rchild=NULL;break;
												case '-':
																	if(str[j+1]>='0' && str[j+1]<='9')
																	{
																		j++;
																		p->data='=';p->a = str[j]-'0';p->lchild=NULL;p->rchild=NULL;
																				while((str[j+1]>='0' && str[j+1]<='9')||(str[j+1]=='.'))
																				{
																					j++;int r=0;
																					if(str[j]!='.') p->a=10*p->a + str[j]-'0';
																					else
																					{
																						j++;r++;p->a = p->a+(str[j]-'0')*0.1;
																						while(str[j+1]>='0' && str[j+1]<='9')
																						{
																							j++;
																							r++;
																							double q=1;
																							for(int w=0;w<r;w++) q=q*0.1;
																							p->a = p->a + (str[j]-'0')*q;
																						}
																					}
																				}
																				p->a = -(p->a);
																						//printf("%.2lf\n",p->a);
																	}
																	else
																	{p->data=ch;p->a=0;p->lchild=NULL;p->rchild=NULL;}
																	break;
												case '*':p->data=ch;p->a=0;p->lchild=NULL;p->rchild=NULL;break;
												case '/':p->data=ch;p->a=0;p->lchild=NULL;p->rchild=NULL;break;
												default:
																				p->data='=';p->a = str[j]-'0';p->lchild=NULL;p->rchild=NULL;
																				while((str[j+1]>='0' && str[j+1]<='9')||(str[j+1]=='.'))
																				{
																					j++;int r=0;
																					if(str[j]!='.') p->a=10*p->a + str[j]-'0';
																					else
																					{
																						j++;r++;p->a = p->a+(str[j]-'0')*0.1;
																						while(str[j+1]>='0' && str[j+1]<='9')
																						{
																							j++;r++;double q=1;
																							for(int w=0;w<r;w++) q=q*0.1;
																							p->a = p->a+(str[j]-'0')*q;
																						}
																					}
																				}
																				//printf("%.2lf\n",p->a);
																				break;
											}
											if(b==NULL)b=p;
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
double BTanswer(BTNode *b)
{
	if(b!=NULL)
	{
		if(b->lchild==NULL) return (b->a);
		else
		{
			if(b->data=='+') return  (BTanswer(b->lchild)+BTanswer(b->rchild));
			if(b->data=='-') return  (BTanswer(b->lchild)-BTanswer(b->rchild));
			if(b->data=='*') return  (BTanswer(b->lchild)*BTanswer(b->rchild));
			if(b->data=='/') return  (BTanswer(b->lchild)/BTanswer(b->rchild));
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
void DispBTNode(BTNode *b)
{
	if(b!=NULL)
	{
		if(b->data=='=')printf("%.2lf",b->a);
		else printf("%c",b->data);
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
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char a[1500];
		scanf("%s",a);
		BTNode *b;
		CreatBTNode(b,a);
		//DispBTNode(b);
		printf("%.2lf\n",BTanswer(b));
		//cout<<fixed<<setprecision(2)<<BTanswer(b)<<endl;
		DestroyBT(b);
	}
}
