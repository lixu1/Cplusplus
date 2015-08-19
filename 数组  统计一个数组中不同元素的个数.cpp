#include <iostream>
using namespace std;
int main()
{
   int n;
   int a[100];
   while(cin>>n)
   {
      for(int i=0;i<n;i++) cin>>a[i];
      for(int i=0;i<n;i++)
      {
         int b=a[i];
         int c=i;
         for(int j=c+1;j<n;j++)
         {
            if(a[j]==b)
            {int d=j ;
            for(int x=d;x<n-1;x++)
            a[x]=a[x+1];a[n-1]=0;n--;}

         }
      }
      cout<<n<<endl;
   }
}
