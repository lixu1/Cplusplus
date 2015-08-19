#include "stdio.h"

int mi(int a,int b,int c)
{
    int er1[1001];
    for(int i=0; i<1001; i++)
        er1[i]=0;
    int length=0;
    while(b>1)
    {
        er1[length]=b%2;
        length++;
        b=b/2;
    }
    er1[length]=1;
    length++;
    int ans=1;
    if(er1[0]==1) ans= a%c;
    for(int i=1; i<length; i++)
    {
        if(er1[i]==1)
        {
            int ans1=a%c;
            for(int j=i; j>0; j--)
            {
                ans1=(ans1*ans1)%c;
            }
            ans=(ans1*ans)%c;
        }
    }
    return ans;
}
int main()
{
    int a;
    while(scanf("%d",&a)!=EOF)
    {
        int b;
        scanf("%d",&b);
        int b1=1;
        int flag=false;
        for(int i=0; i<b; i++)
        {
            b1=b1*b;
            if(b1>a)
            {
                flag=true;
                break;
            }
        }
        if(flag==true)
        {
            int number1=a;
            int number2=mi(b,b,a);
            int temp;
            while(number2!=0)
            {
                temp=number1%number2;
                number1=number2;
                number2=temp;
            }
            printf("%d\n",number1);
        }
        else
        {
            int number1=a;
            int number2=b1;
            int temp;
            while(number2!=0)
            {
                temp=number1%number2;
                number1=number2;
                number2=temp;
            }
            printf("%d\n",number1);
        }
    }
}
