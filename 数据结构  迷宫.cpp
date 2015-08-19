#include "stdio.h"
#include "malloc.h"
#include <iostream>
using namespace std;
typedef struct
{
	int i,j;
	int pre;
}mi;
void InitQueue(mi *&q)
{
	q=(mi * )malloc(sizeof(mi));
	q->i=0;
	q->j=0;
	q->pre=0;
}
void ClearQueue(mi *&q)
{
	free(q);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n,xi,yi,xe,ye;
		cin>>m>>n;
		int mg[n+2][m+2];
		for(int i=1;i<n+1;i++)
		for(int j=1;j<m+1;j++)
		cin>>mg[i][j];
		for(int i=0;i<n+2;i++){int j=0;mg[i][j]=0;}
		for(int i=0;i<m+2;i++){int j=0;mg[j][i]=0;}
		for(int i=0;i<n+2;i++){int j=m+1;mg[i][j]=0;}
		for(int i=0;i<m+2;i++){int j=n+1;mg[j][i]=0;}

		for(int i=1;i<n+1;i++)
		for(int j=1;j<m+1;j++)
		if(mg[i][j]==2){xi=i;yi=j;break;}

		for(int i=1;i<n+1;i++)
		for(int j=1;j<m+1;j++)
		if(mg[i][j]==3){xe=i;ye=j;break;}

		mi *Qu[m*n];
		for(int i=0;i<m*n;i++)
		InitQueue(Qu[i]);
		int front=-1,rear=-1;
		int p,q,find=0;
		rear++;
		Qu[rear]->i=xi;
		Qu[rear]->j=yi;
		Qu[rear]->pre=-1;
		mg[xi][yi]=-1;
		mg[xe][ye]=1;
		while(front<=rear&&!find)
		{
			front++;p=Qu[front]->i;q=Qu[front]->j;
			if(p==xe&&q==ye)
			{
				find=1;int k=front,ans=-1;
				while(k!=-1)
				{
				   k=Qu[k]->pre;
				   ans++;
				}
				cout<<ans<<endl; break;
			}
			for(int di=0;di<4;di++)
			{
				if(di==0){p=Qu[front]->i-1; q=Qu[front]->j;}
				if(di==1){p=Qu[front]->i;   q=Qu[front]->j+1;}
				if(di==2){p=Qu[front]->i+1; q=Qu[front]->j;}
				if(di==3){p=Qu[front]->i;   q=Qu[front]->j-1;}
			
				if(mg[p][q]==1)
				{
					rear++;  Qu[rear]->i=p;  Qu[rear]->j=q;  Qu[rear]->pre=front;
					 mg[p][q]=-1;
				}
			}
		}
		if(find==0)  cout<<"Oh, poor BusyJay!"<<endl;
		for(int i=0;i<m*n;i++)
		ClearQueue(Qu[i]);
	}
}
