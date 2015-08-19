#include <iostream>
using namespace std;

void useLocal();
void useStaticlLocal();
void useGlobal();

int x=1;

int  main()
{
   cout<<"global x in main is "<<x<<endl;
   int x=5;
   cout<<"local x in main's inner scope is "<<x<<endl;
   {
      int x=7;
      cout<<"local x in main's inner scope is "<<x<<endl;

   }
   cout<<"local x in main's outer scope is "<<x<<endl;

   useLocal();
   useStaticlLocal();
   useGlobal();
   useLocal();
   useStaticlLocal();
   useGlobal();

   cout<<"\nlocal x in main is  "<<x<<endl;


}
void useLocal()
{
   int x =25;
   cout<<"\nlocal x is "<<x<<" on entering useLocal"<<endl;
   x++;
   cout<<"local x is "<<x<<" on exiting useLocal"<<endl;

}

void useStaticlLocal()
{
   int x =50;
   cout<<"\nlocal static x is "<<x<<" on entering useStaticlLocal"<<endl;
   x++;
   cout<<"local static x ia "<<x<<" on exiting useStaticlLKocal"<<endl;


}
void useGlobal()
{
   cout<<"\nglobal x is "<<x<<"  on entering useGlobal"<<endl;
   x*=10;
   cout<<"global x is "<<x<<" on entering useGlobal"<<endl;

}






