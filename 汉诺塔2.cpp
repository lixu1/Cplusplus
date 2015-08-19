#include<cstdio>
using namespace std;
void hanoi(int x,char a,char b,char c)
{
   if(x==1)
      printf("%c->%c\n",a,b);
   else
   {
      hanoi(x-1,a,c,b);
      printf("%c->%c\n",a,b);
      hanoi(x-1,c,b,a);
   }
}
int main()
{
   int n;
   while(scanf("%d",&n)!=EOF)
   {
      hanoi(n,'A','C','B');
      printf("\n");
   }
}
