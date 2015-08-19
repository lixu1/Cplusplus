#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;
int main()
{
   char m[1000],n[1000];
   int j,k,l,z,lengh1,lengh2;
   while(cin>>m>>n)
   {
      if(m[0]=='0') break;
      l=k=0;
      lengh1=strlen(m);
      for(int i=0;i<lengh1;i++)
         l=10*l+m[i]-'0';
      lengh2=strlen(n);
      for(int i=0;i<lengh2;i++)
         k=10*k+n[i]-'0';
      j=l*k;
      if(lengh1==1&&lengh2==1)
      {
         cout<<" "<<l<<endl;
         cout<<"x"<<k<<endl;
         cout<<"--"<<endl;
         cout<<setw(2)<<j<<endl;
         cout<<endl;
      }
      else
      {
         int lengh3=0;
         z=j;
         for(z;z>0;z/=10)
            lengh3++;
         cout<<setw(lengh3)<<l<<endl;
         cout<<setw(lengh3-lengh2)<<"x"<<setw(lengh2)<<k<<endl;
         cout<<setfill('-')<<setw(lengh3)<<"-"<<endl;
         for(int i=0;i<lengh2;i++)
         {
            cout<<setfill(' ')<<setw(lengh3-i)<<l*(n[lengh2-1-i]-'0');
            for(int r=0;r<i;r++) cout<<" ";
            cout<<endl;
         }
         if(lengh2!=1)
         {
            cout<<setfill('-')<<setw(lengh3)<<"-"<<endl;
            cout<<setfill(' ')<<setw(lengh3)<<j<<endl;
         }
         cout<<endl;
      }
   }
   return 0;
}
