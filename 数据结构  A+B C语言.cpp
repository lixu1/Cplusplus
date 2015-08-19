#include "stdio.h"
#include <string.h>
using namespace std;
int main()
{
   int n;
   scanf("%d",n);
   while(n--)
	{
   char a[100],b[100],t[100];
   gets(a);
   gets(b);
   if(strlen(a)<strlen(b))
   {strcpy(t,a);
   strcpy(a,b);
   strcpy(b,t);
   }
   int m=strlen(a)-strlen(b),i,j;
   for(i=0;i<strlen(b);i++)
   t[i+m]=b[i];
   for(i=0;i<m;i++)
   t[i]=48;
   strcpy(b,t);
   for(i=0;i<strlen(a);i++)
   t[i]=a[i]+b[i]-48;
   t[i]=0;
   for(i=strlen(t)-1;i>0;i--)
   if(t[i]>'9')
   {int p=t[i]-48;
   t[i]=p%10+48;
   t[i-1]+=p/10;}
   if(t[0]>'9')
   {int p=t[0]-48;
   t[0]=p%10+48;
   printf("%d\n",p/10);}
   //puts(t);

   }
}
