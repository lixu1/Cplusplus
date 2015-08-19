#include <iostream>
using namespace std;
int a[8]={2,1,-1,-2,-2,-1,1,2};
int b[8]={1,2,2,1,-1,-2,-2,-1};
int h[10][10];
int n;
int hor(int I,int x,int y,int &q )
{
   int u,v,k=0,q1=0;
   for(k=0;(k<=7)&&(!q1);k++)
   {
      u=x+a[k];
      v=y+b[k];
      if((u>=0)&&(u<n)&&(v>=0)&&(v<n))
      if(h[u][v]==0)
      {
         h[u][v]=I;
         if(I<n*n)
         {
            q1=hor(I+1,u,v,q1);
            if(q1==0) h[u][v]=0;
         }
         else q1=1;
      }
   }
   q=q1;
   return q;
}
int main()
{
   int i,j,x0,y0;
   int q=0;
   cout<<"please intput n:"<<endl;
   cin>>n;
   cout<<"please intput x0:"<<endl;
   cin>>x0;
   cout<<"please intput y0:"<<endl;
   cin>>y0;
   for(int i=0;i<n;i++)
   for(int j=0;j<n;j++)
   h[i][j]=0;
   h[x0][y0]=1;
   hor(2,x0,y0,q);
   if(q==1)
   {
      for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
      {
         printf("%5d",h[i][j]);
         if(j==n-1) cout<<endl;
      }
   }
   else cout<<"unable to give a resoluition!";
   getchar();
}
