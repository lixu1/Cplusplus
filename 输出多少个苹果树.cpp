#include<iostream>
using namespace std;
int main()
{
   int n;
   char a[30][30];
   while(cin>>n)
   {
      int c,d,e,f;
      int ans=0;
      for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
         cin>>a[i][j];
      for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
      if(a[i][j]=='#')
      {
         c=i;d=j;
         break;
      }
      e=c;f=d;
      while(e>0&&f>0)
      {
         e--;f--;
      }
      while(e<n&&f<n)
      {
         if (a[e][f]=='1')
         ans++;
         e++;
         f++;
      }
      e=c;f=d;
      while(e>0&&f<n-1)
      {
         e--;f++;
      }
      while(e<n&&f>=0)
      {
         if (a[e][f]=='1')
         ans++;
         e++;
         f--;
      }
      cout<<ans<<endl;
   }
   return 0;
}
