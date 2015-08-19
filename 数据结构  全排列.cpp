#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
using namespace std;
const int MAX=10;
char a[MAX],b[MAX];
bool used[MAX]={false};
void DFS(int deep,int n)
{
	int i;
	if(deep==n)
	{
		for(i=0;i<n;i++)printf("%c",b[i]);
		printf("\n");
		return ;
	}
	for(i=0;i<n;i++)
	{
		if(used[i])continue;
		used[i]=true;
		b[deep]=a[i];
		DFS(deep+1,n);
		used[i]=false;
	}
}
int main()
{
	int n,t,i;
	scanf("%d",&t);
	while(t--)
	{
	scanf("%d",&n);
	for(i=0;i<n;i++)cin>>a[i];
	DFS(0,n);
	
    }
	}


