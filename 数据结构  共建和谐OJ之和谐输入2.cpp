#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
struct chuan
{
    char a;
    chuan *next;
};
bool ji(chuan *S,int a)
{ 
    for(int i=1;i<a;i++)
    {
        S=S->next;
        if(S==NULL)
        return false;
    }
    return true;
}
int main()
{
    int t;
    chuan *L,*M,*H;
    char a[100],b[100];
    char s[2001];
    cin>>t;
    while(t--)
    {
         cin>>a>>b;
         int n1=strlen(a),n2=strlen(b);
         cin.get();
         cin.getline(s,2001);
         int n=strlen(s);
         L=(chuan *)malloc(sizeof(chuan));
         L->next=NULL;
         H=L;
         for(int c=0;c<n;c++)
         {
             M=(chuan *)malloc(sizeof(chuan));
             M->next=NULL;
             M->a=s[c];
             H->next=M;
             H=M;
         }
         H=L->next;
         int an=0;
         while(ji(H,n1))
         {
             M=H;
             an=0;
             while(an<n1)
             {
                 if(M->a==a[an])
                 {
                     M=M->next;
                     an++;
                 }
                 else
                 {
                     an=0;
                     H=H->next;
                     break;
                 }
             }
             if(an==n1)
             {
                 M=H;
                 for(int i=0;i<n1-1;i++)
                 {
                     H=M->next;
                     M->next=H->next;
                     free(H);
                     H=M;
                 }
                 for(int i=n2-1;i>=0;i--)
                 {
                     M=(chuan *)malloc(sizeof(chuan));
                     M->a=b[i];
                     M->next=H->next;
                     H->next=M;
                 }
                 chuan *sa=L;
                 while(sa->next!=H)
                 sa=sa->next;
                 sa->next=H->next;
                 free(H);
                 H=M;
                 sa=NULL;
             }
         }
         M=L->next;
         while(M!=NULL)
         {
             cout<<M->a;
             M=M->next;
         }
         cout<<endl;
         while(L!=NULL)
         {
             M=L->next;
             free(L);
             L=M;
         }
    }
} 
