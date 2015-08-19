#include "stdio.h"
void paixu(char a[],int m,int k)
{
	char ch;
	if( (m-1) ==k)
	{
		for(int i=0;i<m;i++)
 	printf("%c",a[i]);
 	printf("\n");
	}
	else
	{
		for(int i=k;i<m;i++)
		{
			ch=a[i];
			a[i]=a[k];
			a[k]=ch;
			if(i-k<=1)
			{
				paixu(a,m,k+1);
			}
			else
			{
				ch=a[i];
				for(int j=i;j>k+1;j--)
				{
					a[j]=a[j-1];
				}
				a[k+1]=ch;
				paixu(a,m,k+1);
				ch=a[k+1];
				for(int j=k+1;j<i;j++)
				{
					a[j]=a[j+1];
				}
				a[i]=ch;
			}
			ch=a[i];
			a[i]=a[k];
			a[k]=ch;
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int m;
		scanf("%d",&m);
		char b[m];
		scanf("%s",b);
		//printf("%s",b);
		paixu(b,m,0);
	}
	
}
