#include "stdio.h"
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int m;
		scanf("%d",&m);
		char b[m][m];
		char a[150];
		scanf("%s",a);
		int length=0;
		for(int i=0;a[i]!='\0';i++)
		{
			length++;
		}
		int p=0;
		for(int j=0;j<m/2;j++)
		{
			for(int k=j;k<m-j;k++)
			{
				if(p<length)   {b[j][k]=a[p]; p++;}
				else b[j][k]='#';
			}
			for(int k=j+1;k<m-j-1;k++)
			{
				if(p<length)   {b[k][m-j-1]=a[p]; p++;}
				else b[k][m-j-1]='#';
			}
			for(int k=m-j-1;k>=j;k--)
			{
				if(p<length)   {b[m-j-1][k]=a[p]; p++;}
				else b[m-j-1][k]='#';
			}
			for(int k=m-j-2;k>j;k--)
			{
				if(p<length)   {b[k][j]=a[p];  p++;}
				else b[k][j]='#';
			}
		}
		if(m%2==1)
		{
			if(p<length){b[m/2][m/2]=a[p];}
			else b[m/2][m/2]='#';
		}
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<m;k++)
			printf("%c",b[j][k]);
			printf("\n");
		}
		
	}	
}
