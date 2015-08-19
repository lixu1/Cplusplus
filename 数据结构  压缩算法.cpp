#include <iostream>
#include <string.h>
using namespace std;
char a[1000];
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
      char b;
      cin>>a;
      int ans;
      int c=strlen(a);
      for(int i=0;i<c;i++)
      {
         b=a[i];
         ans=1;
         for(int j=i+1;j<c;j++)
         {
            if(a[j]==b) {i++;ans++;}
            else break;
         }
         cout<<b<<ans;
      }
      cout<<endl;
    }
}

