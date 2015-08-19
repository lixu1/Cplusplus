#include <iostream>
using namespace std;
int main()
{
   int k,i,j;
   bool flag;

   flag=false;
   while(cin >> k)
   {
      if(flag)cout<<endl;
      flag=true;
      if(k==1)
      {
         cout<<'*'<<endl;
         continue;
      }
      if(k%2==0)
      {
         for(i=1;i<=k/2;i++)
         {
            for(j=1;j<=i;j++)
               if(j%2==1)cout<<'*';
               else cout<<'#';
            for(;j<=k-1;j++)
               if(i%2==1)cout<<'*';
               else cout<<'#';
            for(;j<=k;j++)
               if((k-j+1)%2==1)cout<<'*';
               else cout<<'#';
            cout<<endl;
         }
         for(;i<=k;i++)
         {
            for(j=i;j<=(k-i+1);j++)
               if(j%2==1) cout<<'*';
               else cout<<'#';
            for(;j<=i-1;j++)
               if((k-i+1)%2==1) cout<<'*';
               else cout<<'#';
            for (;j<=k;j++)
               if((k-j+1)%2==1)cout<<'*';
               else cout<<'#';
            cout<<endl;
         }
      }
      else
      {
         for(i=1;i<=k/2;i++)
         {
            for(j=1;j<=i;j++)
               if(j%2==1)cout<<'*';
               else cout<<'#';
            for(;j<=k-1;j++)
               if(j%2==1)cout<<'*';
               else cout<<'#';
            for(;j<=k;j++)
               if((k-j+1)%2==1)cout<<'*';
               else cout<<'#';
            cout<<endl;
         }
         for(j=1;j<=k;j++)
            if(j%2==1) cout<<'*';
            else cout<<'#';
         cout<<endl;
         i++;
         for(;i<=k;i++)
         {
            for(j=i;j<=(k-i+1);j++)
               if(j%2==1) cout<<'*';
               else cout<<'#';
            for(;j<=i-1;j++)
               if((k-i+1)%2==1) cout<<'*';
               else cout<<'#';
            for (;j<=k;j++)
               if((k-j+1)%2==1)cout<<'*';
               else cout<<'#';
            cout<<endl;
         }
      }
   }
   return 0;
}






