#include "stdio.h"
int main()
{
    char a[1000],b[1000];
    while(scanf("%s %s",a,b)!=EOF)
    {
        int alength=0;
        while(a[alength]!='\0')
            alength++;
        int blength=0;
        while(b[blength]!='\0')
            blength++;
        int a1[1000];
        for(int i=0; i<alength; i++)
            a1[i]=a[alength-1-i]-'0';
        int b1[1000];
        for(int i=0; i<blength; i++)
            b1[i]=b[blength-1-i]-'0';
        int ans[alength+blength];
        for(int i=0; i<alength+blength; i++)
            ans[i]=0;
        for(int i=0; i<alength; i++)
            for(int j=0; j<blength; j++)
                ans[i+j]+=a1[i]*b1[j];
        //for(int i=alength+blength-1;i>=0;i--)
        //printf("%d ",ans[i]);
        //printf("\n");

        int temp=0;
        for(int i=0; i<alength+blength; i++)
        {
            temp=ans[i];
            ans[i]=temp%10;
            ans[i+1]+=temp/10;
        }
        int length=0;
        length=alength+blength-1;
        while(ans[length]==0&&length>=0)
            length--;
        if(length<0)
            printf("0\n");
        else
        {
            for(int i=length; i>=0; i--)
                printf("%d",ans[i]);
            printf("\n");
        }
    }
}
