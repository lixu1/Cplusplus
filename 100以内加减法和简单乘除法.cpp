#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
   int n,zhengque,cuowu;
   int fenshu;
   char x;
   while(cin>>x)
   {
      cout<<"100以内加减法和简单乘除法训练，输入你要做的题目个数！"<<endl;
						cin>>n;
      zhengque=0;
      cuowu=0;
      while(n--)
      {
         srand( time( 0 ) );
         int fuhao=rand()%5;
         int a,b,c,d,e;
         int ans1,ans2;
         a=rand()%100;
         b=0;
         while(b<a)
         {
            b=rand()%100;
         }
         c=0;
         while(c==0)
         {
            c=rand()%10;
         }
         d=0;
         while(d==0)
         {
            d=rand()%100;
         }
         e=0;
         while(e==0)
         {
            e=rand()%10;
         }
         switch ( fuhao )
         {
            case 0:
               ans2=a*10+b*10;
               cout<<a*10<<" + "<<b*10<<"= ";
               break;
            case 1:
               ans2=b*10-a*10;
               cout<<b*10<<" - "<<a*10<<"= ";
               break;
            case 2:
               ans2=c*d;
               cout<<c<<" X "<<d<<"= ";
               break;
            case 3:
               ans2=d/c;
               cout<<d<<" 除以 "<<c<<" = ? > 0 的最大值可以是  ";
               break;
            case 4:
               int z;
               z=c*e;
               ans2=e*d;
               cout<<z<<" ÷ "<<c<<" x "<<d<<" = ";
               break;
            default:
               break;
         }
            cin>>ans1;
            if(ans1==ans2) {cout<<"回答正确！"<<endl;zhengque++;}
            else
            {
               cout<<"回答错误！"<<endl;cuowu++;
               cout<<"再次尝试！输入正确答案"<<endl;
               while(cin>>ans1)
               {
                  if(ans1==ans2) { cout << "回答正确！"<<endl;break;}
                  else cout<<"再次尝试！输入正确答案  "<<endl;
               }
            }
      }
      fenshu=(zhengque*100)/(zhengque+cuowu);
      cout<<endl;
      cout<<"回答正确的个数共有"<<zhengque<<"个"<<endl;
      cout<<"回答错误的个数共有"<<cuowu<<"个"<<endl;
      cout<<"分数是"<<fenshu<<"分"<<endl;
      cout<<"是否再练一次，按任意键继续！"<<endl;
   }
}
