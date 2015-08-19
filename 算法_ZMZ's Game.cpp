#include"stdio.h"
char zidian[10001][11];
int length[10001];
bool find(int i,char b[])
{
   int blength=0;
   while(b[blength]!='\0')
   blength++;
   if(length[i]!=blength)
   return false;
   else
   {
      bool flag=true;
      for(int j=0;j<length[i];j++)
      {
         if(b[j]!='?'&&zidian[i][j]!=b[j]){flag=false;break;}
      }
      return flag;
   }
}
int main()
{
   int n;
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   scanf("%s",zidian[i]);
   for(int i=0;i<n;i++)
   {
      int l=0;
      while(zidian[i][l]!='\0')
      l++;
      length[i]=l;
      //printf("%d\n",length[i]);
   }
   int m;
   scanf("%d",&m);
   for(int i=1;i<=m;i++)
   {
      printf("List %d:\n",i);

      char a[11];
      scanf("%s",a);
      for(int j=0;j<n;j++)
      {
         if(find(j,a)==true)
         printf("%s\n",zidian[j]);
      }
      printf("\n");
   }
}
