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
      cout<<"100���ڼӼ����ͼ򵥳˳���ѵ����������Ҫ������Ŀ������"<<endl;
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
               cout<<d<<" ���� "<<c<<" = ? > 0 �����ֵ������  ";
               break;
            case 4:
               int z;
               z=c*e;
               ans2=e*d;
               cout<<z<<" �� "<<c<<" x "<<d<<" = ";
               break;
            default:
               break;
         }
            cin>>ans1;
            if(ans1==ans2) {cout<<"�ش���ȷ��"<<endl;zhengque++;}
            else
            {
               cout<<"�ش����"<<endl;cuowu++;
               cout<<"�ٴγ��ԣ�������ȷ��"<<endl;
               while(cin>>ans1)
               {
                  if(ans1==ans2) { cout << "�ش���ȷ��"<<endl;break;}
                  else cout<<"�ٴγ��ԣ�������ȷ��  "<<endl;
               }
            }
      }
      fenshu=(zhengque*100)/(zhengque+cuowu);
      cout<<endl;
      cout<<"�ش���ȷ�ĸ�������"<<zhengque<<"��"<<endl;
      cout<<"�ش����ĸ�������"<<cuowu<<"��"<<endl;
      cout<<"������"<<fenshu<<"��"<<endl;
      cout<<"�Ƿ�����һ�Σ��������������"<<endl;
   }
}
