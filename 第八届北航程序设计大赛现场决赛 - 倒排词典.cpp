#include "stdio.h"
char a[10001][21];
bool bijiao(char b[],char c[])//b[]>=c[]
{
    int blength=0;
    while(b[blength]!='\0')
        blength++;
    int clength=0;
    while(c[clength]!='\0')
        clength++;
    int i=blength-1;
    int j=clength-1;
    while(i>=0&&j>=0)
    {
        if(b[i]==c[j])
        {
            i--;
            j--;
        }
        else if(b[i]>c[j]) return true;
        else return false;
    }
    if(blength<clength)
        return false;
    else
        return true;
}
bool bijiao2(char b[],char c[])//b[]<=c[]
{
    int blength=0;
    while(b[blength]!='\0')
        blength++;
    int clength=0;
    while(c[clength]!='\0')
        clength++;
    int i=blength-1;
    int j=clength-1;
    while(i>=0&&j>=0)
    {
        if(b[i]==c[j])
        {
            i--;
            j--;
        }
        else if(b[i]<c[j]) return true;
        else return false;
    }
    if(blength>clength)
        return false;
    else
        return true;
}
void quicksort(int s,int t)
{
    int i=s,j=t;
    if(i<j)
    {
        char temp[21];
        for(int l=0; l<21; l++)
            temp[l]=a[i][l];
        while(i<j)
        {
            while(i<j&&bijiao(a[j],temp))j--;
            for(int k=0; k<21; k++)
            {
                a[i][k]=a[j][k];
            }
            while(i<j&&bijiao2(a[i],temp))i++;
            for(int k=0; k<21; k++)
                a[j][k]=a[i][k];
        }
        for(int k=0; k<21; k++)
            a[i][k]=temp[k];
        quicksort(s,i-1);
        quicksort(i+1,t);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%s",a[i]);
        quicksort(0,n-1);
        for(int i=0; i<n; i++)
        {
            printf("%s\n",a[i]);
        }
    }
}

