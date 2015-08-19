#include "stdio.h"
void QuickSort(int a[],int s,int t)
{
    int i=s,j=t;
    int tmp;
    if(s<t)
    {
        tmp=a[s];
        while(i!=j)
        {
            while(j>i&&a[j]>=tmp) j--;
            a[i]=a[j];
            while(i<j&&a[i]<=tmp) i++;
            a[j]=a[i];

        }
        a[i]=tmp;
        QuickSort(a,s,i-1);
        QuickSort(a,i+1,t);
    }
    return;
}
int a[100000];
int main()
{
    int t;
    scanf("%d",&t);
    //int a[10005];
    while(t--)
    {
        int m ;
char c[10];
int k = 0 ;
do
{
	scanf("%d%[^\\-0-9]", &m, c);
	a[k++]=m;
}while(c[0]!='\n' && c[1]!='\n' );


        /*char qq;
        int length=0;
        scanf("%d",&a[length]);length++;
        while(scanf("%c",&qq)&&qq!='\n')
        {
            scanf("%d",&a[length]);length++;
        }*/
        //printf("%d\n",length);

        QuickSort(a,0,k-1);
        for(int i=0;i<k-1;i++)
        printf("%d ",a[i]);
        printf("%d\n",a[k-1]);
    }
}

