#include <cstdio>
#include <cstring>
using namespace std;
bool num[100005];
int main()
{
   //memset(num,0,sizeof(num));
   for(int i=2;i<=100000;i++)
   {
      for(int j=2;i*j<=100000;j++)
         num[i*j]=true;
   }
   int n;
   while(scanf("%d",&n)!=EOF)
   {
      if(num[n]) printf("NO\n");
      else printf("YES\n");
   }
   return 0;
}
