#include <iostream>
using namespace std;
int main()
{
   long i,j,b,m,k,n,a[13][13];
   while(cin>>n)
   {
      m=0;b=0;
      for(i=1;i<=n;i++)
      {
         k=0;
         for(i=1;j<=n;j++)   {cin>>a[i][j];k+=a[i][j];}
         if(k!=1)b=1;
      }

      m=0;
      if(!b)
      {
         for(i=1;i<=n;i++)
         {
            if(b)break;m=0;
            for(j=1;j<=n;j++)m+=a[j][i];
            if(m!=1)b=1;
         }
      }
      if(b)cout<<"NO|n";
      else cout<<"YES\n";
      }
      return 0;
}
