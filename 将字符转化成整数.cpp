#include <iostream>
using namespace std;
int main()
{
   int n;
   char a;
   while (cin>>n)
   {
      int ans = 0;
      for(int i=1;i<=n;i++)
      {
         cin>>a;
         ans = ans + (int)a;
      }
      cout << ans << endl;
   }
   return 0;
}
