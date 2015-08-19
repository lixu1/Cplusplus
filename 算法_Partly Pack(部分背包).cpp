#include "stdio.h"
void Quick(double a[],double b[],double c[],int s,int t)
{
    int i=s,j=t;
    if(i<j)
    {
        double temp=a[i];
        double temp1=b[i],temp2=c[i];
        while(i<j)
        {
            while(a[j]>=temp&&j>i)j--;
            a[i]=a[j];
            b[i]=b[j];
            c[i]=c[j];
            while(a[i]<=temp&&i<j)i++;
            a[j]=a[i];
            b[j]=b[i];
            c[j]=c[i];
        }
        a[i]=temp;
        b[i]=temp1;
        c[i]=temp2;
        Quick(a,b,c,s,i-1);
        Quick(a,b,c,i+1,t);
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        double a[n];
        double b[n];
        int v;
        for(int i=0; i<n; i++)
            scanf("%lf",&a[i]);
        for(int i=0; i<n; i++)
            scanf("%lf",&b[i]);
        scanf("%d",&v);
        double ans=0;

        for(int i=0; i<n; i++)
        {
            if(b[i]==0)
            {
                ans+=a[i];
                for(int j=i; j<n-1; j++)
                {
                    a[j]=a[j+1];
                    b[j]=b[j+1];
                }
                n--;
            }
        }


        double c[n];
        for(int i=0; i<n; i++)
        {
            c[i]=a[i]/b[i];
        }
        Quick(c,a,b,0,n-1);
        for(int i=n-1; i>=0; i--)
        {
            if(v>=b[i])
            {
                v=v-b[i];
                ans=ans+a[i];
            }
            else if(v>0)
            {
                ans=ans+a[i]/b[i]*v;
                break;
            }
        }
        printf("%.2lf\n",ans);
    }
}

