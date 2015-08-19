#include <iostream>
using namespace std;
typedef struct shuzu
{
    int a[200];
    int length;
};

void InitList(shuzu &l ,int a)
{
    for(int i=0;i<a;i++)
    {
        int b;
        cin>>b;
        l.a[i]=b;
    }
    l.length=a;
}
void DestroyList(shuzu &l)
{
    for(int i=0;i<200;i++)
    {
        l.a[i]=0;
    }
    l.length=0;
}
void GetElem(shuzu &l,int i,int &e)
{
    e=l.a[i-1];
}

int ListDelete(shuzu &l,int i)
{
    i--;
    for(int j=i;j<l.length-1;j++)
    l.a[j]=l.a[j+1];

    l.length--;
}
int paixu(shuzu &l)
{
    for(int next=1;next<l.length;next++)
    {
        int insert=l.a[next];
        int movement=next;
        while((movement>0)&&(l.a[movement-1]>insert))
        {
            l.a[movement]=l.a[movement-1];
            movement--;
        }
        l.a[movement]=insert;
    }
}
int hebing(shuzu l,shuzu l1,shuzu &l2)
{
    for(int i=0;i<l.length;i++)
    {
        l2.a[i]=l.a[i];
    }
    for(int i=0;i<l1.length;i++)
    {
        l2.a[i+l.length]=l1.a[i];
    }
    l2.length=l.length+l1.length;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        shuzu l,l1,l2;
        InitList(l,a);
        InitList(l1,b);
        DestroyList(l2);
        hebing(l,l1,l2);
        paixu(l2);
        ListDelete(l2,c);
        for(int i=0;i<a+b-1;i++)
        {
            cout<<l2.a[i]<<" ";
        }
        cout<<endl;
    }
}


