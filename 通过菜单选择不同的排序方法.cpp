#include <iostream>
using namespace std;
#include <cstdlib>
#include <string>
#include <ctime>

const int Max=100;
template <typename T>
class Sample
{
   T A [Max];
   int n;
   void qsort(int I,int h);
public:
   Sample(){n=0;}
   void getdata();
   void insertsort();
   void Shellsort();
   void bubblesort();
   void quicksort();
   void selectsort();
   void disp();
};

template <typename T>
void Sample<T>::getdata()
{
   srand((unsigned)time(NULL));
   cout<<"���Ԫ�ظ��� n :";
   cin>>n;
   for(int i=0;i<n;i++)
      A[i]=rand()*99/32767+1;//����һ��һ�ٵ������
}

template <typename T>
void Sample <T>::insertsort()//��������
{
   int i,j;
   T temp;
   for(i=1;i<n;i++)
   {
      temp=A[i];
      j=i-1;
      while(temp<A[j])
      {
         A[j+1]=A[j];
         j--;
      }
      A[j+1]=temp;
   }
}

template <typename T>
void Sample<T>::Shellsort()//ϣ������
{
   int i,j,gap;
   T temp;
   gap=n/2;
   while(gap>0)
   {
      for(i=gap;i<n;i++)
      {
         j=i-gap;
         while(j>=gap)
         if(A[j]>A[j+gap])
         {
            temp =A[j];
            A[j]=A[j+gap];
            A[j+gap]=temp;
            j=j-gap;
         }
         else j=0;
      }
      gap=gap/2;
   }
}

template <typename T>
void Sample<T>::bubblesort()//ð������
{
   int i,j;
   T temp;
   for(j=n-1;j>=i+1;i--)
   if(A[j]<A[j-1])
   {
      temp=A[j];
      A[j]=A[j-1];
      A[j-1]=temp;
   }
}

template <typename T>
void Sample<T>::quicksort()//��������
{
   qsort(0,n-1);
}
template <typename T>
void Sample <T>::qsort(int I,int h)
{
   int i=1,j=h;
   T temp;
   if(I<h)
   {
      temp=A[I];
      do
      {
         while(j>i&&A[j]>=temp)
         j--;
         if(i<j)
         {
            A[i]=A[j];
            i++;
         }
         while(i<j&&A[i]<=temp)
         i++;
         if(i<j)
         {
            A[j]=A[i];
            j--;
         }
									}while(i<j);
         A[i]=temp;
         qsort(1,j-1);
         qsort(j+1,h);
   }
}
template <typename T>
void Sample <T>::selectsort()//ѡ������
{
   int i,j,k;
   T temp;
   for(i=0;i<n;i++)
   {
      k=i;
      for(j=i+1;j<=n-1;j++)
      if(A[j]<A[k]) k=j;
      temp=A[i];
      A[i]=A[k];
      A[k]=temp;
   }
}

template <typename T>
void Sample<T>::disp()
{
   for(int i=0;i<n;i++)
   cout<<A[i]<<" ";
   cout<<endl;
}

int main()
{
   int sel=0;
   Sample<int>s;
   s.getdata();
   cout<<"ԭ�����У�";
   s.disp();
   while(true)
   {
      cout<<"\n\n���򷽷�ѡ��\n";
      cout<<"0:��������\n";
      cout<<"1:ϣ������\n";
      cout<<"2:ð������\n";
      cout<<"3:��������\n";
      cout<<"4:ѡ������\n";
      cout<<"�������˳�\n";
      cout<<"��ѡ��";
      cin>>sel;
      switch(sel)
      {
         case 0:s.insertsort();cout<<"";break;
         case 1:s.Shellsort();cout<<"";break;
         case 2:s.bubblesort();cout<<"";break;
         case 3:s.quicksort();cout<<"";break;
         case 4:s.selectsort();cout<<"";break;
         default:exit(1);
      }
      s.disp();
   }
}
