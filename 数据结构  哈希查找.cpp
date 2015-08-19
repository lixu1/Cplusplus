#include "stdio.h"
#include "malloc.h"
typedef struct haxi
{
   int data;
   struct haxi *next;
}HAXI;

void CreatHaxi(int a[],HAXI h[],int n,int p)
{
   HAXI *w;int q;
   for(int i=0;i<p;i++)
   {h[i].data=-1;h[i].next=NULL;}
   for(int i=0;i<n;i++)
   {
      q=a[i]%100000;
      w=(HAXI *)malloc(sizeof(HAXI));
      w->data=a[i];
      w->next=h[q].next;
      h[q].next=w;
   }
}
bool SearchHAXI(HAXI h[],int k)
{
   int q=k%100000;
   HAXI *p=h[q].next;
   while(p!=NULL)
   {
      //printf("%d\n",p->data);
      if(p->data==k) return true;
      else p=p->next;
   }
   return false;
}
void DestroyHaxi(HAXI h[],int p)
{
   HAXI *w,*q;
   for(int i=0;i<p;i++)
   {
      w=h[i].next;
      while(w!=NULL)
      {
         q=w;
         w=w->next;
         free(q);
      }
   }
}
int a[1000000];
HAXI h[100000];
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int length=0;
      /*scanf("%d",&a[length]);length++;
      char qqq;
      while(scanf("%c",&qqq)&&qqq!='\n')
      {
         scanf("%d",&a[length]);length++;
      }*/
      int m ;char c[10];//int k = 0 ;
do
{
	scanf("%d%[^\\-0-9]", &m, c);
	a[length++]=m;
}while(c[0]!='\n' && c[1]!='\n' );

      int p=100000;
      CreatHaxi(a,h,length,p);
      int m1;
      scanf("%d",&m1);
      for(int i=0;i<m1;i++)
      {
         int n;
         scanf("%d",&n);
         if(SearchHAXI(h,n)) printf("Yes.\n");
         else printf("No.\n");
      }
      //DestroyHaxi(h,p);
   }
}
