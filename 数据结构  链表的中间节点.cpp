#include<iostream>
//#include<cstdlib>
using namespace std;
struct lian
{
    int a;
    lian *next;
};
int main()
{
    int t;
    int e;
    lian *L=NULL,*M=NULL,*H=NULL;
    cin>>t;
    while(t--)
    {
        int i=0;
        cin>>e;
        L=(lian *)malloc(sizeof(lian));
        i++;
        H=L;
        L->a=e;
        L->next=NULL;
        if(cin.get()=='\n')
        {
            cout<<e<<endl;
            free(L);
            L=NULL;
            continue;
        }
        else
        {
            while(i<100)
            {
                cin>>e;
                if(cin.get()!=' ')
                break;
                M=(lian *)malloc(sizeof(lian));
                i++;
                H->next=M;
                M->a=e;
                M->next=NULL;
                H=M;
            }
            M=(lian *)malloc(sizeof(lian));
            i++;
            H->next=M;
            M->a=e;
            M->next=NULL;
            H=M;
            i/=2;
            M=L;
            for(int j=0;j<i;j++)
            {
                M=M->next;
            }
            cout<<M->a<<endl;
            M=NULL;
            H=L->next;
            while(L->next!=NULL)
            {
                free(L);
                L=H;
                H=L->next;
            }
            free(L);
            L=NULL;
        }
    }
}
