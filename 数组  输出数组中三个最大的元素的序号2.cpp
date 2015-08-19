#include <iostream>
using namespace std;

int main()
{
   int n,maxa,maxb,maxc;
   int a[110];
   int temp,i;
   while(cin>>n)
   {
      for(i=1;i<=n;i++)
         cin>>a[i];
      temp=0;
      for(i=1;i<=n;i++)
         if(a[i]>temp){temp=a[i];maxa=i;}
      a[maxa]=0;temp=0;
      for(i=1;i<=n;i++)
         if(a[i]>temp){temp=a[i];maxb=i;}
      a[maxb]=0;temp=0;
      for(i=1;i<=n;i++)
         if(a[i]>temp){temp=a[i];maxc=i;}
      a[maxc]=0;
      cout<<maxa<<" "<<maxb<<" "<<maxc<<endl;
   }
   return 0;
}
