#include"stdio.h"
void QuickSort(int a[],int s,int t)
{
   int i=s,j=t;
   int temp=a[i];
   while(i<j)
   {
      while(a[j]>=temp&&j>i)j--;
      a[i]=a[j];
      while(a[i]<=temp&&i<j)i++;
      a[j]=a[i];
   }
   a[i]=temp;
}

int main()
{
   int t;
   char qqq;
   scanf("%d",&t);
   scanf("%c",&qqq);
   while(t--)
   {
      char a,b,qqq;
      int s[9],s_length=0;
      int m[9],m_length=0;
      int p[9],p_length=0;
      for(int i=0;i<13;i++)
      {
         scanf("%c%c%c",&a,&b,&qqq);
         if(b=='s'){s[s_length]=a-'0';s_length++;}
         else if(b=='m'){m[m_length]=a-'0';m_length++;}
         else {p[p_length]=a-'0';p_length++;}
      }
      printf("%d %d %d\n",s_length,m_length,p_length);
      for(int i=0;i<s_length;i++)
      printf("%ds ",s[i]);
      for(int i=0;i<m_length;i++)
      printf("%dm ",m[i]);
      for(int i=0;i<p_length;i++)
      printf("%dp ",p[i]);
      printf("\n");

      QuickSort(s,0,s_length-1);
      QuickSort(m,0,m_length-1);
      QuickSort(p,0,p_length-1);

      int number=0,no;
      char answer
      for(int i=0;i<s_length++;i++)

   }
}
