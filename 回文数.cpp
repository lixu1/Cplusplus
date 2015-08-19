#include <iostream>
using namespace std;
int main()
{
    int n,k,i;
    int a,number,t,ans;

    cin>>n;
    while (n--)
    {
        cin>>k;
        ans=0;
        for(i=1;i<=k;i++)
        {
            cin>>a;
            number=a;
            t=0;
            while(number!=0)
            {
                t=t*10+number%10;
                number=number/10;

            }
            if(t==a)ans++;

        }
        cout<<ans<<endl;
    }return 0;
}
