#include <iostream>
#include <cstring>
using namespace std;
bool mystrcmp(const char*a,const char*b)
{
   int length1=strlen(a),length2=strlen(b); 
   int i=0;
   int minilength=length1<length2?length1:length2;
   while(i<minilength)
   {
      if(a[i]>b[i]) return true;
      else if(a[i]<b[i]) return false;
      i++;
   }
   return length1<length2?false:true;
}

void mystrcpy(char*target,const char *source)
{
   int len=strlen(source);
   for(int i=0;i<=len;i++)
      target[i]=source[i];
}
int main()
{
   int n;
   char str[20][101];
   bool flag=true;
   while(cin>>n)
   {
      for(int i=0;i<n;i++)
      cin>>str[i];
      for(int i=0;i<n;i++)
      {
         flag=true;
         for(int j=1;j<n;j++)
         {
            if(mystrcmp(str[j-1],str[j]))
            {
               char tmp[101];
               mystrcpy(tmp,str[j-1]);
               mystrcpy(str[j-1],str[j]);
               mystrcpy(str[j],tmp);
               flag=false;
            }
         }
         if(flag) break;
      }
      for(int i=0;i<n;i++)
      cout<<str[i]<<endl;
      cout<<endl;

   }
   return 0;
}
