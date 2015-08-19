#include "stdio.h"
#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
	{
		char a[1000];int length=0;
		cin.getline(a,1000);
		for(int i=0;a[i]!='\0';i++)
		length++;
		//while(scanf("%c",&a[length])&&a[length]!='\n')
		//{length++;}
		//for(int i=0;i<length;i++)
		//printf("%c",a[i]);
		//printf("\n");
		char b[100];int length1=0;
		for(int i=0;i<length;i++)
		{
			if(a[i]>='A'&&a[i]<='Z'){b[length1]=a[i];length1++;}
		}
		//for(int i=0;i<length1;i++)
		//printf("%c",b[i]);
		//printf("\n");
		char c[100];int length2=0;
		for(int i=0;i<length1;i++)
		{
			int j=0;
			while(j<length2&&(b[i]-c[j]>=0))j++;
			for(int k=length2;k>j;k--)
			c[k]=c[k-1];
			c[j]=b[i];
			length2++;
		}
		//for(int i=0;i<length2;i++)
		//printf("%c",c[i]);
		//printf("\n");
		int p=0;
		for(int i=0;i<length;i++)
		{
			if(a[i]>='A'&&a[i]<='Z'){a[i]=c[p];p++;}
		}
		for(int i=0;i<length;i++)
		printf("%c",a[i]);
		printf("\n");
	}
	//scanf("%d",&t);
}
