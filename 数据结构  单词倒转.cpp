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
		char a[100000];int length=0; 
		//while( scanf("%c",&a[length]) && a[length]!='\n')
		//{length++;}
		cin.getline(a,100000);
		for(int i=0;a[i]!='\0';i++)
		length++;
		char b[100000];
		int i=0,j=0;
		while(j<length)
		{
			while(( (a[j]>='A'&&a[j]<='Z') || (a[j]>='a'&&a[j]<='z') )&&j<length) j++;
			for(int k=i;k<j;k++) b[k]=a[j-k+i-1];b[j]=a[j];
			i=j+1;
			j++; 
		}
		for(int q=0;q<length;q++)
		printf("%c",b[q]);
		printf("\n");
	}
}
 
